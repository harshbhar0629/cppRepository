#include<iostream>
#include<vector>
#include<list>
#include<bits/stdc++.h>
using namespace std;

class Hashing{

vector<list<int> > Hashtable;
int size ;

public:

    Hashing(int size){
        this->size= size;
        Hashtable.resize(size);
    }

    int hashValue(int key){
        return key%size;
    }

    void addKey(int key){
        int idx = hashValue(key);
        Hashtable[idx].emplace_back(key);
        cout<<key <<" is added"<<endl;
    }

    list<int>::iterator searchKey(int key){
        int idx = hashValue(key);
        return find(Hashtable[idx].begin() , Hashtable[idx].end() , key);
    }

    void deleteKey(int key){
        int idx = hashValue(key);
        if(searchKey(key)!=Hashtable[idx].end()){
            Hashtable[idx].erase(searchKey(key));
            cout<<key<< " is deleted "<<endl;
        }
        else {
            cout<<key<<" is not present in the hash table!! "<<endl;
        }
    }



};

int main(){
    Hashing *h = new Hashing(10);
    h->addKey(2);
    h->addKey(3);
    h->addKey(5);
    h->addKey(6);
    h->addKey(6);
    h->addKey(16);
    h->deleteKey(16);
    h->deleteKey(6);
    h->deleteKey(16);

}