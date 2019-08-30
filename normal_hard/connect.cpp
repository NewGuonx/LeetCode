// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        Node *v = nullptr, *post = nullptr;
        deque<Node *> q, nexq;
        q.push_back(root);
        while (q.size())
        {
            while (q.size())
            {
                v = q.front(), q.pop_front();
                if (v->left)
                    nexq.push_back(v->left);
                if (v->right)
                    nexq.push_back(v->right);
                post = q.empty() ? nullptr : q.front();
                v->next = post;
            }
            swap(q, nexq);
        }
        return root;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}