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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode dummy(INT_MIN);
        ListNode *pos, *tmp;
        for (ListNode *walk = head; walk; walk = tmp)
        {
            tmp = walk->next;
            pos = findPos(&dummy, walk->val);
            walk->next = pos->next;
            pos->next = walk;
        }
        return dummy.next;
    }
    ListNode *findPos(ListNode *_begin, int x)
    {
        ListNode *pre = _begin;
        for (ListNode *walk = _begin; walk && walk->val <= x; pre = walk, walk = walk->next)
            ;
        return pre;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}