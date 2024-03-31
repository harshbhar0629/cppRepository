#include <bits/stdc++.h>
using namespace std;


vector<int>parent;
vector<int>rank;
vector<int> sz;
vector<int>minimal;
vector<int>maximal;

int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]); 
}

void Union(int a,int b){

    a = find(a);
    b = find(b);

    if(a==b) return;

    if(rank[a]>=b){
        rank[a]++;
        sz[a]+=sz[b];
        parent[b] = a;
        minimal[a] = min(minimal[a],minimal[b]);
        maximal[a] = max(maximal[a],maximal[b]);
    }
    else{
        rank[b]++;
        parent[a] = b;
        sz[b]+=sz[a];
        minimal[b] = min(minimal[a],minimal[b]);
        maximal[b] = max(maximal[a],maximal[b]);
    }
}


int main(){

    int n;
    cin>>n;

    parent.resize(n+1);
    rank.resize(n+1,0);
    sz.resize(n+1,1);
    minimal.resize(n+1);
    maximal.resize(n+1);

    for(int i=0; i<n; i++){
        minimal[i] = maximal[i] = parent[i] = i;
    }

    int t;
    cin>>t;

    while(t--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(x,y);
        }
        else {
            int x;
            cin>>x;
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<sz[x]<<"\n";
        }
    }

    return 0;
}
