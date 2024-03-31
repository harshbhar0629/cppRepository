#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,*ptr;
    printf("enter size:");
    scanf("%d",&n);
    ptr=(int *)calloc(n,4);
    if(ptr==NULL){
        printf("out of memory");
        exit(0);
    }
    int sum=0,mult=1;
    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
        sum+= *(ptr+i);
        mult*=*(ptr+i);
    }
    printf("%d",sum);
    printf("  %d",mult);
     
     
    printf("enter new size:");
    scanf("%d",&n);
    ptr=(int *)realloc(ptr,n);
    if(ptr==NULL){
        printf("out of memory");
        exit(0);
    }
    sum=0,mult=1;
    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
        sum+= *(ptr+i);
        mult*=*(ptr+i);
    }
    printf("\n new-> %d",sum);
    printf("\n new->  %d",mult);

}

/*
 int n,*ptr;
    printf("enter size:");
    scanf("%d",&n);
    ptr=(int *)calloc(n,2);
    if(ptr==NULL){
        printf("out of memory");
        exit(0);
    }
    int sum=0,mult=1;
    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
        sum+= *(ptr+i);
        mult*=*(ptr+i);
    }
    printf("%d",sum);
    printf("  %d",mult);
*/


/*
 int n,*ptr;
    printf("enter size:");
    scanf("%d",&n);
    ptr=(int *)malloc(n);
    if(ptr==NULL){
        printf("out of memory");
        exit(0);
    }
    int sum=0,mult=1;
    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
        sum+= *(ptr+i);
        mult*=*(ptr+i);
    }
    printf("%d",sum);
    printf("  %d",mult);
*/