#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/min-stack/

class MinStack
{
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int val)
    {
        if (st.size() == 0)
        {
            st.emplace(val, val);
        }
        else
        {
            st.emplace(val, min(st.top().second, val));
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// #define ll long long int
// class MinStack {
//     stack<ll>st;
//     ll mini ;
// public:
//     MinStack() {
//         mini = -1;
//     }

//     void push(ll val) {
//         if(st.size() == 0){
//             st.push(val);
//             mini = val;
//         }
//         else{
//             if(val >= mini){
//                 st.push(val);
//             }
//             else{
//                 st.push(2*val - mini);
//                 mini = val;
//             }
//         }
//     }

//     void pop() {
//         if(st.top() >= mini){
//             st.pop();
//         }
//         else{
//             mini = 2*mini - st.top();
//             st.pop();
//         }
//     }

//     ll top() {
//         if(st.top() < mini){
//             return mini;
//         }
//         return st.top();
//     }

//     ll getMin() {
//         return mini;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    

    return 0;
}