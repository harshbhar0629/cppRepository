#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
  
    int k;
    
    for(int i=0;i<m;i++){
        int a=i;
        k=0;
        for(int j=n-1;j>=0;j--){
            arr[a][k]=arr[j][i];
            a++,k++;
        
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<"  ";
        }cout<<endl;
    }
    
    
}