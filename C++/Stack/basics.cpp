#include <bits/stdc++.h>
#include <stack>
using namespace std;
void* operator new(std::size_t size){
    std::cout<<"making on heap \n";
    return malloc(size);
}
int main()
{
    stack<int> st;
    cout<<sizeof(st);
    // int k = 1;
    // st.emplace(1);
    // st.emplace(k++);
    // st.emplace(k++);
    // cout << sizeof(st);
    // st.emplace(k++);
    // st.emplace(k++);
    // st.emplace(k++);
    // st.emplace(k++);
    // st.emplace(k++);
    // stack<int> t;
    // while (st.size() > 0)
    // {
    //     cout << st.top() << "  ";
    //     t.emplace(st.top());
    //     st.pop();
    // }
    // cout << endl;

    // while (t.size() > 0)
    // {
    //     cout << t.top() << "  ";
    //     st.emplace(t.top());
    //     t.pop();
    // }
    return 0;
}