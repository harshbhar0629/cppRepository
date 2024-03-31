#include<bits/stdc++.h>
using namespace std;


void DownHeapify(vector<int>& v,int idx){
    int n = v.size();
    while(idx < n){
        int lc = 2*idx+1;
        int rc = 2*idx+2; 

        if(lc >= n) return;
        int maxEle = idx;
        if(v[maxEle] < v[lc]){
            maxEle = lc;
        }

        if(rc < n and v[maxEle] < v[rc]){
            maxEle = rc;
        }

        if(maxEle != idx){
            swap(v[maxEle] , v[idx]);
            idx = maxEle;
        }
        else break;
    }
}


void convertArrayToMaxHeap(vector<int> &v){
    int n =v.size()/2;
    for(int i=n;i>=0;i--){
        DownHeapify(v,i);
    }

}

void upHeapify(vector<int> &v,int idx){

    while(idx>0){
        int pIdx = (idx-1)/2;
        if(v[pIdx] < v[idx]){
            swap(v[pIdx],v[idx]);
            idx = pIdx;
        }
        else break;
    }

}

void push(vector<int>& v,int x){
    if(v.size()==0) {
        v.push_back(x);
        return;
    }
    else{
        v.push_back(x);
        upHeapify(v,v.size()-1);
    }

}

void downHeapify(vector<int>&v,int idx,int n){
    while(idx < n){
        int rc = 2*idx+2; 
        int lc = 2*idx+1;

        if(lc >= n) return;
        int maxEle = idx;
        if(v[maxEle] < v[lc]){
            maxEle = lc;
        }

        if(rc < n and v[maxEle] < v[rc]){
            maxEle = rc;
        }

        if(maxEle != idx){
            swap(v[maxEle] , v[idx]);
            idx = maxEle;
        }
        else break;
    }
}


void heapSort(vector<int>&v,int size){
    convertArrayToMaxHeap(v);

    cout<<"Before sort: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
    while(size>0){
        swap(v[0],v[size]);
        downHeapify(v,0,size);
        size--;
    }
}

int main(){

    int n;
    cin>>n;
    vector<int>v;
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     push(v,x);
    // }

    heapSort(v,v.size()-1);

    cout<<"\nAfter HeapSort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }


}