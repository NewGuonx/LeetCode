// author - newguo@sonaspy.cn
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
    bool isValid(string s)
    {
        if (s.size() == 1)
            return false;
        unordered_map<char, char> mp;
        stack<char> S;
        S.push('.');
        mp[')'] = '(', mp[']'] = '[', mp['}'] = '{';
        for (auto i : s)
        {
            if (i == '(' || i == '{' || i == '[')
                S.push(i);
            else
            {
                if (S.top() == mp[i])
                    S.pop();
                else
                    return false;
            }
        }
        if (S.top() == '.')
            return true;
        return false;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.isValid("");
    return 0;
}