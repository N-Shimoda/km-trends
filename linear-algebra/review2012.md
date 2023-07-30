{% include head.html %}

# 線形代数2012

## (1) 行列の対角化
### 逆行列の求め方（復習）
#### 2次行列の場合
$$A^{-1} = \frac{1}{ad-bc} \begin{pmatrix} d & -b \\ -c & a \end{pmatrix}$$

#### 3次以上の場合（掃き出し法）
$\begin{pmatrix} A & E \end{pmatrix}$ に行基本変形を行い、$\begin{pmatrix} E & B \end{pmatrix}$ と変形する。  
このとき、$A^{-1}=B$ となる。

#### 3次以上の場合（余因子行列の利用）
行列 $A$ の $(i,j)$ 余因子 $\tilde{a_{ij}}$ に対し、$\tilde{A} = (\tilde{a_{ji}}) = (\tilde{a_{ij}})^T$ を余因子行列という。  
このとき、
$$A^{-1} = \frac{\tilde{A}}{detA}$$

#### 練習問題
以下の逆行列を求めよ。
$$
A = 
\begin{pmatrix}
-2 & 0 & 1 \\
1  & 1 & 1 \\
-1 & 1 & 0 \\
\end{pmatrix}
$$

#### 参考
- [3行3列以上の逆行列](https://ss1.xrea.com/mmath.s205.xrea.com/E/E1-3.html)
- [逆行列を求める2通りの方法](https://manabitimes.jp/math/1153)（数学の景色）

### 関連問題
p.389：重要例題081, 082など

## (2) 数列の一般項
(1) の $A$ は数列 $(x_n,\ y_n,\ z_n)$ の遷移行列になっている。  
よって、一般項は以下のようになる。
$$
\begin{align}
(x_n,\ y_n,\ z_n)^T &= A^n (x_0,\ y_0,\ z_0)^T \\
                    &= P D^n P^{-1} (x_0,\ y_0,\ z_0)^T 
\end{align}
$$
ただし、$D=P^{-1}AP$

## 配点例
(a)(b) 各25点

{% include foot.html %}