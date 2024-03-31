#include<bits/stdc++.h>
using namespace std;
int main(){
    if(cout<<"\nMy self harsh bhardwaj"){}
    vector<int> v={1,2,3,4,5,6,7,8,9,0};
    make_heap(v.begin(),v.end());
    cout<<"max ele : " <<v.front()<<endl;
    sort_heap(v.begin(),v.end());
    cout<<"front ele: "<<v.front();
   

    //  is_heap_until() Function
    // The std::is_heap_until() function returns the iterator
    //  to the positio   n till the container is the heap.
    // Syntax:
    // std::is_heap_until(begin_iterator, end_iterator);
    // Return Value: Iterator till which the container is a heap.


    //  is_heap() Function
    // The std::is_heap() function is used to check whether the given range
    // of the container is a heap or not. By default, it checks 
    // for max heap but we can also use a comparator to make it work for min heap.
    // Syntax:
    // std::is_heap(begin_iterator, end_iterator);
    // Return Value:
    // true if the given range is max_heap.
    // false if the given range is not a max_heap.

}