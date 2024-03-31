#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Segment{
    vector<ll> seg;
    vector<ll> arr;
    vector<ll> lazy;
    int n;

    void build(int idx, int start, int end){
        if(start == end){
            seg[idx] = arr[start]*arr[start];
            return;
        }
        int mid = (start + end) / 2;
        
        build(idx * 2, start, mid);
        build(idx * 2 + 1, mid + 1, end);

        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

public:
    Segment(int n, vector<ll> arr){
        this->n = n;
        this->arr = arr;
        lazy.resize(n * 4, 0);
        seg.resize(n * 4, 0);
        build(1, 0, n - 1);
    }

    void update(int l, int r, ll val){
        // update(1, 0, n - 1, l, r, val);
    }
    
    ll query(int l, int r){
        
    }
};

int main(){
    int n;
    cin >> n;

    return 0;
}