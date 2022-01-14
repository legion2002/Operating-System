#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<fcntl.h>

void parentProcess(){
        char* records[100];
        char buffer[10000];
        int fileR = open("student_record.csv", O_RDONLY, 0);
        
        while(read(fileR, buffer,10000));
        
        char* rowRead = strtok(buffer, "\n");
        float AssignmentSums[7];
        int row = 0;
        int rowsA = 0;
    
        
        while(rowRead){  
            records[row] = rowRead;
            row++;
            rowRead = strtok(NULL, "\n");

        }
        for( int i = 1; i < row; i++){ 
            
            char *columns = strtok(records[i], ",");
            int columnNum = 0;
            int sectionFlag = 0; 
            
            while(columns){
                columnNum++;
                if(columnNum == 1){

                }
                else if(columnNum == 2){
                    if(strcmp(columns, "B") == 0){
                        // printf("%s", columns);
                        sectionFlag = 1;
                        rowsA++;

                    }
                }
                else{
                    if(sectionFlag == 1){

                        AssignmentSums[columnNum - 2] += atoi(columns);
                    }

                }

                columns = strtok(NULL, ",");
            }
            


        }
        for( int i = 1; i <= 6; i++){
            printf("\n Assignment %d average for section B is: %.6f \n", i, AssignmentSums[i]/rowsA);
        }
        
}

void childProcess(){
int fileR = open("student_record.csv", O_RDONLY, 0);
        char buffer[10000];
        read(fileR, buffer,10000);
        char* records[100];
        char* rows = strtok(buffer, "\n");
        float AssignmentSums[7];
        int row = 0;
        int rowsA = 0;
    
        
        while(rows){  
            records[row] = rows;
            row++;
            rows = strtok(NULL, "\n");

        }
        for( int i = 1; i < row; i++){ 
            
            char *columns = strtok(records[i], ",");
            int columnNum = 0;
            int sectionFlag = 0; 
            
            while(columns){
                columnNum++;
                if(columnNum == 1){

                }
                else if(columnNum == 2){
                    if(strcmp(columns, "A") == 0){
                        // printf("%s", columns);
                        sectionFlag = 1;
                        rowsA++;

                    }
                }
                else{
                    if(sectionFlag == 1){

                        AssignmentSums[columnNum - 2] += atoi(columns);
                    }

                }

                columns = strtok(NULL, ",");
            }
            


        }
        for( int i = 1; i <= 6; i++){
            // printf("Number of rows: %d", rowsA);
            printf("\n Assignment %d average for section A is: %.6f \n", i, AssignmentSums[i]/rowsA);
        }
        exit(EXIT_SUCCESS);

        
        

        

}

int main(){
    pid_t process = fork();
    if(process > 0){
        //Parent Process
        
        parentProcess();
        int status;
        waitpid(process, &status, 0);
        
        
    }
    else{
        //Child Process
        childProcess();
        
        
    }
    

}