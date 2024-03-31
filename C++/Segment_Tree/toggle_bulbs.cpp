#include <bits/stdc++.h>
using namespace std;

class Segment{
    vector<int> seg;
    vector<int> lazy;
    int n;

    int query(int idx, int start, int end, int l, int r){
        propogate(start, end, idx);
        if(r<start || end<l){
            return 0;
        }
        if(start == end){
            return seg[idx];
        }
        else if(l<=start and end<=r){
            return seg[idx];
        }

        int mid = (start + end) / 2;
        int left = query(idx * 2, start, mid, l, r);
        int right = query(idx * 2 + 1, mid + 1, end, l, r);
        return left + right;
    }

    void update(int idx, int start, int end, int l, int r){
        propogate(start, end, idx);
        if(r<start || end<l){
            return;
        }
        if(start == end){
            if(seg[idx] == 0){
                seg[idx] = 1;
            }
            else{
                seg[idx] = 0;
            }
            return;
        }
        if(l<=start and end<=r){
            lazy[idx] = !lazy[idx];
            propogate(start, end, idx);
            return;
        }
        int mid = (start + end) / 2;
        update(idx * 2, start, mid, l, r);
        update(idx * 2 + 1, mid + 1, end, l, r);

        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    void propogate(int start, int end, int idx){
        if(lazy[idx] == 0){
            return;
        }
        if(start == end){
            if(seg[idx] == 0){
                seg[idx] = 1;
            }
            else{
                seg[idx] = 0;
            }
            lazy[idx] = 0;
        }
        else{
            seg[idx] = (end - start + 1) - seg[idx];
            lazy[idx * 2] = !lazy[idx];
            lazy[idx * 2 + 1] = !lazy[idx];
            lazy[idx] = 0;
        }
    }

public:

    Segment(int n){
        this->n = n;
        seg.resize(n * 4, 0);
        lazy.resize(n * 4, 0);
    }

    int query(int l, int r){
        return query(1, 1, n , l, r);
    }

    void update(int l, int r){
        update(1, 1, n, l, r);
    }
};

int main(){
    

    return 0;
}