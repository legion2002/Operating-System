#include<stdio.h>
#include<stdlib.h>
int main(){
    
   
    int ** row = (int **) malloc(sizeof(int *)*6);
    if(row == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    int size[6];
    for(int i = 0; i < 6; i++){
        int col;
        printf("Enter the number of columns in row %d \n", i+1);
        scanf("%d", &col);
        row[i] = (int * ) malloc(sizeof(int)*col);
        if(row[i] == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
        size[i] = col;

    }

    for(int i = 0; i < 6; i++){
        // printf("%d", sizeof(row[i])/sizeof(int));
        for(int j = 0; j < size[i]; j++ ){
            row[i][j] = rand()%10 + 1;
            printf("%d ", row[i][j]);
        }
        printf("\n");
    }

    return 0;
}