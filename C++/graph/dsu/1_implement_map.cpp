#include <bits/stdc++.h>
using namespace std;

map<int,int>mp;
// O(LogN)
int find(int x){
    return mp[x];
}
// O(N)
void Union(int a,int b, vector<int>&v){
    a = find(a);
    b = find(b);
    
    for(auto it: mp){
        if(it.second==b){
            mp[it.first] = a;
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        v[i] = i;
        mp[i] = i;
    }

    int e;
    cin>>e;
    while(e--){
        string s;
        cin>>s;
        if(s=="union"){
            int a,b;
            cin>>a>>b;
            Union(a,b,v);
        }
        else{
            int x;
            cin>>x;
            cout<<find(x)<<"\n";
        }
    }

    return 0;
}