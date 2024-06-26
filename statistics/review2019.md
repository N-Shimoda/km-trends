{% include head.html %}

# 統計学2019

## 設問１（二項分布の確率計算）

## 設問２（コインの偏りの検定）
### 解答方針
朱さんやAcademaidの解答では正規分布による近似を用いてP値を求めている。しかし、今回の問題では母集団の平均・分散が未知であり、さらに母集団が正規分布に従うわけでもない。  
したがって、正規分布やスチューデントのt分布を用いた近似計算ではなく、単純な $(5,p)$-二項分布を使った手計算でP値を求めるべきだと考えられる。

## 設問３（独立な仮説検定を繰り返す場合の誤り）

## 設問４（信頼区間）

## 設問５（HARKingの問題点）
### 問題について
**Harking**（Hypothesizing After the Results are Known）  
研究レポートのイントロダクションで事後仮説を事前仮説であったかのように提示すること。この方法を使えば、有意な結果を得たかのように論文を書くことができる。

### その他の研究不正
**p-hacking**  
有意なp値になるまでデータ分析を繰り返して、有意な値がでたら、それを用いて論文を書くこと

**asterisk-seeking**  
データを分析する際に、有意な値ばかりを探すこと

参考：はてなブログ「[HARKing, p-hacking, asterisk-seekingを助長している学術界](https://tomsekiguchi.hatenablog.com/entry/20170727/1501136241#:~:text=HARKingとは、Hypothesizing%20After,ていく行為である%E3%80%82)」

## 配点例
各10点（50点満点）

{% include foot.html %}