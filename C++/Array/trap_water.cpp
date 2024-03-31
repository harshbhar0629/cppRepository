#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    cout<<"enter element";
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    
    int mx=-1;
    for(int i=0;i<n;i++){
        b[i]=mx;
        mx =max(mx,a[i]);
    }
     for(int i=0;i<n;i++){
        cout<<b[i]<<"  ";
    }
    cout<<endl<<mx<<endl;
    int mn=-1;
    for(int i=n-1;i>=0;i--){
        b[i]=mn;
        mn=max(mn,a[i]);
        if(a[i]==mx) break;
    }
     for(int i=0;i<n;i++){
        cout<<b[i]<<"  ";
    }
    mn=0;
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            mn+=b[i]-a[i];
        }
    }
    cout<<"trap consume water : "<<mn;
   
    // for(int i=0;i<n;i++){
    //     mx=0;
    //     for(int j=i+1;j<n;j++){
    //         mx=max(mx,a[j]);
    //     }
    //     c[i]=mx;
    //     if(i==n-1) c[i]=-1;
    // }
        
    // for(int i=n-1;i>=0;i--){
    //     c[i]=mx;
    //     mx=max(a[i],mx);
    // }
   
    // for(int i=0;i<n;i++){
    //     cout<<c[i]<<"  ";
    // }cout<<endl;
    
    // for(int i=0;i<n;i++){
    //     mx=min(b[i],c[i]);
    //     c[i]=mx;
    // }
    // for(int i=0;i<n;i++){
    //     cout<<c[i]<<"  ";
    // }cout<<endl;
    // mx=0;
    // for(int i=0;i<n;i++){
    //     if(a[i]<c[i]){
    //         mx+=c[i]-a[i];
    //     }
    // }
    // cout<<"trap consume water : "<<mx;


    return 0;
}