// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L078Subsets.cpp"
using namespace std;

int main()
{
    vector<int> nums{1, 2, 3};
    L078Subsets Subsets;
    vector<vector<int>> res = Subsets.subsets(nums);
    for (auto v : res) {
        cout << "[ ";
        for (int i : v) { cout << i << " "; }
        cout << "]" << endl;
    }
    return 0;
}