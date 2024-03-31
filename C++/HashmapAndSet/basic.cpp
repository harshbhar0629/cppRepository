#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
    multimap<int,int>mp;
    unordered_set<int>s;
    s.insert(1);
    if(s.find(1)!=s.end()) cout<<1;
    // mp.insert({1,1});
    // mp.insert({1,1});
    // mp.insert({1,1});
    // mp.insert({1,1});
    // mp.insert({1,1});
    // // mp.erase(1);
    // // map<int,int> mp;
    // // mp.insert({1,1});
    // // mp.insert({1,2});
    // // mp.insert({2,3});
    // // mp.insert({1,9});
    // for(auto it:mp){
    //     cout<<it.first<<endl;
    // }

    //  declaration of both map
    // unordered_map<string,int> mp;
    // cout<<mp.count["hi"];
    // map<int,int> m;
    // cout<<"size "<<sizeof(m)<<endl;
    // cout<<"max " <<mp.max_size()<<endl;
    // // types of way to insert
    // // 1
    // pair<string,int> p = make_pair("harsh",1);
    // mp.insert(p);
    // auto i = mp.find("harsh") ;
    // // 2
    // pair<string,int> p2("har har mahadev",2);
    // mp.insert(p2);
    // // 3
    // mp["hi"] = 3;
    // // #Note : in case if you insert two times same element then it will update not create..
    // m.insert({1,1});


    // // searching
    // // special prop about map if we find unknown from map it will add that value in our size
    // cout<<"harsh find  "<< mp["harsh"] <<endl;
    // cout<<"2nd hi find  "<< mp.at("hi")<<endl;
    // // if we find not exist element then
    // // cout<< mp.at("unknown")<<endl; //if we use at function in not exist ele then it will show error
    // cout<<mp["unknown"]<<endl; //it will give zero
    // cout<< mp.at("unknown")<<endl;  //this will give zero



    // // count 
    // cout<<" harsh count  "<<mp.count("harsh")<<endl;



    // // erase 
    // cout<<"mp size : "<<mp.size()<<endl;
    // mp.erase("hi");
    // cout<<"mp size after erase : "<<mp.size()<<endl;



    // //traverse the map either ordered or unordered
    // // in unordered map it will print non - sequence its first value anythinn=g in the entire map
    // // 1
    // for(auto it: mp){
    //     cout<<"mp.first : "<<it.first <<"   mp.second : "<<it.second<<endl;
    // }
    // // 2 way
    // unordered_map<string,int> :: iterator it = mp.begin();
    // while(it!=mp.end()){
    //     cout<<"mp.first : "<<it->first <<"   mp.second : "<<it->second <<endl;
    //     it++;
    // }
    // cout<<"size "<<sizeof(m)<<endl;

}