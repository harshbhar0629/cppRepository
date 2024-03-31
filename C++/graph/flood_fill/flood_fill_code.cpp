// https://leetcode.com/problems/flood-fill/
#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>> &img, int sr, int sc, int color, int target)
{
    if (sr < 0 | sc < 0 | sr >= img.size() | sc >= img[0].size())
        return;
    if (img[sr][sc] == color || img[sr][sc] != target)
        return;

    img[sr][sc] = color;

    f(img, sr - 1, sc, color, target);
    f(img, sr, sc - 1, color, target);
    f(img, sr + 1, sc, color, target);
    f(img, sr, sc + 1, color, target);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    f(image, sr, sc, color, image[sr][sc]);
    return image;
}

int main()
{

    return 0;
}