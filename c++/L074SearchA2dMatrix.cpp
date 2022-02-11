#include <vector>
using namespace std;

class L074SearchA2dMatrix
{
private:
    /* data */
public:
    L074SearchA2dMatrix(/* args */);
    ~L074SearchA2dMatrix();

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int l = 0;
        int rows = matrix.size();
        for (; l < rows && matrix[l][0] <= target; l++) {}
        if (l == 0 && matrix[l][0] != target) return false;
        cout << l << endl;
        // 在第 l-1 行进行二分查找
        l--;
        int low = 0, high = matrix[l].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[l][mid] == target) {
                return true;
            } else if (matrix[l][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};

L074SearchA2dMatrix::L074SearchA2dMatrix(/* args */) {}

L074SearchA2dMatrix::~L074SearchA2dMatrix() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L074SearchA2dMatrix.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
//     int target = 3;
//     L074SearchA2dMatrix SearchA2dMatrix;
//     bool res = SearchA2dMatrix.searchMatrix(matrix, target);
//     cout << "true:" << true << " " << res << endl;
//     return 0;
// }