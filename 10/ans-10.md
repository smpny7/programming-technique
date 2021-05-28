---
title: 'プログラミング技法 予習課題10'
author: 'IKEDA Kaito'
date: \the\year/\the\month/\the\day
---

# プログラミング作法 8.5節 「データ交換にはテキストを」では，改行コードの問題について触れています．Windows (PC) と Unix (現在のMac も Unix です) のテキストにおける改行コードの差とは何か説明してください．また，これが，具体的には，どういう問題を引き起こすか説明してください．

- Windowsシステム では，各行の末尾に復帰`\r`と改行`\n`がつくのに対し，
 Unixシステムでは改行`\n`だけが使われている．
- 復帰コードがないファイルは，1つの長大な行として解釈されてしまう場合がある．
具体的には，Unixシステムで作成したファイルをWindowsシステムで開いた際に，
行数や文字数の表示が間違ったり，不意に変化することがある．


# データ交換にテキストではなくバイナリを用いる際には，バイト順 (バイトオーダ) が問題です．バイトオーダとは，何ですか．バイトオーダがデータ交換において問題となる例をあげつつ説明してください．

- バイト順とは，複数バイトのデータがある場合に下位にあるバイトが上位にあるバイトよりも低いアドレスに記憶されるか，それとも高いアドレスに記憶されるかの順を表したものである．
- 送信側のコンピュータと受信側のコンピュータのバイト順が違っていた場合，
例えばデータの順が逆になっていたりと転送したデータが正しく受信できない恐れがある．


# 次のコードを実行した際の出力を予測し，根拠ともに示してください．ただし，関数の宣言部分は省略しています．

```c
    (符号付き整数と符号無し整数の関係が大事です)
    1  unsigned char uc = 0xc4;
    2    signed char sc = 0xc4;
    3  printf("%d, %d\n", uc, sc);
```

まず，`0xc4`を2進数にすると`1100 0100`となる．
1行目の`unsigned char uc`については，そのまま10進数に直した値 196 が出力される．
2行目の`signed char sc`については，先頭の1ビットは符号を表し，この場合負であることがわかる．
また，`1111 1111`が-1，`1111 1110`が-2を表すことから分かるように，
下7ビットの値の補数に1を足したものが，その値の絶対値だということがわかる．
そのため，`sc`については-60が出力される．


# 文字列 src を dest に連結する C言語の標準関数 strcat を実装してください．関数の返り値は dest です．

```c
 1  char *strcat(char *dest, const char *src)
 2  {
 3    while (*dest) dest++;
 4
 5    while (*src) dest++[0] = *src++;
 6
 7    return dest;
 8  }
```