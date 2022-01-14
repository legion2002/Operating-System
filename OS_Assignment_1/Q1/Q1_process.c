#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<fcntl.h>
#include<errno.h>

void parentProcess(){
        char* records[100];
        char buffer[10000];
        int fileR = open("student_record.csv", O_RDONLY);
        if(fileR < 0){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Parent Process: Error in Opening File \n");
            exit(errno);
        }

        int read_check = read(fileR, buffer,10000);
        if(read_check < 0){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Parent Process: Error in reading file \n");
            exit(errno);
        }
        
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
        int closeID = close(fileR);
        if(closeID == -1){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Parent Process: Problem in closing file \n");
            exit(errno);
        }
        if(rowsA == 0){
        printf("\nThere are no students in section A \n");
    }
    else{
        for( int i = 1; i <= 6; i++){
            // printf("Number of rows: %d \n", );
            printf("\n Assignment %d average for section B is: %.6f \n", i, AssignmentSums[i]/rowsA);
        }
    }
        
}

void childProcess(){
        int fileR = open("student_record.csv", O_RDONLY);
        if(fileR < 0){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Child Process: Error in Opening File\n");
            exit(errno);
        }

        char buffer[10000];
        int read_check = read(fileR, buffer,10000);
        if(read_check < 0){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Child Process: Error in reading file\n");
            exit(errno);
        }

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
        int closeID = close(fileR);
        if(closeID == -1){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Parent Process: Problem in closing file \n");
            exit(errno);
        }
        if(rowsA == 0){
        printf("\nThere are no students in section A \n");
        }
    else{
        for( int i = 1; i <= 6; i++){
            // printf("Number of rows: %d \n", );
            printf("\n Assignment %d average for section A is: %.6f \n", i, AssignmentSums[i]/rowsA);
        }
    }
        exit(EXIT_SUCCESS);

        
        

        

}

int main(){
    pid_t process = fork();
    if(process < 0){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Child Process could not be created");
            exit(errno);
        }
    if(process > 0){
        //Parent Process
        
        parentProcess();
        int status;
        int wait_check = waitpid(process, &status, 0);
        if(wait_check < 0){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Error in waitpid \n");
            exit(errno);
        }
        
        
    }
    else{
        //Child Process
        childProcess();
        
        
    }
    

}