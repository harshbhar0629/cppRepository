#include <bits/stdc++.h>
using namespace std;

/**
 * problem: we have to update a value (x) in [l..r] inclusive
 * problem: find value at idx
 * 
 * for update query:
 *     we can update a range limit store by seg array how-- [seg[idx]+=val]
 * 
 * find value : (known as lazy propagation)
 *     for finding value we will propogate for every idx to their left and right child value inc by their parent value and parent value now become zero 
 * 
*/

class Segment{
    vector<int> arr;
    vector<int> seg;
    int n;

    void build(int idx, int start, int end){
        if(start == end){
            seg[idx] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(idx * 2, start, mid);
        build(idx * 2 + 1, mid + 1, end);
        seg[idx] = 0;
    }

    void update(int idx, int start, int end, int l, int r, int x){
        if(end<l || r<start){
            return;
        }
        if(start == end){
            seg[idx] += x;
            return;
        }
        if(l<=start and end<=r){
            seg[idx] += x;
            return;
        }
        int mid = (start + end) / 2;
        update(idx * 2, start, mid, l, r, x);
        update(idx * 2 + 1, mid + 1, end, l, r, x);
    }

    void propogate(int idx){
        seg[idx * 2] += seg[idx];
        seg[idx * 2 + 1] += seg[idx];
        seg[idx] = 0;
    }

    int value(int idx, int start, int end, int i){
        if(start == end){
            return seg[idx];
        }
        propogate(idx);
        int mid = (start + end) / 2;
        if(start <= i and i<=mid){
            // found in left
            return value(idx * 2, start, mid, i);
        }
        else{
            //found in right
            return value(idx * 2 + 1, mid + 1, end, i);
        }
    }

public:

    Segment(int n, vector<int>& arr){
        this->n = n;
        this->arr = arr;
        this->seg.resize(n * 4, 0);
        build(1, 0, n - 1);
    }

    void updateRange(int l, int r, int x){
        update(1, 0, n - 1, l, r, x);
    }

    int query(int i){
        return value(1, 0, n - 1, i);
    }

};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    Segment s(n, v);

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;
        if(x==1){
            int l, r, val;
            cin >> l >> r >> val;
            s.updateRange(l, r, val);
            cout << "\n";
        }
        else if(x==0){
            int idx;
            cin >> idx;
            cout << s.query(idx) << "\n";
        }
    }

    return 0;
}