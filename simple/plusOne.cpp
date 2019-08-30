// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int i = digits.size() - 1, carry = 0;
        ++digits[i];
        if (digits[i] < 10)
            return digits;
        for (; i > -1; i--)
        {
            digits[i] += carry;
            if (digits[i] < 10)
                return digits;
            else
            {
                digits[i] %= 10;
                carry = 1;
            }
        }
        if (i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n[] = {9, 9, 9};
    vector<int> c(n, n + 3);
    Solution s;
    s.plusOne(c);
    return 0;
}