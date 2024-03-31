// https://www.geeksforgeeks.org/checking-valid-shuffle-of-two-strings/
#include <bits/stdc++.h>
using namespace std;

bool isEqual(string s, string t, string shuffle){
    return s.size() + t.size() == shuffle.size();
}

bool validShuffle(string s, string t, string shuffle){
    
    // now sort all string now first character must be same and apply like merge sort prop
    sort(s.begin(), s.end());
    sort(t.begin(),t.end());
    sort(shuffle.begin(), shuffle.end());
    
    int i=0 , j=0, k=0;
    while(k<shuffle.size()){
        // check first character of shuffle string is equal to first string if not then check to second and 
        // again if not means this character is diff from all of them so return false;
        if(i<s.size() and s[i]==shuffle[k]){
            i++;
        }
        else if(j<t.size() and t[j]==shuffle[k]){
            j++;
        }
        else return false;
        k++; //k always inc
    }
    if(i<s.size() || j<t.size()) return false ;
    return true;
}

int main(){
    string s,t;
    cin>>s>>t;
    int n;
    cin>>n;
    vector<string>shuffle(n);
    for(int i=0; i<n; i++){
        getline(cin,shuffle[i]);
        if(isEqual(s,t, shuffle[i]) and validShuffle(s,t, shuffle[i])){
            cout<<shuffle[i]<<" is a valid shuffle of "<<s<<" "<<t<<"\n";
        }
        else cout<<shuffle[i]<<" is not a valid shuffle of "<<s<<" "<<t<<"\n";
    }


    return 0;
}