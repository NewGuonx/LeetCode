// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef bitset<8> byte;
typedef vector<byte> stream;
class SymmetricCypher
{
public:
    typedef bitset<8> byte;
    typedef vector<byte> stream;
    SymmetricCypher()
    {
        this->key = generate_stream();
    }
    stream get_cypher(string s)
    {
        stream cypher;
        for (int i = 0; i < s.size(); i++)
        {
            byte b(s[i]);
            cypher.push_back(b ^ key[i]);
        }
        return cypher;
    }
    string get_text(stream cypher)
    {
        string text;
        for (int i = 0; i < cypher.size(); i++)
            text.push_back(char((cypher[i] ^ key[i]).to_ulong()));
        return text;
    }

private:
    stream key;
    inline byte get_byte()
    {
        byte b;
        for (int i = 0; i < 8; i++)
            b[i] = rand() % 2;
        return b;
    }
    inline stream generate_stream(int num = 1 << 16)
    {
        stream _s;
        srand(time(NULL));
        for (int i = 0; i < num; i++)
            _s.push_back(get_byte());
        return _s;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    SymmetricCypher demo;
    stream c = demo.get_cypher("I love s ki");
    cout << "Cypher Stream is : \n";
    for (auto i : c)
        cout << i;
    cout << endl;
    cout << "text is : \n";
    cout << demo.get_text(c);
    return 0;
}