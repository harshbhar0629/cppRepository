/**https://www.spoj.com/problems/RMID2/
 * first number will not be considered
input:
1
9
10
2
5
1
18
-1
-1
4
3
-1
8
7
-1
0

Output:
5
9
3
7
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

    /**
     * for fast input output use 
     * ios_base::sync_with_stdio(0);
     * cin.tie(0);
     * cout.tie(0);
    */
    
    int n ,t;
    priority_queue<int> maxHp;
    priority_queue<int,vector<int>,greater<int>> minHp;
    cout<<"\nEnter num: ";
    cin>>n;
    while(n!=0){
        cout<<"\nEnter num: ";
        cin>>n;
        if(n==-1){
            cout<<"Median ELe: "<<maxHp.top();
            maxHp.pop();
            if(maxHp.size() < minHp.size()){
                maxHp.push(minHp.top());
                minHp.pop();
            }
        }
        else{
            if(maxHp.empty() || n <= maxHp.top()){
                maxHp.push(n);
            }
            else{
                minHp.push(n);
            }

            if(maxHp.size() > 1+minHp.size()){
                minHp.push(maxHp.top());
                maxHp.pop();
            }
            else if(minHp.size() > maxHp.size()){
                maxHp.push(minHp.top());
                minHp.pop();
            }
        }
    }

    return 0;
}