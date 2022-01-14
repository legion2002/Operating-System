#include<stdio.h>
#include<stdlib.h>

char finalAns[32];
int currMod;
int ConvertedSize;
int ConvertedSize2;
int finalPos = 31;
char converted[100];
char * convert( char number[] ){
    int i;
    int x;
    int divisor;
    int holder = 0;
    ConvertedSize = 0;
    int startFlag = 0;
    
    
    while(number[i] != '\0'){
        x = number[i] - '0';
    
        divisor = 10*holder + x;
        
        char temp = divisor/256;
        int t = divisor/256;
        holder = divisor % 256;
        i++;
        if(t == 0 && startFlag == 0){
          continue;
        }
        startFlag = 1;
        converted[ConvertedSize] = temp;
        
        ConvertedSize++;
        
    }
    converted[ConvertedSize + 1] = '\0';
    currMod =  holder;
    return converted;
        

}
char * convert2( ){
    int i;
    int x;
    int divisor;
    int holder = 0;
    ConvertedSize2 = 0 ;
    int startFlag = 0;
    
    
    for(int i = 0; i <ConvertedSize; i++ ){
        
        x = converted[i];
        
    
        divisor = 10*holder + x;
        
        char temp = divisor/256;
        int t = divisor/256;
        holder = divisor % 256;
        if(t == 0 && startFlag == 0){
          continue;
        }
        startFlag = 1;
        converted[ConvertedSize2] = temp;
        
        ConvertedSize2++;
        
    }
    converted[ConvertedSize2 ] = '\0';
    ConvertedSize = ConvertedSize2;
    currMod =  holder;
    return converted;
        

}
int main( int argc, char * argv[]){
    convert(argv[1]);
    while(1){
        finalAns[finalPos] = currMod;
        finalPos--;
        if(ConvertedSize == 3){
            int number = converted[0] + 10* converted[1] + 100 * converted[2];
            if(number < 256 ){
                char temp = number;
                finalAns[finalPos] = temp;
                finalPos--;
                break;
            }
        }
        if(ConvertedSize == 2){
            int number = converted[0] + 10*converted[1];
            char temp = number;
            finalAns[finalPos] = temp;
            finalPos--;
            break;
        }
        if(ConvertedSize == 1){
            int number = converted[0];
            char temp = number;
            finalAns[finalPos] = temp;
            finalPos--;
            break;
        }
        if(ConvertedSize == 0){
            break;
        }
        convert2();
    }
    while(finalPos >= 0){
        finalAns[finalPos] = 0;
        finalPos--;
    }
    for(int i = 0; i< 32; i++){
        printf("%c ", finalAns[i]);
    }


    return 0;
}