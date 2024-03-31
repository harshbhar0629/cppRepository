#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {1,2,3,4,3,2,1};
    int b[]= {2,3,7,7,8,9,0,8,6,6};
    int n =7 , m =10;

    set<int> s;

    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }

    int sum=0;
    for(int i=0;i<m;i++){
        if(s.find(b[i])!=s.end()){
            sum+=b[i];
        }
    }

    cout<<"Sum is : "<<sum;

}