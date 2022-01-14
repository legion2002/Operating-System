#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[20];
    int roll;
    int year;
    struct Student * next;
};
struct Student *front = NULL;
struct Student *back = NULL;
int QueueSize = 0;
void print(){
    
    struct Student *temp = front; 

    while(temp != NULL){
        printf("List Node: %s %d %d \n", temp->name, temp->roll, temp->year);

        temp = temp->next;
    }
   
   
}
void enqueue(){
    
    struct Student * s1 = (struct Student *) malloc(sizeof(struct Student));
    
    printf("Enter Student Name: \n");
    scanf("%s", s1->name);
    printf("Enter Student Roll Number: \n");
    scanf("%d", &(s1->roll));
    printf("Enter Year of Enrollment: \n");
    scanf("%d", &(s1->year));
    s1->next = NULL;
    if(QueueSize == 0){
        front = s1;
        back = s1;
        back->next = NULL;
        QueueSize++;
    }
    else{
        back->next = s1;
        back = s1;
        QueueSize++;
    } 

}

void dequeue(){
     if(QueueSize == 0){
        printf("\n Queue is Empty");
        return;
    }
    struct Student *temp = front;
    front = front->next;
    printf("Dequeued Node: %s %d %d \n", temp->name, temp->roll, temp->year);
    free(temp);
    QueueSize--;
}
void menu(){
    while(1){
        int query;
        printf("\n Press 1 to enqueue, 2 to dequeue, 3 to print,  press 4 to exit");
        scanf("%d", &query);
        if( query == 1){
            enqueue();
        }
        else if(query == 2){
            dequeue();
        }
        else if( query == 3){
            print();
        }
        else if(query == 4){
            break;
        }
        
    }
}
int main(){
    
    menu();
    return 0;
}