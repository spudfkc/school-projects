#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

/* 
 * 
 */
struct doubleByte {
    char dataLo;
    char dataHi;
    struct doubleByte *next;
};

/*
 *
 */
struct frame {
	char SYN1;
	char SYN2;
	char length;
	struct doubleByte *data;
};

struct frameCrc {
    char SYN1;
    char SYN2;
    char length;
    char crc;
    char *data;
};

/*
 *
 */
struct frameWrap {
	struct frame data;
	struct frameWrap *next;
};

/*
 * checks if a number is 0 or a power of 2
 */
int isNotPowerOfTwo(int x) {
    return (x != 1) && (x & (x-1));
}

/*
 * 
 */
int isParitySpot(int x) {
    return (x == 0 || x == 1 || x == 3 || x == 7 || x == 15 || x == 16);
}

/*
 *
 */
char toggleBit(char *byte, int place) {
    return *byte ^ 1<<place;
}

/*
 *
 */
char unsetBit(char *byte, int place) {
    return *byte & ~(1<<place);
}

/*
 * sets the bit in BYTE at PLACE to 1 and returns new byte
 */
char setBit(char *byte, int place) {
    return *byte | 1<<place;
}

/* 
 * returns 0 if the bit in the PLACE is 0, and 1 if the bit is a 1
 */
int checkBit(char byte, int place) {
    return byte & 1<<place;
}

char calculateCrc(struct frameCrc f) {
    // TODO
    char result = 0;
    
    return result;
}

/* 
     p1  p2  d1  p4  d2  d3  d4  p8  d5  d6  d7  d8  d9  d10 d11 p16 || d12 d13 d14 d15 
 p1  x       x       x       x       x       x       x       x       x       x
 p2      x   x           x   x           x   x           x   x           x   x      
 p4              x   x   x   x                   x   x   x   x                   x
 p8                              x   x   x   x   x   x   x   x
 p16                                                             x   x   x   x   x
 */
// TODO - clean this up - this can be optimized 
void calcParityBit(struct doubleByte *data, int place) {
    int result = 0;
    int i;
    if (place == 0) {
        // check every odd place
        for (i = 1; i < 16; i += 2) {
            if (i > 7) {
                int k = i - 9;
                printf("checking spot %u\n", k);
                if (checkBit(data->dataLo, 7-k)) {
                    result++;
                } 
            }
            else {
                int k = i - 1;
                printf("checking spot %u\n", k);
                if (checkBit(data->dataLo, 7-k)) {
                    result++;
                }
            }
        }
        printf("____P1 result: %u\n", result);
        if (result % 2 == 0) { data->dataHi = setBit(&(data->dataHi), 7); }
    }
    else if (place == 1) {
        for (i = 2; i < 16; i+=4) {
            int j;
            for (j = 0; j < 2; j++) {
                if ((i+j) > 8) {
                    result += checkBit(data->dataLo, 15-(i+j));
                }
                else {
                    result += checkBit(data->dataHi, 7 - (i+j));
                }
            } 
        }
        if (result % 2 == 0) { data->dataHi = setBit(&(data->dataHi), 6); }
    }
    else if (place == 3) {
        for (i = 4; i < 16; i+=8) {
            int j;
            for (j = 0; j < 4; j++) {
                if ((i+j) > 8) {
                    result += checkBit(data->dataLo, i+j);  // TODO 
                }
                else {
                    result += checkBit(data->dataHi, 8 - (i+j));    // TODO
                }
            } 
        }
        if (result % 2 == 0) { data->dataHi = setBit(&(data->dataHi), 4); }
    }
    else if (place == 7) {
        for (i = 8; i < 16; i+=16) {
            int j;
            for (j = 0; j < 8; j++) {
                if ((i+j) > 8) {
                    result += checkBit(data->dataLo, 8-(i+j));  // TODO
                }
                else {
                    result += checkBit(data->dataHi, 8 - (i+j));    // TODO
                }
            } 
        }
        if (result % 2 == 0) { data->dataHi = setBit(&(data->dataHi), 0); }
    }
    else if (place == 15) {
        // TODO - not sure what we want to do here yet
    }
    else {
        fprintf(stderr, "Cannot calculate parity bit for non-power-of-2 place [ %u ] (max: 16)\n", place);
    }
}

/*
 *
 */
void putParityBits(struct doubleByte *data) {
    char *lo;
    char *hi;
    int i, j, k;
    
    // TODO is this valid?
    lo = &((*data).dataLo);
    hi = &((*data).dataHi);
    
    // iterate through each bit in the 2 bytes
    // TODO - optimize this
    for (i = 0; i < 16; i++) {
        if (isParitySpot(i)) {
            // this will insert the parity bits into the data part of the doubleByte
            calcParityBit(data, i);
        }
    }
}

