#include<bits/stdc++.h>
#include<set>
using namespace std;
int main(){

    //declaration
    set<int> s;

    // insertion
    s.insert(3);
    s.insert(2);
    s.insert(9);

    cout<<s.size()<<endl;

    // contains unique value
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(6);
    s.insert(3);
    cout<<s.size()<<endl;

    // TRAVERSE   ::    BY DEFAULT VALUE ARE INCREASING ORDER
    // set<int>::iterator it;
    // for(it = s.begin();it!=s.end();it++){
    //     cout<<*it<<"  ";
    // }cout<<endl;


    for(auto value: s){
        cout<<value<<"  ";
    }cout<<endl;

    // deletion of element
    // s.erase(1);
    // cout<<s.size()<<endl;

    // s.erase(2);
    
    // delete range
    auto start_itr = s.begin();
    advance(start_itr,2);
    auto end_itr = s.end();
    end_itr--;
    // before 1 2 3 4 6 9
    s.erase(start_itr , end_itr);
    // after erase 1 2 9
    for(auto value: s){
        cout<<value<<"  ";
    }cout<<endl;


    // find
    if(s.find(3)!=s.end()){
        cout<<"Present "<<endl;
    }
    else{
        cout<<"not present "<<endl;
    }



    return 0;

}