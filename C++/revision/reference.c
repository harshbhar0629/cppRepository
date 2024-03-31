#include<stdio.h>
void f(int *a){
    (*a)++;
}
int main(){
    int a=5;
    printf("%d",a);
    f(&a);
    printf("%d",a);

}