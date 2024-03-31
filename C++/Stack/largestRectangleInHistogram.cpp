#include<bits/stdc++.h>
using namespace std;

void prev_and_smaller(int prevSmall[],int nextSmall[],int arr[],int n){
    stack<int>st;
    for(int i=0;i<n;i++){
        if(i==0){
            st.push(i);
            prevSmall[i] = -1;
            nextSmall[i]=n;
        }
        else{
            while(st.size()>0 and arr[i] < arr[st.top()]){
                nextSmall[st.top()] = arr[i];
                st.pop();
            }
            if(st.size()==0) prevSmall[i] = -1;
            else prevSmall[i] = arr[st.top()];
            nextSmall[i]=n;
            st.push(i);
        }
    }
    
}

int main(){
    int arr[] = {5,2,4,6,3,5};
    int n=6;

    int prevSmall[n], nextSmall[n];

    prev_and_smaller(prevSmall,nextSmall,arr,n);

    cout<<"prev"<<endl;
    for(int i=0;i<n;i++){
        cout<<prevSmall[i]<<"  ";
    }cout<<endl;

    cout<<"next"<<endl;
    for(int i=0;i<n;i++){
        cout<<nextSmall[i]<<"  ";
    }cout<<endl;
    
    //Area
    int maxArea = 0;
        
    for(int i=0;i<n;i++){
        int area = heights[i]*(next[i]- prev[i] -1);
        maxArea = max(area,maxArea);
    }
    
    return maxArea;

    // int l=0,b=0;
    // int area=0,maxArea=0;
    // for(int i=0;i<n;i++){
    //     b=arr[i];
    //     for(int j=i;j<n;j++){
    //         l = j-i+1;
    //         b = min(b,arr[j]);
    //         area = l*b;
    //         cout<<area<<endl;
    //         maxArea = max(maxArea,area);
    //     }
    // }
    // cout<<"max area is: "<<maxArea<<endl;
    return 0;
}