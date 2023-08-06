{% include head.html %}

# アルゴリズムとデータ構造2013

文字列検索アルゴリズムである **KMP法**（Knuth-Morris-Pratt algorithm, 1977年）に関する問題。KMP法の問題は2019年度にも出題されている。

## 設問２（部分マッチテーブルの作成方法）
### 基本的な考え方
照合文字列（pattern）を $m$ 文字、テキスト文字列（text）を $n$ 文字とする。また、`pattern[a:b]` で pattern の $a$ 文字目から $b$ 文字目までの部分文字列を表すとする。

マッチングにおいて、pattern の $j$ 文字目（$0 \leq j \leq m-1$）で不一致が発覚した際、基本的には照合位置を $+j$ だけシフトさせることができる。たとえば、pattern の文字が全て異なる場合（"ABCDE"、"ア ル ゴ リ ズ ム"）である。  
ただし、次のようなシフト幅が $+j$ でないケースも存在する。

1. pattern の先頭 $l$ 文字の `pattern[0:l-1]` と、末尾から $l$ 文字の `pattern[j-l+1 : j]` が一致する場合、シフト幅は $j-l$ 文字に短縮される。
1. `pattern[j] = pattern[0]` の場合、$+j$ シフトさせた後に `pattern[0]` とテキストの同じ文字を照合しても、当たり前だが一致しない。この場合、シフト幅は $j+1$ にする必要がある。  
同様に、pattern の先頭に `pattern[j]` の文字が連続する場合、すなわち $x=0,1,\cdots,d < j$ に対して `pattern[x] = pattern[j]` である場合、シフト幅は $j+d$ まで増やすことができる。

Wikipediaのアルゴリズムでは１つ目のみを考慮しており、pattern $= X_l\ Y\ X_l$ となるような最長の部分文字列 $X_l$ の長さを求めたのち、`shift[j] = j-l` と計算している。シフト幅短縮のみを実装すれば、シフト幅の増加（KMP法の高速化）を実装しなくてもアルゴリズムは正しく動作する。   
ただし、今回の問題では、問題文の具体例 (a) でシフト幅の増加も示されており、両者を実装する必要がある。

シフト幅短縮のみのアルゴリズムで `shift[j] = j - l` を求めることができれば、先に述べた $d$ を調べることで、今回の問題でのシフト幅は `shift[j] = j - l + d` として実装できる。  
そこで、以下では簡単のため **シフト幅短縮のみ** を実装したアルゴリズムを示す。

### 解答１（$X_l$ を線形走査で探す）
pattern と text のある部分を先頭から照合していく際、pattern の $j$ 文字目で初めて不一致が判明した場合のシフト幅を `shift[j] = j - T[j]` とおく。このとき、`T[j]` は pattern $= X_l\ Y\ X_l$ となるような最長の部分文字列 $X_l$ の長さであるので、次のような線形走査で調べることができる。ただし、$X_l$ は pattern の*真の*部分文字列である必要がある（i.e. pattern $\neq X_l$）

> 

    algorithm get_T(j, pattern):

        l_max = 0   (* 見つかっている X_l で最長のものの長さ *)

        (* pattern の先頭から j-2 文字目までで最長の X_l を探す *)
        for l = 0 to j-2:

            if pattern[0:l] = pattern[j-l:j]:
                l_max = l
            else:
                l_max = l_max   (* use previous value *)
        
        return l_max

### 別解（木構造を使った解答）
pattern を先頭から走査し、次の手順で１本の経路のみを持つ木を構築する。この過程で `T[j]` を計算していくことができる。

1. `pattern[0]` の文字を木の根する。 
また、`j=1` とする。
1. `pattern[j]` の文字を先に作ったノードの子として追加する。
1. このとき、ビット `s` が付与されたノードがあれば、そのうち深さが最も深いノードの深さ `l` を `T[j]` とする。そのようなノードがなければ、`T[j] = 0` とする。
1. 次に、`s` が付与されたノードのうち最も深いノードの子と `pattern[j]` が一致するかを確認する。一致する場合、最も深いノードの子にもビット `s` を付与する。  
1. 木構造にビット `s` が1つもない場合、木の根と `pattern[j]` の文字が同じであれば、木の根にビット `s` を付与する。
1. `j=j+1` として Step 2 に戻る。これを `j=m-1` まで繰り返す。

この方法では、各時点 `j` で `s` が付与されているノードが、`pattern` に含まれる最長の $X_l$ を表す。

## 疑似コード
Wikipediaより
### メインコード
> 

    algorithm kmp_search:  

        input:
            an array of characters, S (検索対象のテキスト)
            an array of characters, W (単語)
        output:
            an integer (W が見つかった際の S 内の位置。ただし先頭文字は 0番目とする)

        define variables:
            an integer, m ← 0 (S 内の現在照合中の開始位置)
            an integer, i ← 0 (W 内の現在位置)
            an array of integers, T (テーブル。他で事前に構築される)

        while m + i is less than the length of S, do:
            if W[i] = S[m + i], let i ← i + 1
                if i equals the length of W, return m
            otherwise, let m ← m + i - T[i], and if i > 0, let i ← T[i]

        (W が S 内に見つからなかった場合)
        return the length of S

### 部分マッチテーブル `T[i]` の生成
> 

    algorithm kmp_table:

        input:
            an array of characters, W (解析すべき単語)
            an array of integers, T (生成すべきテーブル)
        output:
            nothing (ただし、処理を行うことでテーブルの中身が書き込まれる)

        define variables:
            an integer, i ← 2 (T の中で現在計算している位置)
            an integer, j ← 0 (現在見ているサブ文字列の次の文字のインデックス。0から始まる)

        (先頭ふたつの値は固定。ただしアルゴリズムの実装によっては具体的値は異なる)
        let T[0] ← -1, T[1] ← 0

        while i is less than the length of W, do:
            (第一の場合: サブ文字列は継続中)
            if W[i - 1] = W[j], let T[i] ← j + 1, i ← i + 1, j ← j + 1

            (第二の場合: サブ文字列は継続しないが、フォールバック可能)
            otherwise, if j > 0, let j ← T[j]

            (第三の場合: 対象をはみ出した。このとき j = 0)
            otherwise, let T[i] ← 0, i ← i + 1

## 参考
- [Wikipedia（KMP法）](https://ja.wikipedia.org/wiki/クヌース–モリス–プラット法)

## 配点例
設問１：(i)(ii) 各6点  
設問２：23点  
設問３：(1)-(3) 各5点  
（50点満点）

{% include foot.html %}