#include <bits/stdc++.h>
using namespace std;
// https://leetcode.ca/2016-08-08-252-Meeting-Rooms/

bool isPossibleToAttendAllMeeting(vector<vector<int>> &rooms){
    int n = rooms.size();
    sort(rooms.begin(), rooms.end(), [&](const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    });

    for (int i = 1; i < n; i++){
        if(rooms[i-1][1] > rooms[i][0]){
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cin >> v[i][j];
        }
    }

    cout << isPossibleToAttendAllMeeting(v);

    return 0;
}