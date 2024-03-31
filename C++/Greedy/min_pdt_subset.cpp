#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& v){

    int cz = 0, cp = 0, cn = 0;
    int n = v.size();
    for(int i=0; i<n; i++){
        if(v[i] == 0){
            cz ++ ;
        }
        else if (v[i] < 0){
            cn++;
        }
        else{
            cp++;
        }
    }

    // no negative
    if(cn == 0){
        if(cz > 0){
            return 0;
        }else{
            return *min_element(v.begin(), v.end());
        }
    }
    else{
        int pdt = 1;
        int mini = INT_MIN;
        for (int i = 0; i < n; i++){
            if (v[i] == 0){
                continue;
            }
            if(v[i] < 0)  mini = max(mini, v[i]);
            pdt *= v[i];
        }
        if(cn%2 == 1){
            return pdt;
        }
        else{
            return pdt / mini;
        }
    }

}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << f(v);

    return 0;
}