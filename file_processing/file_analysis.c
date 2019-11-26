/**
 * this code will analysis any text file that you send in
 * it will perform the following functions
 * 
 * *****
 * 
 * 1. return the number lines inside
 * 2. return the content into a new file which will contain all the lines from the original text file.
 *     all the lines will be on a new line
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int main(){
    char data[MAXLEN];
    int line_counter = 0, len = 0, i;
    FILE *infile, *outfile;

    if ((infile = fopen("random_text_file.txt", "r")) == NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    
    infile = fopen("random_text_file.txt", "r"); outfile = fopen("formatted.txt", "w");

    printf("data out in line by line: \n");

    
    while (fgets(data, MAXLEN, infile) != NULL){
        line_counter ++;
        len = strlen(data);

        // writing data to the output file
        for (i = 0; i < len; i ++){
            if (data[i] == '.'){
                fputs(".\n", outfile);
                printf("\n");
            }else{
                fputc(data[i], outfile);
                printf("%c", data[i]);
            }
        }
    }
    
    printf("This file contains a total of %d lines.\n", line_counter);

    fclose(infile); fclose(outfile);
    return 0;
}