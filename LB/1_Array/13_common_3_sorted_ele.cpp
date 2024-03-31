#include <bits/stdc++.h>
using namespace std;


vector <int> commonElements (vector<int>&A, vector<int>&B, vector<int>&C){
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    vector<int> ans;
    int i=0, j=0, k=0;
    while(i<n1 and j<n2 and k<n3){
        if(A[i] == B[j] and A[i] == C[k]) {
            if(ans.size() == 0 || ans.back() != A[i]) ans.push_back(A[i]);
            i++, j++, k++;
        }
        while(i<n1 and (A[i]<B[j] || A[i]<C[k])) i++;
        while(j<n2 and (B[j]<C[k] || B[j]<A[i])) j++;
        while(k<n3 and (C[k]<B[j] || A[i]>C[k])) k++;
    }
    return ans;
}


int main(){
    int n,m,s;
    cin>>n>>m>>s;
    vector<int>a(n);
    vector<int>b(m);
    vector<int>c(s);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    for(int i=0; i<s; i++) cin>>c[i];

    vector<int>res = commonElements(a,b,c);

    for(auto it: res){
        cout<<it<<" ";
    }

    return 0;
}