#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char **argv){
    char a[] = "hello world";
    char b[] = "hello, world";
    if(strcmp(a, b) == 0)
        printf("equal");
    else
        printf("not equal");

    return 0;
}