#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        while(st.size()>1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(M[a][b] == 1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        // store celebrity
        int cele = st.top();
        int count=0;
        for(int i=0; i<n; i++){
            // checking if celebrity knows anyone then it is connfirms that this is not a celebrity
            if(M[cele][i] == 0) count++;
        }
        // if celebrity not knows anyone then count == n o/w count is less than n
        if(count!=n) return -1;
        count=0;
        for(int i=0; i<n; i++){
            //checking all canditate knows celebrity if yes then count==n-1 o/w less than n-1
            if(i!=cele and M[i][cele]==1) count++;
        }
        if(count==n-1) return cele;
        return -1;

    }
};



int main(){
    

    return 0;
}