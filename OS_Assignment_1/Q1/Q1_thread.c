#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<fcntl.h>
#include<pthread.h>
#include<errno.h>

  pthread_t tid1;
  pthread_t tid2;
  char* records[100];
    
    float AssignmentSumsB[7];
    float AssignmentSumsA[7];

    int row = 0;
    int rowsB = 0;
    int rowsA = 0;


struct Student{
    int roll;
    int section;
    float a1;
    float a2;
    float a3;
    float a4;
    float a5;
    float a6;
};

struct Student list[1000];

void* finalAverages(){
    if(rowsB + rowsA == 0){
        printf("\n There are no students in the file\n");
    }
    else{
    for( int i = 1; i <= 6; i++){
            // printf("Number of rows: %d", rowsA);
            printf("\n Combined Assignment %d average is: %.6f \n", i, (AssignmentSumsB[i] + AssignmentSumsA[i])/(rowsB+rowsA));
    }
    }
}
void* parentProcess(){
    
    for(int i = 1; i < row; i++){
        if(list[i].section == 1){
            AssignmentSumsB[1] += list[i].a1;
            AssignmentSumsB[2] += list[i].a2;
            AssignmentSumsB[3] += list[i].a3;
            AssignmentSumsB[4] += list[i].a4;
            AssignmentSumsB[5] += list[i].a5;
            AssignmentSumsB[6] += list[i].a6;
            rowsB++;

        }
    }
    if(rowsB == 0){
        printf("\n There are no students in section B \n");
    }
    else{
    for( int i = 1; i <= 6; i++){
            // printf("Number of rows: %d", rowsA);
            printf("\n Assignment %d average for section B is: %.6f \n", i, AssignmentSumsB[i]/rowsB);
    }
    }
    int join_check = pthread_join(tid1, NULL);
    if(join_check != 0){
         printf("An error occurred, Error Number: %d\n", errno);
            perror("Error in joining threads \n ");
            exit(errno);
    }
    
    
    
        
}

void * childProcess(){
        
        for(int i = 1; i < row; i++){
        if(list[i].section == 0){
            AssignmentSumsA[1] += list[i].a1;
            AssignmentSumsA[2] += list[i].a2;
            AssignmentSumsA[3] += list[i].a3;
            AssignmentSumsA[4] += list[i].a4;
            AssignmentSumsA[5] += list[i].a5;
            AssignmentSumsA[6] += list[i].a6;
            rowsA++;

        }
    }
    if(rowsA == 0){
        printf("\nThere are no students in section A \n");
    }
    else{
        for( int i = 1; i <= 6; i++){
            // printf("Number of rows: %d \n", );
            printf("\n Assignment %d average for section A is: %.6f \n", i, AssignmentSumsA[i]/rowsA);
        }
    }
    
    pthread_exit(NULL);
        

}

int main(){
    int fileR = open("student_record.csv", O_RDONLY);
    if(fileR < 0){
            printf("An error occurred, Error Number: %d\n", errno);
            perror("Error in Opening File \n");
            exit(errno);
    }
    char buffer[10000];
    int read_check = read(fileR, buffer,10000);
    if(read_check < 0){
            printf("An error occurred, Error Number: %d\n", errno);
            perror(" Error in reading file\n");
            exit(errno);
        }

    char* rows = strtok(buffer, "\n");

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
                if(columns == NULL){
                    continue;
                }
                columnNum++;
                if(columnNum == 1){
                    list[i].roll = atoi(columns);
                }
                else if(columnNum == 2){
                    if(strcmp(columns, "A") == 0){
                        list[i].section = 0;
                    }
                    else if(strcmp(columns, "B") == 0){
                        list[i].section = 1;
                    }
                }
                else if(columnNum == 3){
                    list[i].a1 = atoi(columns);
                   
                }
                else if(columnNum == 4){
                    list[i].a2 = atoi(columns);
                    
                   
                }
                else if(columnNum == 5){
                    list[i].a3 = atoi(columns);
                   
                }
                else if(columnNum == 6){
                    list[i].a4 = atoi(columns);
                    
                   
                }
                else if(columnNum == 7){
                    list[i].a5 = atoi(columns);
                    
                   
                }
                else if(columnNum == 8){
                    list[i].a6 = atoi(columns);
                    
                   
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
    int thread_check = pthread_create(&tid1, NULL, childProcess, NULL);
    if(thread_check != 0){
        printf("An error occurred, Error Number: %d\n", errno);
        perror("Error in Creating Thread \n");
        exit(errno);
    }
    parentProcess();
    finalAverages();
    
    
    
    

    



    
    

}