#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define f first
#define s second

class Segment{
    vector<pi> seg;
    vector<int> arr;
    int n;

    pi build(int idx, int start, int end){
        if(start == end){
            return seg[idx] = {arr[start], arr[start]};
        }
        int mid = (start + end) / 2;
        auto left = build(idx * 2, start, mid);
        auto right = build(idx * 2 + 1, mid + 1, end);
        
        // pair.first represent sum of tree and pair.second represent the max val of tree
        int sum = max({left.f, right.f, left.s + right.s});
        int maxi = max(right.s, left.s);
        // {sum, max value}
        return seg[idx] = {sum, maxi};
    }

    void update(int idx, int start, int end, int pos, int val){
        if(start == end){
            seg[idx] = {val, val};
            arr[start] = val;
            return;
        }
        int mid = (start + end) / 2;
        
        if(start<=pos and pos<=mid){
            update(idx * 2, start, mid, pos, val);
        }
        else{
            update(idx * 2 + 1, mid + 1, end, pos, val);
        }

        int sum = max({seg[idx * 2].f, seg[idx * 2 + 1].f, seg[idx * 2].s + seg[idx * 2 + 1].s});
        int maxi = max(seg[idx * 2 + 1].s, seg[idx * 2].s);
        seg[idx] = {sum, maxi};
    }

    pi query(int idx, int start, int end, int l, int r){
        if(r<start || end<l){
            return {0,0};
        }
        if(start == end){
            return seg[idx];
        }
        if(l<=start and end<=r){
            return seg[idx];
        }

        int mid = (start + end) / 2;
        auto left = query(idx * 2, start, mid, l, r);
        auto right = query(idx * 2 + 1, mid + 1, end, l, r);

        int sum = {max({left.f, right.f, left.s + right.s})};
        int maxi = max({left.s, right.s});
        return {sum, maxi};
    }

public:

    Segment(int n, vector<int>& arr){
        this->arr = arr;
        this->n = n;
        this->seg.resize(n * 4, {0,0});
        build(1, 0, n - 1);
    }

    void update(int idx, int val){
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r){
        return query(1, 0, n - 1, l, r).f;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; i++){
        cin >> v[i];
    }

    Segment s(n, v);
    // s.display();
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(x==1){
            // update
            int idx, val;
            cin >> idx >> val;
            s.update(idx, val);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout<<s.query(l, r)<<"\n";
        }
    }

    return 0;
}
// 8 2 6 1 5 4 10 10 9