#include<bits/stdc++.h>
using namespace std;
// O(2^n)
void f(string s,int n){
  if(s.size()==n){
    cout<<s;
    cout<<endl;
    return;
  }

  f(s+'0',n);
  if(s.back()!='1')
  f(s+'1',n);

}
int main(){
  int n;
  cin>>n;
  f("",n);
}