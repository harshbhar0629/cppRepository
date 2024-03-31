#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

int activitySelection(vector<int> start, vector<int> end, int n){
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        v.push_back({start[i], end[i]});
    }
    sort(v.begin(), v.end(), [](pair < int, int> &p1, pair<int, int> &p2){ 
        return p1.second < p2.second; 
    });

    int lastTime = v[0].second;
    int cnt = 1;
    for (int i = 1; i<n; i++){
        if(lastTime < v[i].first){
            cnt++;
            lastTime = v[i].second;
        }
    }

    return cnt;
}

int main(){
    

    return 0;
}