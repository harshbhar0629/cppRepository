#include <bits/stdc++.h>
using namespace std;


int find(int x, vector<int>&v){
    return v[x];
}

// O(N)
void Union(int a,int b,vector<int>&v){
    a = find(a,v);
    b = find(b,v);
    for(int i=0; i<v.size(); i++){
        if(b==v[i]){
            v[i] = a;
        }
    }
}


int main(){
    int n ;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        v[i] = i;
    }
    int e;
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
            cout<<find(x,v)<<" \n";
        }
    }

    return 0;
}