// author -sonaspy@outlook.com 
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
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.empty()) return "";
        string s = "";
        char common;
        int min = 999999;
        for(auto i : strs){
            if(i.size() < min)
            min = i.size();
        }
        for(int i = 0; i < min; i++){
            bool f = true;
            common = strs[0][i];
            for(auto j : strs){
                if(j[i] != common){
                    f = false;
                    break;
                }
            }
            if(!f)break;
            else if(f) s.push_back(common);
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution S;
    vector<string> v;
    v.push_back("aca");
    v.push_back("cba");
    string s = S.longestCommonPrefix(v);
    return 0;
}