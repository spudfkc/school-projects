#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define ASCII_VALUE 48

/* Author: Nick Caley
 * Date: 02/07/2013
 * Course: EECS 2550
 * 
 * Project 01 - A simple encryption program written in C
 * It takes 2-3 parameters: 
 *  1. a number to rotate all alphabetic characters by
 *  2. an input file path
 *  3. an output file path (defaults to stdout)
 * 
 * The program will then rotate any alphabetic charaters found in the input file
 * by the given number (case stays the same) and output it to the output file.
 * 
 */

/* Handles opening/closing of files, reading/writing, and rotating*/
int rotateFile(char *inputFile, char *outputFile, int rotate) {
	FILE *inFile;
	inFile = fopen(inputFile, "r");

	if (inFile == NULL) {
		perror("The following error occured while trying to read a file\n");
		return 1;
	}
	
	FILE *outFile;
	if (strcmp(outputFile, "stdout") == 0 || strcmp(outputFile, "") == 0) {
        outFile = stdout;
	} 
	else {
    	outFile = fopen(outputFile, "w");
		if (outFile == NULL) {
		    perror("The following error occured while trying to write a file\n");
            return 1;
	    }
	}
	
	while (!feof(inFile)) {
	    char *buffer = malloc(1);
        fread(buffer, 1, 1, inFile);
        
        if (isalpha(*buffer)) {
            unsigned int newNumber = 0;
            newNumber = *buffer + rotate;
            if (isupper(*buffer)) {
                if (newNumber > 90) {
                    newNumber -= 26;
                } 
            }
            else if (islower(*buffer)) {
                if (newNumber > 122) {
                    newNumber -= 26;
                }
            }
            *buffer = newNumber;
        }
        fwrite(buffer, 1, 1, outFile);
        free(buffer);
    }
	
	if (inFile != NULL) { fclose(inFile); }
	if (outFile != NULL) { fclose(outFile); }
	return 0;
}

/* Checks the arguments for the program for validity */
int main(int argc, char **argv) {
	int toRotate = 13;
    const int MAX_FILE_LENGTH;
	char *inputFile = malloc(MAX_FILE_LENGTH);
	char *outputFile = malloc(MAX_FILE_LENGTH);
	
	int c;
	while((c = getopt(argc, argv, "r:i:o:")) != -1) {
	    size_t len = strlen(optarg);
		switch (c) {
			case 'r':
			    if (len > 0 && len < 3) { 
                    toRotate = atoi(optarg);
			        //toRotate = *optarg - ASCII_VALUE; 
			    }
			    else { 
			        printf("Bad number to rotate by2\n"); 
			        return 1; 
			    }
                if (toRotate < 0 || toRotate > 26) {
   			        printf("Bad number to rotate by\n"); 
   			        return 1; 
   			    }
				break;
			case 'i':
				if (len > 1 &&  len < MAX_FILE_LENGTH) { 
				    inputFile = optarg; 
			    }
				else { 
				    printf("No input file specified\n"); 
				    return 1; 
				}
				break;
			case 'o': 
                if (len > 1 && len < MAX_FILE_LENGTH) { 
                    outputFile = optarg; 
                } 
   				else { 
   				    printf("No output file specified - using stdout\n"); 
   				    outputFile = "stdout";
   				}
				break;
			default: 
				printf("\nUsage: simpleEncrypter -r[0-26] -i[inputFilePath] [-o OutputFilePath]\n");
				return 1;
		}
	}

	printf("\n==================================================\n");
    char *s0 = " _____ _           _     _____                     _           \n";
    char *s1 = "|   __|_|_____ ___| |___|   __|___ ___ ___ _ _ ___| |_ ___ ___ \n";
    char *s2 = "|__   | |     | . | | -_|   __|   |  _|  _| | | . |  _| -_|  _|\n";
    char *s3 = "|_____|_|_|_|_|  _|_|___|_____|_|_|___|_| |_  |  _|_| |___|_|  \n";
    char *s4 = "              |_|                         |___|_| \n";
    printf("\n%s%s%s%s%s\n", s0,s1,s2,s3,s4);
              
	printf("=================================================\n");
	printf("=====  # to rotate by: %u\n", toRotate);
	printf("=====  Input File: %s\n", inputFile);
	printf("=====  Output File: %s\n", outputFile);
	printf("==================================================\n\n");
	
	return rotateFile(inputFile, outputFile, toRotate);
}
