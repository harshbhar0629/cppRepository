#include <bits/stdc++.h>
using namespace std;
/**
 * https://www.lintcode.com/problem/range-addition/description
    Given:
    length = 5,
    updates =
    [
    [1,  3,  2],
    [2,  4,  3],
    [0,  2, -2]
    ]
    return [-2, 0, 3, 5, 3]
*/

class Solution{
public:
    /**
     * @param n: the length of the array
     * @param updates: update operations [i, j, val]
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int n, vector<vector<int>> &updates){
        vector<int> ans(n, 0);
        for(auto& upd: updates){
            int i = upd[0];
            int j = upd[1] + 1;
            int val = upd[2];
            ans[i] += val;
            if(j<n){
                ans[j] -= val;
            }
        }

        for (int i = 1; i < n; i++){
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    int m = 3;
    vector<vector<int>> upd(m, vector<int>(3));
    for (int i = 0; i<m; i++){
        for (int j = 0; j < 3; j++){
            cin >> upd[i][j];
        }
    }

    Solution s;
    vector<int> ans = s.getModifiedArray(n, upd);
    for (int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}