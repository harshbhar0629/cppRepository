#include<iostream>
using namespace std;
int main(){
//3 pointer approach
int n=9;
int arr[9]={2,1,0,2,2,1,1,0,0};
// for(int i=0;i<n;i++){
//     cin>>arr[i];
// }
int mid=0,lo=0,hi=n-1;
while(mid<=hi){
    if(arr[mid]==2){
        int temp=arr[hi];
        arr[hi]=arr[mid];
        arr[mid]=temp;
        hi--;   
    }
    else if(arr[mid]==0){
        int temp=arr[mid];
        arr[mid]=arr[lo];
        arr[lo]=temp;
        lo++,mid++;
    }
    else mid++;
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<"   ";
}

return 0;
}