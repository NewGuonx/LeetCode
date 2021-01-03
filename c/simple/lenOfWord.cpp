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
    int lengthOfLastWord(string s)
    {
        int c2 = s.size(), c1 = s.size(), lock = 0;
        for (int i = s.size() - 1; i > -1; i--)
        {
            if (!lock && isalpha(s[i]))
            {
                c2 = i;
                lock = 1;
            }
            if (lock && (s[i] == ' ' || i == 0))
            {
                c1 = (s[i] == ' ') ? i : -1;
                break;
            }
        }
        return c2 - c1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.lengthOfLastWord(" asd");
    return 0;
}