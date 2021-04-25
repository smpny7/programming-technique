---
title: 'プログラミング技法 予習課題4'
author: 'IKEDA Kaito'
date: \the\year/\the\month/\the\day
---

# 次のコードの潜在的な間違いを最小限に食い止めるには，プログラムをどう書換えたらよいだろうか．改良せよ．
```c
 1  #define FT2METER  0.3048
 2  #define METER2FT  3.28084
 3  #define MI2FT     5280.0
 4  #define MI2KM     1.609344
 5  #define SQMI2SQKM 2.589988
```

根本的なところを変えることになり，意図された回答ではないかもしれませんが，
`double FT2METER = 0.3048;` のように変数で，型をつけて宣言するといいと思います．
変換の計算時に`double`型ということがわかるので，出力などをするときに自然と意識が向くようになると思います．



# 西暦の年月日を表す3つの整数を引数として，その組合せがカレンダー上の正しい日付かどうかを返す関数を記述せよ．

```c
 1  int DAY_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 2
 3  /*
 4  Overview: Returns if it's the leap year.
 5  @argument: {int} year - Input year.
 6  @return: {bool}
 7  */
 8  bool isLeapYear(int year)
 9  {
10      return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
11  }
12
13  /*
14  Overview: Returns if it's the right date.
15  @argument: {int} year - Input year.
16  @argument: {int} month - Input month.
17  @argument: {int} day - Input day.
18  @return: {bool}
19  */
20  bool isValidDate(int year, int month, int day)
21  {
22      if (year < 1970 || year >= 2038)
23          return false;
24      if (month < 1 || month > 12)
25          return false;
26
27      int max_day = DAY_IN_MONTH[month - 1];
28
29      // For Leap Year
30      if (month == 2 && isLeapYear(year))
31          max_day++;
32
33      if (day < 1 || day > max_day)
34          return false;
35
36      return true;
37  }
```