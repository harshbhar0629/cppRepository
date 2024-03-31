#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/merge-two-binary-max-heaps_1170049?leftPanelTabValue=PROBLEM

void downHeapify(vector<int>& v, int i){
    int n = v.size();
    while(i<n)
    {
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        if(lc>=n){
            break;
        }
        int idx = i;
        if(v[idx] < v[lc]){
            idx = lc;
        }
        if(rc < n and v[idx] < v[rc]){
            idx = rc;
        }

        if(idx != i){
            swap(v[idx], v[i]);
            i = idx;
        }
        else{
            break;
        }
    }
}

void upHeapify(vector<int>& v, int i){
    while(i>0){
        int parent = (i - 1) / 2;
        if(v[i] > v[parent]){
            swap(v[i], v[parent]);
            i = parent;
        }
        else{
            break;
        }
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2){
    // TC: (nlogn + nlogm) 
    // nlogn for n insertion with downheapify also
    // n insertion in arr2 with upheapify also

    // for (int i = n - 1; i >= 0; i--){
    //     //swap first node and apply downHeapify
    //     swap(arr1[i], arr1[0]);
    //     int last = arr1[i];
    //     //remove last element 
    //     arr1.pop_back();
    //     downHeapify(arr1, 0);

    //     arr2.push_back(last);
    //     upHeapify(arr2, arr2.size()-1);
    // }

    // TC: (nlogm) -> n insertion in arr2 and it takes logm times
    // for (int i = n - 1; i >= 0; i--){
    //     arr2.push_back(arr1[i]);
    //     upHeapify(arr2, arr2.size() - 1);
    // }

    for (int i = 0; i < n; i++){
        arr2.push_back(arr1[i]);
    }

    for (int i = (arr2.size() / 2) - 1; i >= 0; i--){
        downHeapify(arr2, i);
    }

    return arr2;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v1(n), v2(m);

    for (int i = 0; i<n; i++){
        cin >> v1[i];
    }

    for (int i = 0; i<m; i++){
        cin >> v2[i];
    }

    vector<int> ans = mergeHeap(n, m, v1, v2);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}