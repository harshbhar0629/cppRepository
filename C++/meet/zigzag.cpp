#include<bits/stdc++.h>
using namespace std;
int main(){
    // P     I    N
    // A   L S  I G
    // Y A   H R
    // P     I

    // *     *     *
    // *   * *   * *
    // * *   * *   
    // *     *     
    // if(n<=1) return s;
    char s[] = "paypalishiring";
    vector<string> v(n,"");
    int j=0,direction=-1;
    
    for(int i=0;i<s.size();i++){
        if(j==0||j==n-1) direction *=(-1);
        v[j] += s[i];
        if(direction==1) j++;
        else j--;
    }
    
    string ans("");
    for(auto it: v){
        ans+=it;
    }
    
    return ans;




}