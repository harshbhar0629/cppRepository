#include<bits/stdc++.h>
using namespace std;

/*void f(int arr[],vector<int>&v,int x,int n){
   int low=0;int high=n-1;
   while(low<=high){
      int mid=(low+high)/2;
      if(arr[mid]==x){
         if(mid==0){
            v[0]=mid;
            break;
         }
         else if(arr[mid-1]!=x){
            v[0]=mid;
            break;
         }
         else high=mid-1;
      }
      else if(arr[mid]>x) 
         high=mid-1;
         else low=mid+1;
   }
   low=0,high=n-1;
   while(low<=high){
      int mid=(low+high)/2;
      if(arr[mid]==x){
         if(mid==n-1){
            v[1]=mid;
            break;
         }
         if(arr[mid+1]!=x){
            v[1]=mid;
            break;
         }
         else high=mid-1;
      }
      else if(arr[mid]>x) 
         high=mid-1;
         else low=mid+1;
   }
   cout<<v[0] <<"   "<<v[1];


}

int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   vector<int>v(2,-1);
   int x;
   cout<<"target";
   cin>>x;
   f(arr,v,x,n);
   
   return 0;
}*/
int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   int low=0,high=n-1;
   while(low<=high){
      int mid=(low+high)/2;
      if(arr[mid]==mid+1)low=mid+1;
     
      else high=mid-1;
   }
   cout<<arr[high];
   
   return 0;
}
