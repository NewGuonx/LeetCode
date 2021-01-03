// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> dirs;
        for (auto i = path.begin(); i != path.end();)
        {
            i++;
            auto j = find(i, path.end(), '/');
            string dir = string(i, j);
            if (dir.size() && dir != ".")
            {
                if (dir == "..")
                {
                    if (dirs.size())
                        dirs.pop_back();
                }
                else
                    dirs.push_back(dir);
            }
            i = j;
        }
        stringstream ss;
        if (dirs.empty())
            ss << "/";
        else
            for (auto d : dirs)
                ss << "/" << d;
        return ss.str();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}