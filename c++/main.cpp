// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L090Subsets2.cpp"
using namespace std;

int main()
{
    vector<int> nums{2, 1, 2};
    L090Subsets2 Subsets2;
    vector<vector<int>> res = Subsets2.subsetsWithDup(nums);
    for (vector<int> v : res) {
        cout << "[ ";
        for (int i : v) cout << i << " ";
        cout << "]" << endl;
    }
    return 0;
}