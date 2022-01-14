#include<stdio.h>
#include<inttypes.h>


extern void B(int64_t a);


int A(){
    // Enter the test number in variable a - 
    int64_t a = 4629771061636907072  ;
    //4629771061636907072
    //478560413000
    
    printf("\nYou are now in A function\n" ); 
    B(a);    
}

int main(){
    
  
    A();
}