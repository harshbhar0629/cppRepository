#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>st;
    int arr[]= {100,80,60,70,60,75,85};
    int n=  sizeof(arr)/sizeof(arr[0]);
    int ans[n];
  
    for(int i=0;i<n;i++){
        if(i==0){
            ans[i] = -1;
            st.push(i);
        }
        else {
            while(st.size()>0 and arr[i] >= arr[st.top()]){
                st.pop();
            }

            if(st.size()==0){ 
                ans[i] = -1;
            }
            else{ 
                ans[i] = st.top();
            }
            st.push(i);
        }
    }
    
    for(int i=0;i<n;i++){
        ans[i] = i- ans[i]; 
        cout<<ans[i]<<"  ";
    }cout<<endl;
    return 0;
}