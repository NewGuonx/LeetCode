// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int countSegments(string s)
    {
        s.push_back(' ');
        int count = 0, consecutive = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!consecutive && s[i] != ' ')
                consecutive = 1;
            else if (consecutive == 1 && s[i] == ' ')
            {
                consecutive = 0;
                count++;
            }
        }
        return count;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}