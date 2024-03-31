#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
#include <queue>
#include <stack>
#include<bits/stdc++.h>
#include <unordered_map>
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
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rloop(i,a) for(int i=a; i>=0; i--)
#define res(i,a,b) for(int i=a; i>=b; i--)
#define N 1e9+7
#define mod N
#define pi pair<int,int>
#define vpi vector<pi>
#define ppi pair<int,pi>
#define pl pair<ll,ll>
#define ppl pair<ll,pl>
#define ri(vi) reverse(v.begin(),v.end())
#define rl(vl) reverse(v.begin(),v.end())


int countPairs(vpi& v,int k){
    map<pi,int>mp;
    int ans=0;
    int n = v.size();

    loop(i,0,n){
        int x1 = v[i].first;
        int y1 = v[i].second;
        loop(j,0,k+1){
            int x2 = j^x1; 
            int y2 = (k-j)^y1;
            ans+=mp[{x2,y2}]; 
        }
        mp[{x1,y1}]++;
    }
    return ans;

}


int main(){

    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vpi v(n);
    loop(i,0,n){
        cin>>v[i].first>>v[i].second;
    }
    int k;
    cin>>k;

    cout<<countPairs(v,k);

    return 0;
}