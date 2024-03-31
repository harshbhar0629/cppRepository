#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){

    map<int,int> mp;
    int a=1,b=2;
    mp.insert(make_pair(a++,b++));
    mp.insert(make_pair(a++,b++));
    mp.insert(make_pair(a++,b++));
    mp.insert(make_pair(a++,b++));
    mp.insert(make_pair(a++,b++));
    mp.insert(make_pair(a++,b++));

    // print simple
    // map<int,int>::iterator it ;
    // for(it = mp.begin();it!=mp.end();it++){
    //     cout<<it->first <<"  "<<it->second<<endl;
    // }

    map<int,int>::iterator it =  mp.begin();
    for(; it != mp.end() ; it++){
        cout<<it->first <<"  "<<it->second<<endl;
    }



    // traverse in reverse direction
    map<int,int>::reverse_iterator r ;
    for(itr = mp.rbegin();itr!=mp.rend();itr++){
        cout<<itr->first <<"  "<<itr->second<<endl;
    }

}