#include <bits/stdc++.h>
using namespace std;

vector<int> size;
vector<int> rank;
// v-> represent parent here
// o(logn) find
// o(1) union
int find(int x, vector<int> &v)
{
    if (v[x] == x)
        return x;
    return find(v[x], v);
}

void UnionRank(int a, int b, vector<int> &v)
{
    a = find(a, v);
    b = find(b, v);
    if (rank[a] <= rank[b])
    {
        v[a] = b;
        rank[b]++;
    }
    else
    {
        v[b] = a;
        rank[a]++;
    }
}

void Union(int a, int b, vector<int> &v)
{
    a = find(a, v);
    b = find(b, v);
    if (size[a] <= size[b])
    {
        v[a] = b;
        size[b] += size[a];
    }
    else
    {
        v[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    // size.resize(n,1);
    rank.resize(n, 1);
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    int e;
    cin >> e;
    while (e--)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int a, b;
            cin >> a >> b;
            // Union(a,b,v);
            UnionRank(a, b, v);
        }
        else
        {
            int x;
            cin >> x;
            cout << find(x, v);
        }
    }

    return 0;
}