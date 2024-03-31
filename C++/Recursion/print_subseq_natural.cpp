#include<bits/stdc++.h>
using namespace std;

void f(int n,int k,int curr,vector<int>ans){
    if(ans.size()==k) {
        for(int j=0;j<k;j++){
            cout<<ans[j]<<"   ";
        }cout<<endl;
    }

    for(int i=curr+1;i<=n;i++){
        ans.push_back(i);
        f(n,k,i,ans);
        ans.pop_back();
    }
}
int main(){
    int n,k;
    cout<<"enter natural no. : ";
    cin>>n;
    cout<<"size of subsequece : ";
    cin>>k;
    vector<int >v;
    f(n,k,0,v);
}