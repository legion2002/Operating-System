#include<stdio.h>
#include<math.h>
#include<stdlib.h>




int main(){
    int *x;
    x = malloc(40*sizeof(int));
    x[40] = 5;
    printf("%d\n", x[40]);
}