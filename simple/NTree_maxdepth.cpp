// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Node
{
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution
{
  public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int _max = 0;
        for (auto i : root->children)
        {
            int d = maxDepth(i);
            if (_max < d)
                _max = d;
        }
        return _max + 1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}