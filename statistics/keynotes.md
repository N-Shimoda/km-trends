{% include head.html %}

# 統計学 メモ

## 大数の法則と中心極限定理
### 大数の法則（Law of Large Numbers）
事象 $A$ が確率 $p$ で発生するとする。このとき、試行回数 $n$ を限りなく増やしていくと、観測された事象の頻度は $p$ に収束する。  
異なる２つの定義が存在する。

**大数の弱法則**（by ベルヌーイ）
$$
\lim_{n\to\infty}P(|\bar{X_n}-\mu|>\epsilon)=0
$$

**大数の強法則**（by ボレル, コルモゴロフ）
$$
P(\lim_{n\to\infty}\bar{X_n}=\mu)=1
$$

### 中心極限定理（Central Limmit Theorem）  
母集団によらず、和 $X_1+X_2+\dots+X_n$ の確率分布の形は、$n\rightarrow\infty$ のとき大略正規分布と見做せる。すなわち
$$
\begin{align}
  S_n=X_1+X_2+\dots+X_n\approx N(n\mu,n\sigma^2) \\
  \bar{X}=(X_1+X_2+\dots+X_n)/n\approx N(\mu, \sigma^2/n)
\end{align}
$$
ただし、$\mu, \sigma^2$ は母集団の平均・分散