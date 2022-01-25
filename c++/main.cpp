// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L046Permutations.cpp"
using namespace std;

int main()
{
    vector<int> nums{1, 2, 3};
    L046Permutations Permutations;
    vector<vector<int>> result = Permutations.permute(nums);
    for (vector<int> v : result) {
        cout << "[";
        for (int i : v) { cout << " " << i; }
        cout << " ]" << endl;
    }
    return 0;
}