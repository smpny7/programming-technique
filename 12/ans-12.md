---
title: 'プログラミング技法 予習課題12'
author: 'IKEDA Kaito'
date: \the\year/\the\month/\the\day
---

# Refactoring とは何ですか

- コンピュータプログラミングにおいて，プログラムの外部から見た動作を変えずにソースコードの内部構造を整理することである．


# TDD とは何ですか．Refactoring とどういう関係にありますか

- `TDD`（テスト駆動開発）とは，テストファーストなプログラムの開発手法である．
- プログラムの実装前にテストコードを書き，そのテストコードに適合するように実装と`Refactoring`を進めていく．


# ペアプログラミングとは何ですか，TDD にどう影響を与えていますか

- ペアプログラミングとは，1台のPCで2人のプログラマーが共同で開発を行う手法である．
- ドライバーとナビゲーターという役割があり，通常2人はプログラム開発の小さな区切りや一定時間で交代する．
- ナビゲーターは，ドライバーに仕様に基づいたコード記述の指示や，コードの誤りの指摘などのサポート作業を行う．
- ドライバーは，ナビゲーターの指示に基づきPCを使用しプログラムのコード記述を行う．
- `TDD`は，テストコードに沿って間違いがないかを常に確認しながら実装を行うのに対し，ペアプログラミングではナビゲーターの指示や指摘によって間違いがないかを常に確認しながら実装する．