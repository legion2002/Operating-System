#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <string.h>
// #include <sys/wait.h>
#include <stdlib.h>
#include<fcntl.h>

int main(){
    int fileR = open("student_record.csv", O_RDONLY, 0);
    char buffer[10000];
    read(fileR, buffer,10000);
    char* records[100];
    char* rows = strtok(buffer, "\n");
    int row = 0;
   
    
    while(rows){  
        records[row] = rows;
        row++;
        rows = strtok(NULL, "\n");

    }
    for( int i = 0; i < rows; i++){ 
        char *columns = strtok(rows[i], ",");


    }

}