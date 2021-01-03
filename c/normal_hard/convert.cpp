// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1 || s.size() <= 1)
            return s;
        string res;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0, index = i; index < s.size(); j++, index = (2 * numRows - 2) * j + i)
            {
                res.append(1, s[index]);
                if (i == 0 || i == numRows - 1)
                    continue;
                if (index + (numRows - i - 1) * 2 < s.size())
                    res.append(1, s[index + (numRows - i - 1) * 2]);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}