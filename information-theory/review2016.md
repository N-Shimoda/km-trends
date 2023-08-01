{% include head.html %}

# 情報理論2016

## 解答の方針
### 素朴な方針
入力記号・出力記号を $X,Y\in\{0,1\}$ とする。入力記号の出現確率を  

$$
\begin{align}
  P_X(0) &= q   \\
  P_X(1) &= 1-q
\end{align}
$$

とおけば、$T$ の通信路容量は $C(p) = \max_{0\leq q\leq 1} I(X;Y)$ となる。微分法を使う場合、

1. $q$ に関する偏微分で $I(X;Y)$ を最大化する $q$ と $C(p)$ を求める
1. $C(p)$ を $p$ で偏微分し、最大・最小値を調べる

という手順になる。この方法が一番厳密であるが、計算量が多いため時間内に解き終わるのが難しい。

### 対称性の利用
では、どうすれば問題を解くことができるか。問題設定をもう一度読み直してみると、通信路の対称性より、$p=0,1,\frac{1}{2}$ あたりが答えになりそうとわかる。  
ここで、通信路容量の定義より必ず $C\geq0$ が成り立つ。実際に $p=1/2$ のとき、$C=0$ となるので、(1) の答えはこれである。  
(2) は、  

$$
C_{\mathrm{max}} = \max_p \{ \max_q I(X;Y) \} = \max_q \{ \max_p I(X;Y) \}
$$

が成り立つことから、相互情報量を $p$ について最大化した後、$q$ について最大化した値が答えとなる。$p$ に関する最大化は定性的に解くことができるので、この方針は比較的簡単である。

### 教訓
- 通信路容量は $C\geq0$ を満たすので、$\exists P_X.\ I(X;Y)=0$ となるのであれば、$C$ の最小値は $0$ である。
- $X,Y$ が独立なほど $C = \max_{P_X} I(X;Y)$ の値は小さく、独立でないほど大きくなる。したがって、入力記号ごとの出力記号の確率に偏りがないほど[^1]、相互情報量は小さくなる。

[^1]: 例えば入力に関する対称通信路では相互情報量 $I(X;Y)$ が小さくなる…はず

## 配点例
(1)(2) 各25点、50点満点

{% include foot.html %}