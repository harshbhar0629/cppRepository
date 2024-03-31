#include<iostream>
using namespace std;
int power(int n,int m){
    if(m==0) return 1;
    return n*power(n,m-1);
}
void subset(int arr[],int n,int i,int sum,int result[],int k,int a){
    if(i==n){
        result[k]=sum;    
        return;   
    }
    subset(arr,n,i+1,sum+arr[i],result,k+1,a);
    subset(arr,n,i+1,sum,result,k+1,a);

}
int main(){
    int n;
    cout<<"enter size";
    cin>>n;
    int arr[n];
    cout<<"enter element ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k=(power(2,n));
    int result[k];
    subset(arr,n,0,0,result,0,k);
    for(int i=0;i<k;i++){
        cout<<result[i]<<"  ";
    }

    return 0;
}