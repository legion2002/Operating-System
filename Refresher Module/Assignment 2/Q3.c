#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add(int a, int b){
    
    printf("\n Answer =  %d \n", a+b);
}
 void sub(int a, int b){
    printf("\n Answer =  %d \n", a-b);
}
void mul(int a, int b){
    printf("\n Answer =  %d \n", a*b);
}
void divi(int a, int b){
    printf("\n Answer =  %lf \n",(double) a/b);
}
void expo(int a, int b){
    int answer = 1;
    for( int i = 0; i < b; i++){
        answer = answer*a;
    }
    printf("\n Answer =  %d \n", answer);
}


int main(int argc, char * argv[]){
    void (*arr[5])(int, int);
    arr[0] = &add;
    arr[1] = &sub;
    arr[2] = &mul;
    arr[3] = &divi;
    arr[4] = &expo;
    int o1 = atoi(argv[2]);
    int o2 = atoi(argv[3]);

    if(strcmp(argv[1],"add") == 0){
        
        (*arr[0])(o1,o2);
    }
    else if(strcmp(argv[1],"sub") == 0){
        (*arr[1])(o1,o2);
    }
    else if(strcmp(argv[1],"mul") == 0){
        (*arr[2])(o1,o2);
    }
    else if(strcmp(argv[1],"divi") == 0){
        (*arr[3])(o1,o2);
    }
    else if(strcmp(argv[1],"expo") == 0){
        (*arr[4])(o1,o2);
    }


    return 0;
}
