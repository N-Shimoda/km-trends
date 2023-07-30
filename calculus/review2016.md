{% include head.html %}

# 微分積分2016

## (1) ロンスキアンの性質
### １次独立・１次従属な関数
$c_1f_1(x) + c_2f_2(x) + \cdots + c_nf_n(x) = 0$ がすべての $x$ について成り立つための必要条件が「 $c_1 = c_2 = \cdots c_n$ 」であるとする。このとき、$n$ 個の関数 $f_1(x), f_2(x), \cdots, f_n(x)$ は1次独立であるという。

１次独立でない場合、１次従属であるという。したがって、$f_1(x), f_2(x), \cdots, f_n(x)$ が１次従属であるとき、以下が成り立つ。
> $\exists c_1,c_2,\cdots,c_n.\ (\forall x.\ \sum_{i=1}^{n} c_if_i(x) = 0)$ かつ 「$c_0 = c_1 = \cdots = c_n = 0$」ではない

参考：[金沢工業大学の講義ページ](https://w3e.kanazawa-it.ac.jp/math/category/bibun/bibunhouteisiki/henkan-tex.cgi?target=/math/category/bibun/bibunhouteisiki/kannsuu_no_itijidokuritu.html)

## (2) ロンスキアンと微分方程式
`1.` は証明問題。  
`2.` は `1.` で得た $W(x,y)$ に関する１階線形微分方程式（しかも同時微分方程式）の解を求める問題。

## ロンスキー行列式について
ロンスキー行列式（Wronski determinant）は、微分方程式の分野で用いられる行列式である。(1) の性質 `6.` `7.` より、 

> 関数 $f,g$ が１次従属であれば $W(f,g)=0$

> $W(f,g) \neq 0$ であれば 関数 $f,g$ が１次独立である

が成立する。よって、ロンスキー行列式を使って、微分方程式の解の独立性を証明できる。

ただし、Wikipediaにもあるように、「$W(f,g)=0$ ならば、関数 $f,g$ が１次従属である」は不成立。

参考：[Wikipedia](https://ja.wikipedia.org/wiki/ロンスキー行列式)

## 配点例
(1) 各4点（28点満点）  
(2) 各11点（22点満点）

{% include foot.html %}