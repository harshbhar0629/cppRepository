#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
    vector<int>v;
    int i;

    void upHeapify(int childIdx){
        while(childIdx > 0){
            int parentIdx = (childIdx-1)/2;
        // this is for max heap if we want a min heap then check parent 
        // idx is greater or not if it is greater then swaped it;
            if(v[parentIdx] < v[childIdx]){
                swap(v[parentIdx] , v[childIdx]);
                childIdx = parentIdx;
            }
            else break;
        }
    }

    void downHeapify(int idx){
        int n = v.size();
        while(idx < n){
            int lc = 2*idx+1;
            int rc = 2*idx+2;
            
            if(lc >= n) break; //checking exist or not
            int maxEle = idx;
            
            if(v[maxEle] < v[lc]){
                maxEle = lc;
            }

            if(rc < n and v[maxEle] < v[rc]){
                maxEle = rc;
            }

            if(maxEle != idx){  //if old ele is not greater then swapped it otherwise break
                swap(v[maxEle],v[idx]);
                idx = maxEle;
            }
            else break;
        }
    }

public: 

    Heap(vector<int> hp){ //constructor
        this->v = hp;
        int n = v.size();
        // O(n Log n) for upheapify
        // for(int i=1;i<n;i++){
        //     upHeapify(i);
        // }

        for(int i=n/2;i>=0;i--){
            downHeapify(i);
        }

    }

    void _pop(int idx){
        /*
        * TC: 2*O(log n) 
        */
        if(idx >= v.size()) return;
        v[idx] = INT_MAX; // given idx pe sbse bade value dal do
        upHeapify(idx); //upheapify k lia bhej do or wo root tk phunch jayega
        swap(v[0],v[v.size()-1]);//swap root with last element 
        v.pop_back();
        downHeapify(0);//then call downHeapify it will make a with root
    }

    bool isEmpty(){
        return v.size()==0;
    }

    void display(){
        cout<<"[ ";
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<"]\n";
    }

    int peek(){
        if(!isEmpty()) return v[0];
        return INT_MIN;
    }

    void pop(){
        /*
        * TC: O(log n) 
        */
        if(v.empty()) return;
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        if(!v.empty()) downHeapify(0);
    }

    void push(int ele){
        /*
        * TC: O(log n) 
        */
        v.push_back(ele);
        upHeapify(v.size()-1);
    }
};

int main(){
    vector<int> h={1,2,3,4,5,9,0};
    Heap hp(h);
    hp.display();

}