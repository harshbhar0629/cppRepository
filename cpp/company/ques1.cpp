#include <bits/stdc++.h>
using namespace std;

int main(){
    int *app, *bpp;
    bpp = malloc(8);
    *bpp = 6;
    *app = free(bpp);
    cout << *app;

    return 0;
}