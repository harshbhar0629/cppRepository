#include<bits/stdc++.h>
using namespace std;

int binaryGap(int n) {
        string s("");
        while(n){
           s = (to_string)(n%2) + s;
           n= n>>1;
        }
        cout<<"string"<<s<<endl;
        int j=0,maxlen=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                maxlen=max(maxlen,i-j);
                j=i;
            }
        } 
        return maxlen;
    }

int main(){
    cout<< (binaryGap(5));
    return 0;
}