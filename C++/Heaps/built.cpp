#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
int main(){
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pqr;
    // by default it is max heap
    int k=1;
    pq.push(k++);
    pq.push(k++);
    pq.push(k++);
    pq.push(k++);
    pq.push(k++);
    pq.push(k++);
    cout<<pq.top()<< " "<<endl;

    /**********************************************************/
    // change deafult queue into min heap
    priority_queue<int ,vector<int>,greater<int>> p;
    // cout<<"Min heap "<<p.top()<<endl; //stop all iteration
    p.push(k++);
    p.push(k++);
    p.push(k++);
    p.push(k++);
    p.push(k++);
    cout<<"Min heap "<<p.top()<<endl;
    /**********************************************************/
    // make heap by using vector 
    vector<int> v={1,2,3,4,5,6,7,8};
    priority_queue<int> a(v.begin(),v.end());  //it make max heap
    priority_queue<int ,vector<int>,greater<int>> b(v.begin(),v.end()); //it make a min heap
    


}