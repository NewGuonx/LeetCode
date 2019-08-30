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
    bool hasCycle(ListNode *head)
    {
        while(head){
            if(st.count(head))return true;
            st.insert(head);
            head = head->next;
        }
        return false;
    }
    unordered_set<ListNode*> st;
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}