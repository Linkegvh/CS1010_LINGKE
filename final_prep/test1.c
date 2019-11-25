#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 46 
#define ISBN_LEN 18
#define MAX_BOOKS 800 
 
typedef struct{
    char title[MAX_STRING_LEN]; 
    char author[MAX_STRING_LEN]; 
    char isbn[ISBN_LEN];
    float price;
    int qty;
} book_t;

book_t book_list[MAX_BOOKS];

int read_file (char [], book_t []);

int main(void) {
    char file_name [100];
    printf("input the file name: ");
    scanf("%s", file_name);
    read_file(file_name, book_list);
}

int read_file(char filename[], book_t booklist[]){
    int rec_read = 0, len; char ch;
    FILE *fptr;

    if ((fptr = fopen(filename, "r")) == NULL) {
        printf("Cannot open input file.\n");
        exit(1); 
    }

    while (fgets(booklist[rec_read].title,MAX_STRING_LEN, fptr) != NULL) {
    len = strlen(booklist[rec_read].title);

    if (booklist[rec_read].title[len-1] == '\n')
        booklist[rec_read].title[len-1] = '\0';

    fgets(booklist[rec_read].author, MAX_STRING_LEN, fptr); 
    len = strlen(booklist[rec_read].author);

    if (booklist[rec_read].author[len-1] == '\n')
        booklist[rec_read].author[len-1] = '\0';

    fgets(booklist[rec_read].isbn, ISBN_LEN, fptr); len = strlen(booklist[rec_read].isbn);
    if (booklist[rec_read].isbn[len-1] == '\n') 
        booklist[rec_read].isbn[len-1] = '\0';

    fscanf(fptr, "%f", &booklist[rec_read].price); fscanf(fptr, "%d", &booklist[rec_read].qty);
    fscanf(fptr, "%c", &ch); // to skip the newline after qty
    
    rec_read++; 
    }
    
    fclose(fptr);
    printf("this is the number of records read: %d\n", rec_read);
    return rec_read; 
}