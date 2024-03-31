// https://cses.fi/paste/347bafc16e6a379a360130/
#include<bits/stdc++.h> 
using namespace std;
#define ll long long int

ll ans = 0;
const int totalSteps = 48;
const int n = 7;
bool vis[n][n];
string s;

void f(int i, int j, int& steps ){
    if(i==n-1 and j == 0){
        if(steps==totalSteps){
            ++ans;
        }
        return;
    }

    //if we reach last row
    if((i==n-1 || (vis[i-1][j] and vis[i+1][j])) and j-1>=0 and j+1<n and !vis[i][j-1] and !vis[i][j+1]){
        return;
    }

    //if we reach the last column
    if((j==n-1 || (vis[i][j+1] and vis[i][j-1])) and i-1>=0 and i+1<n and !vis[i-1][j] and !vis[i+1][j]){
        return;
    } 

    //if we r standing on first row
    if((i==0 || (vis[i-1][j] and vis[i+1][j])) and j-1>=0 and j+1<n and !vis[i][j-1] and !vis[i][j+1]){
        return;
    }

    //if(we r standing on last column)
    if((j==0 || (vis[i][j-1] and vis[i][j+1])) and i-1>=0 and i+1<n and !vis[i-1][j] and !vis[i+1][j]){
        return;
    }


    //algorithm

    vis[i][j] = true;
    if(s[steps]!='?'){
        
        // upward case
        if(s[steps] == 'U'){
            if(i-1>=0 ){ 
                if(!vis[i-1][j]){
                    steps++;
                    f(i-1, j, steps);
                    steps--;
                }
            }
        }
        
        // downward case
        else if(s[steps] == 'D'){
            if(i+1 < n ){
                if(!vis[i+1][j]){
                    steps++;
                    f(i+1, j, steps);
                    steps--;
                }
            }  
        }

        //right case
        else if(s[steps] == 'R'){
            if(j+1<n ){
                if(!vis[i][j+1]){
                    steps++;
                    f(i, j+1, steps);
                    steps--;
                }
            } 
        }

        //left case
        else if(s[steps] == 'L'){
            if(j-1>=0 ){
                if(!vis[i][j-1]){
                    steps++;
                    f(i, j-1, steps);
                    steps--;
                }
            } 
        }
    }
    else{
        if (i + 1 < n)
        {
            if (!vis[i + 1][j])
            {
                steps++;
                f(i + 1, j, steps);
                steps--;
            }
        }
 
        // move right
        if (j + 1 < n)
        {
            if (!vis[i][j + 1])
            {
                steps++;
                f(i, j + 1, steps);
                steps--;
            }
        }
 
        // move up
        if (i - 1 >= 0)
        {
            if (!vis[i - 1][j])
            {
                steps++;
                f(i - 1, j, steps);
                steps--;
            }
        }
 
        // move left
        if (j - 1 >= 0)
        {
            if (!vis[i][j - 1])
            {
                steps++;
                f(i, j - 1, steps);
                steps--;
            }
        }
    }
    vis[i][j] = false;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>s;
    ans = 0;
    int step=0;
    // vector<vector<bool>>vis(10, vector<bool>(10, 0));
    f(0, 0, step);

    cout<<ans<<endl;

}