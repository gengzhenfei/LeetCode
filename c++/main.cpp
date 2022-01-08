#include <iostream>
#include "L006ZigzagConversion.cpp"
using namespace std;

int main()
{
    string s("PAYPALISHIRING");
    int rows = 40;
    L006ZigzagConversion ZigzagConversion;
    cout << ZigzagConversion.convert(s, rows) << endl;

    return 0;
}