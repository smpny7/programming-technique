---
title: 'プログラミング技法 予習課題1'
author: 'IKEDA Kaito'
date: \the\year/\the\month/\the\day
---

(1) return retval;

(2) 1 2, 2 1
（前者が`clang`，後者が`gcc`でのコンパイル）

(3) プログラミング技法の観点から配慮した点

- 関数にDOCSをつけて，何をする関数か，引数や返り値の情報を明確にした．
- コメントが使用する環境によって文字化けするので，英字でのコメントにした．
- return内に直接計算をいれる人もいるが，私は一度変数に代入する方が何の処理をしているかが明確になるので，
以下のように一度代入して返すようにした．

```c
 1  /*
 2  Overview: Convert decimal single digit to one character
 3  @argument: {int} num - Decimal single digit.
 4  @return: {char} - One character.
 5  */
 6  char itoc(int num)
 7  {
 8      char c = num + 48;
 9      return c;
10  }
```

(4) ローカル変数のアドレスを返しているため`warning`がでている．

また，`msg`関数の外で`char buf[100];`の宣言をすることで解決できる．