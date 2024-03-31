#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // int sum=0;
    // cout<<"enter coordinates";
    // cin>>a>>b>>c>>d;
    // for(int i=a;i<=c;i++){
    //     for(int j=b;j<=d;j++){
    //         sum+=arr[i][j];
    //     }
    // }
    // cout<<"sum is : "<<sum;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
           arr[i][j]+=arr[i][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    } 
    cout<<endl;
    cout<<endl;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]+=arr[i-1][j];
        }
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    } 
    cout<<"enter coordinates";
    int a,b,c,d,sum_of_rectangle=0;
    cin>>a>>b>>c>>d;
    if(a!=0 && b!=0){
        sum_of_rectangle=arr[c][d] -arr[a][b-1]-arr[c][d-1-b]+arr[a-1][b-1];
    }
    else if(a==0 &&b!=0){
        sum_of_rectangle=arr[c][d]-arr[c ][d-b-1];
    }
    else if(a!=0 && b==0){
        sum_of_rectangle=arr[c][d] -arr[a-1][d];
    }
    else sum_of_rectangle=arr[c][d];

    cout<<endl<<sum_of_rectangle;
    return 0;
}