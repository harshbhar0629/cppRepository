#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
//     vector<int>v;
//     for(int i=0;i<5;i++){
//         int x;
//         cin>>x;
//         v.push_back(x);
//     }
//     v.insert(v.begin(),1);
//     for(int i=0;i<v.size();i++){

//         cout<<v[i]<<"    ";
//     }
string s,t;
cin>>s>>t;
int sum=0;
int i=s.size()-1;
string ans("");
int j=t.size()-1;
while(i>=0||j>=0){
   int y=0,x=0;
   if(i>=0) x=(s[i]-'0');
    
    if(j>=0) y=(t[j]-'0');
    sum+=x+y;
    if(sum>1) ans.push_back(0);
    else if(sum==1) ans.push_back(1);
    else ans.push_back(0);
}
while(sum--){
  if(sum>1) ans.push_back(0);
    else if(sum==1) ans.push_back(1);
    else ans.push_back(0);
}
sort(ans.begin(),ans.end());
// cout<<(s[0]-'0');
cout<<ans;

}