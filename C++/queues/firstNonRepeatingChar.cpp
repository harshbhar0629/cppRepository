#include<bits/stdc++.h>
using namespace std;
int main(){
    string s("aabc");
    unordered_map<char,int>count;
    queue<int>qu;
    string ans("");
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        count[ch]++;
        qu.push(ch);
        while(qu.size()>0){
            if(count[qu.front()]>1){
                qu.pop();
            }
            else {
                ans.push_back(qu.front());
                break;
            }
        }
        if(qu.size()==0) ans.push_back('#');
    }
    cout<<ans;


    return 0;
}