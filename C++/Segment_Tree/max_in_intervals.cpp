#include <bits/stdc++.h>
using namespace std;

class Segment{
public:
    vector<int> seg;
    int n;
    Segment(int n){
        this->n = n;
        seg.resize(n * 4, 0);
    }

    void build(vector<int>& arr, int lo, int hi, int idx){
        if(lo == hi){
            seg[idx] = arr[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(arr, lo, mid, idx * 2);
        build(arr, mid + 1, hi, idx * 2 + 1);
        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }
    void display(){
        for(auto it: seg){
            if(it!=0)
            cout << it << " ";
        }
        cout << "\n";
    }

    int solve(int start, int end, int l, int r, int idx){
        if(end<l || r<start){
            return -1;
        }
        if(start == end){
            return seg[idx];
        }
        if(l <= start and end <= r){
            return seg[idx];
        }
        int mid = (start + end) / 2;
        int left = solve(start, mid, l, r, idx * 2);
        int right = solve(mid + 1, end, l, r, idx * 2 + 1);

        return max(left, right);
    }

    int queryAns(int l, int r){
        return solve(0, n - 1, l, r, 1);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    Segment s(n);
    s.build(arr, 0, n-1, 1);
    s.display();

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin>>l>>r;

        cout << s.queryAns(l, r)<<"\n";
    }

    return 0;
}