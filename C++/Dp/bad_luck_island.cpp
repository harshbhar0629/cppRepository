// https://codeforces.com/problemset/problem/540/D
#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define dd double


dd dp[105][105][105];
/// @brief 
/// @param r rock
/// @param s scissor
/// @param p paper
/// @param fr it return the prob of rock survive in island
/// @return 

dd fr(int r,int s,int p){
    // base case
    if(p==0) {          // paper finished then rock and scissor will survive 
        return 1.0;     //in island but rock destroy all scissor
    } 
    if(r==0 || s==0) {  // rock finished then no prob of rock will exit to survive 
        return 0.0;     // scissor finished in island so all rock destroy by paper
    }
    if(dp[r][s][p] > -0.9){
        return dp[r][s][p];
    }

    dd  total = (r*s + s*p + p*r)*1.0;
    dd ans =0.0;
    ans += fr(r, s-1, p)*( 1.0*(r*s) /total);
    ans += fr(r, s, p-1)*( 1.0*(p*s) /total);
    ans += fr(r-1, s, p)*( 1.0*(r*p) /total);
    return dp[r][s][p] = ans;
}



/// @brief 
/// @param r rock
/// @param s scissor
/// @param p paper
/// @param fs it return the prob of scissor survive in island
/// @return 
dd fs(int r,int s,int p){
    // base case
    if(r==0) {          // rock finished then paper and scissor will survive 
        return 1.0;     //in island but scissor destroy all paper
    } 
    if(p==0 || s==0) {  // scissor finished then no prob of scissor will exit to survive 
        return 0.0;     // pper finished in island so all rock destroy  scissor
    }
    if(dp[r][s][p] > -0.9) {
        return dp[r][s][p];
    }

    dd  total = (r*s + s*p + p*r)*1.0;
    dd ans =0.0;
    ans += fs(r, s-1, p)*( 1.0*(r*s) /total);
    ans += fs(r, s, p-1)*( 1.0*(p*s) /total);
    ans += fs(r-1, s, p)*( 1.0*(r*p) /total);
    return dp[r][s][p] = ans;
}




/// @brief 
/// @param r rock
/// @param s scissor
/// @param p paper
/// @param fs it return the prob of paper survive in island
/// @return 
dd fp(int r,int s,int p){
    // base case
    if(s==0) {          // scissor finished then rock and paper will survive 
        return 1.0;     //in island but paper destroy all rock
    } 
    if(r==0 || p==0) {  // paper finished then no prob of paper will exit to survive 
        return 0.0;     // rock finished in island so all paper destroy by scissor
    }
    if(dp[r][s][p] > 0.9){
        return dp[r][s][p];
    }

    dd  total = (r*s + s*p + p*r)*1.0;
    dd ans =0.0;
    ans += fp(r, s-1, p)*( 1.0*(r*s) /total);
    ans += fp(r, s, p-1)*( 1.0*(p*s) /total);
    ans += fp(r-1, s, p)*( 1.0*(r*p) /total);
    return dp[r][s][p] = ans;
}



int main(){

    clock_t begin = clock();

    dd r,s,p;
    cin>>r>>s>>p;

    memset(dp,-1.0,sizeof dp);
    cout<<"rock-> "<<fixed<<setprecision(9)<<fr(r,s,p)<<endl;
    memset(dp,-1.0,sizeof dp);
    cout<<"scissor-> "<<fixed<<setprecision(9)<<fs(r,s,p)<<endl;
    memset(dp,-1.0,sizeof dp);
    cout<<"paper-> "<<fixed<<setprecision(9)<<fp(r,s,p)<<endl;
    
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;

    #endif
    return 0;
}