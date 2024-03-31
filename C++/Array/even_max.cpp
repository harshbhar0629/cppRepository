#include<iostream>
#include<climits>
using namespace std;
int main(){
    // int n;
    // cin>>n;
    int n=7;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int st=0,end=n-1,m=INT_MIN;
    for(int i=0;i<n;i++){
        m=max(arr[i],m);
    }
    m++;
    bool flag=true;
    for(int i=0;i<n;i++){
        if(flag){
            int val=arr[end--]%m;
            arr[i]+=m*val;
        }
        else{
            int val=arr[st++]%m;
            arr[i]+=m*val;
        }
        flag=!flag;
    }
    for(int i=0;i<n;i++) cout<<"  "<<arr[i]/m;
    
    return 0;
}