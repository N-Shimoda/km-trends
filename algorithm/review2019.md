{% include head.html %}

# アルゴリズムとデータ構造2019

## F2-1（マージソート）
以下の別解が考えられる？
- (1)(a)「`i != len(L) or j!= len(R)`」
- (1)(d)「`L[i] < R[j]`」

## F2-2（文字列のマッチング）
朱さんの (3) の解答が間違っている。  
KMP法の平均時間計算量は $O(n)$

### メモ
主要な文字列探索アルゴリズム
- ナイーブ法：textの先頭から1文字ずつを比較。不一致の場合は1文字だけシフトする。
- KMP法[^1]：今回の問題のアルゴリズム。不一致の場合のシフト幅を工夫する。
- BM法[^2]：文字列をpatternの最終文字から順に比較する。

[^1]: Knuth Morris Pratt法
[^2]: Boyer Moore法

### 参考サイト
- [文字列探索アルゴリズムとは？](https://products.sint.co.jp/topsic/blog/string-searching-algorithm)  
- [Wikipedia](https://ja.wikipedia.org/wiki/クヌース–モリス–プラット法)

## 配点例
### F2-1
(1) (a)-(d)各2点、(2) 8点、(3) 9点  
25点満点

### F2-2
(1) 各4点、(2) 6点、(3) 11点  
25点満点