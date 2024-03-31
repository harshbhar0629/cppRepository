#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>st;
    int arr[]= {3,1,2,5,4,6,2,3};
    int n=  sizeof(arr)/sizeof(arr[0]);
    int ans[n];
    // -1 3 3 -1 5 -1 6 6
    // for previous greater element we can traverse reverse in array and pop ans push apply the condition
  
    for(int i=0;i<n;i++){
        if(i==0){
            ans[i] = -1;
            st.push(arr[i]);
        }
        else {
            while(st.size()>0 and arr[i] >= st.top()){
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
    
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"  ";
    }cout<<endl;
    
    return 0;

}