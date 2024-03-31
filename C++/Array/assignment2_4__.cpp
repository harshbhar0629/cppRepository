#include<iostream>
using namespace std;
int main(){
// 4. difference b/w even indices and odd indices i array
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // int seven=0,sodd=0;
    // for(int i=0;i<n;i++){
    //     if(i%2==0){
    //         seven+=arr[i];
    //     }
    //     else{
    //         sodd+=arr[i];
    //     }
    // }
    // cout<<"difference between odd and even indices is: "<<abs(sodd-seven);
  
    // 5. in even indices add 10 and odd indices multiply by 2 in array
    //  int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // } 
    // for(int i=0;i<n;i++){
    //     if(i%2==0){
    //         arr[i]+=10;
    //     }
    //     else arr[i]*=2;

    //     cout<<arr[i]<<"  ";
    // }
    int n;
    cin>>n;
    int arr[n];
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0,j=n-1;
    while(i<=j){
        if(arr[i]!=arr[j]){
            flag=false;
        cout<<"array is not palindrome";
    
            break;
        }
        i++,j--;
    }
    if(flag){
        cout<<"array is palindrome";
    }
   

    return 0;
}