#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"eter number";
    cin>>n;
    cout<<n<<endl;
    int *p=&n;
    cout<<(*p)++;    
    cout<<n;    
}