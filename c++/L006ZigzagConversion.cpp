#include <iostream>
#include <string>
#include <vector>
using namespace std;

class L006ZigzagConversion
{
private:
    /* data */
public:
    L006ZigzagConversion(/* args */);
    ~L006ZigzagConversion();

    /**
     *
      解题思路： 找规律
      例如对一个4行的
        0     6      12       18
        1   5 7   11 13    17 19
        2 4   8 10   14 16    20
        3     9      15       21
      对 k = i%(2n-2)进行判断：
        k<=n-1时候，s[i]就属于第k行；
        k>n-1时候，s[i]就属于2n-2-k行；
     */
    string convert(string s, int numRows)
    {
        int s_len = s.size();
        if (s_len <= numRows || numRows == 1) return s;
        vector<string> result;
        for (int i = 0; i < numRows; i++) { result.push_back(""); }
        for (int i = 0; i < s_len; i++) {
            int k = i % (2 * numRows - 2);
            if (k > numRows - 1) k = 2 * numRows - 2 - k;
            result[k] += s[i];
        }
        string row_str;
        for (string str : result) row_str += str;
        return row_str;
    }
};

L006ZigzagConversion::L006ZigzagConversion(/* args */) {}

L006ZigzagConversion::~L006ZigzagConversion() {}

// include <iostream>
// #include "L006ZigzagConversion.cpp"
// using namespace std;

// int main()
// {
//     string s("PAYPALISHIRING");
//     int rows = 40;
//     L006ZigzagConversion ZigzagConversion;
//     cout << ZigzagConversion.convert(s, rows) << endl;

//     return 0;
// }