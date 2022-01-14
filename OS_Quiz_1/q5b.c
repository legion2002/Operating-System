#include<stdio.h>

int main(void)
{
    int a=2, *b = NULL;
    b=&a;
    printf("%lu\n", sizeof(void));
    // printf("%p\n", &a);
    printf("%p",b+1);
    printf("%p",(char *)b+1);
    printf("%p",(void *)b+1);
}