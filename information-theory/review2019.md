{% include head.html %}

# 情報理論2019
## (1) 通信路容量
参考：一様通信路について（[講義スライド](http://yfa23308.a.la9.jp/2016LNs/IT06-20161029.pdf)）

## (2) 定常状態における出現回数

## (3) エントロピーレート
定常情報源におけるエントロピーレートの性質

$$
\lim_{t\rightarrow\infty} \frac{1}{t} H(X_1,\dots X_t) = \lim_{t\rightarrow\infty} \frac{1}{t} H(X_t|,X_1\dots X_{t-1})
$$
から、単純マルコフ情報源においては以下が成立する。

$$
\lim_{t\rightarrow\infty} \frac{1}{t} H(X_1,\dots X_t) = H(X_2|X_1)
$$

エントロピーレートの最大化基準が機械学習における特徴選択に利用されるらしい。

参考：[某サイトの記事](https://academ-aid.com/info-theory/entropy-rate)／[Wikipedia](https://ja.wikipedia.org/wiki/エントロピーレート)

## (4)(5) 条件付きエントロピー
定義に従って忠実に。

## 配点例
各10点（50点満点）

{% include foot.html %}