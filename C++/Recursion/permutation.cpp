#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void p(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        p(ros,ans +ch);
    }
}
int ans =0;
void recursion(string num, int i, int j) {
        if (i == j-1) {
           ans++;
            // cout<<num<<endl;
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j);
        }
}


int main(){
    string s;
    getline(cin,s);
    sort(s.begin(),s.end());
    recursion(s,0,s.size());
    cout<<ans<<endl;
    int a= ans;
    reverse(s.begin()+1,s.end()-2);
    ans =0;
    recursion(s,0,s.size());
    cout<<ans<<endl;
    cout<<"diff  "<< abs(ans-a);
    // cout<<s;
    // recursion(s,0,s.size());
    // cout<<ans;
    // p(s,"");

}