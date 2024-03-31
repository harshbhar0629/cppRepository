#include <iostream>
#include <vector>
using namespace std;


int f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
        return 0;

    int sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i < 0)
            break;
        sum += f(n - i);
    }
    return sum;
}


#define ll long long int
vector<ll> dp;

ll ftd(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    ll sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i < 0)
            break;
        sum += ftd(n - i);
    }
    return dp[n] = sum;
}


int fbu(int n){
    dp[0]=1;
    for(int i=1; i<=n;i++){
        ll sum=0;
       for(int j=1; j<=6; j++){
            if(i-j<0) break;
            sum= sum + dp[i-j];
        }
        dp[i]=sum;
    }
    return dp[n];
}

int main()
{
    int target;
    cin >> target;

    dp.resize(1000009, 0);
    cout << fbu(target)<<endl;

    dp.clear();
    dp.resize(target+11,-1);

    cout<<ftd(target);
    return 0;
}