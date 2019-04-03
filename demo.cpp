// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
// #include<setjmp.h>
#include <stdlib.h>
#include<string.h>

#define DUMYCOPY for(i = 0; i< 65536; i++)\
            dst[i] = src[i]


#define SMARTCOPY memcpy(dst, src,65536)


// jmp_buf buf;
// #include<setjmp.h>
#define test() freopen("in", "r", stdin)

using namespace std;

// void banan(){
//     printf("in banan\n");
//     longjmp(buf, 1);
// }

union {
    char a[10];
    int i;
}u;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    // if(setjmp(buf))
    //     printf("back in \n");
    // else{
    //     printf("1st Time\n");
    //     banan();
    // }

    // int MB = 0;
    // while (malloc(1 << 20))
    // {
    //     ++MB;
    //     cout << MB << "MB\n";
    // }

    // char src[65536], dst[65536];
    // int i, j;
    // for(int j = 0; j < 100; j++)
    //     SMARTCOPY;
    
    return 0;
}