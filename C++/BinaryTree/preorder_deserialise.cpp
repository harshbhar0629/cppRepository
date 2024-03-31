#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string pre) {
        int c=1;
        int n = pre.size();
        for(int i=0; i<n; i++){
            c-=1;
            if(c<0) return false;
            if(pre[i]!='#') c+=2;
            i++;
            while(i<n and pre[i]!=',') i++;
        }
        return c==0;
        // int c = 1;
        // stringstream ss(pre);
        // string str;
        // while(getline(ss, str, ',')){
        //     c-=1;
        //     if(c<0) return false;
        //     if(str != "#") c+=2;
        // }
        // if(c == 0) return true;
        // return false;
    }
};

int main(){
    

    return 0;
}