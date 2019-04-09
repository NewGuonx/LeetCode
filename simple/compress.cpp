// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int compress(vector<char> &chars)
    {
        chars.push_back('\0');
        int cnt = 1, sum = 0, j = 0;
        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == chars[i - 1])
                cnt++;
            else
            {
                string s = to_string(cnt);
                chars[j++] = chars[i - 1];
                if (cnt != 1)
                    for (auto k : s)
                    {
                        chars[j++] = k;
                    }
                if (cnt == 1)
                    ++sum;
                else
                    sum += 1 + s.size();
                cnt = 1;
            }
        }
        return sum;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}