// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef bitset<8> byte;
typedef bitset<32> block;
typedef vector<byte> stream;
typedef vector<block> blocks;
class SymmetricCypher
{
public:
    typedef bitset<8> byte;
    typedef bitset<32> block;
    typedef vector<byte> stream;
    typedef vector<block> blocks;
    SymmetricCypher()
    {
        srand(time(NULL));
        this->key = generate_key();
    }
    blocks get_cypher(string s)
    {
        blocks cypher;
        s.resize(s.size() + s.size() % 4);
        for (int i = 0; i < s.size(); i += 4)
        {
            byte b1(s[i]), b2(s[i + 1]), b3(s[i + 2]), b4(s[i + 3]);
            byte b[4] = {b1, b2, b3, b4};
            block blk;
            for (int j = 0; j < 32; j++)
                blk[j] = b[j / 8][7 - j % 8];
            cypher.push_back(blk ^ key);
        }
        return cypher;
    }
    string get_text(blocks cypher)
    {
        string text;
        for (int i = 0; i < cypher.size(); i++)
            text.push_back(char((cypher[i] ^ key).to_ulong()));
        return text;
    }

private:
    bitset<32> key;
    inline bitset<32> generate_key()
    {
        bitset<32> _s;
        for (int i = 0; i < 32; i++)
            _s[i] = rand() % 2;
        return _s;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    SymmetricCypher demo;
    blocks c = demo.get_cypher("IIII");
    cout << "Cypher Stream is : \n";
    for (auto i : c)
        cout << i;
    cout << endl;
    cout << "text is : \n";
    cout << demo.get_text(c);
    return 0;
}