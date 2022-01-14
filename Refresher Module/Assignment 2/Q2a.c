#include <stdio.h>
#include <stdlib.h>

//Singly Linked List
struct Student{
    char name[20];
    int roll;
    int year;
    struct Student * next;
};
struct Student *root;
struct Student *end;
int ListSize = 0;
void print();
void insert();
void search(int);
void delete(int);
void menu(){
    while(1){
        int query;
        printf("\nPress 1 to insert, 2 to delete, 3 to search, 4 to print, 5 to exit \n");
        scanf("%d", &query);
        if( query == 1){
            insert();
            
        }
        else if(query == 2){
            int DelVal;
            printf("\nEnter the integer value of the roll number to be deleted: ");
            scanf("%d", &DelVal);
            delete(DelVal);
        }
        else if(query == 3){
            int SearchVal;
            printf("\nEnter the integer value of the roll number to be searched: ");
            scanf("%d", &SearchVal);
            search(SearchVal);
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
void insert(){
    struct Student * s1 = (struct Student *) malloc(sizeof(struct Student));
    
    printf("Enter Student Name: \n");
    scanf("%s", s1->name);
    printf("Enter Student Roll Number: \n");
    scanf("%d", &(s1->roll));
    printf("Enter Year of Enrollment: \n");
    scanf("%d", &(s1->year));
    if(ListSize == 0){
        root = s1;
        end = s1;
        ListSize++;

    }
    else{
        end->next = s1;
        end = s1;
        ListSize++;
    }



    

}
void search(int r){
    struct Student *temp = root;
    int flag = 0; 
    if(r == end->roll){
        printf("List Node: %s %d %d \n", end->name, end->roll, end->year);
        flag = 1;
    }
    while(temp != end){
        if(temp->roll == r){
            printf("List Node: %s %d %d \n", temp->name, temp->roll, temp->year);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 0){
        printf("NOT FOUND \n");
    }
}
void delete(int r){
    struct Student *temp = root;
    struct Student *del;
    int flag = 0; 
    if(r == root->roll){
        printf("Deleted List Node: %s %d %d \n", root->name, root->roll, root->year);
        del = root;
        root = root->next;
        free(del);
        ListSize--;
        flag = 1;
        
    }
    
    while(temp != end && flag == 0){
        if(temp->next->roll == r){
            if(temp->next == end){
                end = temp;
            }
            printf("Deleted List Node: %s %d %d \n", temp->next->name, temp->next->roll, temp->next->year);
            del = temp->next;
            temp->next = temp->next->next;
            free(del);
            flag = 1;
            ListSize--;
            break;
        }
        temp = temp->next;
    }
    if(flag == 0){
        printf("NOT FOUND \n");
    }
}
void print(){
    
    struct Student *temp = root; 

    while(temp != end){
        printf("List Node: %s %d %d \n", temp->name, temp->roll, temp->year);

        temp = temp->next;
    }
   
    printf("List Node: %s %d %d \n", temp->name, temp->roll, temp->year);
}