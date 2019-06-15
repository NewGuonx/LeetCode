// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node() {}

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        Node *v;
        deque<Node *> q;
        unordered_map<Node *, Node *> mp;
        q.push_back(node);
        mp[node] = new Node(node->val, vector<Node *>());
        while (q.size())
        {
            v = q.front(), q.pop_front();
            for (auto &adj : v->neighbors)
            {
                if (mp.count(adj))
                    mp[v]->neighbors.push_back(mp[adj]);
                else
                {
                    Node *tmp = new Node(adj->val, vector<Node *>());
                    mp[adj] = tmp;
                    mp[v]->neighbors.push_back(tmp);
                    q.push_back(adj);
                }
            }
        }
        return mp[node];
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}