#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    string s,t;
cin>>s>>t;
int sum=0;
int i=s.size()-1;
string ans="";
int j=t.size()-1;
while(i>=0||j>=0||sum){
   if(i>=0)sum+=s[i]-'0';
   if(j==0) sum+=t[j]-'0';
   ans+= sum % 2 + '0';
   sum/=2;
   i--,j--;
}
reverse(begin(ans),end(ans));
// if(sum){
// while(sum--){
//   if(sum>1) ans.push_back(0);
//     else if(sum==1) ans.push_back(1);
//     else ans.push_back(0);
// }
// }
// sort(ans.begin(),ans.end());
// cout<<(s[0]-'0');
cout<<ans;
}