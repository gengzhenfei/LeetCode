#include <vector>
using namespace std;

class L027RemoveElement
{
private:
    /* data */
public:
    L027RemoveElement(/* args */);
    ~L027RemoveElement();
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        int dup = 0; // 移除重复数
        for (int i = 0; i < len; i++) {
            if (nums[i] == val) {
                dup++;
            } else if (dup != 0) {
                nums[i - dup] = nums[i];
            }
        }
        return len - dup;
    }
};

L027RemoveElement::L027RemoveElement(/* args */) {}

L027RemoveElement::~L027RemoveElement() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L027RemoveElement.cpp"
// using namespace std;

// int main()
// {
//     // 构造测试数据
//     vector<int> v{0, 1, 2, 2, 3, 0, 4, 2};
//     int val = 2;
//     L027RemoveElement RemoveElement;
//     int result = RemoveElement.removeElement(v, val);
//     cout << result << endl;
//     for (auto i : v) cout << i << endl;

//     return 0;
// }