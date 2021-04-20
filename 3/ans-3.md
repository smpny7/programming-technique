---
title: 'プログラミング技法 予習課題3'
author: 'IKEDA Kaito'
date: \the\year/\the\month/\the\day
---

# プログラミングにおいて，「インデント」とは何ですか．インデントで喧嘩したことはありますか?

- インデントとは．行の先頭にTabやスペースを挿入して字下げを行うこと．
- インデントで喧嘩というのが正直ピンとこなかったのですが，
以前，字下げを空白2文字分でする人と4文字分でする人がいて，むしゃくしゃした記憶はあります．
そのときは`linter`を導入して，字下げを揃えさせるようにしたと思います．



# Person 構造体を宣言して，それに適切なコメントを付けてください．構造体には，名前，年齢，身長，体重，現住所の都道府県番号のメンバがあるとします．

- 基本不要なところにコメントアウトはつけないようにし，変数名に情報を持たせるようにしているのですが，
"現住所の都道府県番号" のみ全情報を付け加えると変数名が長くなり扱いにくくなるので，
"現住所" という情報はコメントアウトで表しました．
(この`Person`場合 "旧住所" の情報を使用しないため)

```c
 1  struct Person {
 2      char fullname[80];
 3      int age;
 4      int bodyHeight;
 5      int bodyWeight;
 6      int prefectureNumber; // 現住所の都道府県番号
 7  };
```



# プログラムにコメントを付けろと先生はよく言いますが，それに対して反論してください．

- 変数名を変えたりした場合，それにつけられているコメントアウトの編集を忘れるといったことがあるため，
コメントアウトではなく変数名で読む人に情報を与えられるコードにするといいと思います．



# 以下のプログラムのコメントは，どの程度プログラムを分かりやすくしていると思いますか．
```c
 1  char a[10]; /* char型の配列を用意 */
 2  :
 3  if (0 <= n && n < 10) {
 4      a[0] = n; /* 配列にnを格納 */
 5      return a;  /* aを返す */
 6  }
```

- 1行で行われている処理の説明を書いているだけなので，
ほとんどの人がコメントアウトがなくてもわかりやすさは同じだと思います．
もっと大きな視点でコメントアウト（これは〇〇をする関数です．など）をつけると，
全体のプログラムのわかりやすさに繋がるのかなと思います．