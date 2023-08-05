{% include head.html %}

# アルゴリズムとデータ構造2013

文字列検索アルゴリズムである **KMP法**（Knuth-Morris-Pratt algorithm, 1977年発表）に関する問題。KMP法の問題は2019年度にも出題されている。

## 設問２（部分マッチテーブルの作成方法）
### 基本的な考え方
照合文字列（pattern）を $m$ 文字、テキスト文字列（text）を $n$ 文字とする。また、`pattern[a:b]` で pattern の $a$ 文字目から $b$ 文字目までの部分文字列を表すとする。  
マッチングにおいて、pattern の $j$ 文字目（$0 \leq j \leq m-1$）で不一致が発覚した際、基本的には照合位置を $+j$ だけシフトさせる必要がある。ただし、pattern の先頭 $l$ 文字の `pattern[0:l-1]` と、末尾から $l$ 文字の `pattern[j-l+1:j]` が一致する場合、シフト幅は $j-l$ 文字に短縮される。  
よって、pattern = $X_l \cdot Y \cdot X_l$ となるような最長の部分文字列 $X_l$ の長さを求めれば、`shift[j]=j-l` と計算できる。

### 答案１（Wikipediaの方法？）

### 答案２（trie木の利用）

## 参考
- [Wikipedia（KMP法）](https://ja.wikipedia.org/wiki/クヌース–モリス–プラット法)

## 配点例
設問１：(i)(ii) 各6点  
設問２：23点  
設問３：(1)-(3) 各5点  
（50点満点）

{% include foot.html %}