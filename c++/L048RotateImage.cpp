#include <iostream>
#include <vector>
using namespace std;

class L048RotateImage
{
private:
    /* data */
public:
    L048RotateImage(/* args */);
    ~L048RotateImage();

    /**
     * 方法一 逐个元素旋转
     */
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int k = 0; k < n / 2; k++) {
            for (int i = k; i < n - 1 - k; i++) {
                int ki = matrix[k][i];
                matrix[k][i] = matrix[n - 1 - i][k];
                matrix[n - 1 - i][k] = matrix[n - 1 - k][n - 1 - i];
                matrix[n - 1 - k][n - 1 - i] = matrix[i][n - 1 - k];
                matrix[i][n - 1 - k] = ki;
            }
        }
        // for (vector<int> v : matrix) {
        //     cout << "[";
        //     for (int i : v) { cout << " " << i; }
        //     cout << " ]" << endl;
        // }
    }

    /**
     * 方法二 先转置再镜像对称 相当于图片右旋转90度
     */
    void rotate2(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) { swap(matrix[i][j], matrix[j][i]); }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) { swap(matrix[i][j], matrix[i][n - 1 - j]); }
        }
        for (vector<int> v : matrix) {
            cout << "[";
            for (int i : v) { cout << " " << i; }
            cout << " ]" << endl;
        }
    }
};

L048RotateImage::L048RotateImage(/* args */) {}

L048RotateImage::~L048RotateImage() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L048RotateImage.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     // vector<vector<int>> matrix{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
//     L048RotateImage RotateImage;
//     RotateImage.rotate2(matrix);
//     return 0;
// }