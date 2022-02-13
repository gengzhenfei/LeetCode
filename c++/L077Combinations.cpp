#include <vector>
using namespace std;

class L077Combinations
{
private:
    /* data */
public:
    L077Combinations(/* args */);
    ~L077Combinations();

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> com;
        vector<vector<int>> res;
        backtrace(n, k, com, res, 1);

        return res;
    }

    void backtrace(int &n, int &k, vector<int> &com, vector<vector<int>> &res, int last)
    {
        if (com.size() == k) {
            res.push_back(com);
            return;
        }
        for (int i = last; i <= n; i++) {
            com.push_back(i);
            backtrace(n, k, com, res, i + 1);
            com.pop_back(); // 还原
        }
        return;
    }
};

L077Combinations::L077Combinations(/* args */) {}

L077Combinations::~L077Combinations() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L077Combinations.cpp"
// using namespace std;

// int main()
// {
//     int n = 1, k = 1;
//     L077Combinations Combinations;
//     vector<vector<int>> res = Combinations.combine(n, k);
//     for (auto v : res) {
//         cout << "[ ";
//         for (int i : v) { cout << i << " "; }
//         cout << "]" << endl;
//     }
//     return 0;
// }