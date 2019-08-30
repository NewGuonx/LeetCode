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
    ListNode *reverseList(ListNode *head)
    {
        if(!head)return nullptr;
        ListNode* walk = head, *post = head->next, *pre = nullptr;
        while(walk){
            walk->next =pre;
            pre = walk;
            walk = post;
            if(post)
            post = post->next;
        }
        return pre;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}