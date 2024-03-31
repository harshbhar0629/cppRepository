#include <iostream>
#include <vector>
#include <utility>
 using namespace std;
int main()
{

    int arr[5]={1,2,3,2,1};
        int a=arr[0];
    for(int i=1;i<5;i++){
        a= a^arr[i];
    }
    cout<<a;
    // vector<pair<int,int>>v;
    // v.push_back({1,3});
    // // v.second=2;
    // cout<<v[0].first;

    // // vector<pair<int, int>> pairs = {{1, 2}, {3, 4}, {5, 6}};
 
    // // // add a new pair to vector using emplace_back()
    // // pairs.emplace_back(7, 8);
 
    // // // print all pairs
    // // for (auto p: pairs) {
    // //     cout << "(" << p.first << ", " << p.second << ") ";
    // // }
 
    // return 0;
}
