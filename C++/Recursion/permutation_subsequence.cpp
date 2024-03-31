#include<bits/stdc++.h>
using namespace std;
string permutation(string s,string ans,int k){
    if(s.size()==0){
        return ans;
    }
    int  n=s.size();
    int fact=1;
    for(int i=2;i<n;i++){
        fact*=i;
    }
    int idx=k/fact;
    if(k%fact==0){
        idx--;
    }
    char ch=s[idx];
    string ros=s.substr(0,idx)+s.substr(idx+1);
    // ans+=ch;
    return  permutation(ros,ans+ch,k-fact*idx);

}
int main(){
    int n,k;
    cout<<"enter n and enter k: ";
    cin>>n>>k;
    string s("");
    for(int i=1;i<=n;i++){
        s+=(to_string)(i);
    }
    // string ans("");
    
    cout<<permutation(s,"",k);
}