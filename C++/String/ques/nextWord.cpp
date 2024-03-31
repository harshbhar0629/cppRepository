#include<bits\stdc++.h>
using namespace std;
int main(){
    // string s;
    // getline(cin,s);
    // stringstream ss(s);
    // string t;
    // int count=0;
    // while(ss>>t){
    //     count++;
    //     //cout<<t<<endl;
    // }
    // cout<<count;
    
//word come most times
    string s;
    getline(cin,s);
    stringstream ss(s);
    string t;
    vector<string>v;
    while(ss>>t){
        v.push_back(t);
    }
    int count=1,mx=0;
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        if(v[i-1]==v[i]){
            count++;
        }
        else count=1;
        mx=max(count,mx);
    }count=1;
     if(mx==1){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<"  "<<mx<<endl;
        }
    }
    else {
        for(int i=1;i<v.size();i++){
            if(v[i-1]==v[i]){
                count++;
            }
            else count=1;
            if(mx==count){
                cout<<v[i]<<"   "<<count<<endl;
            }
        }
    }

    return 0;
}