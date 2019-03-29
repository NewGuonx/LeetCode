// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<queue>
#include<numeric>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(1, 1);
        if (!rowIndex)
            return res;
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> current(i + 1, 1);
            for (int j = 1; j < i ; j++)
                current[j] = res[j - 1] + res[j];
            res = current;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}