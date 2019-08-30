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
    string addBinary(string a, string b)
    {
        int n = max(a.size(), b.size()), carry = 0;
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            const int bit_a = (i < a.size() ? a[i] - '0' : 0);
            const int bit_b = (i < b.size() ? b[i] - '0' : 0);
            const int ans_bit = (bit_a + bit_b + carry) % 2;
            carry = (bit_a + bit_b + carry) / 2;
            ans.insert(ans.begin(), ans_bit + '0');
        }
        if (carry == 1)
            ans.insert(ans.begin(), '1');
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.addBinary("10001", "10111");
    return 0;
}