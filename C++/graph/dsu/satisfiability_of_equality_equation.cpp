// https://leetcode.com/problems/satisfiability-of-equality-equations/description/
#include <bits/stdc++.h>
using namespace std;


int parent[26];

int find(int x){
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

// void _union(int a, int b){
//      b = find(b);
//      a = find(a)
//      if(a==b) return;
//      parent[a] = b;
// }


// pattern is that first confirm or iterate in equal condition and after check invalid cases means 
// not equal cases it is easier to find if any of time is equal or not if it is equal then return false  
bool f(vector<string>&equation){
    int n = equation.size();
    for(auto it: equation){
        if(it[1]=='='){
            parent[find(it[0]-'a')] = find(it[3]-'a');
        }
    }
    for(auto it: equation){
        if(it[1]=='!'){
            if(find(it[0]-'a') == find(it[3]-'a')) return false;
        }
    }

    return true;
}

int main(){
    

    return 0;
}