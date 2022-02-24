// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L084LargestRectangleInHistogram.cpp"
using namespace std;

int main()
{
    vector<int> heights{2, 1, 5, 6, 2, 3};
    L084LargestRectangleInHistogram LargestRectangleInHistogram;
    int res = LargestRectangleInHistogram.largestRectangleArea(heights);
    cout << res << endl;
    return 0;
}