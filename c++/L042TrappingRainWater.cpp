#include <vector>
#include <iostream>
using namespace std;

class L042TrappingRainWater
{
private:
    /* data */
public:
    L042TrappingRainWater(/* args */);
    ~L042TrappingRainWater();

    /**
     * 思路：
     * 如果 i+1 < i, 则寻找第一个大于i高度的柱子索引，或后续柱子中最高的一个柱子索引；
     * 否则 i+1 >= i, 则i++ 跳过当前柱子。
     */
    int trap(vector<int> &height)
    {
        int len = height.size();
        int result = 0;
        int i = 0;
        while (i < len) {
            int hi = i + 1; // 当前柱子之后最高柱子的索引
            int fhi = i; // 第一个高于当前柱子的柱子索引
            if (i + 1 < len && height[i + 1] < height[i]) { // 当前柱子高度大于下一个柱子高度
                for (int j = i + 1; j < len; j++) {
                    if (height[j] >= height[hi]) hi = j;
                    if (height[j] >= height[fhi] && fhi == i) fhi = j;
                }
                if (fhi > i) { // 找到第一个高于当前柱子的柱子索引 则最高柱子的索引hi一定大于等于fhi
                    result += accumulate(height, i, fhi);
                    i = fhi;
                } else if (hi >= i + 1) { // hi为当前之后最高的一个柱子
                    result += accumulate(height, i, hi);
                    i = hi;
                } else {
                    return result;
                }
            } else { // 当前高度小于下一个柱子高度 则跳过当前柱子
                i++;
            }
        }
        return result;
    }

    int accumulate(vector<int> &height, int start, int end)
    {
        int m = min(height[start], height[end]);
        int acc = 0;
        for (int i = start + 1; i < end; i++) { acc += m - height[i]; }
        // cout << "start: " << start << " end: " << end << " m: " << m << " acc: " << acc << endl;
        return acc;
    }
};

L042TrappingRainWater::L042TrappingRainWater(/* args */) {}

L042TrappingRainWater::~L042TrappingRainWater() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L042TrappingRainWater.cpp"
// using namespace std;

// int main()
// {
//     // vector<int> height{4, 2, 0, 3, 2, 5};
//     vector<int> height{5, 4, 1, 2};
//     L042TrappingRainWater TrappingRainWater;
//     int result = TrappingRainWater.trap(height);
//     cout << result << endl;
//     return 0;
// }