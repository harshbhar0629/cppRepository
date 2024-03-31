#include<bits/stdc++.h>
using namespace std;

    bool isPalindrome(string s) {
        if(s.size() <= 1) return true;
        string temp = "";
        
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'A' and s[i] <= 'Z'){
                char ch = s[i]+32;
                temp.push_back(ch);
            }
            else if(s[i] >= 'a' and s[i] <= 'z'){
                temp.push_back(s[i]);
            }
        }

        cout<<temp<<endl;

        int n= temp.size();
        for(int i=0; i<n/2; i++){
            if(temp[i] != temp[n-i-1] ) return false;
        }
        
        return true;
    }

int main(){
    cout<<isPalindrome("");
    return 0;
}