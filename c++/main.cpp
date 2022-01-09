#include <iostream>
#include "L022GenerateParentheses.cpp"
using namespace std;

int main()
{
    int n = 3;
    L022GenerateParentheses GenerateParentheses;
    vector<string> result = GenerateParentheses.generateParenthesis(n);
    for (auto i : result) cout << i << endl;

    return 0;
}