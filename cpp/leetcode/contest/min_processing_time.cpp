#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    vector<int>v(n);
    int num=4*n;
    vector<int>time(num);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<num;i++){
        cin>>time[i];
    }

    sort(v.begin(),v.end());
    sort(time.begin(),time.end());

    int i=0,j=num-1;    
    int ans=INT_MIN;

    while(i<n){
        int maxi = INT_MIN;
        for(int idx=3; idx>=0; idx--){
            maxi  = max(maxi , v[i]+time[j]);
            j--;
        }
        ans = max(ans,maxi);
        i++;
    }

    cout<<ans;
 
    return 0;
}