#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/* RECEIVER */

struct frame {
    char length;
    struct doubleByte *data;
    struct frame *next;
};

struct doubleByte {
    char hi;
    char lo;
    struct doubleByte *next;
};

/*
 * 
 */
int isParitySpot(int x) {
    return (x == 0 || x == 1 || x == 3 || x == 7 || x == 15 || x == 16);
}

int checkBitFromLeft(char byte, int place) {
    return byte & 1<<(7-place);
}

/* 
 * returns 0 if the bit in the PLACE is 0, and 1 if the bit is a 1
 */
int checkBit(char byte, int place) {
    return byte & 1<<place;
}

/*
 * sets the bit in BYTE at PLACE to 1 and returns new byte
 */
char setBitFromLeft(char *byte, int place) {
    return (*byte | 1 << (7-place));
}

/*
 * sets the bit in BYTE at PLACE to 1 and returns new byte
 */
char setBit(char *byte, int place) {
    return (*byte | 1 << place);
}


/*
 * checks if a number is 0 or a power of 2
 */
int isNotPowerOfTwo(int x) {
    return (x != 1) && (x & (x-1));
}


void checkCRC(struct frame *data) {
    // TODO
}

int validateParity(struct doubleByte *data, int i) {
    int errorFound = 0;
    int errorSpot = -1;
    int count;
    if (i == 0) {
        int j;
        for (j = 0; j < 8; j+=2) {
            if (data->hi & 1<<j) {
                count++;
            }
            if (data->lo & 1<<j) {
                count++;
            }
        }
    }
    else if (i == 1) {
        int j;
        for (j = 1; j < 8; j += 2) {
            int k;
            for (k = 0; k < 2; k++) {
                if (data->hi & 1 <<j) {
                    count++;
                }   
                if (data->lo & 1 <<j) {
                    count++;
                }
            }
        }
    }
    else if (i == 3) {
        int j;
        for (j = 3; j < 8; j += 2) {
            int k;
            for (k = 0; k < 4; k++) {
                if (data->hi & 1 <<j) {
                    count++;
                }
                if (data->lo & 1 <<j) {
                    count++;
                }
            }
        }
    }
    else if (i == 7) {
        int j;
        if (data->hi & 1 << 7) {
            count++;
        }
        for (j = 0; j < 7; j++) {
            if (data->lo & 1 <<j) {
                count++;
            }
        }
    }
    else if (i == 15) {
    
    }
    
    count = (count % 2);
    if (count) {
        printf("found odd number of 1's for p1\n");
        // TODO Fix!
    }
    else {
        printf("found even number of 1's for p1\n");
    }
}

/* 
 * Checks the parity of a given doubleByte and fixes and errors it can
 */ 
void checkParity(struct doubleByte *data) {
    int i;
    int totalErrorsFound = 0;
    for (i = 0; i < 16; i++) {
        if (isParitySpot(i)) {
            totalErrorsFound += validateParity(data, i);
        }
    }
}

/* 
 * Constructs the data char from a doubleByte
 */ 
char reconstructData(struct doubleByte *data) {
    char *result;
    result = (char *)malloc(1);    
    
    printf("Restoring Data for \n\tHI: %x\n\tLO: %x\n", data->hi, data->lo);
    
    int i = 0, j = 0;
    
    if (checkBit(data->hi, 5)) {
        *result = setBit(result, 7);
    }
    
    if (checkBit(data->hi, 3)) {
        *result = setBit(result, 6);
    }
    
    if (checkBit(data->hi, 2)) {
        *result = setBit(result, 5);
    }
    
    if (checkBit(data->hi, 1)) {
        *result = setBit(result, 4);
    }
    
    if (checkBit(data->lo, 7)) {
        *result = setBit(result, 3);
    }
    
    if (checkBit(data->lo, 6)) {
        *result = setBit(result, 2);
    }
    
    if (checkBit(data->lo, 5)) {
        *result = setBit(result, 1);
    }
    
    if (checkBit(data->lo, 4)) {
        *result = setBit(result, 0);
    }
    printf("-----RESULT: %x\n", *result);
    /*
    int i,          // index in doubleByte
        j = 0;      // index in restored byte
    for (i = 0; i < 16; i++) {
        if (!isParitySpot(i)) {
            printf("--Data spot %d\n", i);
            if (i > 8) {
                if (checkBitFromLeft(data->lo, i)) {
                    result = setBit(&result, j++);
                    printf("Setting bit in spot %d\n", j-1);
                }
            }
            else {
                if (checkBitFromLeft(data->hi, i)) {
                    result = setBit(&result, j++);
                    printf("Setting bit in spot %d\n", j-1);
                }
            } 
        }
    }
    */
    return *result;
}

