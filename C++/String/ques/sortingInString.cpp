#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    // string s;
    // getline(cin,s);
    vector <int> v;
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    cout<<v[i]<< "   ";
}