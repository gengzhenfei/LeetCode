// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L077Combinations.cpp"
using namespace std;

int main()
{
    int n = 1, k = 1;
    L077Combinations Combinations;
    vector<vector<int>> res = Combinations.combine(n, k);
    for (auto v : res) {
        cout << "[ ";
        for (int i : v) { cout << i << " "; }
        cout << "]" << endl;
    }
    return 0;
}