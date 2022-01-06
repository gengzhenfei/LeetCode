#include <iostream>
#include <string>
#include <vector>
#include "L015ThreeSum.cpp"
using namespace std;

int main()
{
    // vector<int> list{-1, 0, 1, 2, -1, -4};
    // vector<int> list{-1, 0};
    // vector<int> list{1, -1, -1, 0};
    vector<int> list{-2, 0, 0, 2, 2};
    L015ThreeSum ThreeSum;
    vector<vector<int>> result = ThreeSum.threeSum(list);
    cout << "result.size() " << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "i=" << i << " ";
        for (auto j : result[i]) cout << j << " ";
        cout << endl;
    }

    return 0;
}