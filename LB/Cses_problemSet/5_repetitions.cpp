#include<bits/stdc++.h>
using namespace std;

int main(){
    //acgt
    string s;
    cin>>s;
    char ch='x';
    int count = 0;
    int maxCount=0;

    for(int i=0; i<s.size(); i++){
        if(ch==s[i]){
            count++;
        }
        else{
            count=1;
            ch=s[i];
        }
        maxCount = max(maxCount, count);
    }

    cout<<maxCount<<endl;
}