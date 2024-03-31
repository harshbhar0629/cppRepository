#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int>v{2,0,3,4,5,5,6,7,8,9};
    for(int i=2;i<129;i=pow(i,2)){
        cout<<" 1 ";
    }
    // auto it = binary_search(v.begin(),v.end(),8);
    // if(it){
    //     auto itr = lower_bound(v.begin(),v.end(),8);
    //     cout<<*itr;
    //     cout<<" found";
    // }
    // else{
    //     cout<<"not found";
    // }


    // vector<int> v={1,2,3,4,9,5,6,7,8,9};
    // vector<pair<int,int>> vp;
    // for(int i=0;i<v.size();i++){
    //     vp.push_back({v[i],i});
    // }
    // sort(vp.begin(),vp.end());
    // for(int i=0;i<vp.size();vp++)
    // *  *  *  *  *  *  *  1  *  *  *  *  *  *  * 
    // *  *  *  *  *  *  2  *  2  *  *  *  *  *  * 
    // *  *  *  *  *  3  *  3  *  3  *  *  *  *  * 
    // *  *  *  *  4  *  4  *  4  *  4  *  *  *  * 
    // *  *  *  5  *  5  *  5  *  5  *  5  *  *  * 
    // int n =5;
    // bool flag = false;
    // for(int i=1;i<=n;i++){
    //     for(int  j=1;j<=3*n;j++){
    //         if(j>=9-i and j<=7+i and flag) {
    //             cout<<" "<<i<<" ";
    //         }
    //         else {
    //              cout<<" * ";
    //         }
    //         flag = !flag;
    //     }cout<<endl;
    // }

    int n =8;
    int k=1;
    int count =0;
    // for(int i=1;i<=n;i++){
    //     count =k;
    //     for(int j=1;j<=2*i-1;j++){
    //         if(j%2==0) cout<<" * ";
    //         else  cout<<" "<<k++<<" ";
            
    //     }cout<<endl;
    // }
    
    // for(int i=n;i>=1;i--){
    //     k = count ;
    //     int rem = i-1;
    //     for(int j=1;j<=2*i-1;j++){
    //         if(j%2==0) cout<<" * ";
    //         else  cout<<" "<<k++<<" ";
    //     }cout<<endl;
    //     count = 2*rem;
    //     count = k- count-1;
    // }

    return 0;
}