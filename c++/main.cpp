// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L047Permutations2.cpp"
using namespace std;

int main()
{
    vector<int> nums{2, 2, 1, 1};
    L047Permutations2 Permutations2;
    vector<vector<int>> result = Permutations2.permuteUnique(nums);
    for (vector<int> v : result) {
        cout << "[";
        for (int i : v) { cout << " " << i; }
        cout << " ]" << endl;
    }
    return 0;
}