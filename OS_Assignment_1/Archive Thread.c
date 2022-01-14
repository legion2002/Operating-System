#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<fcntl.h>
#include<pthread.h>

  pthread_t tid1;
    pthread_t tid2;
void* parentProcess(){
    pthread_join(tid1, NULL);

        
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
            // printf("Number of rows: %d", rowsA);
            printf("\n Assignment %d average for section B is: %.6f \n", i, AssignmentSums[i]/rowsA);
        }
        
}

void * childProcess(){
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
        

        

}

int main(){
  

    pthread_create(&tid1, NULL, childProcess, NULL);
    parentProcess();


    
    

}