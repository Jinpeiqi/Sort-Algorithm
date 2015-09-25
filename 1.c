#include <stdio.h>
int b;
void function1(int *a) { a=&b; }
void function2(int *&a) { a=&b; }
void function3(int **a) { *a=&b; }
main(){
int *a; int x=10; a=&x;
printf("a=%d \n",*a);
b=20; function1(a);
printf("a=%d \n",*a);
b=30; function2(a);
printf("a=%d \n",*a);
b=40; function3(&a);
printf("a=%d \n",*a);
}