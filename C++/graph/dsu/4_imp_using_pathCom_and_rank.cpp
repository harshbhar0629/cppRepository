#include <bits/stdc++.h>
using namespace std;


// v-> represent parent here
// o(on an avg constant) = log*N -> when logbas 2 apply again and again on any 
// no then by inverse ackermann function it is represented as log*n find
//o(1) union

int find(int x,vector<int>&v){
    if(v[x]==x) return x;
    return v[x] = find(v[x],v); //store like overlapping subprblm
}


void Union(int a, int b,vector<int>&v,vector<int>& rank){
    a = find(a,v);
    b = find(b,v);
    if(a==b) return;
    if(rank[a]<=rank[b]){
        v[a] = b;
        rank[b]++;
    }
    else{
        v[b] = a;
        rank[a]++;
    }
}


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int> rank(n,1);

    for(int i=0; i<n; i++){
        v[i] = i;
    }
    int e;
    cin>>e;
    while(e--){
        string s;
        cin>>s;
        if(s=="union"){
            int a,b;
            cin>>a>>b;
            Union(a,b,v,rank);
        }
        else{
            int x;
            cin>>x;
            cout<<find(x,v);
        }
    }

    return 0;
}