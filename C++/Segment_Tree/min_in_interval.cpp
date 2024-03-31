#include <bits/stdc++.h>
using namespace std;

class Segment{
public:
    vector<int> seg;
    int n;
    Segment(int n){
        seg.resize(n * 4, 1e8);
        this->n = n;
    }

    void build(int lo, int hi, int idx, vector<int>& arr){
        if(lo == hi){
            seg[idx] = arr[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(lo, mid, idx * 2, arr);
        build(mid + 1, hi, idx * 2 + 1, arr);
        seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
    }

    int solve(int start, int end, int l, int r, int idx){
        if(end<l || start>r){
            return 1e8;
        }
        if(start==end){
            return seg[idx];
        }
        if(l<=start and end<=r){
            return seg[idx];
        }
        int mid = (start + end) / 2;
        int left = solve(start, mid, l, r, idx * 2);
        int right = solve(mid + 1, end, l, r, idx * 2 + 1);

        return min(right, left);
    }

    int queryAns(int l, int r){
        return solve(0, n - 1, l, r, 1);
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Segment s(n);
    s.build(0, n - 1, 1, arr);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << s.queryAns(l, r) << "\n";
    }

    return 0;
}