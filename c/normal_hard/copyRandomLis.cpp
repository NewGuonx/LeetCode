// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        for (Node *cur = head; cur;)
        {
            Node *node = new Node(cur->val, cur->next, nullptr);
            cur->next = node;
            cur = node->next;
        }
        for (Node *cur = head; cur;)
        {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node dummy(-1, nullptr, nullptr);
        for (Node *cur = head, *new_cur = &dummy; cur;)
        {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}