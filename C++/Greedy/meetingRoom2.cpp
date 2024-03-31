#include <bits/stdc++.h>
using namespace std;
// https://leetcode.ca/2016-08-09-253-Meeting-Rooms-II/

//using sorting
int minConferenceRoomRequired1(vector<vector<int>>& meetingTime){
    
    int n = meetingTime.size();
    vector<int> start(n);
    vector<int> ending(n);

    for (int i = 0; i < n; i++){
        // starting time stores in 0th index of every ith room
        start[i] = meetingTime[i][0];
        // ending time stores in 1th index of every ith room
        ending[i] = meetingTime[i][1];
    }

    sort(start.begin(), start.end());
    sort(ending.begin(), ending.end());
    
    int i = 0, j = 0;
    int rooms = 0;
    int ans = 0;

    while(i<n and j<n){
        // cout << rooms << " ";
        if (start[i] < ending[j])
        {
            //new room required for meeting
            rooms++;
            i++;
            //stores max room required at a point of time
            ans = max(rooms, ans);
        }
        else if (start[i] > ending[j])
        {
            //our meeting is going to end means this room is empty you 
            // can conduct new meeting in this room
            j++;
            rooms--;
        }
        else{
            i++, j++;
        }
    }

    return ans;
}

//without sorting
int minConferenceRoomRequired2(vector<vector<int>> &meetingTime){
    int n = 1e6 + 5;
    vector<int> time(n, 0);
    
    for(auto& mTime: meetingTime){
        ++time[mTime[0]];
        --time[mTime[1]];
    }

    for (int i = 0; i < n-1; i++){
        time[i + 1] += time[i];
    }

    int ans = *max_element(time.begin(), time.end());
    return ans;
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

    cout << minConferenceRoomRequired2(v) << "\n";

    return 0;
}