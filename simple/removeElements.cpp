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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *walk = head, *newhead = new ListNode(0), *pre = newhead;
        newhead->next = head;
        while (walk)
        {
            bool f=true;
            if (walk->val == val)
            {
                pre->next = walk->next;
                cout << val << endl;
                f = false;
            }
            if(f) pre = pre->next;
            walk = walk->next;
        }
        return newhead->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    ListNode *head = new ListNode(8);
    ListNode *h = head;
    for (int i = 0; i < 7; i++)
    {
        head->next = new ListNode(8);
        head = head->next;
    }
    Solution s;
    head = s.removeElements(h, 8);
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    return 0;
}