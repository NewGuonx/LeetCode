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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *next, *pre, *walk, *dummy = new ListNode(1);
        pre = dummy, walk = head, next = walk->next;
        int cnt = 0;
        while (next)
        {
            if (cnt % 2 == 0)
            {
                pre->next = next;
                walk->next = next->next;
                next->next = walk;
                pre = next;
                next = walk->next;
            }
            else{
                pre = pre->next;
                walk = walk->next;
                next = next->next;
            }
            cnt++;
        }
        return dummy->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}