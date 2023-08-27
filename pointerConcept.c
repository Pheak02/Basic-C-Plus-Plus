#include <stdio.h>
int main(int argc, char **argv){
    int x, *p1, **p2;
    x=100;

    p1 = &x;
    p2 = &p1;

    getch();
    printf("x= %d", **p2);

    printf("hello world\n");
    return 0;

}