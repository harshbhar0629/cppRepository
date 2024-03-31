#include <bits/stdc++.h>
#include <queue>
using namespace std;
void* operator new(std::size_t size){
    std::cout<<"stored in heap \n";
    return malloc(size);
}
int main()
{
    queue<int> qu;
    
    qu.push(1);
    qu.push(2);
    qu.push(1);
    cout << sizeof(qu) << "  ";
    qu.push(2);
    qu.push(1);
    qu.push(2);
    qu.push(1);
    qu.push(2);
    qu.push(1);
    qu.push(2);
    qu.push(1);
    qu.push(2);

    cout << "qu back-> " << qu.back() << "\n";
    cout << "queue size-> " << qu.size() << "\n";
    cout << "front ele-> " << qu.front() << "\n";
    qu.pop();
    cout << "front ele-> " << qu.front() << "\n";
    cout<<"queue ele are: ";
    // while(qu.size()>0){
    //     cout<<qu.front()<<"  ";
    //     qu.pop();
    // }
    for(int i=0;i<qu.size();i++){
        int x =qu.front();
        qu.pop();
        cout<<x<<"  ";
        qu.push(x);
    }
    return 0;
}