#include <bits/stdc++.h>
using namespace std;
// https://leetcode.ca/2017-12-28-759-Employee-Free-Time/

class Interval{
    public:
    int start, end;
    Interval(){}
    Interval(int s, int e) : start(s), end(e){};
};

vector<Interval> employeeFreeTime(vector<Interval>& A){
    map<int, int> mp;
    for(auto it: A){
        mp[it.start]++;
        mp[it.end]--;
    }
    int cnt = 0;
    vector<Interval>ans;
    for (auto it = mp.begin(); it != mp.end(); it++){
        cnt += it->second;
        if(cnt){
            continue;
        }
        cout << cnt << " ";
        int start = it->first;
        it++;
        if(it == mp.end()){
            break;
        }
        cnt += it->second;
        ans.emplace_back(start, it->first);
    }
    cout << "\n";
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<Interval>v(n);
    for (int i = 0; i<n; i++){
        cin>>v[i].start;
        cin >> v[i].end;
    }

    vector<Interval> ans = employeeFreeTime(v);

    for(auto it: ans){
        cout << it.start << " " << it.end << "\n";
    }

    return 0;
}