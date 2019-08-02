// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s1;
        int n1, n2;
        for (auto &i : tokens)
        {
            if (i == "+")
            {
                n1 = s1.top(), s1.pop(), n2 = s1.top(), s1.pop();
                s1.push(n2 + n1);
            }
            else if (i == "-")
            {
                n1 = s1.top(), s1.pop(), n2 = s1.top(), s1.pop();
                s1.push(n2 - n1);
            }
            else if (i == "*")
            {
                n1 = s1.top(), s1.pop(), n2 = s1.top(), s1.pop();
                s1.push(n2 * n1);
            }
            else if (i == "/")
            {
                n1 = s1.top(), s1.pop(), n2 = s1.top(), s1.pop();
                s1.push(n2 / n1);
            }
            else
                s1.push(stoi(i));
        }
        return s1.top();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}