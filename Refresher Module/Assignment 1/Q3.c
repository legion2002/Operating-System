#include <stdio.h>

int main(){
   
    int num1;
    int num2;
    
   
    char query;
    printf("Enter v to swap integer variables, Enter a to swap integer arrays: \n");
    scanf("%c", &query);
    if( query == 'a'){
        
        int size1;
        
        printf("Enter the number of elements in the arrays: \n");
        scanf("%d", &size1);
        int arr1[size1];
        for( int i = 0; i < size1; i++){
            printf("Enter number in array 1\n");
            scanf("%d", &arr1[i]);
        }
        printf("\nNow enter the numbers in array 2 \n");
        int arr2[size1];
        for( int i = 0; i < size1; i++){
            printf("Enter number in array 2 \n");
            scanf("%d", &arr2[i]);
        }
        printf("\n Array 1 was - ");
        for(int i = 0; i < size1; i++){          
            printf("%d ", arr1[i]);
        }
        printf("\n Array 2 was - ");
        for(int i = 0; i < size1; i++){            
            printf("%d ", arr2[i]);
        }
        for(int i = 0; i < size1; i++){
            int temp = arr1[i];
            arr1[i] = arr2[i];
            arr2[i] = temp;

        }
        printf("\n Array 1 is now - ");
        for(int i = 0; i < size1; i++){          
            printf("%d ", arr1[i]);
        }
        printf("\n Array 2 is now - ");
        for(int i = 0; i < size1; i++){            
            printf("%d ", arr2[i]);
        }

    }
    else if(query == 'v'){
        printf("Enter num1 \n");
        scanf("%d", &num1);
        printf("Enter num2 \n");
        scanf("%d", &num2);
        int temp = num2;
        num2 = num1;
        num1 = temp;
        printf("After Swap Num 1: %d and Num 2: %d \n", num1, num2);
    
    }
}
