#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(int arr[],int n){
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            ans[i] = -1;
            st.push(arr[i]);
        }
        else {
            while(st.size()>0 and arr[i] <= st.top()){
                st.pop();
            }

            if(st.size()==0){ 
                ans[i] = -1;
            }
            else{ 
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
    }
    return ans;

}

int main(){
    stack<int>st;
    int arr[]= {4,6,3,1,0,9,5,6,7,3,2};
    int n=  sizeof(arr)/sizeof(arr[0]);
    // next greater

    // for(int i=n-1;i>=0;i--){
    //     if(i==n-1){
    //         ans[i] = -1;
    //         st.push(arr[i]);
    //     }
    //     else {
    //         while(st.size()>0 and arr[i] >= st.top()){
    //             st.pop();
    //         }

    //         if(st.size()==0){ 
    //             ans[i] = -1;
    //         }
    //         else{ 
    //             ans[i] = st.top();
    //         }
    //         st.push(arr[i]);
    //     }
    // }

    vector<int > v = nextSmaller(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<v[i]<<"  ";
    }cout<<endl;
    
    return 0;

}
