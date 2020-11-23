#include <typeinfo>
#include <stdio.h>

// 一次元配列と二次元配列について、型の詳細。
// typeinfoというc++の機能を使えば、以下のように型を表示できる。
// typeid(変数).name() で型が表示される。
// そのままだと見にくいので、c++filtというコマンドで見やすく出来る
//
// How to run:
// (1) コンパイル。gccではなくてg++なので注意。つまりこれはcではなくc++プログラム
//   $ g++ main.cpp
// (2) 実行。パイプでc++filtというプログラムに渡すと、見やすくなる。
//    （ただし、文字列置換を行うので、普通のprintfの出力がおかしくなるかもしれないので注意）
//   $ ./a.out | c++filt -t 


int main(int argc, char *argv[]) {
    // =================== 一次元配列の場合 =================== 
    int a[] = {1, 2, 3};
    int *p;
    p = a;

    // 次のように、配列の型は「int [3]」、int型へのポインタは「int*」となる
    printf("=== 0 ===\n");
    printf("%s\n", typeid(a).name());  // int [3]
    printf("%s\n", typeid(p).name());  // int*

    // 配列とポインタは同じように扱えると習ったが、それでも、
    // int [3] と int*は型が違うじゃないかと思うかもしれない。
    // これはルールなので仕方ないのだが、一つの説明として、
    // a + 0 を考えてみる。 a + 0 の型は実はポインタと同じ int* である。
    // a + 0 も a も似たようなものだと考えると、この事実から、
    // 配列をポインタと同じように扱えることがわかるかもしれない。
    // 配列が関数に渡されるときは、こっちになっていると思えばOK。
    // 逆に、複雑な配列に対してそれをポイントする型がわからないときは、
    // "+0"して型を調べてみるといいかもしれない。
    printf("%s\n", typeid(a + 0).name());  // int*

    // 「a」だけの場合、それは実体としての配列（intを3つ分確保）を指している。
    // sizeofも12になる。 一方、「a + 0」とした場合、
    // それをポインタだとコンパイラは解釈する。sizeofも8になる。
    // この二つはポインタを経由して扱う場合は同じもの。なので、
    // int *p = aと出来る。
    // 結論として、型が「int [3]」のものは、「int*」でポイント出来る。
    printf("%p %p\n", a, a + 0);  // 値は同じ。 0x7ffd864060b4 0x7ffd864060b4
    printf("%lu\n", sizeof(a));      // sizeofは違う：12
    printf("%lu\n", sizeof(a + 0));  // sizeofは違う：8


    // 「a + 1」のように指定すると、「p + 1」と全く同じにふるまう
    printf("=== 1 ===\n");
    printf("%s\n", typeid(a + 1).name());  // int* 
    printf("%s\n", typeid(p + 1).name());  // int*
    printf("%s\n", typeid(*(a + 1)).name());  // int
    printf("%s\n", typeid(*(p + 1)).name());  // int


    // *(a + i) とa[i]は同じ
    printf("=== 2 ===\n");
    printf("%s\n", typeid(&a[1]).name());  // int*  ちなみにこれは &(a[1])のこと
    printf("%s\n", typeid(&p[1]).name());  // int*
    printf("%s\n", typeid(a[1]).name());  // int
    printf("%s\n", typeid(p[1]).name());  // int


    printf("=== 3 ===\n");
    // &aと&pは型も値も違う（week 4を参照）

    // &aは何かを考えることは難しい。結論はint (*)[3] である。
    // すなわち、「int 3つ」を単位とするポインタである。
    // それはなぜだろうか？例えば変数一つの場合を考える。
    // int n;
    // int *p;
    // p = &n;
    // このように、「int 1つ」であるnのアドレス（&n）を代入すべきポインタは、
    // int *である。すなわち、「int 1つ」を単位とするポインタである。
    // この議論を拡張し、int a[3]; とすると、
    // 「int 3つ」であるaのアドレス（&a）を代入すべきポインタは、
    // int (*)[3] すなわち、「int 3つ」を単位とするポインタである、と言える
    printf("%s\n", typeid(&a).name());  // int (*)[3]

    // &pは単純にポインタのさらにアドレスなので、ポインタのポインタ
    printf("%s\n", typeid(&p).name());  // int**

    // &aはaと同じ。&pはポインタ変数そのもののアドレス
    printf("%p %p\n", &a, &p);  // 違う: 0x7ffd864060b4 0x7ffd86406098


    // =================== 二次元配列の場合 =================== 
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*p2)[3];
    p2 = arr; // p2はarrを二次元配列として指すポインタ。

    // 授業で習った通り、arrは二次元配列 int [2][3] で、
    // p2は「int 3つ分を単位とするポインタ」
    // では、int [2][3] を指すポインタが int (*)[3]だと
    // どうすればわかるだろうか？
    printf("=== 4 ===\n");
    printf("%s\n", typeid(arr).name());  // int [2][3]
    printf("%s\n", typeid(p2).name());   // int (*)[3]

    // 一次元配列の例で見た通り、0を足すと、コンパイラは
    // arrをポインタとして解釈する。そのときの型を見ると、
    // それは、arrをポインタとして指すときの型。
    // なので、この場合、p2と型が同じなので、OKということになる。
    printf("%s\n", typeid(arr + 0).name());  // int (*)[3]


    // 添え字を使って各行にアクセスする場合。これは一次元配列そのものになる
    printf("=== 5 ===\n");    
    printf("%s\n", typeid(arr[0]).name());  // int [3]
    printf("%s\n", typeid(p2[0]).name());   // int [3]
    printf("%s\n", typeid(arr[0] + 0).name()); // int*
    printf("%s\n", typeid(p2[0] + 0).name());  // int*


    // arrやp2に&をすると次のようになる。値も異なる。
    printf("=== 6 ===\n");    
    printf("%s\n", typeid(&arr).name());  // int (*)[2][3]
    printf("%s\n", typeid(&p2).name());  // (**)[3]



    printf("=== 7 ===\n");    
    // 以下は全てアドレスの値は同じだが、型は異なる
    // 0x7ffcc93804a0 0x7ffcc93804a0 0x7ffcc93804a0 0x7ffcc93804a0 0x7ffcc93804a0
    printf("%p %p %p %p %p\n", &arr, arr, &arr[0], arr[0], &arr[0][0]);

    // &arrは、二次元配列そのものを一単位として扱う。よって、
    // 「intが2 * 3個」を一つの単位とする。
    // これは一次元配列名に&をしたときと同じ。難しいが、普段は使わない
    printf("%s\n", typeid(&arr).name());       // int (*)[2][3]   

    // arrは二次元配列そのもの。これはそのまんま。
    printf("%s\n", typeid(arr).name());        // int [2][3]

    // 再度の注意として、arrに0を足すと、これをポインタとして解釈してくれる
    printf("%s\n", typeid(arr + 0).name());    // int (*)[3]

    // arr[0]は一行目の一次元配列そのもの
    printf("%s\n", typeid(arr[0]).name());    // int [3]

    // 再度の注意として、arr[0]に0を足すと、これをポインタとして解釈してくれる
    printf("%s\n", typeid(arr[0] + 0).name());    // int*

    // &arr[0]は難しい。考え方として、次の二通りがあると思う
    // (1) &arr[0]（アンド＋添え字アクセス）は arr + 0（変数名＋オフセット）と同じ
    //     というルールを適用すると、上のarr + 0になる、と覚える
    // (2) arr[0]は一次元配列そのものだった。一次元配列そのものに&をつけると、
    //     配列長を単位とするポインタになったことを思い出す
    //     （上のほうの === 3 === のところを参照）
    printf("%s\n", typeid(&arr[0]).name());    // int (*)[3]

    // arr[0][0]はintなので、そのポインタ。
    printf("%s\n", typeid(&arr[0][0]).name()); // int*


    // =================== 三次元配列の場合も同様 =================== 
    int arr2[2][3][4] = {
        {{ 1,  2,  3,  4}, { 5,  6,  7,  8}, { 9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };
    int (*p3)[3][4];
    p3 = arr2; // p3はarr2を三次元配列として指すポインタ。
    printf("=== 8 ===\n");
    printf("%s\n", typeid(arr2).name());      // int [2][3][4]
    printf("%s\n", typeid(p3).name());        // int (*)[3][4]
    printf("%s\n", typeid(arr2 + 0).name());  // int (*)[3][4]

    return 0;
}