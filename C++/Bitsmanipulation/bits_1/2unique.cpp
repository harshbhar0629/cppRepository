#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,4,3,2,6,6};
    int n=10;
    int sum=0;
    for(int i=0;i<n;i++){
        sum = sum^arr[i];
    }
    int current=0,pos=0;
    int unique1=sum;
    cout<<"sum"<<sum<<endl<<"unique1 zor"<<unique1<<endl;
    while(sum){
        if(sum & 1 >0){
            break;
        }
        else current++;
        sum=sum>>1;
    }
    pos= current;
    cout<<"pos"<<pos<<endl;
    // pos++;
    current=0;
    for(int i=0;i<n;i++){
        if(((1<<pos) & arr[i]) >0 ){
            current= current ^ arr[i];
        }
    }
    cout<<"current"<<current<<endl;
    unique1= unique1 ^ current;
    cout<<current <<endl<<unique1;
    return 0;
}