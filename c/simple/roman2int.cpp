// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
  public:
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> mp;
        unordered_map<char, unordered_set<char>> mp1;
        mp1['I'].insert('V'), mp1['I'].insert('X'), mp1['X'].insert('L'), mp1['X'].insert('C'), mp1['C'].insert('D'), mp1['C'].insert('M');
        mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50, mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;
        for(int i = 0, c1 = 0, c2 = 0; i < s.size();){
            c1 = i;
            while(s[i] == s[c1])i++;
            c2 = i;
            if(!mp1[s[c1]].count(s[c2])){
                res += (c2-c1)*mp[s[c1]];
                continue;
            }
            else{
                res += mp[s[c2]] - (c2-c1)*mp[s[c1]];
                i++;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout <<  s.romanToInt("MCMXCIV");
    return 0;
}