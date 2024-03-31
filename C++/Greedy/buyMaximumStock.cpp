// https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({price[i],i+1});
        }
        
        sort(v.begin(),v.end());
        int count=0;
        
        for(int i=0; i<n; i++){
            int first = v[i].first;
            int second = v[i].second;
            if(k >= second*first){
                count+=second;
                k-=second*first;
            }
            else{
                while(second>0 and k <(first*second)){
                    second--;
                }
                k-=second*first;
                count+=second;
            }
        }
        return count;
    }
};

int main(){

    
    return 0;
}