/*
 * 
 */
struct doubleByte putDataByte(char data) {
    struct doubleByte result;   // TODO - do we need to malloc?
    result.dataLo = 0;
    result.dataHi = 0;
    result.next = NULL;
    
    int i = 0,      // contains the index to original data bit
        j = 0,      // contains index to bit in doubleByte
        k = 0;      // position in lo/hi byte to set
        
    char *c;        // holds lo/hi byte to edit
    for (i = 0; i < 8; i++) {
        while (isParitySpot(j)) { 
            j++;    // find the next spot we can put data
        }
        
        //fprintf(stdout, "Putting data bit in place %i\n", j);
        
        // check the bit, and set as needed (it's already cleared)
        if (checkBit(data, 7-i)) {
            if (j > 7) {
                c = &result.dataLo;
                k = j - 8;
                result.dataLo = setBit(c, 7-k);
            }
            else {
                c = &result.dataHi;
                k = j;
                result.dataHi = setBit(c, 7-k);
            }
            printf("setting bit %i\n", k);
        }
        j++;        // move to next spot
    }
    //printf("DataLo: %x\n", result.dataLo);
    //printf("DataHi: %x\n", result.dataHi);
    fprintf(stdout, "---- Data put for byte %c Done ----\n", data);
    //printf("--- %x ---\n", data);
    return result;
}

/*
 * flips a random bit in the given byte and returns the byte
 */
char corruptByte(char *byte) {
    srand(time(NULL));  // initialize random seed
    
    // generate a random number between 0 and 8
    // this will be the bit place we will change
    int rshift = rand() % 8;
    
    fprintf(stdout, "Flipping bit %u in byte %x", rshift, *byte);
    
    // flip the bit
    *byte = toggleBit(byte, rshift);
    
    fprintf(stdout, "Resulting byte is %x", *byte);    
    
    return *byte;
}

/*
 *
 */
char * readFile(int offset, int length, char *filepath) {
    FILE *file;
    char *mode = "r";
    int fileSize;
    char *buffer;
    size_t result;
    // try to open the file for reading    
    file = fopen(filepath, mode);  
    
    if (file == NULL) {
        fprintf(stderr, "Cannot open file for reading: %s \n", filepath);
        //exit(1);
    }
    // go to where we should start reading from
    fseek(file, offset, SEEK_SET);
    
    buffer = malloc(length);    // TODO malloc only remaining space at EOF
    if (buffer == NULL) {
        fprintf(stderr, "Could not allocate memory\n");        
    }
    
    result = fread(buffer, 1, length, file);
    //printf("STATS: result=%d  length=%d\n", (int)result, length);
    if (feof(file)) {
        fprintf(stderr, "EOF - Last Frame!\n");    
    }    
    if (result == 0) {
        buffer = NULL;
    }
    fclose(file);
    
    return buffer;
}

/*
 * create frame from start of srcData with length
 */
struct frame createFrame(char *srcData, int length) {
	if (length > 64) {
		// TODO - error!
	}
	
	struct frame newFrame;

	newFrame.SYN1 = 22;
	newFrame.SYN2 = 22;
	
	newFrame.length = length; // converting from 32bit int to 8bit char
	
    /* START HAMMING CODE */    
	struct doubleByte *head = NULL, *tmp, *current = NULL;
    int i;
    for (i = 0; i < length; i++) {
        tmp = (struct doubleByte *) malloc(sizeof(struct doubleByte));
        *tmp = putDataByte(srcData[i]);
        
        printf("TMP VALUE-LO: %x\n", tmp->dataLo);
        printf("TMP VALUE-HI: %x\n", tmp->dataHi);
     
        putParityBits(tmp);
        
        printf("PARITY VALUE-LO: %x\n", tmp->dataLo);
        printf("PARITY VALUE-HI: %x\n", tmp->dataHi);
        
        if (head == NULL) {
            head = tmp;
	        newFrame.data = head;
        }
        if (current != NULL) {
            current->next = tmp;       
        }
        current = tmp;  
    }
    /* END HAMMING CODE */    

	return newFrame;
}

struct frameCrc createFrameCrc(char *srcData, int length) {
    if (length > 64) {
        // TODO 
    }
    
    struct frameCrc newFrame;
    
    newFrame.SYN1 = 22;
    newFrame.SYN2 = 22;
    
    newFrame.length = length;
    
    /* START CRC */
    int i;
    newFrame.data = srcData;
    printf("DATA STRING: %s\n", newFrame.data);
    
    newFrame.crc = calculateCrc(newFrame);
    /* END CRC */
    
    return newFrame;
}

/*
 *******************************************************************************
 This handles the writing of the frame to a file
 */
