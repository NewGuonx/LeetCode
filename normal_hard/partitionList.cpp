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
        ListNode *walk, *v = new ListNode(0), *v1 = new ListNode(0), *vwalk = nullptr, *v1walk = nullptr;
        for (walk = head, vwalk = v, v1walk = v1; walk; walk = walk->next)
        {
            if (walk->val < x)
            {
                vwalk->next = new ListNode(walk->val);
                vwalk = vwalk->next;
            }
            else
            {
                v1walk->next = new ListNode(walk->val);
                v1walk = v1walk->next;
            }
        }
        if (v->next)
        {
            vwalk->next = v1->next;
            return v->next;
        }
        else
            return v1->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}