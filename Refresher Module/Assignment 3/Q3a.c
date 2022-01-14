#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node * left;
    struct Node * right;
};
struct Node * root = NULL;
int count = 0;

void insertion(int a){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = a;
    
    
    struct Node * temp = root;
    if(count == 0){
        root = newNode;
        
    }
    else{
        while(1){
            if(a < temp->val){
                if(temp->left == NULL){
                    temp->left = newNode;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
    count++;
}
struct Node * succ(struct Node * curr){
    curr = curr->right;
    while(1){
        if(curr->left == NULL){
            return curr;
        }
        else{
            curr = curr->left;
        }
    }
}
struct Node * delete(struct Node * curr, int a){
    if(curr == NULL){
        printf("Not Found");
        return curr;
    }
    
    if( a < curr->val){
        curr->left = delete(curr->left, a);
    }
    else if ( a > curr->val){
        curr->right = delete(curr->right, a);

    }
    else{
        //at this point we have found the node
        if(curr->right == NULL){
            struct Node * temp = curr->left;
            free(curr);
            count--;
            return temp;
        }
        if(curr->left == NULL){
            struct Node * temp = curr->right;
            free(curr);
            count--;
            return temp;
        }
        //it has 2 children
        struct Node * successor = succ(curr);
        curr->val = successor->val;
        
        curr->right = delete(curr->right, successor->val);
    }
    return curr;
    
}
void preorder(struct Node * root){
        
        if(root != NULL){
            printf("%d ",root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
void deletion(int a){
    root = delete(root, a);
}
void menu(){
    while(1){
        int query;
        printf("\nPress 1 to insert, 2 to delete, 3 to print preorder traversal of tree, 4 to exit \n");
        scanf("%d", &query);
        if( query == 1){
            int QueryVal;
            printf("\nEnter the integer value of the node to be inserted : ");
            scanf("%d", &QueryVal);
            insertion(QueryVal);
        }
        else if(query == 2){
            int DelVal;
            printf("\nEnter the integer value of the node to be deleted: ");
            scanf("%d", &DelVal);
            deletion(DelVal);
        }
        else if( query == 3){
            preorder(root);
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
