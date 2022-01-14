#include<stdio.h>
#include<stdlib.h>

char finalAns[32];
char * curr[];
int currMod;
int ConvertedSize;
int finalPos = 31;
char converted[100];
char * convert( char number[] ){
    int i;
    int x;
    int divisor;
    int holder = 0;
    ConvertedSize = 0;
    
    
    
    while(number[i] != '\0'){
        x = number[i] - '0';
    
        divisor = 10*holder + x;
        
        char temp = divisor/256;
        converted[ConvertedSize] = temp;
        holder = divisor % 256;
        ConvertedSize++;
        i++;
    }
    currMod =  holder;
    return converted;
        

}
int main( int argc, char * argv[] ){
    for(int i = 1; i <= argc; i++){
        converted[i-1] = argv[i];               
    }
    
    convert(converted);
    while(1){
        finalAns[finalPos] = currMod;
        finalPos--;
        if(ConvertedSize <= 3){
            int number = converted[0] + 10* converted[1] + 100 * converted[2];
            if(number < 256 ){
                finalAns[finalPos] = currMod;
                finalPos--;
                break;
            }
        }
        convert(converted);
    }
    while(finalPos >= 0){
        finalAns[finalPos] = 0;
        finalPos--;
    }


    return 0;
}