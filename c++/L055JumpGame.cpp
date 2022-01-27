#include <iostream>
#include <vector>
using namespace std;

class L055JumpGame
{
private:
    /* data */
public:
    L055JumpGame(/* args */);
    ~L055JumpGame();

    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1) return true; // 长度小于等于1 直接满足条件
        int max_i = 0; // 最远可到位置
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i > max_i) { return false; }
            max_i = max(max_i, i + nums[i]); // 更新最远可到位置
            if (max_i >= len - 1) { return true; }
        }

        return false;
    }
};

L055JumpGame::L055JumpGame(/* args */) {}

L055JumpGame::~L055JumpGame() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L055JumpGame.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1, 6, 3, 5, 1, 2, 6, 6, 0, 4, 8, 6, 0, 3, 2, 8, 7, 6, 5, 1, 7, 0, 3, 4, 8, 3,
//                      5, 9, 0, 4, 0, 1, 0, 5, 9, 2, 0, 7, 0, 2, 1, 0, 8, 2, 5, 1, 2, 3, 9, 7, 4, 7, 0, 0, 1, 8, 5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5};
//     L055JumpGame JumpGame;
//     bool result = JumpGame.canJump(nums);
//     cout << "true:" << true << " " << result << endl;
//     return 0;
// }