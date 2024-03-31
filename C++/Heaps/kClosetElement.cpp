#include<bits/stdc++.h>
using namespace std;
int main(){

    int n ,k;
    cin>>n>>k;
    int arr[n][2];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++)
            cin>>arr[i][j];
    }

    vector<vector<int>> v;
    for(int i=0;i<k;i++){
        double c=INT_MAX;
        for(int j=0;j<n;j++){
            int x = abs(arr[j][0]);
            if(x==INT_MAX) continue;
            int y = abs(arr[j][1]);
            double sqr = sqrt(x*x + y*y);
            if(c>sqr){
                if(c==INT_MAX){
                    v.push_back({arr[j][0] , arr[j][1]});
                }
                else{
                    v.pop_back();
                    v.push_back({arr[j][0] , arr[j][1]});
                }
                arr[j][0]= INT_MAX;
                c= sqr;
            }
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i][0]<<"  "<<v[i][1]<<endl;
    }

}