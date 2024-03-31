#include<iostream>
#include<vector>
#include<bits\stdc++.h>
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
    for(int i=0;i<m;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m/2;j++){
           int t=arr[i][j];
           arr[i][j]=arr[i][m-j-1];
           arr[i][m-1-j]=t;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<"  ";
        }cout<<endl;
    }
    // int  n;
    // cin>>n;
    // vector<string> ans;
    // string s=to_string(n);
    // do{
    //      ans.push_back(s);
    // }while(next_permutation(s.begin(),s.end()));
    // for(int i=0;i<ans.size();i++){
    //     cout<<endl<<ans[i];
    // }
    
    
}