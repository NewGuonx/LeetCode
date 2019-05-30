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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (!head)
            return head;
        ListNode *dummy = new ListNode(1);
        dummy->next = head;
        ListNode *pre = dummy;
        for (int i = 0; i < m - 1; i++)
            pre = pre->next;
        ListNode *walk = pre->next, *tmp;
        for (int i = m; i < n; i++)
        {
            tmp = walk->next;
            walk->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
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