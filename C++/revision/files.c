#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    int n,x; 
    fp=fopen("harsh.txt","w+");
    printf("enter number of digit");
    scanf("%d",&n);
     printf("\nenter");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        putw(x,fp);
    }
    fclose(fp);
    fp=fopen("harsh.txt","r+");
    while((n=getw(fp))!=EOF){
        printf("%d",n);
    }

    fclose(fp);
}

/*
 FILE *fp;
    char ch[100];
    fp=fopen("harsh.txt","w+");
    fputs("my name is harsh",fp);
    fclose(fp);
    fp=fopen("harsh.txt","r");
    fgets(ch,100,fp);
    printf("%s",ch);
    fclose(fp);
*/