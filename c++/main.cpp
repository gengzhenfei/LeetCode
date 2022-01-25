// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L048RotateImage.cpp"
using namespace std;

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> matrix{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    L048RotateImage RotateImage;
    RotateImage.rotate2(matrix);
    return 0;
}