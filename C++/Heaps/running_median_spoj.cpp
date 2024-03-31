#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    scanf("%d", &t);
    while(t--){
        priority_queue<int> maxHp;
        priority_queue<int, vector<int>, greater<int>> minHp;
        int n;
        while (true)
        {

            scanf("%d", &n);
            if(n==0){
                break;
            }

            if (n == -1)
            {
                printf("%d\n", maxHp.top());
                maxHp.pop();
                if (minHp.size() > maxHp.size())
                {
                    int curr = minHp.top();
                    maxHp.push(curr);
                    minHp.pop();
                }
            }
            else
            {
                if (maxHp.size() == 0 || n <= maxHp.top())
                {
                    maxHp.push(n);
                    if (maxHp.size() > minHp.size() + 1)
                    {
                        int curr = maxHp.top();
                        maxHp.pop();
                        minHp.push(curr);
                    }
                }
                else
                {
                    minHp.push(n);
                    if (minHp.size() > maxHp.size())
                    {
                        int curr = minHp.top();
                        minHp.pop();
                        maxHp.push(curr);
                    }
                }
            }
           
        }
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int getMedian(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right)
// {
//     int totalSize = left.size() + right.size();
//     if (totalSize % 2 != 0)
//     {
//         // odd
//         return right.top();
//     }
//     else
//     {
//         // even
//         return left.top();
//     }
// }

// bool isBalanced(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right)
// {
//     return (left.size() == right.size()) or (left.size() + 1 == right.size());
// }

// void removeMedian(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right)
// {
//     if (left.size() == right.size())
//     {
//         // even
//         left.pop();
//     }
//     else
//     {
//         // odd
//         right.pop();
//     }
// }

// int main()
// {
//     // Fast io
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // Fast io
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         priority_queue<int> left;
//         priority_queue<int, vector<int>, greater<int>> right;
//         while (true)
//         {
//             int n;
//             cin >> n;
//             if (n == 0)
//                 break;
//             // do something
//             if (left.size() + right.size() == 0)
//             {
//                 // incoming element is the first;
//                 right.push(n);
//             }
//             else if (n == -1)
//             {
//                 // get the median
//                 cout << getMedian(left, right) << "\n";
//                 // remove the median
//                 removeMedian(left, right);
//             }
//             else
//             {
//                 int med = getMedian(left, right);
//                 if (n > med)
//                 {
//                     right.push(n);
//                     if (!isBalanced(left, right))
//                     {
//                         // imbalance caused by right
//                         int curr = right.top();
//                         right.pop();
//                         left.push(curr);
//                     }
//                 }
//                 else
//                 {
//                     left.push(n);
//                     if (!isBalanced(left, right))
//                     {
//                         // imbalance caused by left
//                         int curr = left.top();
//                         left.pop();
//                         right.push(curr);
//                     }
//                 }
//             }
//         }
//     }

//     return 0;
// }