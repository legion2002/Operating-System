#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>



#define NUM 5

int forks[NUM] = {0, 1, 2, 3, 4};
int diners[NUM] = {0, 1, 2, 3, 4};

sem_t Forks[NUM];
pthread_t threads[NUM];


void * philosopherFunction(void* num){

    while(1){
        int* referencePhilo = num;
        int philosopherNum = *referencePhilo;

        printf("Philosopher %d is thinking\n", philosopherNum);
        if(philosopherNum == 1){
            sem_wait(&(Forks[ philosopherNum]));
            sem_wait(&(Forks[ (philosopherNum + 1)%NUM]));
        }
        else{
            sem_wait(&(Forks[ (philosopherNum + 1)%NUM]));
            sem_wait(&(Forks[ philosopherNum]));
        }
       
        printf("Philosopher %d is EATING and has forks %d, %d \n", philosopherNum, philosopherNum, (philosopherNum + 1)%NUM);
        sleep(1);
        if(philosopherNum == 1){
            sem_post(&(Forks[ philosopherNum]));
            sem_post(&(Forks[ (philosopherNum + 1)%NUM]));
        }
        else{
            sem_post(&(Forks[ (philosopherNum + 1)%NUM]));
            sem_post(&(Forks[ philosopherNum]));
        }
    }
    
}
void initializeSemaphores(){
    for (int i = 0; i < NUM; i++){
            sem_init(&Forks[i], 0, 1);
    }

}

void initializePhilosophers(){
    for (int i = 0; i < NUM; i++) {

		pthread_create(&threads[i], NULL, philosopherFunction, &diners[i]);
	}

}
int main(){
    initializeSemaphores();
    initializePhilosophers();
    for (int i = 0; i < NUM; i++){
		pthread_join(threads[i], NULL);
    }
}