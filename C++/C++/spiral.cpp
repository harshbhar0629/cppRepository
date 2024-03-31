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
    int rend=n-1,cend=m-1,cst=0,rst=0;
    while(rst<=rend && cst<=cend){
        for(int i=cst;i<=cend;i++){
            cout<<arr[rst][i]<<"  ";
        }
        rst++;
        for(int i=rst;i<=rend;i++){
            cout<<arr[i][cend]<<"  ";
        }
        cend--;
        for(int i=cend;i>=cst;i--){
            cout<<arr[rend][i]<<"  ";
        }
        rend--;
        for(int i=rend;i>=rst;i--){
            cout<<arr[i][cst]<<"  ";
        }
        cst++;
    }

    return 0;
}