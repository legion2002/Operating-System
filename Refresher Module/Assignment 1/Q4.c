#include <stdio.h>

int main(){
   
    char text[1000];
    int count = 0;
    printf("Enter the string you want to reverse (<1000) \n");
    fgets(text, 1000, stdin);
    
    while(text[count] != '\0'){
        count++;
    }
      
    for(int i = 0; i < count/2; i++){
        char c = text[i];
        text[i] = text[count-1-i];
        text[count-1-i] = c;
    }
    printf("\nThe reversed string is \n");
    printf("%s", text); 
    return 0;
}
