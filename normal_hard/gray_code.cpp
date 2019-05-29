// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        int size = 1 << n;
        res.reserve(size);
        for (int i = 0; i < size; i++)
            res.push_back(bin2gray(i));
        return res;
    }

private:
    static int bin2gray(int n) { return n ^ (n >> 1); }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}