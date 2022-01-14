#include<stdio.h>
#include<stdlib.h>
// #include <unistd.h>
int main(int argc, char *argv[]){
    

    int ** row = (int **) malloc(sizeof(int *)*6);
    if(row == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    int size[] = {7,4,6,3,7,2};
    row[0] = (int * ) malloc(sizeof(int)*7);
    if(row[0] == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    row[1] = (int * ) malloc(sizeof(int)*4);
    if(row[1] == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    
    row[2] = (int * ) malloc(sizeof(int)*6);
    if(row[2] == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    row[3] = (int * ) malloc(sizeof(int)*3);
    if(row[3] == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    row[4] = (int * ) malloc(sizeof(int)*7);
    if(row[4] == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    row[5] = (int * ) malloc(sizeof(int)*2);
    if(row[5] == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    printf("Matrix for a part of the question is: \n");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < size[i]; j++ ){
            row[i][j] = rand()%9 + 1;
            printf("%d ", row[i][j]);
        }
        printf("\n");
    }
    printf("Rearranged Matrix for b part of the question is: \n");
    for( int i = 0; i < 6; i++){
        int temp = atoi(argv[i]);
       
        row[i] = (int *) realloc(row[i],sizeof(int)*temp );
        size[i] = temp;
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < size[i]; j++ ){
            row[i][j] = rand()%9 + 1;
            printf("%d ", row[i][j]);
        }
        printf("\n");
    }


    return 0;
}