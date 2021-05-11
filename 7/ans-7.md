---
title: 'プログラミング技法 予習課題7'
author: 'IKEDA Kaito'
date: \the\year/\the\month/\the\day
---

# 次のプログラムのバグを指摘してなおしなさい．

```c
 1  void get_nums(int *p, int num)
 2  {
 3    int i, n;
 4
 5    for (i = 0; i < num; i++){
 6  　　// main loop?
 7      printf("number %d: ", i);
 8      scanf("%d", n);
 9      *p++ = n;
10    }
11  }
12
13  main()
14  {
15    int *p, sum, i;
16
17    get_nums(p, 3);
18    for (i = 0; i < 3; i++)
19      sum += *p++;
20    printf("sum = %d\n", sum);
21  }
```

- 6行目のコメントアウト前に全角スペースが2文字が入っていました．全角スペース2文字を取り除き，半角スペースでインデントを合わせることで解消しました．


# 次のプログラムに含まれる dangling pointer の問題 (なぜも含めて) を指摘し，改善案を示しなさい．

```c
 1  char *msg(int n, char *s)
 2  {
 3    char buf[100];
 4    sprintf(buf, "err %d: %s\n", n, s);
 5    return buf;
 6  }
 7
 8  int main()
 9  {
10    char *str;
11    str = msg(1, "test.");
12    printf(str);
13    return 0;
14  }
```

- `buf`という配列は`msg`という関数内で宣言されているため，この関数の処理が終了するとメモリが解放されてしまい，この変数があったアドレスにアクセスしても意味のない値となっています．
- `char buf[100];`を1行目に移動させ，グローバル変数にすることで解消されます．
