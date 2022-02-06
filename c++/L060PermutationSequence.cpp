#include <iostream>
#include <string>
#include <vector>
using namespace std;

class L060PermutationSequence
{
private:
    /* data */
public:
    L060PermutationSequence(/* args */);
    ~L060PermutationSequence();

    string getPermutation(int n, int k)
    {
        string nums, mark;
        for (int i = 1; i <= n; i++) { // 初始化数据
            nums.push_back('0' + i);
            mark.push_back('0');
        }
        string result;
        dfs(nums, k, "", mark, result);
        return result;
    }

    void dfs(string &nums, int &k, string res, string mark, string &result)
    {
        if (res.size() == nums.size()) {
            k--;
            // cout << "k:" << k << " res:" << res << endl;
            if (0 == k) { // 符合条件的结果
                result = res;
                return;
            }
        }
        for (int j = 0; j < nums.size(); j++) {
            if (mark[j] == '0') {
                res.push_back(nums[j]);
                mark[j] = '1';
                dfs(nums, k, res, mark, result);
                if (0 == k) { return; } // 提前结束
                res.pop_back(); // 恢复
                mark[j] = '0';
            }
        }
    }
};

L060PermutationSequence::L060PermutationSequence(/* args */) {}

L060PermutationSequence::~L060PermutationSequence() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L060PermutationSequence.cpp"
// using namespace std;

// int main()
// {
//     int n = 4, k = 9;
//     L060PermutationSequence PermutationSequence;
//     string result = PermutationSequence.getPermutation(n, k);
//     cout << result << endl;
//     return 0;
// }