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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;
        vector<ListNode *> v;
        ListNode *p = head, dummy = ListNode(0);
        for (; p; p = p->next)
            v.push_back(p);
        int n = v.size();
        p = &dummy;
        bool flag = 1;
        for (int i = 0; i < n / 2; i++)
        {
            p->next = v[i];
            p = p->next;
            p->next = v[n - 1 - i];
            p = p->next;
        }
        if (n % 2)
        {
            p->next = v[n / 2];
            p = p->next;
        }
        p->next = nullptr;
    }
};
int main(int argc, char const **argv)
{
    /* code */
    //test();
    ListNode *head = new ListNode(0), *p = head;
    int i = 1, n = 3;
    while (n--)
    {
        p->next = new ListNode(i);
        p = p->next;
        i++;
    }
    Solution s;
    s.reorderList(head);
    p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}