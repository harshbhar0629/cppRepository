#include <bits/stdc++.h>
using namespace std;

class Segment{
public:
    vector<int>seg;
    int n;
    Segment(int n){
        this->n = n;
        seg.resize(n * 4, 0);
    }

    void build(vector<int>& arr, int lo, int hi, int idx){
        if(lo == hi){
            this->seg[idx] = arr[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(arr, lo, mid, idx * 2);
        build(arr, mid + 1, hi, idx * 2 + 1);
        this->seg[idx] = this->seg[idx * 2] + this->seg[idx * 2 + 1];
    }

    void display(){
        for(auto it: this->seg){
            cout << it << " ";
        }
        cout << "\n";
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
    s.build(arr, 0, n - 1, 1);
    s.display();

    return 0;
}