size_t writeFrameCrc(struct frameCrc *f, char *filepath) {
    FILE *file;
    const char *mode = "a";
    size_t result = 0;
    
    file = fopen(filepath, mode);
    
    if (file == NULL) {
        perror("The following error occured");
        printf("Unable to open %s for writing!\n", filepath);
        exit(1);
    }
    
    fseek(file, 0, SEEK_END);       // Seek to the end of the file, since we're appending stuff

    result  = fwrite(&(f->SYN1), 1, 1, file);
    result += fwrite(&(f->SYN2), 1, 1, file);
    result += fwrite(&(f->length), 1, 1, file);
    
    result += fwrite(&(f->data), 1, f->length, file);
    result += fwrite(&(f->crc), 1, 1, file);
    
    if (result != (4 + f->length)) {
        printf("Error writing frame - only wrote %zu bytes when expected to write %d\n", result, f->length + 4);
    }
    
    fclose(file);
    return result;
}

/*
 *******************************************************************************
 This handles the writing of the frame to a file
 */
size_t writeFrame(struct frame *f, char *filepath) {
    FILE *file;                     // file we are transmitting to
    const char *mode = "a";         // append mode - TODO more handling if file exists (replace on first round)
    size_t result = 0;

    file = fopen(filepath, mode);   // opent the file for writing
    
    if (file == NULL) {
        perror("The following error occured ");
        printf("Unable to open %s for writing!\n", filepath);
        exit(1);
    }
    
    // TRANSMIT FRAME //
    fseek(file, 0, SEEK_END);       // Seek to the end of the file, since we're appending stuff

    result  = fwrite(&(f->SYN1), 1, 1, file);
    result += fwrite(&(f->SYN2), 1, 1, file);
    result += fwrite(&(f->length), 1, 1, file);
    
    struct doubleByte *dataToWrite;
    dataToWrite = f->data;
    while (dataToWrite != NULL) {
        result += fwrite(&(dataToWrite->dataHi), 1, 1, file);
        result += fwrite(&(dataToWrite->dataLo), 1, 1, file);
        dataToWrite = dataToWrite->next;
    }
    
    if (result != (3 + 2*(unsigned int)f->length)) {
        printf("Error writing frame - only wrote %zu bytes when expected to write %d\n", result, f->length + 3);
    }
    
    fclose(file);
    return result;
}

/*
 *******************************************************************************
 */
void transmitFrame(struct frame *toWrite, char *filepath) {
    size_t result;      // number of bytes transmitted
    
    // This can be swapped for other methods of transmitting (instead of just writing to a file)
    result = writeFrame(toWrite, filepath);
}

void transmitFrameCrc(struct frameCrc *toWrite, char *filepath) {
    size_t result;
    result = writeFrameCrc(toWrite, filepath);
}

/*
 *******************************************************************************
 */
int main(int argc, char **argv) {
	char *inputFile;
    char *outputFile;
    char *encoding = "h";
	int c;
	
	if (argc < 3) {
	    fprintf(stderr, "Invalid number of arguments!\n");
	    return 1;
	}
	
    while ((c = getopt(argc, argv, "o:i:c:")) != -1) {
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
                if (strlen(optarg) == 1) {
                    encoding = optarg;
                    printf("OPTARG: %c\n", *optarg);
                    if (*optarg == 'c' || *optarg == 'h') {
                    
                    }
                    else {
                        fprintf(stderr, "Bad encoding type\n");
                        return 1;
                    }
                }
                else {
                    fprintf(stderr, "Bad encoding type\n");
                    return 1;
                }
                break;
            case '?':
                // bad args
                if (optopt == 'i' || optopt == 'o') {
                    fprintf(stderr, "File must be specified with -%c\n", optopt);
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
	
	/* BEGIN TRANSMITION */
	char *buffer;
	int offset;
	int length;
	int blength;
    FILE *file;
	offset = 0;
    length = 64;

    int framesLeft = 1;     // send at least one frame
    
    while (framesLeft) {
        buffer = readFile(offset, length, inputFile);
        blength = strlen(buffer);
        printf("blength: %d\n", blength);
        if (blength < 64) {
            length = blength;
            framesLeft = 0;
        }
        
        if (encoding[0] == 'h') {
            struct frame *tmp;
            tmp  = (struct frame *) malloc(sizeof(struct frame));
            *tmp = createFrame(buffer, length);
            transmitFrame(tmp, outputFile);
            free(tmp);    
        }
        else if (encoding[0] == 'c') {
            struct frameCrc *tmp;
            tmp = (struct frameCrc *) malloc(sizeof(struct frameCrc));
            *tmp = createFrameCrc(buffer, length);
            transmitFrameCrc(tmp, outputFile);
            free(tmp);
        }
        
        offset += length;
    }

    printf("\n - Transmition Done - \n");

	return 0;
}


