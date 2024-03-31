// https://www.hackerrank.com/challenges/kruskalmstrsub/problem#:~:text=Given%20an%20undirected%20weighted%20connected,node%20to%20every%20other%20node.
#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int find(vector<int>&par, int x){
    if(par[x]==x) return x;
    return par[x] = find(par, par[x]);
}

void _union(vector<int>&par, vector<int>& rank, int a, int b){
    a = find(par, a);
    b = find(par, b);
    if(a == b) return;
    if(rank[a]>=rank[b]){
        rank[a]++;
        par[b] = a;
    }
    else{
        rank[b]++;
        par[a] = b;
    }
}


struct Edge{
    int wt;
    int src;
    int dest;
};


bool cmp(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}

// O(E logE) or O(V logV)
ll kruskal(vector<Edge>& input, int n, int e){
    
    vector<int> par(n+1), rank(n+1,1);
    sort(input.begin(), input.end(), cmp); // sort on basis of wt of edges
    // for(int i=0; i<=n; i++){
    //     par[i] = i;
    // } 
    iota(par.begin(), par.end(), 0);

    ll ans=0;
    int edgeCount=0 , i=0;

    while(i<e and edgeCount<n){
        auto curr = input[i]; //input already sorted so it will get first min wt edge
        int parSrc = find(par, curr.src);
        int parDest = find(par, curr.dest);
   
        if(parSrc != parDest){
            _union(par, rank, parSrc, parDest);
            ans += curr.wt;
            edgeCount++;
        }
        i++; // doestn't matter either parents are equal or not it will inc. every time
    }    
    return ans;
}


int main(){

    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);


    int n, e;
    cin>>n>>e;
    vector<Edge> input(e);

    for(int i=0; i<e; i++){
        cin>>input[i].src >>input[i].dest >>input[i].wt;
    }

    cout<<kruskal(input, n, e);

    return 0;
}