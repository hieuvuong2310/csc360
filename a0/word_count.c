#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_LINE 100
#define MAX_LINE_LEN 110
#define MAX_WORD 500
#define MAX_WORD_LEN 120
int main(int argc, char *argv[]) {
    char buffer[MAX_LINE][MAX_LINE_LEN];
    char f1[MAX_WORD][MAX_WORD];
    int num_lines=0;
    if(argc<2){
        fprintf(stderr, "You should provide a filename\n");
        exit(1);
    }
    FILE *data_fp = fopen(argv[1], "r");
    for(int i= 0; i<MAX_LINE; i++){
            while(fgets(buffer[i], MAX_LINE_LEN, data_fp)){
                buffer[i][strlen(buffer[i])-1]= '\0';
                strncpy(f1[num_lines], buffer[i], MAX_WORD_LEN); 
                num_lines++;
            }
    }
    int count = 0;
    for(int i = 0; i<num_lines; i++) {
        char* elements = strtok(f1[i], " ");
        while (elements != NULL){
            // printf("%s\n", elements);
            elements = strtok(NULL, " ");
            count++;
        }
    }
    printf("%d %s", count, argv[1]);
    fclose(data_fp);
    return 0;
}