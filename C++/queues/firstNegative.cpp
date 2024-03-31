#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter size of array: ";
    cin>>n;
    // -1 2 3 -2 3 4 5 -6 
    //  0 1 2  3 4 5 6  7
    // -1 -2 -2 -2 0 -6

    // enter size of array: 8
    // enter element: -1 -2 -3  -4 -5 -6 -7 -8    
    // enter k 3
    // -1  -2  -3  -4  -5  -6
    int arr[n];
    cout << "enter element: ";
    for (int i = 0; i < n; i++)
    {
        cin >> i[arr];
    }

    int k;
    cout << "enter k";
    cin >> k;
    queue<int> qu;
    vector<int>v;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            qu.push(i);
        }
    }

    if(qu.size() and qu.front()>=0 and qu.front()<k){
        v.push_back(arr[qu.front()]);
    }
    else {
        v.push_back(0);
    }

    for(int i=k;i<n;i++){
        if(qu.size() and qu.front() == (i-k)) qu.pop();
        if(qu.size() and qu.front() >= (i+1-k) and qu.front()<=i){
            v.push_back(arr[qu.front()]);
        }
        else v.push_back(0);
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }


    return 0;
}