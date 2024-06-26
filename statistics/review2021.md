{% include head.html %}

# 統計学2021

## 設問１（平均の検定）
### 問題について
母集団が「正規分布, かつ分散 $\sigma^2$ が既知」である標本に関する、平均の検定。この分野は帰無仮説 $H_0$ が棄却されるかという問題が多いが、今回は検出力を求める問題になっている。

### 考察
- 標本 $x_1,\dots,x_n$ の母集団：$N(\mu,4^2)$
- 帰無仮説 $H_0: \mu=\mu_0$
- 対立仮説 $H_1: \mu>\mu_0$

のとき、検出力 $1-\beta$ は $\mu-\mu_0$ や 標本数 $n$ の値に依存する。具体的には(2)の途中式より、$\mu-\mu_0$ や $n$ が大きいほど検出力は高くなる。この理由は次のように解釈でき、確かに直感と一致する。
- $\mu-\mu_0$：推定した平均 $\mu_0$ と母集団の平均 $\mu$ がずれているほど、「本当は平均 $\mu$ なのに、誤って平均 $\mu_0$ と推定される」確率が下がる。
- $n$：参考にできる標本数が多いほど、平均の検定を誤る確率 $\beta$ が下がる。これは第二種の誤りだけでなく、第一種の誤りでも同様である（2022年度　設問４(2)：複数回検定を行った際の第一種の誤り）。

## 設問２（不良品の発生確率・不良率の検定）
(1) 計算問題  
(2) **$\lambda$-ポアソン分布による$(n,p)$-二項分布の近似**：  
$np=\lambda$ を満たしながら $n\rightarrow\infty,\ p\rightarrow 0$ であるとき、$(n,p)$-二項分布 $\approx \lambda$-ポアソン分布となる。  
(3) 中心極限定理を用いる。

## 設問３（期待値・分散・共分散・相関係数）

## 配点例
設問１(1)9点、(2)8点（17点満点）  
設問２(1)3点、(2)6点、(3)8点（17点満点）
設問３(1)7点、(2)9点（16点満点）