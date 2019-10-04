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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;
        ListNode *walk, *l_dummy = new ListNode(0), *r_dummy = new ListNode(0), *p1, *p2;
        for (walk = head, p1 = l_dummy, p2 = r_dummy; walk; walk = walk->next)
        {
            if (walk->val < x)
            {
                p1->next = walk;
                p1 = p1->next;
            }
            else
            {
                p2->next = walk;
                p2 = p2->next;
            }
        }
        p1->next = r_dummy->next;
        p2->next = nullptr;
        return l_dummy->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}