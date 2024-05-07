#set text(
  font: "New Computer Modern",
  size: 6pt
)
#set page(
  paper: "a5",
  margin: (x: 1.8cm, y: 1.5cm),
)
#set par(
  justify: true,
  leading: 0.52em,
)
#set heading(numbering: "1.")
=  向量空间
行列式只能判别n个未知量,n个方程的线性方程组的解的情况，并且，当行列式为0时，n维向量空间就是从另外一个角度，来研究解的情况。

取数域K上任意n个数组成的有序数组:
$
K^n ={(a_1, a_2, ... ,a_n) | a_i in K }
$
如果$K^n$中的两个元素有$a_i = b_i$. 则称这两个元素相等。
加法定义:
$
(a_1, a_2, ...,  a_n) + (b_1, b_2, ..., b_n) = ((a_1+b_1),(a_2+b_2),..., ((a_n+b_n)))
$
标量乘法:
$
k(a_1,a_2, ...,a_n) = (k a_1, k a_2, ..., k a_n)
$

#let a = math.bold($alpha$); 
#let b = math.bold($beta$); 
#let c = math.bold($gamma$)
对于#a、#b、#c $in K^n$，容易验证以下8条规则:

加法的4条法则：
1. 加法交换律 $#a + #b = #b + #a$
2. 加法结合率 $#a + #b + #c =  (#a + #b) + #c$
3. $bold(0) + #a = #a + bold(0) = #a$, 我们把$bold(0)$称为0元，也是加法的单位元
4. 对于$#a$, 定义$-#a = (-a_1,-a_2, ..., -a_n) -> #a + (-#a) = bold(0)$, $-#a$ 称作$#a$的负元

