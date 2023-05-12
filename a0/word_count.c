#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int num_lines=0;

    // Check whether file is input.
    if(argc<2){
        fprintf(stderr, "You should provide a filename\n");
        exit(1);
    }
    int count = 0;
    char ch;

    // Open the file to count the number of lines
    FILE *data_fp = fopen(argv[1], "r");
    if (NULL == data_fp) {
        printf("file can't be opened \n");
    }
 
    // Count the number of lines in the file
    do {
        ch = fgetc(data_fp);
        if (ch == '\n') {
            num_lines++;
        }
    } while (ch != EOF);
    fclose(data_fp);

    // Open the file again and count the number of words in there
    data_fp = fopen(argv[1], "r");
    char buffer[num_lines];
    while (fscanf(data_fp, "%s", buffer) != EOF) {
        count++;
    }
    printf("%d %s\n", count, argv[1]);

    // Close the file
    fclose(data_fp);
    return 0;
}