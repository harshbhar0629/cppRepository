#include <iostream>
using namespace std;
int main()
{
     int n=5;
     cout << "enter size";
     // cin >> n;
     cout << "enter element";
     int arr[n] = {1,2,3,4,5};
     // for (int i = 0; i < n; i++)
     //      cin >> arr[i];
     int i = 0, jump = 0;
     while (i < n)
     {
          jump++;
          i = i + arr[i];
     }
}