
#include<stdio.h>
#include<stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


struct Node {
        struct Node * left;
        struct Node * right;
        int val;
        int height; //Make this one somehow
    


    };
struct Node * rightRotate(struct Node * pivot);
struct Node * leftRotate(struct Node * pivot);

struct Node * root;

int height(struct Node * n) {
            if (n == NULL) {
                return 0;
            }
            return n->height;
        }

int balance(struct Node * n) {
            if (n == NULL) {
                return 0;
            }
            return height(n->left) - height(n->right);
        }

struct Node * insert(int n, struct Node * curr) {
        
            if (curr == NULL) {
                // Node newNode = new Node(n);
                struct Node * newNode = (struct  Node *) malloc(sizeof(struct Node));
                newNode->val = n;
                newNode->height = 1;
                newNode->left = NULL;
                newNode->right = NULL;
                
                return newNode;
            } else if (n > curr->val) {
                // printf("entered");
                curr->right = insert(n, curr->right);
            } else if (n < curr->val) {
                curr->left = insert(n, curr->left);
            } else {
                return curr;
            }

            curr->height = 1 + MAX(height(curr->left), height(curr->right));
            if (abs(balance(curr)) > 1) {
                int bal = balance(curr);
                if (bal > 1 && n > curr->left->val) {
                    curr->left = leftRotate(curr->left);
                    return rightRotate(curr);
                }
                if (bal < -1 && n < curr->right->val) {
                    curr->right = rightRotate(curr->right);
                    return leftRotate(curr);
                }
                if (bal < -1 && n > curr->right->val) {

                    return leftRotate(curr);
                }
                if (bal > 1 && n < curr->left->val) {

                    return rightRotate(curr);
                }


            }
            return curr;


        }

struct Node * leftRotate(struct Node * pivot) {
//            System.out.println(pivot->val);
            if (pivot == NULL) {
                return NULL;
            }
            struct Node * temp = pivot->right;
            pivot->right = temp->left;
            temp->left = pivot;
            pivot->height = MAX(height(pivot->left), height(pivot->right)) + 1;
            temp->height = MAX(height(temp->left), height(temp->right)) + 1;

            return temp;


        }

struct Node * rightRotate(struct Node * pivot) {
            
            if (pivot == NULL) {
                return NULL;
            }
            struct Node * temp = pivot->left;
            pivot->left = temp->right;
            temp->right = pivot;
            pivot->height = MAX(height(pivot->left), height(pivot->right)) + 1;
            temp->height = MAX(height(temp->left), height(temp->right)) + 1;
            return temp;

        }
struct Node * succ(struct Node * found) {
            struct Node * temp2 = found;
            while (temp2->left != NULL) {
                temp2 = temp2->left;
            }
            return temp2;
        }

struct Node * pred(struct Node * found) {
            struct Node * temp2 = found;
            while (temp2->right != NULL) {
                temp2 = temp2->right;
            }
            return temp2;
        }

struct Node * delete(int n, struct Node * curr) {
            // printf("delete");
            if (curr == NULL) {
                return NULL;
            }
            if (n > curr->val) {
                curr->right = delete(n, curr->right);
            } else if (n < curr->val) {
                curr->left = delete(n, curr->left);
            } else {

                if (curr->left == NULL) {
                    curr = curr->right;
                } else if (curr->right == NULL) {
                    curr = curr->left;
                } else {
//                    System.out.println(curr->right.val);
//                    Node del = succ(curr->right);
                    curr->val = succ(curr->right)->val;
                    curr->right = delete(curr->val, curr->right);
                }

            }
            if (curr == NULL) {
                return NULL;
            }


            curr->height = MAX(height(curr->left), height(curr->right)) + 1;
            if (abs(balance(curr)) > 1) {
                int bal = balance(curr);
                if (bal > 1 && balance(curr->left) < 0) {
                    curr->left = leftRotate(curr->left);
                    return rightRotate(curr);
                }
                if (bal < -1 && balance(curr->right) > 0) {
                    curr->right = rightRotate(curr->right);
                    return leftRotate(curr);
                }
                if (bal < -1 && balance(curr->right) <= 0) {

                    return leftRotate(curr);
                }
                if (bal > 1 && balance(curr->left) >= 0) {

                    return rightRotate(curr);
                }


            }
            return curr;
        }



void insertNew(struct Node * newNode) {
            if (root == NULL) {
                root = newNode;
            } else {
                struct Node * temp = root;
                while (temp != NULL) {
                    if (newNode->val >= temp->val) {
                        if (temp->right == NULL) {
                            temp->right = newNode;
                            break;
                        } else {
                            temp = temp->right;
                        }
                    } else {
                        if (temp->left == NULL) {
                            temp->left = newNode;
                            break;
                        } else {
                            temp = temp->left;
                        }
                    }
                }
            }
        }




void preorder(struct Node * root){
        
        if(root != NULL){
            printf("%d ",root->val);
            preorder(root->left);
            preorder(root->right);
        }
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
            root = insert(QueryVal, root);
        }
        else if(query == 2){
            int DelVal;
            printf("\nEnter the integer value of the node to be deleted: ");
            scanf("%d", &DelVal);
            root = delete(DelVal, root);
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
    //comment
    menu();    
    return 0;
}