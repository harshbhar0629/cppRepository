// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/**
 *
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2

Sample Output
6
0
0
4
*/



int main(){
    
    int n ;
    cin>>n;
    // n denotes no of boxes

    int m;
    cin>>m;
    // m denotes no. of days querries will come

    vector<int> l(n+1,0),r(n+1,0); // l-> querry start from and R-> querry end 
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        // querry start
        l[x]++;
        // querry end
        r[y]++;
    }

    // storing ans of every boxes ans
    vector<int>dp(n+1);
    //freq of curr ans and greater than ans no. of boxes
    vector<int>mp(n+1,0);

    dp[1] = l[1];
    mp[dp[1]]++;
    for(int i=2; i<=n; i++){
        dp[i] = l[i] + dp[i-1] - r[i-1];
        
        mp[dp[i]]++;
    }

    for(int i=n-1; i>=0; i--){
        mp[i] += mp[i+1];
    }

    // // q denotes no of querry
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int x;
        cin>>x;
        cout<< mp[x] <<"\n";
    }


    return 0;
}