/* 
 * Displays a given frame in stdout
 */ 
void displayFrame(struct frame *frame) {
    if (frame && frame->data) {
        char *result = (char *) malloc(64);
        
        struct doubleByte *t = frame->data;
        int i = 0;
        while (t != NULL) {
        // TODO - low byte gets stuck as 2 bytes?!?!?! and breaks everything
            if (t->lo != 0xffffffc5) {
                char restored = reconstructData(t);
                printf("Restored char: %c\n", restored);
                strcat(result, &restored);
                t = t->next;
            }
        }
        
        printf("RESULT: %s\n", result);
    }
}

/*
 * Reconstructs a whole frame with the given data
 */
struct frame reconstructFrame(char length, struct doubleByte *data) {
    struct frame result;
    result.length = length;
    result.data = data;
    result.next = NULL;
    
    return result;
};

/*
 * Receives a single frame
 */
struct frame receiveFrame(FILE *file) {
    char *currentByte, *nextByte, *actualData, length;
    struct frame result;

    // allocate mem for bytes
    currentByte = (char *) malloc(1);
    nextByte = (char *) malloc(1);

    *currentByte = fgetc(file);   
    
    // if we find 2 SYN chars in a row, then it is a new frame
    if (*currentByte == 22 && (*currentByte = fgetc(file)) == 22) {
        // the next byte should be length
        *currentByte = fgetc(file);
        
        length = *currentByte;
        int i = length;
        struct doubleByte *start = NULL, *current = NULL, *tmp = NULL, *frameData;
        while (i >= 0) {
            // read the lo and hi part of the data
            *currentByte = fgetc(file);
            *nextByte = fgetc(file);
            
            frameData = (struct doubleByte *)malloc(sizeof(struct doubleByte));
            
            // create linked list of doubleBytes
            frameData->hi = *currentByte;
            frameData->lo = *nextByte;
            frameData->next = NULL;
            //printf("Hi: %x\nLo: %x\n\n", frameData->hi, frameData->lo);
            if (start == NULL) {
                start = frameData;
            }
            else {
                tmp->next = frameData;
            }
            tmp = frameData;
            
            i--;
        }
        result = reconstructFrame(length, start);
        
    }
    
    return result;
}

/*
 * Starts receiving all the frames
 */
void receiveData(char *filepath) {
    FILE *file;
    char *mode = "r";
    struct frame *current;
    
    file = fopen(filepath, mode);
    if (file == NULL) {
        printf("Could not open file");
    }
    
    // read the whole file
    while (!feof(file)) {
        current = (struct frame *)malloc(sizeof(struct frame));
        *current = receiveFrame(file);
        if (current->length > 0) {
            //checkParity(current.data);
            displayFrame(current);
        
        }
        free(current);
    }
    
    fclose(file);
}

/*
 * 
 */
int main(int argc, char **argv) {
    char *inputFile;
    char *outputFile;
    char *errorHandling;
    int c;
    
    // Parse cmd line args
    if (argc < 3) {
        fprintf(stderr, "Invalid number of arguments\n");
        return 1;
    }
    while ((c = getopt(argc, argv, "o:i:")) != -1) {
        switch (c) {
            case 'i':
                if (strlen(optarg) > 1) {
                    inputFile = optarg;
                }
                else {
                    fprintf(stderr, "Bad input file\n");
                    return 1;
                }
                break;
            case 'o':
                if (strlen(optarg) > 1) {
                    outputFile = optarg;
                }
                else {
                    fprintf(stderr, "Bad input file\n");
                    return 1;
                }
                break;
            case 'c':

                if (strlen(optarg) > 1) {
                    // TODO - check for HAM or CRC
                    errorHandling = optarg;
                }
                else {
                    fprintf(stderr, "Bad Error Handling Type! %c is invalid ( should be 0 or 1)\n", optopt);
                    return 1;
                }
            case '?':
                // bad args
                if (optopt == 'i' || optopt == 'o') {
                    fprintf(stderr, "File must be specified with -%c\n", optopt);
                }
                else if (optopt == 'c') {
                    fprintf(stderr, "Error checking type must be specified with -%c\n", optopt);
                }
                else {
                    fprintf(stderr, "Unknown option -%c\n", optopt);
                }
                return 1;
            default:
                return 1;
        }
    }
    
    fprintf(stdout, "Input file: %s\n", inputFile);
    fprintf(stdout, "Output file: %s\n", outputFile);
//    fprintf(stdout, "Error Handling: %s\n", errorHandling);

    receiveData(inputFile);
    
    return 0;
}
