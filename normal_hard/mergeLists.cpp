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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        ListNode *p = lists[0];
        auto it = lists.begin() + 1, end = lists.end();
        for (; it != end; ++it)
            p = mergeTwoLists(p, *it);
        return p;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0), *p = dummy;
        for (; l1 && l2; p = p->next)
        {
            if (l1->val > l2->val)
                p->next = l2, l2 = l2->next;
            else
                p->next = l1, l1 = l1->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

bool cmp(const ListNode *a, const ListNode *b)
{
    return a->val > b->val;
}
class Solution1
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *walk, *pre, *dummy = new ListNode(0);
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            walk = lists[i];
            while (walk)
            {
                pq.push_back(walk);
                walk = walk->next;
            }
        }
        pre = dummy;
        sort(pq.begin(), pq.end(), cmp);
        for (auto i : pq)
        {
            pre->next = i;
            pre = i;
        }
        pre->next = nullptr;
        return dummy->next;
    }
    vector<ListNode *> pq;
};

//[[-1,-1,-1],[-2,-2,-1]]
int main(int argc, char const *argv[])
{
    /* code */
    //test();


    return 0;
}