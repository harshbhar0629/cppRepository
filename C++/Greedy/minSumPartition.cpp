#include<bits/stdc++.h>
using namespace std;

void divideIntoTwoEqualSum(int n){

    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        v[i]=i+1;
    }

    vector<int>a;
    vector<int>b;

    sort(v.begin(),v.end(),greater<int>());
    int sum1 =0,sum2=0;
    int i=0;

    while(i<n){
        if(sum1<=sum2){
            sum1+=v[i];
            a.push_back(v[i]);
        }
        else{
            sum2+=v[i];
            b.push_back(v[i]);
        }
        i++;
    }

    int minDiff =0;
    cout<<"First Array: ";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"  ";
        minDiff+=a[i];
    }
    cout<<"\nSecond Array: ";
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<"  ";
        minDiff-=b[i];
    }

    cout<<"\npossible minimum Difference: "<<minDiff;

}

int main(){

    cout<<"Enter no. greater than 2: ";
    int num;
    cin>>num;
    
    if(num<2) cout<<"NIKLO: "<<endl;
    else divideIntoTwoEqualSum(num);
    
    return 0;
}