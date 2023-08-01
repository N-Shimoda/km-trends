{% include head.html %}

# アルゴリズムとデータ構造2016

## (3) 二分探索木へのノードの挿入・削除
日本語で説明する場合も、ステップごとに分けた方が読みやすい。

### 挿入
二分探索木 $T$ に要素 $p$ を挿入する手順
1. $T$ の根の要素を $c$ とする。
1. $p<c$ であれば、c の左側の木 $T_1$ に p を挿入する。$c<p$ であれば、右側の木 $T_2$ に p を挿入する。  
なお、$p=c$ であれば、要素 p が既に二分探索木に含まれているので、操作を終了する。
1. 選択した $T_i$ が末端の葉 $l$ である場合、$p,l$ の大小関係に応じて、$p$ を $l$ の左または右の子として挿入する。
1. 選択した $T_i$ が葉でない[^1]場合、$T_i$ に対し、今回定義している $p$ の挿入を再帰的に行う。

[^1]: 2段以上の木である

### 削除
二分探索木 $T$ から要素 $p$ を削除する手順
1. まず、通常の二分探索を行い、$p$ の位置まで移動する[^2]。
1. $p$ が $T$ の葉である場合、$p$ を削除する。
1. $p$ が葉でなく、左側に $p$ より小さい要素の木 $T_1$ を持つ場合、$T_1$ の最大の要素を削除し、$p$ の位置に移動させる。  
また、このような $T_1$ を持たないとき、$p$ は自身より大きい要素のみからなる木 $T_2$ を右側にもつ。この場合は、$T_2$ の最小の要素を削除し、$p$ の位置に移動させる。

[^2]: この際、$p$ が見つからなければ、エラーを出力して操作を終了する。

参考：[ブログ](https://www.momoyama-usagi.com/entry/info-algo-tree)

## (5) 文字列の出現検知方法
### Trie木
今回の問題で登場した文字列の出現検知手法をTrie木という。  
Trie木は、文字列の効率的な検索（re**trie**val）のために使われるデータ構造。現在の位置から始まる文字列が、それ以前にも出現しているかを `True` or `False` で検知する。

### 解答
アルファバットの種類の総数を $m=26$ とおき、文字列の先頭から $i$ 番目の文字から始まる連続した４文字を `a[i:i+4]` と表すことにする。  
文字列を前から走査していき、どのアルファベットでもない空の文字 $\epsilon$ を根とする $m$ 分木を以下の手順で構成していく。
1. はじめに `i=1` とする。
1. `a[i:i+4]` の文字に対応する位置にノードを挿入する。  
なお、途中まで同じ文字列がすでに木構造に存在する場合、そこから枝分かれする形でノードを挿入し、検知結果として `True` を出力する。  
途中まで同じ文字列が存在しない場合、`False` を出力する。
1. `i=i+1` としてこの作業を文字列の終わりまで繰り返すと、各文字列 `a[i:i+4]` の部分文字列がそれ以前に出現しているかを調べることができる。。

### 参考
- [トライ木の解説と実装](https://algo-logic.info/trie-tree/)
- [Wikipedia（Trie木）](https://ja.wikipedia.org/wiki/トライ_(データ構造))

## (6) B木
### B-tree とは
B-tree（B木）は、データを格納するための木構造の１種であり、$O(\log n)$ の計算量[^3]で目的のデータに辿り着くことができる。  
B木の最大の特徴は、各ノードに複数のデータを格納できることであり、データの挿入や削除をする際に操作を工夫することで、木構造が以下の条件を常に満たすようにしている。

- 葉ノード以外は常に２つ以上の以上の子ノードを持つ
- $M$ 個のキー（データ）を持つノードは $M+1$ 個の子ノードを持つ
- 葉ノードはすべて同じレベル（高さ）である
- 各キーにおいて、左の子ノードには小さい値、右の子ノードには大きい値が入る[^4]

[^3]:全レコードを順番に走査する場合の $O(n)$ よりも少ない  
[^4]:したがって親ノードには中間値が入る

### B-tree の応用
![B+ 木](https://camo.qiitausercontent.com/8d789f1b1bb940e79d8ef8b3a0dd9159100e751d/68747470733a2f2f71696974612d696d6167652d73746f72652e73332e61702d6e6f727468656173742d312e616d617a6f6e6177732e636f6d2f302f33353838342f63616339313633362d383062312d613832352d333737362d6639323136306338386364632e706e67)
B-tree を関係データベースに特化させた木構造を B+ 木と呼ぶ。B+ 木では、B-tree の葉のみにデータを格納し、２段目以上の部分を索引（インデックス）として利用する。  
値の検索・挿入・削除の方法は通常の B-tree と同様であるが、B+ 木では葉のノード間にもポインタが用意されている。これにより、関係データベースで多用される **値の範囲検索** を高速化することができる。ただし、データを葉ノードに格納するため、挿入コストは大きくなる。

また、B-tree をファイルシステムに応用した B*木がある。

### 参考
- [Qiita記事](https://qiita.com/higuo/items/c4d6629d28725118bc2d)
- [B木を学ぼう](https://atmarkit.itmedia.co.jp/fcoding/articles/delphi/05/delphi05a.html)
- [Wikipedia（B\*木）](https://ja.wikipedia.org/wiki/B*木#:~:text=B*木（英%3A%20B,のノードと共有する%E3%80%82)

#### B木の由来について
> “B-tree” の名前の由来は、考案者の1人Bayer の頭文字, 考案した時の関係会社 Boeing の頭文字, または Balanced の頭文字等、諸説のうち第1説が有 力だが,本人の釈明もないので、本文では単に B-tree と呼ぶことにする

（[Google](https://www.google.com/search?client=safari&rls=en&q=B%E6%9C%A8%E3%80%80%E7%94%B1%E6%9D%A5&ie=UTF-8&oe=UTF-8)より）

## 配点例
(1)〜(4)：各8点  
(5)〜(6)：各9点  
（50点満点）

{% include foot.html %}