#include<bits/stdc++.h>
using namespace std;

bool isEqualString(vector<string > & v){
    int n = v.size();
    unordered_map<char,int> mp;

    for(auto str: v){
        for(auto ch : str){
            mp[ch]++;
        }       
    }

    for(auto ele : mp){
        
        if(ele.second % n != 0 )  return false;
    }cout<<endl;
    return true;

}

int main(){
    int n;
    cout<<"enter string size : ";
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<< (isEqualString(v)? "Yes " : "No") <<endl;
}