#include<bits/stdc++.h>
using namespace std;

bool beautifulNumber(int n) {
    // cout<<n;
        if(n==1) return true;
        if(n==2) return false;
        unordered_map<int,int>s;
        s[n]++;
        long  num = n;
        long dup =0;
        while(1){
            if(dup==1) return true;
            dup=0;
            while(num>0){
                int sq = num%10;
                dup += (sq*sq);
                num /= 10;
            }
            num = dup;
            if(s[dup]==0){
                s[dup]++;
            }
            else return false;
        }
        return false;
}

 int diffSum(int n,int m,int arr[]) {
        sort(arr,arr+n);
        long mini=INT_MAX;
        long maxi=INT_MIN;
        long sum=0;
        for(int i=0;i<m;i++){
            sum+=arr[i];
        }
        mini = min(sum,mini);
        maxi = max(sum,maxi);
        int i=m,j=0;
        while(i<n){
            sum += arr[i] - arr[j];
            mini = min(sum,mini);
            maxi = max(sum,maxi);
            i++,j++;
        }
        int ans = (int)maxi - (int)mini;
        return ans;
}


int main(){
    // cout<<beautifulNumber(19)<<endl;
    // cout<<beautifulNumber(2)<<endl;
    // cout<<beautifulNumber(27)<<endl;
    int n = 5,m = 4;
    int arr[] = {1, 2, 3, 4, 5};
    cout<< diffSum(n,m,arr);

    return 0;
}