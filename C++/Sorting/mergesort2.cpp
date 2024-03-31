#include<bits/stdc++.h>
#include<vector>
using namespace std;
// without space O(nlogn) //merge mein v bhejo low bhejo and high bhejo or wo mid hoga 2 call hogi mid tk mid+1 s dusre
// merge all m ek b vector bnao phir usme element dal do a vector s hi jisme hmara low mid high jayega
// i jo hoga wo low s mid tk jayega j jo hoga mid+1 s high tk jayega phir b k element a m dal do
void mergeall(vector<int>& v,vector<int>& a,vector<int>& b){
    int n=v.size();
    int n1=a.size();
    int n2=b.size();
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]>b[j]){
            v[k]=b[j];
            k++,j++;
        }
        else{
            v[k]=a[i];
            k++,i++;
        }
    }
    if(i<n1){
        while(i<n1){
            v[k]=a[i];
            k++,i++;
        }
    }
    else{
        while(j<n2){
            v[k]=b[j];
            k++,j++;
        }
    }
   
}

void merge(vector<int>& v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2;
    int n2=n-n/2;
    vector<int> a(n1), b(n2);
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int j=0;j<n2;j++){
        b[j]=v[n1+j];
    }
    merge(a);
    merge(b);
    mergeall(v,a,b);
  
}

int main(){
    int arr[]={2,3,1,7,8,9,6,4,5};
    int n=9;
    vector<int> v(arr,arr+n);
    merge(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }
}
