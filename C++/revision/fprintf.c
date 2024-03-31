#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    int roll;
    char ch[20]; 
    printf("enter  roll and name");
    fp=fopen("harsh.txt","w+");
    // scanf("%s",&ch);
        scanf("%d",&roll);
    //  fscanf(fp,"%d%s",&roll,&ch);
    fclose(fp);
     fp=fopen("harsh.txt","r+");
    //  fprintf(fp,"%s",ch);
    fprintf(fp,"%d",roll);

    fclose(fp);
}
