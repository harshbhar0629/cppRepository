#include <bits/stdc++.h>
using namespace std;


int n ,m;
vector<vector<char>>grid;
    

// Approach-1
bool canReachDest1(){
    
    int i=0, j=0;
    int stepCount=0;
    int maxStep = n*m+2;

    while(stepCount<=maxStep){
        if(grid[i][j]=='r'){
            j++;
        }
        else if(grid[i][j]=='l'){
            j--;
        }
        else if(grid[i][j]=='u'){
            i--;
        }
        else{
            i++;
        }

        // check validation
        if(i<0 || j<0 || i>=n || j>=m) return false;
        // destination
        if(i==n-1 and j==m-1) return true;
        // increase our steps by one
        stepCount++;
    }
    return false;
}


// Approach-2
bool canReachDest2(){
    
    int i=0, j=0, a=0, b=0;
    //  where i and j just represent slow pointer and a and b 
    // represent just fast pointer bcoz it increase by one
    int stepCount=0;
    int maxStep = n*m+2;

    while(stepCount<=maxStep){
        if(grid[i][j]=='r'){
            j++;
        }
        else if(grid[i][j]=='l'){
            j--;
        }
        else if(grid[i][j]=='u'){
            i--;
        }
        else{
            i++;
        }

        // check validation
        if(i<0 || j<0 || i>=n || j>=m) return false;

        for(int k=0; k<2; k++){
            if(grid[a][b]=='r'){
                b++;               
            }
            else if(grid[a][b]=='l'){
                b--;
            }
            else if(grid[a][b]=='u'){
                a--;
            }
            else{
                a++;
            }
            // check validation
            if(a<0 || b<0 || a>=n || b>=m) return false;
            if(i==a and j==b) return false;
            // destination
            if(a==n-1 and b==m-1) return true;
        }

        // increase our steps by one
        stepCount++;
    }

    return false;

}



// it contains only L,R,U,D
int main(){
    
    cin>>n>>m;
    grid.resize(n,vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    cout<<canReachDest1();

    return 0;
}