#include <vector>
using namespace std;

class L084LargestRectangleInHistogram
{
private:
    /* data */
public:
    L084LargestRectangleInHistogram(/* args */);
    ~L084LargestRectangleInHistogram();

    int largestRectangleArea(vector<int> &heights)
    {
        int largest = 0;
        vector<int> st; // 栈 用来存入单调增的元素的下标
        heights.insert(heights.begin(), 0); // 头部插入0
        heights.push_back(0); // 尾部插入0
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.back()] > heights[i]) { // 计算体积
                int top = st.back(); // 栈顶元素
                st.pop_back(); // 出栈
                int left = st.back() + 1; // 左
                int right = i - 1; // 右
                largest = max(largest, (right - left + 1) * heights[top]);
            }
            st.push_back(i); // 下标入栈
        }

        // 以下为暴力解法 超时
        // int largest = heights[0];
        // for (int i = 0; i < heights.size(); i++) { // 逐个元素遍历
        //     // dfs(heights, largest, i, i, heights[i]);
        //     between(heights, largest, i);
        // }

        return largest;
    }

    /**
     * 深度遍历 暴力解法
     */
    void dfs(vector<int> &heights, int &largest, int si, int ei, int min)
    {
        if (ei >= heights.size()) return;
        if (min > heights[ei]) { // 遇到更小的数字
            if (largest / (heights.size() - si) < heights[ei]) {
                min = heights[ei];
            } else {
                return;
            }
        }
        // min = min > heights[ei] ? heights[ei] : min;
        if (largest / (ei - si + 1) < min) { largest = (ei - si + 1) * min; }
        dfs(heights, largest, si, ei + 1, min);
    }

    /**
     * 区间解法
     */
    void between(vector<int> &heights, int &largest, int i)
    {
        int si = i - 1, ei = i + 1;
        while (si >= 0 && heights[si] >= heights[i]) { si--; }
        while (ei < heights.size() && heights[ei] >= heights[i]) { ei++; }
        int area = (ei - si - 1) * heights[i];
        if (largest < area) largest = area;
    }
};

L084LargestRectangleInHistogram::L084LargestRectangleInHistogram(/* args */) {}

L084LargestRectangleInHistogram::~L084LargestRectangleInHistogram() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L084LargestRectangleInHistogram.cpp"
// using namespace std;

// int main()
// {
//     vector<int> heights{2, 1, 5, 6, 2, 3};
//     L084LargestRectangleInHistogram LargestRectangleInHistogram;
//     int res = LargestRectangleInHistogram.largestRectangleArea(heights);
//     cout << res << endl;
//     return 0;
// }