#include <vector>
using namespace std;

class L075SortColors
{
private:
    /* data */
public:
    L075SortColors(/* args */);
    ~L075SortColors();

    void sortColors(vector<int> &nums)
    {
        static int red = 0, white = 1, blue = 2;
        int r = 0; // r指针之前元素为红
        int w = 0; // w指针为移动指针 当w为白色时移动w指针
        int b = nums.size() - 1; // b指针之后元素为蓝
        while (w <= b) {
            if (nums[w] == red) { // w 为红色 则与 r 交换
                swap(nums[w++], nums[r++]);
            } else if (nums[w] == blue) { // w 为蓝色 则与b交换
                swap(nums[w], nums[b--]);
            } else { // w为白色 则继续
                w++;
            }
        }
        return;
    }
};

L075SortColors::L075SortColors(/* args */) {}

L075SortColors::~L075SortColors() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L075SortColors.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{2, 0, 1};
//     L075SortColors SortColors;
//     SortColors.sortColors(nums);
//     for (int i : nums) { cout << i << endl; }
//     return 0;
// }