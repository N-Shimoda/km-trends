{% include head.html %}

# 平均と分散の性質

$X,Y$ を確率変数とすると、平均・分散について以下が成り立つ。

## 加法性
$$
\begin{align}
E(X+Y) &= E(X) + E(Y)  \\
V(X+Y) &= V(X) + V(Y) + 2\mathrm{Cov}(X,Y)  \\
\end{align}
$$

特に、$X,Y$ が独立であるとき、

$$
\begin{align}
V(X \pm Y) &= V(X) + V(Y)
\end{align}
$$

{% include foot.html %}