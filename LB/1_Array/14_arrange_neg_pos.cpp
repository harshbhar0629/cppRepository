#include <bits/stdc++.h>
using namespace std;


void arrange(vector<int>& a){
    int n = a.size();
    int  i=0, j=n-1, count = 0;
    //first arange all neg ele in starting and after arrange all elemnt in alternating position
    while(i<=j){
        if(a[j]<0) {
            swap(a[i],a[j]);
            i++,j--;
            count++;
        }
        else j--;
    }

}


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
} 0;
}