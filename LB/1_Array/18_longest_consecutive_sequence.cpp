// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n){
        unordered_set<int>s;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            s.insert(arr[i]);
        }
        for(int i=0; i<n; i++){
            if(s.find(arr[i]-1) == s.end()){
                int num = arr[i];
                int len =0;
                while(s.find(num)!=s.end()){
                    num++, len++;
                }
                maxLen = max(maxLen , len);
            }
        }
        return maxLen;
    }
};


int main(){
    

    return 0;
}