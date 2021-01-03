// author -sonaspy@outlook.com 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<queue>
#include<numeric>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    string countAndSay(int n)
    {
        string s("1");
        while (--n)
            s = getNext(s);
        return s;
    }

    string getNext(const string &s)
    {
        stringstream ss;
        for (auto i = s.begin(); i != s.end();)
        {
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }
        return ss.str();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}