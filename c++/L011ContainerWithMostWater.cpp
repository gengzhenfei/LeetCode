#include <vector>
#include <algorithm>

using namespace std;

class L011ContainerWithMostWater
{
private:
    /* data */
public:
    L011ContainerWithMostWater(/* args */);
    ~L011ContainerWithMostWater();

    /**
     * 算法思路：
     * 双指针，分别从头和尾开始向中间聚拢；不妨设指针i为头，指针j为尾；
     * 1. 初始 most = container = (j-i) * min(height[i], height[j])
     * 2. 将两个指针中较小的指针向中间移动一个位置，此时再次计算 container = (j-i) * min(height[i], height[j])， most = max(most, container);
     * 3. 重复执行2，直到i=j，最终most即为所求
     */
    int maxArea(vector<int> &height)
    {
        int most = 0;
        int height_len = height.size();
        int i = 0, j = height_len - 1;
        while (i < j) {
            int tmp = (j - i) * min(height[i], height[j]);
            most = max(most, tmp);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return most;
    }
};

L011ContainerWithMostWater::L011ContainerWithMostWater(/* args */) {}

L011ContainerWithMostWater::~L011ContainerWithMostWater() {}

// #include <iostream>
// #include <string>
// #include <vector>
// #include "L011ContainerWithMostWater.cpp"
// using namespace std;

// int main()
// {
//     vector<int> height{1, 2, 1};
//     L011ContainerWithMostWater ContainerWithMostWater;
//     cout << ContainerWithMostWater.maxArea(height) << endl;

//     return 0;
// }