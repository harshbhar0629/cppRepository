#include <bits/stdc++.h>
using namespace std;

// giving max in interval with update query
class Segment
{
    int query(int start, int end, int idx, int l, int r)
    {
        if (r < start || end < l)
        {
            return -1;
        }
        if (start == end)
        {
            return seg[idx];
        }
        if (l <= start and end <= r)
        {
            return seg[idx];
        }

        int mid = (start + end) / 2;
        int left = query(start, mid, idx * 2, l, r);
        int right = query(mid + 1, end, idx * 2 + 1, l, r);

        return max(left, right);
    }

    void build(int lo, int hi, int idx)
    {
        if (lo == hi)
        {
            seg[idx] = arr[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(lo, mid, idx * 2);
        build(mid + 1, hi, idx * 2 + 1);
        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int start, int end, int idx, int pos, int val)
    {
        if (start == end)
        {
            // cout << start << "\n";
            arr[start] = val;
            seg[idx] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (start <= pos and pos <= mid)
        {
            update(start, mid, idx * 2, pos, val);
        }
        else
        {
            update(mid + 1, end, idx * 2 + 1, pos, val);
        }
        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

public:
    vector<int> arr;
    vector<int> seg;
    int n;
    Segment(int n, vector<int> &arr)
    {
        this->arr = arr;
        this->n = n;
        seg.resize(this->n * 4, 0);
        build(0, n - 1, 1);
    }

    void updateQuery(int pos, int val)
    {
        update(0, n - 1, 1, pos, val);
    }

    int queryAns(int l, int r)
    {
        return query(0, n - 1, 1, l, r);
    }
    void display(){
        for(auto it: arr){
            cout << it << " ";
        }
        cout << "\n";
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Segment s(n, arr);
    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << s.queryAns(l, r) << "\n";
        }
        if (x == 0)
        {
            int pos, val;
            cin >> pos >> val;
            s.updateQuery(pos, val);
            s.display();
        }
    }

    return 0;
}