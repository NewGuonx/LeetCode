// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

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
    void deleteNode(ListNode *node)
    {
        ;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}