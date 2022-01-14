#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[20];
    int roll;
    int year;
    struct Student * next;
};
struct Student *top;
int StackSize = 0;
void print();
void push();
void peek();
void pop();
void menu(){
    while(1){
        int query;
        printf("Press 1 to push, 2 to pop, 3 to peek, press 4 to print, press 5 to exit");
        scanf("%d", &query);
        if( query == 1){
            push();
        }
        else if(query == 2){
            pop();
        }
        else if( query == 3){
            peek();
        }
        else if(query == 4){
            print();
        }
        else if(query == 5){
            break;
        }
        
    }
}
int main(){
    menu();
   
   return 0; 
}
void push(){
    struct Student * s1 = (struct Student *) malloc(sizeof(struct Student));
    
    printf("Enter Student Name: \n");
    scanf("%s", s1->name);
    printf("Enter Student Roll Number: \n");
    scanf("%d", &(s1->roll));
    printf("Enter Year of Enrollment: \n");
    scanf("%d", &(s1->year));
    s1->next = NULL;
    if(StackSize == 0){
        top = s1;
        top->next = NULL;
        StackSize++;
    }
    else{
        s1->next = top;
        top = s1;
        StackSize++;
    } 

}

void pop(){
    if(StackSize == 0){
        printf("\n Stack is Empty");
        return;
    }
    struct Student *temp = top;
    top = top->next;
    printf("Popped Node: %s %d %d \n", temp->name, temp->roll, temp->year);
    free(temp);
    StackSize--;
    
    
    
}
void print(){
    
    struct Student *temp = top; 

    while(temp != NULL){
        printf("List Node: %s %d %d \n", temp->name, temp->roll, temp->year);

        temp = temp->next;
    }
   
   
}
void peek(){
    if(StackSize == 0){
        printf("\n Stack is Empty");
        return;
    }
    
    printf("Top Node: %s %d %d \n", top->name, top->roll, top->year);
    
}