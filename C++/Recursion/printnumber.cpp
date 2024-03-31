#include<bits/stdc++.h>
using namespace std;
void f(int n,string s[],bool flag){
   
   if(n==0) return ;
   
   f(n/10,s,!flag);

    if(flag){
        cout<<n%10;
        // flag=!flag;
    }else{
        cout<<s[n%10];
        // flag=!flag;
    }
   

}

int main(){
    int n;
    cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>i[arr];
    // }
    string s[]={"zero","one","two","three","four","five","six","Seven","eight","nine"};
    f(n,s,1);
}