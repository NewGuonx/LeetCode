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

struct cmp
{
    bool operator()(const ListNode *a, const ListNode *b) const
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *walk, *pre, *dummy = new ListNode(0);
        pre = dummy;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            walk = lists[i];
            while (walk)
            {
                pq.push(new ListNode(walk->val));
                walk = walk->next;
            }
        }
        while (pq.size())
        {
            walk = pq.top();
            pre->next = walk;
            pre = walk;
            pq.pop();
        }
        return dummy->next;
    }
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
};

//[[-1,-1,-1],[-2,-2,-1]]
int main(int argc, char const *argv[])
{
    /* code */
    //test();




    return 0;
}