// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || (!k))
            return head;
        int n = 1;
        ListNode *walk;
        for (walk = head; walk->next; walk = walk->next, n++)
            ;
        k = n - k % n;
        walk->next = head;
        for (int i = 0; i < k; i++)
            walk = walk->next;
        head = walk->next;
        walk->next = nullptr;
        return head;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}