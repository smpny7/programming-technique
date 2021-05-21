---
title: 'プログラミング技法 予習課題9'
author: 'IKEDA Kaito'
date: \the\year/\the\month/\the\day
---

# ある年が閏年かどうかを判定する関数を書いてください．

```c
 1  int isLeapYear(int year)
 2  {
 3      return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
 4  }
```


# 問題1 で作成した関数の動作をテストするコードを書いてください．

```c
 1  void testIsLeapYear(FILE *fp)
 2  {
 3      int year = 1900;
 4      char str[256];
 5
 6      while (fgets(str, 256, fp) != NULL)
 7      {
 8          if (year > 2400) return;
 9
10          while (year != atoi(str))
11          {
12              if (isLeapYear(year) != 0)
13                  printf("%d has different output.\n", year);
14              year++;
15          }
16
17          if (isLeapYear(atoi(str)) != 1)
18              printf("%d has different output.\n", year);
19          year++;
20      }
21      return;
22  }
23
24  int main(void)
25  {
26      FILE *fp;
27      char fname[] = "years.txt";
28
29      fp = fopen(fname, "r");
30      if (fp == NULL)
31      {
32          printf("%s file not open!\n", fname);
33          return -1;
34      }
35
36      testIsLeapYear(fp);
37
38      fclose(fp);
39      return 0;
40  }
```


# 問題2 で作成したテストコードやその実行結果から，問題1 で作成した関数について評価してください．

まず，閏年かどうかの正解データを集めるために，シェルで実行するソースコードをお借りしてテキストファイルに書き出しを行った．
内容は以下の通りである．

```shell
$ seq 1900 2400 | awk '$1%4==0' |
> ( cat; seq 1900 2400 | awk '$1%100==0' ) | sort | uniq -u |
> ( cat; seq 1900 2400 | awk '$1%400==0' ) | sort | uniq
```
【参考文献】閏年をデータ重視な発想で (https://papiro.hatenablog.jp/entry/2015/12/13/194107)

1900年から2400年までの閏年の一覧を，`years.txt`に格納しておく．
ここで，何でも良いが別の言語（方法）で生成したものと比べるのが得策だと思う．

ここで，結果が正のデータだけでなく負のデータも正しく判断できているかテストする必要がある．
`isLeapYear`関数で，閏年であるのに0が返った場合，
閏年でないのに1が返った場合に`その年`と`エラー文`を出力するようにしている．

結果は，1900年から2400年のデータを正しく分類できたので，
基本的な入力値については正しい動作をしていることが確認できた．