乘法的4条法则：
5. $1 #a = #a$,注意这里的1是标量 
6. $(k l)#a = k(l#a)$
7. $(k+l)#a = k#a + l#a$
8. $k(#a + #b) = k#a + k#b$

以上定义及其规律，我们可以从平面或者立体向量联想得出，同样的后续的向量空间，在1维时，对应的就是一条直线，在2维时，对应的就是一个平面空间，在3维时就是一个立体空间，在4维时就是一个时空空间，更高维则不能从物理角度出发去联想了。

我们也可以把系数矩阵的每一行当做一个行向量，那么矩阵的初等行变换（不包括行交换），就对应于上面的加法、标量乘法运算。

以上8条法则，实际上是被定义出来的（参考邱维声 高等代数下册 第8章），这里不做介绍了

== 向量空间定义
数域K上所有的n元有序数组组成的集合$K^n$, 连同上述定义的运算规则一起，称作数域K上的一个#highlight()[n维向量空间x，$K^n$中的元素称为n维向量]。对于$#a = (a_1,a_2, ...,a_i, ..., a_n)$, $a_i$ 叫做$#a$的第i个分量

上述线性空间中的n元有序数组可以写成行或者写成列的形式，写成行时，是行向量；写成列时，是列向量，列向量可以看成行向量的转置。

给定一个系数数组$(k_1,k_2, ...,k_n)$,将其与n个向量分别乘加$k_1 (#a _1) +k_2 (#a _2) + ... + k_n (#a _n) = bold(b)$, 则称$bold(b)$ 是向量组$(#a _1,#a _2, ..., #a _n) $的一个线性组合。 在$K^n$中，如果$#b in K^n$, 并且存在一组系数$(k_1,k_2, ...,k_n)$, 能满足:$k_1 (#a _1) +k_2 (#a _2) + ... + k_n (#a _n) = #b $, 则就称$#b$ 可以被向量组$(#a _1,#a _2, ..., #a _n) $线性表示

现在我们再看线性方程组:
$
cases(
  a_11 x_1 + a_12 x_2 + ... + a_(1 n)x_n = b_1,
  a_21 x_1 + a_22 x_2 + ... + a_(2 n)x_n = b_2,
  dots.v,
  a_(m 1) x_1 + a_(m 2) x_2 + ... + a_(m n)x_n = b_m,
)
$
注意，这里可能$m!=n$,我们将系数矩阵的每1列都看做一个列向量，把$x_1,x_2, ..., x_n$，则方程组就可以表达为:
$x_1 bold(a_1) + x_2 bold(a_2) + ... + x_n bold(a_n) = bold(b)
$
#highlight()[即常数项组成的向量$bold(b)$ 能否被列向量组$bold(a_1), bold(a_2), ... bold(a_n)$线性表示。]
（此处的线性表示，不限定系数是否全为0，当系数全为0时，则表示的向量一定是一个0向量）
== 向量空间的子空间 （imortant）
对于任意$#a, #b in U$, U是$K^n$的一个非空子集，如果满足:
1. 加法封闭 $#a + #b in U$
2. 标量乘法封闭 $l #a in U$
则就称U是$K^n$的一个线性子空间，或者子空间，向量组$bold(a_1), bold(a_2), ... bold(a_n)$ 的所有线性组合组成了$K^n$的一个子空间，称其为$bold(a_1), bold(a_2), ... bold(a_n)$#highlight()[张成的一个子空间]，记作$<bold(a_1), bold(a_2), ... bold(a_n)>$
所以就有以下推论:

$x_1 bold(a_1) + x_2 bold(a_2) + ... + x_n bold(a_n) = bold(b)
$ 有解 $<->$ $bold(b)$ 可以由$bold(a_1), bold(a_2), ... bold(a_n)$线性表示 $<->$$ bold(b) in <bold(a_1), bold(a_2), ... bold(a_n)>$ 此处解可能不唯一，注意这里无穷多解的情况被合并到有解中；在前面的行列式章节内，无穷多解的情况被合并到无解中。

向量空间和线性空间的关系：
1. 向量空间只封闭了空间内的加法和标量乘法，而线性空间则封闭了更多运算。对于子空间同理。向量空间可以认为是线性空间的子集或者特例
2. 向量空间，通常是有限维的
3. 向量空间中的元素都是向量， 线性空间中的元素可以是向量、矩阵、或者其他东西

= 线性相关的向量组和线性无关的向量组（important）
== 向量组线性无关和相关的定义
#let inr_express=$k_1 bold(a_1) + k_2 bold(a_2) + ... + k_n bold(a_n)$
#let parameters=$(k_1,k_2, ..., k_n)$
#let vectors=$(bold(a_1) , bold(a_2), ..., bold(a_n)  )$
#let zv = $bold(0)$
#let ceq = $<->$
类似于我们前面提到的齐次线性方程组，对于公式:$#inr_express = bold(0)$, 如果有不全为0的系数$#parameters$,使得此公式成立，则称$#vectors$是#highlight()[线性相关]的；否则，即只有$k_1=k_2 = ... = k_n = 0$ 使得此公式成立，则称#vectors 是#highlight()[线性无关]的

#highlight(fill:red)[线性无关时，如果我们尝试用$(bold(a_k))\\ bold(a_i)$ 表示$bold(a_i)$, 则需要除0，因此不存在任何系数能使得$(bold(a_k))\\ bold(a_i)$ 表示$bold(a_i)$, 这就是无关的内涵]
=== 从其他角度理解向量组无关和相关
线性相关和线性无关是线性代数中最为重要的概念之一，有以下几个方面的内涵（以下的向量组表示中，向量数$>1$）
1. 从线性组合来看：
  - 线性相关：#vectors 可以通过不全为0的系数序列，组合成$bold(0)$向量
  - 线性无关：#vectors 只有全为0的系数序列，才能组合成$bold(0)$向量
2. 线性表示
  - 线性相关，#vectors 中至少某一个向量可以表示为其他向量的线性组合（考虑将被表示的向量移动到等式右侧即可得证）
  - 线性无关，#highlight()[每一个向量都不能被其他向量线性表示]
  - 如果向量$bold(b)$可以被#vectors 线性表示，那么
    - #vectors 线性相关 #ceq $bold(b)$ 被表示的方式不唯一
    - 。。。。。 线性无关 #ceq $bold(b)$ 被表示的方式唯一
      - 即线性方程组$#vectors=bold(b)$ 在有解时，解的区分情况
3. 齐次线性方程组
  - 齐次线性方程组的列向量组是线性相关的$<->$齐次线性方程组有非0解
  - ......................线性无关的..$<->$ ...... 只有0解
4. 行列式(行列式限定矩阵为方阵)，#vectors 中每个向量需要是n维向量
  - 以#vectors 构成的矩阵的行列式等于0 $<->$ #vectors 线性相关，这个可以由行列式与齐次线性方程组解的关系得出，同时结合3
  - 。。。。。。。。。。。。不等于0 $<->$ #vectors 线性无关
5. 如果#vectors 中的一部分$(bold(a_i), ..., bold(a_s))$ 线性相关，则整体线性相关
  - 如果 #vectors 整体线性无关，则 其任意一部分也线性无关 （考虑通过反证法），其实就是命题5. 的#highlight()[逆否命题]
6. 如果#vectors 整体线性无关，则在每个向量上扩充其维度（相当于增加方程组个数），则扩充后的延伸组依然线性无关,这个证明很自然，因为使得扩充后的向量组的每个向量前$n$个分量，使得#inr_express = $bold(0)$ 的条件只有#parameters 全为0（这是定义），所以扩充后的向量组 使得该公式成立的条件依然只有#parameters 全为0
  - 如果#vectors 线性相关，则对于其中每个向量减去m个分量，得到的缩短向量组，也是线性相关的（6.的逆否命题）
==== 6 的证明
下面 证一下6.
#let cvectors=$(bold(c_1), bold(c_2), ..., bold(c_n))$
对于#vectors $in K^n$, 设其线性无关，那么设#cvectors $in K^(n+m)$ 是扩充后的向量组，根据线性无关定义:$
cases(k_1 a_(11) + k_2 a_(12) + ... + k_n a_(1n) = 0,
k_1 a_(11) + k_2 a_(12) + ... + k_n a_(1n) = 0,
dots.v,
k_1 a_(n 1) + k_2 a_(n 2) + ... + k_n a_(n n) = 0,
) <->^(扩 充 后) cases(
k_1 a_(11) + k_2 a_(12) + ... + k_n a_(1n) = 0,
k_1 a_(11) + k_2 a_(12) + ... + k_n a_(1n) = 0,
dots.v,
k_1 a_(n 1) + k_2 a_(n 2) + ... + k_n a_(n n) = 0,
k_1 a_(n+1, 1) + k_2 a_(n+1, 2) + ... + k_n a_(n+1, n) = 0,
dots.v,
k_1 a_(n+m, 1) + k_2 a_(n+m, 2) + ... + k_n a_(n+m, n) = 0,
)
$
根据线性无关定义，使得扩充后的前n个等式成立的条件，只有#parameters 全为0，从而扩充后的向量组依然是线性无关的

对于其逆否命题，我们设#vectors 是线性相关的，即
$
cases(k_1 a_(11) + k_2 a_(12) + ... + k_n a_(1n) = 0,
k_1 a_(11) + k_2 a_(12) + ... + k_n a_(1n) = 0,
dots.v,
k_1 a_(n 1) + k_2 a_(n 2) + ... + k_n a_(n n) = 0,
) <->^(缩 短 m) 
cases(k_1 a_(11) + k_2 a_(12) + ... + k_n a_(1n) = 0,
k_1 a_(11) + k_2 a_(12) + ... + k_n a_(1n) = 0,
dots.v,
k_1 a_(n-m, 1) + k_2 a_(n-m, 2) + ... + k_n a_(n-m, n) = 0,
) 
$
根据线性相关定义，存在不全为0的#parameters 使得上述任意一项等式成立，从而对于缩短后的等式组也成立，从而得出缩短后的向量组，依然线性相关
==== 2. 的证明
这里再给一下 2. 的第三部分的证明
1. 假设$bold(b)$ 可以被#vectors 线性表出，并且#vectors 线性相关，那么就有$t_1 bold(a_1) + t_2 bold(a_2) + ... t_n bold(a_n) = bold(b)$，同理，因为#vectors 线性相关，则$#inr_express = 0$ 中的系数$(k_1,k_2, ..., k_n)$ 不全为0， 那么令$m_i=(t_i + k_i)$, 则$m_i bold(a_1) + ... + m_i bold(a_n) =  k_1 bold(a_1) + ... + k_n bold(a_n) + t_1 bold(a_1) + ... + t_n bold(a_n) = bold(0) + bold(b) = bold(b)$, 又因为$(k_i)$ 不全为0，那么$(m_i) != (t_i)$. 从而$bold(b)$ 表出方式不唯一 

2. 假设$bold(b)$ 可以被#vectors 线性表出，并且#vectors 线性无关，我们假设b 有两个不同的表出方式，其系数$(s_i)$ 和$(t_i)$, 令$(m_i) = (s_i - t_i)$, 那么就有$sum_i m_i bold(a_i) = sum_i s_i bold(a_i) - sum_i t_i bold(a_i) = bold(b) - bold(b) = bold(0)$，又因为#vectors 线性无关，则#inr_express 中的系数$0 = (k_i) = (m_i) = (s_i - t_i) => s_i = t_i$，与假设矛盾，从而$bold(b)$的表出方式唯一

补充2.的正面的主要目的是这个正面过程和后面的线性方程组的解联系比较紧密，同时我们可以看到，在代数领域，我们主要通过抽象化的各种解而不是具某个数值的解做逻辑推理。


=== 命题 1 设向量组#vectors 线性无关，则$bold(beta)$ 可以被#vectors 表示的充要条件是$[bold(beta), #vectors]$ 线性相关。下面只证明充分性

证，设#vectors 线性无关，且$[bold(beta), #vectors]$线性相关，则根据定义有:$#inr_express + l bold(beta) = bold(0)$，如果$l = 0$,则$#inr_express = bold(0) -> 与 已 知 条 件 矛 盾$，因此$l!=0$，从而有:$bold(beta) = -(#inr_express)/l$

== 极大线性无关组
=== 1. 极大线性无关组定义
假设$bold(beta)$可以被#vectors 线性表示，如果#vectors 是线性无关组，则表示方式唯一（见前述推论2）， 如果#vectors 线性相关，则表示方式不唯一。如果我们能在#vectors 找到一个部分组是线性无关的，当从其余向量中往该组中再添加一个向量时，则该组变成线性相关的。这个部分组就称为#vectors 的一个极大无关组。#highlight()[极大无关组可能不唯一]

=== 2. 向量组等价
#let bvectors=($(bold(b_1), bold(b_2), ..., bold(b_r))$)
#let cvectors=($(bold(c_1), bold(c_2), ..., bold(c_s))$)
如果向量组#vectors 中的每一个向量$bold(a_i)$ 都可以被#bvectors 线性表示，同时#bvectors 中的每个向量都可以被#vectors 线性表示。#highlight()[则称两个向量组等价, 记作$#vectors =^(~) #bvectors$]， 注意定义中，#highlight()[是每一个向量都可以被另外一者线性表示]

等价关系是$K^n$中的向量组之间的一种关系，这种关系有以下性质:
1. 反身性: 任何一个向量组都与自身等价
2. 对称性: $#vectors =^(~) #bvectors <-> #bvectors =^(~) #vectors$
3. 传递性: $#vectors =^(~) #bvectors,   #bvectors =^(~) #cvectors  => #vectors =^(~) #cvectors$

下面对第3点证明:
$
#vectors =^(~) #bvectors => bold(a_i) = sum_(j = 1)^(r)b_(i j)bold(b_j);\
#bvectors =^(~) #cvectors => bold(b_j) = sum_(k = 1)^(s) c_(j k) bold(c_k);\
=> bold(a_i) = sum_(j = 1)^(r)b_(i j)[sum_(k = 1)^(s) c_(j k) bold(c_k)]
$
我们对这个式子做一些展开
$
bold(a_i) =  sum_(j = 1)^(r)b_(i j)[sum_(k = 1)^(s) c_(j k) bold(c_k)] = sum_j b_(i j) [c_(j 1)bold(c_1) + c_(j 2) bold(c_2) + ... + c_(j_s) bold(c_s)] =sum_j  b_(i j)(c_(j 1)) bold(c_1) + sum_j b_(i j)(c_(j 2)) bold(c_2) + ... + sum_j b_(i j) (c_(j s)) bold(c_s) = (k_1 bold(c_1) + k_2 bold(c_2) + ... + k_s bold(c_s))
$
反之亦然

=== 命题1. 向量组与其极大线性无关组等价
#let inr_group = $(bold(a_1), bold(a_2), ..., bold(a_m))$
1. 根据极大线性无关组定义， 该向量组可以被原向量组直接线性表示
2. 根据极大线性无关组定义，设线性无关组为#inr_group, 对于$m<j<=n, bold(a_j)$一定可以被该无关组线性表示，那么其整体都可以被该无关组线性表示
  - 综上所述，该命题成立

=== 推论1. 向量组的任意两个极大线性无关组等价:
  - #highlight()[由性质3.（传递性） + 命题1. 可得证]

=== 推论2. $bold(beta)$ 可以由#vectors 线性标出 当且仅当 $bold(beta)$ 可以被#vectors 的一个极大线性无关组线性表出
  - #vectors 等价于其一个极大线性无关组，根据传递性可知$bold(beta)$ 可由该无关组线性表出；同理，当$bold(beta)$可被一个极大无关组标出时，根据 推论1， 其一定可以被#vectors 线性表出

=== 引理1. 若#bvectors 可以被 #vectors 线性表示，且 $r>n$，则#bvectors 线性相关 
证明（important）
如果 #bvectors  可被#vectors 线性表出，那么:

$bold(b_1) = a_(11)bold(a)_1 + a_(12)bold(a)_2 + ... + a_(1 n) bold(a)_n \
bold(b_2) = a_(2 1)bold(a)_1 + a_(2 2)bold(a)_2 + ... + a_(2 n) bold(a)_n\
dots.v\
bold(b_r) = a_(r 1)bold(a)_1 + a_(r 2)bold(a)_2 + ... + a_(r n) bold(a)_n => x_1 bold(b_1) + x_2 bold(b_2) + ... + x_r bold(b_r) = \
x_1(a_(11)bold(a)_1 + a_(12)bold(a)_2 + ... + a_(1 n) bold(a)_n ) + x_2(a_(2 1)bold(a)_1 + a_(2 2)bold(a)_2 + ... + a_(2 n) bold(a)_n) + ... + x_r (a_(r 1)bold(a)_1 + a_(r 2)bold(a)_2 + ... + a_(r n) bold(a)_n) = \
(a_11 x_1 + a_21x_2 + ... + a_(r 1)x_r)bold(a)_1  + (a_12 x_1 + a_22 x_2 + ... + a_(r 2) x_r)bold(a)_2 + ...+ (a_(1 n) x_1 + a_(2 n) x_2 + ... + a_(r n)x_r) bold(a_n) <- 共 n 项
$ 

若$bvectors$ 线性相关，那么存在一组不全为0的数$(x_1, x_2, ..., x_r)$，使得$ x_1 bold(b_1) + x_2 bold(b_2) + ... + x_r bold(b_r) = bold(0)$. 对应于展开式中，我们将设每一项的系数的结果都为0，这样整体就是一个$bold(0)$, 按照这个思路，我们构造这样的方程:
$
cases(
a_11 x_1 + a_21 x_2 + ...+a_(r 1) x_r = 0,
a_12 x_1 + a_22 x_2 + ...+a_(r 2) x_r = 0,
dots.v,
a_(1 n) x_1 + a_(2 n) x_2 + ...+a_(r n) x_r = 0,
)
$ 我们得到了一个有r个未知量，有n个方程的齐次线性方程组，（观察系数a的指标，从1到n，故而有n个方程），因为$r>n$ 所以，该方程组必有非0解。取任意一个非0解$(k_1, k_2, ..., k_r)$, 代入 $ x_1 bold(b_1) + x_2 bold(b_2) + ... + x_r bold(b_r)$的展开式中, 有:
$
(a_11 k_1 + a_21 k_2 + ... + a_(r 1)k_r)bold(a)_1  ...+ (a_(1 n) k_1 + a_(2 n) k_2 + ... + a_(r n)k_r) bold(a_n) = 0bold(a)_1 + 0bold(a)_2 + ... + 0bold(a)_n = bold(0)
$

得证。这里要注意的是#vectors 并不要求是线性无关的

从引理1 可以推出(逆否命题)
=== 推论3 设#bvectors 可由 #vectors 线性表出，若 #bvectors 线性无关，则 $r <= n$
除了逆否命题外，可以考虑引理1.中得到的系数方程组 只有0解的条件必须满足$n >= r$(必要条件，但不充分), 从而得证
=== 推论4. 两个等价的线性无关的向量组，向量个数相等
从推论3可以得出， 即$#bvectors$ 线性无关且可以被#vectors 表示，则$r <= n$，又$#vectors$ 线性无关且可被#bvectors 表出，则$n <= r$，则$n=r$
=== 推论5.  向量组的任意两个极大无关组的向量个数相等
结合 推论4. + 推论1. 可得证。 推论1. 说明了两个极大无关组可以互相标出，推论4.结合了极大无关组得线性无关定义，限定了两者个数相等
== 定义 #highlight(fill: green)[向量组的极大线性无关组所含向量个数成为该向量组的秩，全为0向量的向量组的秩规定为0，记作$r a n k(#vectors)$] 
=== #highlight(fill:red)[命题2. #vectors 线性无关的充要条件是它的秩等于向量个数]
证:
因为#vectors 线性无关，因此其极大线性无关组是其自身$=>$ $r a n k #vectors = n$

命题2 表明了秩的重要性，通过一个自然数就可以分析出一个向量组是否线性无关，在结合线性无关的概念及含义，可以直接得到很多结论。

== 秩的比较
=== 命题3.  如果(1)可以被(2) 线性表出，则前者的秩小于或等于后者的秩 即$r a n k{(1)} <= r a n k {(2)}$
1. 设#bvectors 是(1)的一个极大线性无关组，#vectors 是（2）的一个极大线性无关组，由命题1，可知#bvectors 等价于(1)，而(1) 又可以被 (2) 线性表出,(2) 等价于 #vectors, 则可知#bvectors 可以被 #vectors 线性表出，根据推论3. #bvectors  向量个数小于 #vectors 向量个数，即$r a n k{(1)} <= r a n k {(2)}$

=== 命题4.  等价的向量组有相等的秩（必要但不充分）
证明：若两个向量组等价，则可以互相表出，则其设其极大无关组分别为$a$和$b$, 那么a被b表示时，则$r a n k(a) <= r a n k(b)$，同理，b 被a 表出时$r a n k(b) <= r a n k(a)$ 从而$r a n k(a) = r a n k(b)$，从而得证。

但反过来不一定。秩可以理解为向量组降维的特征，不能直接代表向量组本身，并且上面的向量组讨论秩时，也没有限定向量的维度


== #highlight(fill:red)[向量空间的基、标准基以及维数(最重要概念)]
原书这部分内容有点循环引用的意思，即为了说明A，需要引入B，而B的定义又依赖A。所以有点生涩

定义1. 向量空间的基

设U是$K^n$的一个子空间， 并且$#vectors in U$, #vectors 同时能满足以下性质：
1. #vectors 线性无关
2. U 中任意向量都可以被#vectors 线性表出

此时，我们称#vectors 是 U的一个#highlight(fill: red)[基]

(注：如果#vectors 每个向量的模长都是1，那么这个基就称为U的一个标准基，如果#vectors 是标准基，并且满足$bold(a_i)dot bold(a_j) = 0$ 这样的基称为标准正交基)
#let KSpace =$K^n$
=== 定理1. $K^n$的任意非零子空间都有一个基

这里补充一个命题， $K^n$ 中的线性无关组所含向量个数至多为$n$

证，利用反证法，不仿设$(bold(a_1),bold(a_2), ..., bold(a_n), bold(a_(n+1)))$ 是$K^n$的一个线性无关组，那么对于方程组:
$cases(
  x_1a_(11) + x_2a_(21) + ... + x_n(a_(n 1)) + x_(n+1)(a_(n+1, 1)) = 0,
  x_1a_(12) + x_2a_(22) + ... + x_n(a_(n 2)) + x_(n+1)(a_(n+1, 2)) = 0,
  dots.v,
  x_1a_(1n) + x_2a_(2n) + ... + x_n(a_(n n)) + x_(n+1)(a_(n+1, n)) = 0,
)
$ 

应当只有0解，但是上面的方程组未知量个数(n+1)多于方程个数(n), 因此必有非0解，取任意非0解$(k_1, k_2, ..., k_(n+1))$ 均能使得$k_1(bold(a_1)) + ... + k_(n+1)(bold(a_(n+1))) = bold(0)$ 成立，则其该向量组线性相关，与假设矛盾，因此命题得证

接下来证定理1.
从U中取一个非0向量$bold(a_1)$, 若$<bold(a_1)> != U$, 那么必然可以从U中再取一个$bold(a_2)$； 若$<bold(a_1)> = U$, 那么$(a_1)$ 就是U的一个基。其不可以被$bold(a_1)$线性表出。若$<bold(a_1), bold(a_2)> !=U$, 那么可以取到$bold_(a_3)$ 不可以被$(bold(a_1), bold(a_2))$ 线性表出，如果$<bold(a_1), bold(a_2)> =U$,那么$(bold(a_1), bold(a_2))$ 就是U的一个基，依次类推。又根据上面的命题（$K^n$的线性无关组所含向量数至多为n），这个步骤至多可以重复到n次，不妨设为s次，那么$(bold(a_1), bold(a_2), ..., bold(a_s))$ 就是U的一个基。从而得证。

=== 定理2. $K^n$的非零子空间U的任意两个基所含向量个数相等
根据基的定义，设U的两个基分别为$#vectors$ 和#bvectors, 那么$#vectors =^(~) #bvectors$, 又两者线性无关，根据（极大线性无关组/推论4. 两个等价的线性无关组所含向量个数相同），定理得证

=== 定义2. $K^n$ 非0子空间U的一个基所含向量个数称为U的维数，记作$dim_K U$ 或者$dim U$
#highlight()[零子空间的维数定义为0]

#highlight(fill: green)[这里特别要注意，U的维数是基所含向量个数决定的，而不是向量的维数]
举例来说，三维向量空间中的一个平面上的两个不共线向量所构成的子空间就是一个平面空间，其维数为2，而其中的向量维数都是3（或者说是3维向量）

$K^n$ 是其自身的子集，我们回顾$K^n$的定义：$[(a_1,a_2, ...,a_n) | a_i in K]$ 所构成的所有集合，所以，其一个标准基是：$
[mat(1;0;...;0;), mat(0;1;...;0), ..., mat(0;0;...;1)] <->共 n 项
$，因此$dim(K^n) = n$

=== 基和坐标(important)
设$vectors$ 是U的一个基，那么U下的任意向量$bold(alpha)$ 都可以表示为:$bold(alpha) = a_1 bold(a_1) + a_2  bold(a_2) + ... a_n bold(a_n)$. 我们把有序数组$(a_1, a_2, ..., a_n)$ 称为在基$vectors$ 下的#highlight(fill: red)[坐标]

#let bases=$(bold(a_1), bold(a_2), ..., bold(a_r))$
=== 命题1. 设$dim U = r$，则U中任意$r+1$个向量（组成的向量组）线性相关
由维数的定义$->$ U的一个基的向量组个数为$r$ $->$ 由极大无关组/引理1 即可得证

=== 命题2. 设$dim U = r$，则U中任意r个线性无关的向量构成一个基
在定理1.的证明过程中，我们逐步推导，证明了U中至少有一个基。我们任取线性无关向量组$(bold(a_1), bold(a_2), ..., bold(a_r))$,该向量组扩充一个U中的向量$bold(beta)$, 根据命题1，则$(bold(a_1), bold(a_2), ..., bold(a_r), bold(beta))$ 线性相关($dim U = r->$  (r+1)个向量线性相关)

=== 命题3. 设$dim U = r$, 如果U中任意向量可被#bases 线性表出，则#bases 是U的一个基
#let o_bases=$(bold(b_1), bold(b_2), ..., bold(b_n))$
证: 
取U中的一个基 #o_bases, 那么任意$bold(b_i)$可以被#bases 线性表出， 根据（秩的比较/推论3，向量组A可被向量组B线性表出$->$ rank(A)$<=$ rank(B)）,从而有 $ r = r a n k(#o_bases) <= r a n k (#bases) <= r -> r a n k (#bases) = r$, 因此#bases 是线性无关的（根据秩的定义直接可得），进而是U的一个基 


=== 命题4. 设U W都是#KSpace 的子空间，并且$U subset.eq W$，那么 $dim U <= dim W$
#let bases=($bold(a_1), bold(a_2), ..., bold(a_r)$)
#let w_bases=($bold(w_1), bold(w_2), ..., bold(w_t)$)
#let rb = $r a n k (#bases)$
#let rw = $r a n k (#w_bases)$
证： 取 U 的一个基 #bases, 取W的一个基#w_bases, 因为$U subset.eq W$, 所以U中的向量都可以被W的基表示，进而 #bases 可以被#w_bases 表示，根据秩的定义及相关推论可得$r = #rb <= rw = t -> r<=t <-> dim U <= dim W$ 

=== 命题5. 设U W都是#KSpace 的子空间，并且$U subset.eq W$，如果$dim U = dim W$，则$U = W$
根据命题4. 证明过程，当$dim U = dim W$时，即$r = t$,即$bases$是W中的一个向量个数为$r=t$线性无关组，再根据本节命题2，#bases 就是W的一个基

=== 定理3. 向量组#vectors 的一个极大线性无关组是#vectors 生成向量空间的一个基
#let space = $<bold(a_1), bold(a_2), ..., bold(a_n)>$
#let expr_a = $p_j bold(a_j)$
#let expr_b = $k_i bold(a_i)$
#let rank = $r a n k $
证:
根据极大线性无关组的定义，#vectors 中任意向量都可以被其极大无关组#bases 表出，那么空间#space 表示的任意向量$#b = sum_i #expr_b = sum_i k_i sum_j #expr_a =>^(交 换 求 和 顺 序) sum_(j=1)^(r) sum_i k_i #expr_a = sum_j t_j bold(a_j)$, 即#space 中的任意向量，都可以被#bases 线性表示，从而#bases 是 #space 的一个基  

由定理3，我们有一些推论:
$dim #space = #rank #vectors$, 这个是数值上相等，含义上不同，前者指空间的维数，后者指向量组的秩
