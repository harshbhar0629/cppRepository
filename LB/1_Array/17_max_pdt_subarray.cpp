// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    if(n==1) return arr[0];
	    long long int maxi = arr[0], mini = arr[0], ans = arr[0];
	    for(int i=1; i<n; i++){
	        if(arr[i]<0){
	            swap(maxi, mini);
	        }
	        maxi = max(arr[i]*maxi, arr[i]*1ll);
	        mini = min(arr[i]*mini, arr[i]*1ll);
	        ans = max(maxi, ans);
	    }
	    return ans;
	}
};

int main(){
    

    return 0;
}