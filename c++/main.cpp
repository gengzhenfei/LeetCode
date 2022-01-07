#include <iostream>
#include "L018FourSum.cpp"
using namespace std;

int main()
{
    // vector<int> nums{1, 0, -1, 0, -2, 2};
    // int target = 0;
    // vector<int> nums{2, 2, 2, 2, 2};
    // int target = 8;
    // vector<int> nums{-3, -1, 0, 2, 4, 5};
    // int target = 0;
    // vector<int> nums{-2, -1, -1, 1, 1, 2, 2};
    // int target = 0;
    // vector<int> nums{-1, 0, 1, 2, -1, -4};
    // int target = -1;
    // vector<int> nums{1, -2, -5, -4, -3, 3, 3, 5};
    // int target = -11;
    // vector<int> nums{1000000000, 1000000000, 1000000000, 1000000000};
    vector<int> nums{0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000};
    int target = 1000000000;
    L018FourSum FourSum;
    vector<vector<int>> result = FourSum.fourSum(nums, target);
    for (auto i : result) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }

    return 0;
}