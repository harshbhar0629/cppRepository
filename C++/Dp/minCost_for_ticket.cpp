// https://leetcode.com/problems/minimum-cost-for-tickets/description/
    
int dp[370];
int n;
int f(vector<int>& days,vector<int>& cost,int i){
    if(i >= n) return 0;
    if(dp[i]!=-1) return dp[i];

    int option1 = f(days, cost, i+1) + cost[0];

    int idx = i;
    for(idx=i; idx<n and days[idx]<days[i]+7; idx++);
    int option2 = f(days, cost , idx) + cost[1];

    int id = i;
    for(id =i; id < n and days[id]<days[i]+30; id++);
    int option3 = f(days,cost, id) + cost[2];

    return dp[i] = min({option1, option2, option3});
}

int fbu(vector<int>& days, vector<int>& cost){
    memset(dp,0,sizeof dp);
    n = days.size();

    for(int i=n-1; i>=0; i--){
        int option1 = dp[i+1] + cost[0];

        int idx = i;
        for(idx=i; idx<n and days[idx]<days[i]+7; idx++);
        int option2 = dp[idx] + cost[1];

        int id = i;
        for(id =i; id < n and days[id]<days[i]+30; id++);
        int option3 = dp[id] + cost[2];

        dp[i] = min({option1, option2, option3});
    }
    return dp[0];
}



int mincostTickets1(vector<int>& days, vector<int>& cost) {
    int n = days.size();
    queue<pair<int,int>>week;
    queue<pair<int,int>>month;
    int ans=0;

    for(auto day: days){

        while(week.size() and week.front().first+7 <= day) week.pop();
        while(month.size() and month.front().first+30 <= day) month.pop();
        
        week.push({day,ans+cost[1]});
        month.push({day,ans+cost[2]});

        ans = min({ans+cost[0], week.front().second, month.front().second});
    }
    return ans;
}


int mincostTickets(vector<int>& days, vector<int>& costs) {
    // memset(dp,-1,sizeof dp);
    // n = days.size();
    return fbu(days,costs);
}
