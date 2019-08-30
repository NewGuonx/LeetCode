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
        ListNode *walk = head, *fixed = head;
        while (fixed)
        {
            int data = fixed->val;
            while ((walk = walk->next) && walk->val == data)
                ;
            fixed->next = walk;
            fixed = walk;
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}