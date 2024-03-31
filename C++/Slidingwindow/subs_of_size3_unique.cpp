#include<bits/stdc++.h>
using namespace std;

 int countGoodSubstrings(string s) {
        int v[26]={0};
        bool flag = true;
        int k=3,j;
        for( j = 0 ; j < 3 ; j++){
            if(v[s[j] - 'a']==0){
                v[s[j] - 'a']++;
            }
            else {
                flag = false;
            }
        }
        int count=0;
        if(flag) count++;
        while( j < s.size()){
            flag = true;
            v[s[j - 3] - 'a']--;
            if(v[s[j] - 'a'] == 0){
                v[s[j] - 'a']++;
            }
            else{
                v[s[j] - 'a']++;
                flag = false;
            }

            if(flag) 
                count++;
            j++;
        }
    }

int main(){
    string s("xyzzaz");
    // cout<<countGoodSubstrings(s);
    cout<<pow(10,2);
    return 0;
}