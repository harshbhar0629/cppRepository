#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,-3,-4,-7,6,7,8,-6,-4};
    int n= sizeof(arr)/sizeof(arr[0]);
    int k=3;
    // 0,-3,-3,-3,-4,-7,0,-6,-6
    vector<int>v;
    int p=-1;
    int j=0,i=1;
    for(;j<k;j++){
        if(arr[j]<0){
            p=j;
            break;
        }
    }
    if(p==-1){
        v.push_back(0);
    }
    else{
        v.push_back(arr[p]);
    }
    j=k;
    while(j<n){
        if(p >= i){
            v.push_back(arr[p]);
        }
        else{
            // linearly tranverse throughout the loop so it willnot affect the time complexity..
            for(p=i;p<=j;p++){
                if(arr[p]<0){
                    break;
                }
            }
            if(p==j+1){
                v.push_back(0);
            }
            else{
                v.push_back(arr[p]);
            }
        }
        i++,j++;
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }
    return 0;
}