#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/count-tested-devices-after-test-operations/description/

int countTestedDevices(vector<int> &batteryPercentages){
    int n = batteryPercentages.size();
    int cnt = 0, dec = 0;
    for (int i{0}; i < n; i++){
        int x = batteryPercentages[i] - dec;
        if(x<=0) continue;
        cnt++, dec++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << countTestedDevices(v);

    return 0;
}