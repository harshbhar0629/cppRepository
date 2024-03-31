#include<iostream>
using namespace std ;
// void sub(string s,string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }
//     string ros=s.substr(1);
//     sub(ros,ans+s[0]);
//     sub(ros,ans);
// }
// int main(){
//     string s;
//     cout<<"enter string name : ";
//     getline(cin,s);
//     sub(s,"");

// }
#include<vector>
void f(int arr[],int n,int i,int sum,vector<int> &v){
    if(i==n){
        v.push_back(sum);
        return ;
    }
    f(arr,n,i+1,sum+arr[i],v);
     f(arr,n,i+1,sum,v);
}
int main(){
    int n;
    cout<<"enter size ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector <int> v;
    f(arr,n,0,0,v );
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }

}