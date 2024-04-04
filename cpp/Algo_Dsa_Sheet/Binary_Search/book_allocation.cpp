#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/allocate-books/

bool isPoss(vector<int> &a, int b, int mid)
{
    int cnt = 1;
    int m = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (m + a[i] <= mid)
        {
            m += a[i];
        }
        else
        {
            cnt++;
            m = a[i];
        }
    }
    if (cnt <= b)
    {
        return true;
    }
    return false;
}

int booksAllocate(vector<int> &A, int B)
{
    if (B > A.size())
    {
        return -1;
    }
    int lo = 0;
    int hi = 0;
    for (int i = 0; i < A.size(); i++)
    {
        lo = max(lo, A[i]);
        hi += A[i];
    }

    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isPoss(A, B, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

int main(){
    

    return 0;
}