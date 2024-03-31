#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <ctime>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

#define ld long double
#define dd double
#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define MI INT_MIN
#define MX INT_MAX
#define vvl vector<vl>
#define for1(i,a,b) for(int i=a; i<b; i++)
#define rev(i,a) for(int i=a; i>=0; i--)
#define res(i,a,b) for(int i=a; i>=b; i--)
#define N 1e9+7
#define mod N
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pl pair<ll,ll>
#define ppl pair<ll,pl>
#define ri(vi) reverse(v.begin(),v.end())
#define rl(vl) reverse(v.begin(),v.end())


int minLengthAfterRemovals(vi& v){
    
    int n = v.size();
    unordered_map<int,int>mp;
    for1(i,0,n){
        mp[v[i]]++;
    }

    int maxi = MI;
    for(auto it: mp){
        maxi = max(maxi,it.second);
    }

    if(maxi<=n/2){
        return n%2;
    }
    return 2*maxi-n ; 

    // int n = v.size();
    // unordered_map<int,int>mp;
    // for1(i,0,n){
    //     mp[v[i]]++;
    // }

    // priority_queue<int>pq;
    // for(auto it: mp){
    //     pq.push(it.second);
    // }

    // int ans=0;

    // while(pq.size()){
    //     int x= pq.top();
    //     pq.pop();
    //     if(pq.size()==0){
    //         ans=x;
    //         break;
    //     }
    //     int y= pq.top();
    //     pq.pop();
    //     x--,y--;
    //     if(x>0) pq.push(x);
    //     if(y>0) pq.push(y);

    // }

    // return ans;
}


int main(){

    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vi v(n);
    for1(i,0,n){
        cin>>v[i];
    }

    cout<<minLengthAfterRemovals(v);

    return 0;
}