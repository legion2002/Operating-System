#include<stdio.h>
#include<stdlib.h>

void bubble(int num[], int length){
    for(int i = 0; i < length;i++ ){
        for( int j = 0; j < length - 1; j++){
            if(num[j] > num[j + 1]){
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;                
            }
        }
    }
}
void print(int num[], int length){
    
    for( int i = 0; i < length ; i++){
        
        printf("%d ", num[i]);
    }
    printf("\n");
}
void selection(int num[], int length){
    for( int i = 0; i < length; i++){
        int minNum = num[i];
        int minIndex = i;
        for ( int j = i+1; j < length; j++){

            if(num[j] < minNum){
                minNum = num[j];
                minIndex = j;

            }
        }
        int temp = num[minIndex];
        num[minIndex] = num[i];
        num[i] = temp;

    }
}
int main(int argc, char *argv[]){
   
    int numbers[argc-1];
    for(int i = 1; i < argc; i++){
        
        numbers[i-1] = atoi(argv[i]);
    } 
    char query;
    
    printf("Enter b for bubble sort and s for selection sort");
    scanf(" %c", &query);
    if(query == 'b'){
        
        bubble(numbers, argc - 1);
        
    }
    else if(query == 's'){
        selection(numbers, argc - 1);
        
    }
    
    print(numbers, argc - 1);
    
    return 0;
    
}