// author - newguo@sonaspy.cn
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *walk, *pre, *tmp;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        for (walk = head, pre = dummy; walk;)
        {
            bool f = false;
            while (walk->next && walk->val == walk->next->val)
            {
                f = true;
                tmp = walk;
                walk = walk->next;
                delete tmp;
            }
            if (f)
            {
                tmp = walk;
                walk = walk->next;
                delete tmp;
                continue;
            }
            pre->next = walk, pre = walk, walk = walk->next;
        }
        pre->next = walk;
        return dummy->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}