#include <bits/stdc++.h>
using namespace std;

class Segment{
    vector<int> arr;
    vector<int> seg;
    vector<int> lazy;
    int n;

    void build(int idx, int start, int end){
        if(start == end){
            seg[idx] += arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(idx * 2, start, mid);
        build(idx * 2 + 1, mid + 1, end);
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    void propogate(int start, int end, int idx){
        if(start == end){
            seg[idx] += lazy[idx];
            lazy[idx] = 0;
        }
        else{
            seg[idx] += (end - start + 1) * (lazy[idx]);
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx] = 0;
        }
    }

    void update(int idx, int start, int end, int l, int r, int val){
        propogate(start, end, idx);
        if(r<start || end<l){
            return;
        }
        if(start == end){
            seg[idx] += val;
            return;
        }
        if(l<=start and end<=r){
            lazy[idx] += val;
            propogate(start, end, idx);
            return;
        }
        int mid = (start + end) / 2;
        update(idx * 2, start, mid, l, r, val);
        update(idx * 2 + 1, mid + 1, end, l, r, val);
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    int query(int idx, int start, int end, int l, int r){
        propogate(start, end, idx);
        if (r < start || end < l){
            return 0;
        }
        if(start == end){
            return seg[idx];
        }
        if(l<=start and end<=r){
            return seg[idx];
        }
        int mid = (start + end) / 2;
        int left = query(idx * 2, start, mid, l, r);
        int right = query(idx * 2 + 1, mid + 1, end, l, r);
        return left + right;
    }

public:
    Segment(int n, vector<int>& arr){
        this->arr = arr;
        this->n = n;
        seg.resize(n * 4, 0);
        lazy.resize(n * 4, 0);
        build(1, 0, n - 1);
    }

    void update(int l, int r, int val){
        update(1, 0, n-1, l, r, val);
    }

    int queryAns(int l, int r){
        return query(1, 0, n - 1, l, r);
    }

};


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Segment s(n, arr);
    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;
        if(x==1){
            int l, r, val;
            cout << "Enter l and r and val: ";
            cin >> l >> r >> val;
            s.update(l, r, val);
        }
        if(x==0){
            int l, r;
            cout << "Enter l and r: ";
            cin >> l >> r;
            cout << s.queryAns(l, r) << "\n";
        }
    }


    return 0;
}