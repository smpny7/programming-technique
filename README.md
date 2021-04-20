# mdtopdf の利用方法

MarkdownをPDFに変換する覚え書きです．
[こちら](https://github.com/p1ass/mdtopdf) のリポジトリを利用させていただきます．

1. Docker イメージを pull する
```shell
$ docker pull plass/mdtopdf
```

2. 変換したい Markdown ファイルがあるディレクトリに移動する
```shell
$ cd path/to/directory
```

3. PDF に変換する
```shell
$ docker run -it --rm -v `pwd`:/workdir plass/mdtopdf mdtopdf INPUT.md
```

おまけ:  alias を使って簡単に変換を実行できるようにする
```shell
$ echo "alias mdtopdf='docker run -it --rm -v `pwd`:/workdir plass/mdtopdf mdtopdf'" >> ~/.zshrc
$ source ~/.zshrc

$ mdtopdf INPUT.md
```
