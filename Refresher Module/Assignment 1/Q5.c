#include<stdio.h>
 int binary(unsigned int num[],unsigned int length, unsigned int x){
    unsigned long long int left = 0;
    unsigned long long int right = length-1;
    while(left <= right){
        unsigned long long int mid;
        if(right % 2 == 1 && left % 2 == 1){
            mid = right/2 + left/2 + 1;
        }
        else{
         mid = right/2 + left/2;
        }
        if(num[mid] == x){
            return mid;
        }
        else if(num[mid] > x){
            right = mid -1;
        }
        else{
            left = mid+1;
        }

    }
    return -1;
}
void bubble(unsigned int num[], unsigned int length){
    for(unsigned int i = 0; i < length; i++ ){
        for(unsigned int j = 0; j < length - 1; j++){
            if(num[j] > num[j + 1]){
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;                
            }
        }
    }
}
int main(){
    printf("Enter the number of elements in the array");
    unsigned int size;
    scanf("%u", &size);
    unsigned int numbers[size];
    for(unsigned int i = 0; i < size; i++){
        printf("Enter Number \n");
        scanf("%u",&numbers[i]);
    }
    printf("Enter the number you want to search: \n");
    unsigned int x;
    scanf("%u", &x);
    bubble(numbers, size);
    
    unsigned int ans = binary(numbers,size, x);
    
    if(ans == -1){
        printf("Element Not Found");
    }
    else{
        printf("Found the element at index %u ", ans);
    }



}