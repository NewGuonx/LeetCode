// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;
// Definition for singly-linked list.
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
        if (!head || !head->next)
            return head;
        ListNode *walk = head, *fixed = head;
        int data;
        while (fixed)
        {
            data = fixed->val;
            while ((walk = walk->next) && walk->val == data)
                ;
            fixed->next = walk;
            fixed = walk;
        }
        return head;
    }
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        bool hasdup;
        ListNode *walk, *valid_p, *dummy = new ListNode(0);
        dummy->next = head;
        for (walk = head, valid_p = dummy; walk; walk = walk->next)
        {
            for (hasdup = false; walk->next && walk->val == walk->next->val; walk = walk->next)
                hasdup = true;
            if (!hasdup)
                valid_p->next = walk, valid_p = walk;
        }
        valid_p->next = nullptr;
        return dummy->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}