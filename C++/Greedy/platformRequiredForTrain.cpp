// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int reqPlatform =1,maxReqPlatform=0;
    	int i=1,j=0;
    	
    	while(i<n and j<n){
    	    if(arr[i]<=dep[j]){
    	        reqPlatform++;
    	        i++;
    	    }
    	    else {
    	        reqPlatform--;
    	        j++;
    	    }
    	    maxReqPlatform = max(maxReqPlatform,reqPlatform);
    	}
    	return maxReqPlatform;
    }
};