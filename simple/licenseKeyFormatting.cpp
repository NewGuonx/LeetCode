// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    string licenseKeyFormatting(string s, int k)
    {
        stack<char> st;
        string ret;
        for (int i = s.size() - 1, count = 0; i > -1; --i)
        {
            if (s[i] != '-')
            {
                ++count;
                if (islower(s[i]))
                    s[i] = toupper(s[i]);
                if (count > k && (count % k == 1 || k == 1))
                    st.push('-');
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }

        return ret;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}