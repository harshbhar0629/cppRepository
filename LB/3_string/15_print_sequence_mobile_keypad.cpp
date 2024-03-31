#include <bits/stdc++.h>
using namespace std;


string printSequence(string& s){
    
    string arr[] = {" ", "2","22", "222", "3", "33", "333", "4","44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999" };
    int n = s.size();
    string ans("");

    for(int i=0; i<n; i++){
        if(s[i]==' '){
            ans+='0';
        }
        else{
            int idx = s[i] - 'a';
            ans+=arr[idx+1];
        }
        ans+=' ';
    }
    return ans;
}


int main(){
    string s;
    cin>>s;

    string ans = printSequence(s);
    
    cout<<ans;

    return 0;
}