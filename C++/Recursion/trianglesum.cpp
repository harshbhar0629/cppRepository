#include <bits/stdc++.h>
using namespace std;
// void sumTriangle(vector<int> &arr, int n) {
//     if(n == 0) return;

//     for(int i = 0; i < n-1; i++) {
//         arr[i]=arr[i]+arr[i+1];
//         cout<<arr[i]<<"  ";
//     } cout << endl;

//     sumTriangle(arr, n-1);

// }
void sumTriangle(vector<int> arr, int &ans) {
    if(arr.size() == 1) {
        ans= arr[0];
        return;
    }
    int n = arr.size();
    vector<int>a(n-1);
    for(int i = 0; i < n-1; i++) {
        a[i]=arr[i]+arr[i+1];
        cout<<a[i]<<"  ";
    } cout << endl;

    sumTriangle(a, ans);

}
int main(){

    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans;
    sumTriangle(v,ans);
    cout<<ans;

}