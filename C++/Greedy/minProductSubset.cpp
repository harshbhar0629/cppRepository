#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int minPdt(vector<int>& arr){

    int countNeg =0,countPos=0,countZero=0;
    int pdtPos=1,pdtNeg=1,largestNeg=INT_MIN;
   
    for(int i=0;i<arr.size();i++){
     
        if(arr[i]>0){
            countPos++;
            pdtPos *= arr[i];
        }
        if(arr[i]==0) countZero++;
        if(arr[i]<0){
            countNeg++;
            pdtNeg *= arr[i];
            largestNeg = max(largestNeg,arr[i]);
        }
    }

    if(countNeg==0){
      
        if(countZero>0){
            return 0;
        }
        else {
            auto ans = min_element(arr.begin(),arr.end());
            return *ans;
        }
    }
    else {
    
        if(countNeg%2==0){
            return (pdtNeg/largestNeg)*pdtPos;
        }
        else{
            return pdtPos*pdtNeg;
        }
    }
}
int main(){
    vector<int> v={1,2,3,0,4,-1,-5,-2};
    cout<<minPdt(v);
}
