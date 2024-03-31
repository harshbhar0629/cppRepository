#include <bits/stdc++.h>
using namespace std;


// vector<int> rank;
int find(int x,vector<int>& v){
    if(v[x]==x) return x;
    return v[x] = find(v[x],v); 
}


bool Union(int a, int b,vector<int>& v, vector<int>& rank){
    a = find(a,v);
    b = find(b,v);
    // cout<<a<<"  "<<b<<endl;
    if(a==b) return true;
    if(rank[a]<=rank[b]){
        v[a] = b;
        rank[b]++;
    }
    else{
        v[b] = a;
        rank[a]++;
    }
    return false;
}


int main(){
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
  
    int n;
    cin>>n;
    vector<int>parent(n);
    vector<int>Rank(n,1);

    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    int e;
    cin>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        bool result = Union(a,b,parent,Rank);
        if(result==true) cout<<"Cycle Detected\n";
    }

    return 0;
}
// 6
// 9
// 0 1
// 0 2
// 0 3
// 2 1
// 2 3
// 2 4
// 4 5
// 3 5
// 3 4