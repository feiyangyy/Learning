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
// 函数实例
#let Mab(body)={
  $bold(#body)$
}
// 数学公式标号
#set math.equation(numbering: "(1)", supplement: [式])
= 笛卡尔积
== 定义
#let bs = Mab[S]; #let bm = Mab[M]; #let bsm = $bs times bm$
#let mx =$x$; #let my = $y$
设 #Mab[S] #Mab[M] 是两个集合，则从 #bs #bm 分别取一个元素，组成的集合称为#bs #bm 的笛卡尔积，记作$bs times bm$, 数学上的表示为:
$
  bs times bm = {(a, b) | a in bs, b in bm}
$
如果 #bsm 中的两个元素$(a_1, b_1), (a_2, b_2)$ 满足$a_1 = b_1, a_2 = b_2$， 则称两者相等。

笛卡尔积最直接的例子是直角坐标系，我们从 #mx  #my 轴上分别取值构成的有序数对$(x_0, y_0)$ 就是一个坐标，其刻画了一个平面的点的位置。

== 二元关系
#let mw = Mab[W]; #let bs = Mab[S]
设 #bs 是一个非空集合，如果有一个 #mw 是 $bs times bs$的非空子集，则称 #mw 是 #bs 上的一个二元关系。如果$a,b in bs; (a,b) in mw$, 则称$a,b$ 具有#mw 关系， 记作$a mw b$ 或者$a ~ b$。如果$a,b in bs; (a,b) in.not mw$, 则称$a,b$ 没有#mw 关系
== 等价关系
如果#bs 上的一个关系满足以下性质
=== 反身性 $a~a$
=== 对称性 $a~b => b ~ a$
=== 传递性 $a~b, b~c => a~c$

那么这样的关系称作等价关系

== 等价类
#let hov(b) = {
  $macron(#b)$
}
#let ha = $#hov[a]$; #let hx = $#hov[x]$;#let hy = $#hov[y]$;
设 $~$ 是 #bs 上的一个等价关系，那么，令:
$
  a in bs, macron(a) eq.def {x in bs | x ~ a}
$
称#highlight()[$macron(a)$ 是 #bs 上由 $a$ 确定的等价类], 由定义可知，$ha$ 是一个集合
=== 性质1. $a in ha$
=== 性质2. $x in ha <=> x ~ a$
=== 性质3. $hx = hy <=> x ~ y$
证明：
1. 必要性: 因为$hx = hy => x in hx => x in hy => x ~ y$ (性质1. 性质2.)
2. 充分性: 设$forall c in hx => c ~ x; x ~ y => c ~ y => c in hy => hx subset.eq hy$，  同理从$hy$ 任取元素可得$hy subset.eq hx$ 结合两者可得$hx = hy$

=== 定理 设$~$是#bs 上的一个等价关系，则任取$a,b in bs$, 有$#hov[a] = #hov[b]$ 或者$#hov[a] sect #hov[b] = emptyset$
1. 先证明$#hov[a] != #hov [b] => #hov[a] sect #hov[b] = emptyset$. 设$c in #hov[a] sect #hov[b] => c ~ a, c ~ b => a ~ b => #hov[a] = #hov[b] $ 与假设矛盾，因此其交集必为空集。 同理，当$#hov[a] sect #hov[b] != emptyset$ 时， 存在上述的$c$ 使得结果成立，从而必有$#hov[a] = #hov[b]$
== 定义#bs 的划分
设有I个#bs 的非空子集的并集$union S_i, i in I$, 并且满足$S_i sect S_j = emptyset, i != j$，则称${S_i, i in I}$是#bs 的一个划分，记作$pi(#bs)$
=== 定理 设$~$是#bs 上的一个等价关系，则所有等价类组成的集合是#bs 的一个划分，记作$pi_(~)(bs)$
证明:
$
forall a in bs, a in #hov[a] => bs = union_(a in bs){#hov[a]}, 又 a_i, a_j in bs, #hov[a_i] != #hov[a_j] => #hov[a_i] sect #hov[a_j]= emptyset => union_(a in bs){#hov[a]} 满 足 划 分 条 件
$

=== 商集
我们可以在整数集上定义这样的一个关系:
$
 a ~ b eq.def a mod 7 = b mod 7
$
这个关系是否满足等价关系?
1. 反身：$a mod 7 = a mod 7$
2. 对称: $a mod 7 = b mod 7 <=> b mod 7 = a mod 7$
3. 传递: $a mod 7 = b mod 7, b mod 7 = c mod 7 <=> a mod 7 = c mod 7$ (mod 取得的是一个具体的数，因此是满足传递性质的)

从而模7同余关系是一个等价关系，易知#Mab[Z] 中有7个等价类${#hov[0],#hov[1],#hov[2],#hov[3],#hov[4],#hov[5], #hov[6]}$.
由此引入商集概念：

设$~$ 是#bs 上的一个等价关系，由所有等价类组成的集合称为#bs 对于$~$ 关系的商集，记作$bs \/~$。注意商集是一个集合，不是元素

= 矩阵相抵
#let Mkn = $bold(M)_(s times n)$; #let Mnn = $bold(M)_n$
#let M(body) = {
  $body$
}
#Mab[K] 上的所有$s times n$的矩阵的集合记作#Mkn ,当$s = n$时，简记为#Mnn , 表示#Mab[K] 上所有n阶矩阵的集合。

== 相抵定义： 
#Mkn 上的矩阵$A$ 经过一系列初等行列变换得到$B$, 则称$A, B$是相抵的，记作$A~^(相 抵)B$.
相抵是#Mkn 上的一个二元关系，容易验证，相抵满足等价关系的三条性质：
1. 反身: $A$ 和自身相抵
2. 对称: $A, B$ 相抵 等价于 $B, A$ 相抵
3. 传递: $A,B,C$, 如果$A~B, B~C => A~C$

相抵关系下，$A$的等价类称为其相抵类

回忆: 矩阵的初等行变换等价于, 矩阵左乘以一系列初等矩阵（矩阵被视作行向量组合）；矩阵的初等列变换等价于矩阵右乘以一系列初等矩阵Q。从而矩阵的相抵关系可以表达为:
$
  B = (Pi_k P_k) A (Pi_k Q_k) = P A Q 
$ <aa>
@aa 中的 $P,Q$ 均是可逆矩阵

== 定理
#let rk = $r a n k$
设$A in Mkn, rk(A) = r$, 如果$r > 0$, 则A相抵于矩阵:$mat(#Mab[I]_r, bold(0); #Mab[0],#Mab[0])$ ,这个()矩阵称为$A$的相抵标准形。如果$r = 0$, 那么$A$ 相抵于0矩阵。

证明：
1. 如果$r > 0$, 那么矩阵$A$可以经过初等行变换为简化阶梯型$J$, 但是$J$的列分布不一定是连续的，我们可以通过初等列变换，将主元的列分布控制位连续的，其形式如下:
$
mat(1, 0, 0, ..., 0, c_(1, r+1), ..., c_(1, n); 0, 1, 0, ..., 0, c_(2, r+1), ..., c_(2, n); 0, 0, 1, ..., 0, c_(3, r+1), ..., c_(3, n); ...; 0, 0, 0, ..., 1, c_(r, r+1), ..., c_(r, n);0, 0, 0, ..., 0, 0, ..., 0; ...; 0, 0, 0, ..., 0, 0, ..., 0)
$
这个矩阵的前r行，可以通过初等列变换将后面的列全部消去（如同矩阵初等行变换生成阶梯型一样），从而最终就变成形如$mat(#Mab[I]_r, bold(0); #Mab[0],#Mab[0])$ 的矩阵。这个变换过程只涉及初等行变换和列变换，从而矩阵与之相抵

== 定理 矩阵相抵判定定理
设$A, B in Mkn$, $A, B$ 相抵的充要条件是$rk(A) = rk(B)$
()
证明:
1. 必要性，如果$A, B$ 相抵，根据定义，矩阵的初等行列变换不会改变矩阵的秩（注意不是行列式），从而$rk(A) = rk(B)$
2. 充分性, 如果$rk(A) = rk(B)$，则它们的标准型相等，再根据相抵的传递性可知，$A,B$ 相抵·

 
根据该定理，可以得知，对于$0 <= r <= min(s, n)$, $r$ 唯一决定了相抵类。这种称为相抵关系下的完全不变量。

== 定义 不变量与完全不变量
设$~$是#Mab[S]上的一个等价关系，一个量或者表达式对于等价类里的元素是相等的，则称该量或表达式是该关系下的一个不变量。如果能恰好完全决定等价类的一组不变量则称为完全不变量

结合以上信息，我们可以有以下推论:
$
A in Mkn,rk(A) != 0 => A = P mat(#Mab[I]_r, bold(0); #Mab[0],#Mab[0])Q
$ 

=  广义逆矩阵
#let inv(b) = [ $#b ^(-1)$]
如果$A$ 是一个可逆矩阵，那么$A X A = A$ 的一个解是$X = #inv[A]$. 当A不可逆时，这个方程是否有解呢?
== 定理
设$A in Mkn, rk(A) = r > 0$, 则矩阵方程:$A X A = A$ 一定有解。 设$A = P mat(#Mab[I]_r, bold(0); bold(0), bold(0))Q$, P 是 s 阶矩阵，Q 是n阶矩阵。则该矩阵方程的解为:$X = #inv[Q] mat(#Mab[I]_r, #Mab[B]; ; #Mab[C], #Mab[D])#inv[P]$. 其中$B in M_(r times (s - r)), C in M_((n-r) times r), D in M_((n-r) times (s-r))$, 矩阵$mat(#Mab[I]_r, #Mab[B]; ; #Mab[C], #Mab[D])$ 是一个$n times s$矩阵

证明:
$
A X A &= P mat(#Mab[I]_r, bold(0); bold(0), bold(0))Q  #inv[Q] mat(#Mab[I]_r, #Mab[B]; ; #Mab[C], #Mab[D])#inv[P] A  \
&= P mat(#Mab[I]_r, bold(0); bold(0), bold(0)) #Mab[I]_n mat(#Mab[I]_r, #Mab[B]; ; #Mab[C], #Mab[D])#inv[P] A \
&= P mat(#Mab[I]_r, bold(0); bold(0), bold(0)) mat(#Mab[I]_r, #Mab[B]; ; #Mab[C], #Mab[D])#inv[P] A \
&= P mat(#Mab[I]_r, bold(0); bold(0), bold(0)) mat(#Mab[I]_r, #Mab[B]; ; #Mab[C], #Mab[D]) mat(#Mab[I]_r, bold(0); bold(0), bold(0)) Q
$ <a1>
@a1 中的左侧矩阵$mat(#Mab[I]_r, bold(0); bold(0), bold(0))$ 的列划分是$(r, n-r)$, 右侧矩阵$mat(#Mab[I]_r, #Mab[B]; ; #Mab[C], #Mab[D])$的行划分是$(r, n-r)$,因此两者可以相乘(参考分块矩阵乘积，证明比较复杂), 其结果为:$mat(#Mab[I]_r, #Mab[B];;bold(0), bold(0))$, 从而:
@a1 就可写作:
$
P mat(#Mab[I]_r, #Mab[B];;bold(0), bold(0))mat(#Mab[I]_r, bold(0); bold(0), bold(0)) Q = P  mat(#Mab[I]_r, bold(0); bold(0), bold(0)) Q = A
$
从而我们验证了这个定理，上面的定理中对$B C D$ 除了形状之外，没有特殊要求
== 广义逆
#let ginv(b) = { $#b ^(-)$;}
设$A in Mkn$, 矩阵方程$A X A = A$的每一个解都称为$A$的广义逆矩阵，简称$A$的广义逆， 记作$#ginv[A]$ 根据定义显然$A #ginv[A] A = A$. 同时根据上述定理，$rk(A)=r, A  = P mat(#Mab[I]_r, bold(0); bold(0), bold(0))Q => X = #inv[Q] mat(#Mab[I]_r, #Mab[B]; ; #Mab[C], #Mab[D])#inv[P] = #ginv[A]$, 可见$#ginv[A]$通常是一个集合

对于$bold(0)_(s times n)$ 任意$B in M_(n times s) => bold(0) B bold(0) = bold(0)_(s times n) => B = #ginv[0]$

== 定理 非齐次线性方程组的相容性定理
非齐次线性方程组$A #Mab[x] = #Mab[$beta$]$ 有解的充要条件是$#Mab[$beta$] = A #ginv[A] #Mab[$beta$]$

证明：
#let bb = $bold(b)$;#let bx = $bold(x)$; #let bbeta = $bold(beta)$
1. 必要性:设$bb$ 是$A bx = bbeta$的解，那么$A bb = bbeta => A #ginv[A] (A bb) = bbeta, 又 A bb = bbeta => bbeta = A #ginv[A] bbeta$
2. 充分性:$ bbeta = A #ginv[A] bbeta = A (#ginv[A] bbeta) => A [#ginv[A]bbeta] = bbeta $<a4> 从而$#ginv[A] bbeta $是$A bx = bbeta$的一个解

== 定理 非齐次线性方程组的解的结构定理
如果$A bx = bbeta$ 有解，则其通解为
$
  bx = #ginv[A] bbeta
$
证明：
#let bgm =$bold(gamma)$
设$bgm$ 是一个解，则$A bgm = bbeta$. 那么有:
$
  P mat(#Mab[I]_r, bold(0); bold(0), bold(0)) Q bgm &= bbeta \
  mat(#Mab[I]_r, bold(0); bold(0), bold(0)) Q bgm &= #inv[P] bbeta 
$ <a3>
#let veca = $vec(#Mab[$Y_1$]_r, #Mab[$Y_2$]_(n - r))$
#let vecb = $vec(#Mab[$Z_1$]_r, #Mab[$Z_2$]_(s - r))$
#let matr = $mat(#Mab[I]_r, bold(0); bold(0), bold(0))$
@a3 中,$Q$ 是n阶可逆矩阵，$bgm$是一个$n times 1$的向量，从而$Q bgm$ 是一个$n times 1$的矩阵（向量），将$Q bgm$ 写作$Q bgm = vec(#Mab[$Y_1$]_r, #Mab[$Y_2$]_(n - r))$. 同理$#inv[P] bbeta = vec(#Mab[$Z_1$]_r, #Mab[$Z_2$]_(s - r))$ 
从而@a3 可以写作:
$
  matr veca = vecb => #Mab[$Z_1$]_r = #Mab[$Y_1$]_r, #Mab[$Z_2$]_(s-r) = bold(0) => #inv[P] bbeta = vec(Z_1, bold(0))
$
#let b0 = $bold(0)$
这里要证明一个推论，就是$P_s$可逆时，$forall bx != bold(0), P bold(x) != bold(0)$. 设$exists bx != 0 s.t. P bx = b0$, 因为$P$是可逆矩阵$=>rk(P) = s => P bx = b0$ 只有0解，与假设矛盾,从而$P bx != b0$

#let BC = $bold(C)$;#let BZ = $bold(Z)$;#let BY = $bold(Y)$
从而$#inv[P] bbeta != b0 => #Mab[$Z_1$] != b0_r$, 因此设$#Mab[Z_1] = vec(k_1,k_2, ..., k_r), exists k_i != 0$; 根据前述广义逆定理，$#ginv[A]  = #inv[Q] mat(#Mab[I]_r, bold(B); bold(C), bold(D)) #inv[P]$, 我们将$bold(C)_((n-r)times(r))$ 写作$bold(C) = (b0, b0, ..., k_i^(-1)bold(Y)_2, ..., b0)$,这里要注意$bold(Y)_2$ 是一个列向量. 那么$BC BZ_1 = (b0, b0, ..., k_i^(-1)bold(Y)_2, ..., b0) vec(k_1,k_2, ..., k_r) = BY_2$，那么:
$
Q bgm = vec(BY_1, BY_2) = vec(BZ_1, BC BZ_1) = mat(bold(I)_r, b0; BC, b0)vec(BZ_1, b0) => \
bgm = #inv[Q] mat(bold(I)_r, b0; BC, b0)vec(BZ_1, b0), because #inv[P] bbeta = vec(Z_1, bold(0)) => \
bgm = #inv[Q] mat(bold(I)_r, b0; BC, b0) #inv[P] bbeta = #ginv[A] bbeta
$

我们也可以反过来验证，对于$#ginv[A]$, 由3.3. 定理可知，$bbeta = A #ginv[A] bbeta$ , 从而$ #ginv[A] bbeta$ 一定是$A bx = bbeta$的解

综上，如果$A bx = bbeta$ 有解，则其解可表示为$x = #ginv[A] bbeta$

== 齐次线性方程组的解的结构定理：
$A bx = b0$ 的通解为:
$
  bx = (I_n - #ginv[A]A)Z, Z in K^n
$<a5>
证明:
$
Z in K^n,  A[(I_n - #ginv[A]A)Z] = A[(I_n - #ginv[A]A)]Z = (A - A#ginv[A]A) Z = b0
$
这里注意$#ginv[A] in M_(n times s)$, 同时这个证明只证明了$bx = (I_n - #ginv[A]A)Z, Z in K^n$ 是$A bx = b0$的解的一部分而不是全部，接下来要证明任意解的情况
$
bb s.t. A bb = b0, (I_n - #ginv[A] A) bb = bb - #ginv[A] (A bb) = bb - #ginv[A] b0 = bb => A (I_n - #ginv[A] A) bb  = b0
$
综上， 定理得证

#highlight()[此处证明实际上有重复证明的情况，并且没有说明@a5 为何包含了全部解]
1. 重复证明$bb in K^n, s.t. A bb = b0$ 而第一步证明时取得向量$Z in K^n $ 一定包含$bb$
2. 没有包含全部情况$(I_n - #ginv[A]A)Z$ 会对$Z$ 做变换，验证全部情况，应当说明$A bx = b0$的解的空间和$(I_n - #ginv[A]A)Z$ 是同一个空间
== 推论
设$bbeta in K^n , bbeta != b0$, 则如果$A bx = bbeta$ 有解时，其通解为:
$
  bx = #ginv[A] bbeta + (I_n - #ginv[A]A)Z, Z in K^n
$
证明:
由定理3.4. 知,$bx in {#ginv[A] bbeta}, s.t. A bx = bbeta$, 又$A bx = bbeta = bbeta + b0 = A bx + A bgm, A bgm = b0$, 由3.5. 知$bgm in {(I_n - #ginv[A]A)Z, Z in K^n}$ 从而$A bx + A bgm = #ginv[A]bbeta + (I_n - #ginv[A]A)Z, Z in k^n$

== (略)设A是复数域上的$s times n$ 矩阵，那么
$
cases(A X A = A, X A X = X, (A X)^* = A X, (X A)^* = X A)
$
称为A的#highlight(fill: green)[Penrose]方程组，他的解叫做$A$ 的#highlight(fill: green)[Moore-Penrose] 广义逆，记作$A^+$

= 矩阵的相似
#highlight[相似仅对方阵而言有意义]
== 相似定义
设#Mab[A],#Mab[B] 是 数域K上的两个$n 阶$矩阵，并且存在一个$P_n$ 满足：
$
  #inv[P] A P = B 
$<a6>
那么称#Mab[A] #Mab[B] 是相似的，记作$A~B$,注意@a6 中乘积顺序不可更改。
相似关系是一种等价关系：
1. 反身: #Mab[A] 和自身相似，因为$I_n -> #inv[$I_n$] A I_n = A$ 
2. 对称: $A~B -> B~A$， 因为$A~B <=> B=#inv[P]A P <=> P B #inv[P] = A(because (#inv[P]) ^(-1) = P ) => B~A $
3. 传递:$A~B, B~C => A~C$, 因为$C = #inv[Q]B Q = #inv[P]#inv[Q] A Q P = (Q P)^(-1) A (Q P) => A~C$

在相似关系下，$A$的等价类称为A的相似类

== 相似的性质
=== 1. 设$B_1 = #inv[P] A_1 P; B_2 = #inv[P] A_2 P$
那么
$
B_1 + B_2 = #inv[P] (A_1 + A_2) P, 证:B_1 + B_2 = #inv[P]{A_1 P + A_2 P} = #inv[P]{A_1+A_2} P \
B_1 B_2 = #inv[P] (A_1 A_2) P, 证:B_1 B_2 = #inv[P]A_1 P #inv[P] A_2 P = #inv[P] A_1 A_2 P \
B_1^m = #inv[P]A_1^m P, 证：B_1 B_1 = #inv[P] A_1^2 P ==>^(数 学 归 纳 法) B_1^m = #inv[P]A_1^m P
$
=== 2. 相似矩阵行列式相等
回忆矩阵的乘积的性质：
1. $|A B| = |A||B|$

那么$A~B => B = #inv[P] A P => |B| = |#inv[P]| |A P| =|#inv[P]| |A| |P| =^(数 值) |#inv[P]| |P| |A| = |#inv[P]P| |A| = |A|$
这个证明过程中，要注意矩阵乘积是不可随便交换位置的，但是矩阵的行列式的乘积是可以的（其实质就是一堆数值相乘）

=== 3. 相似的矩阵要么都可逆，要么都不可逆；可逆时，其逆矩阵也相似
1. 由性质2. 知，如果$A~B$, $A$ 不可逆，那么$|A| = 0 => |B| = 0$, 从而$B$不可逆
2. 如果$A~B$,$A$可逆，那么$|B| = |A| != 0$ ，从而$B$ 可逆
3. $A~B, |A| != 0, #inv[B] = (#inv[P]A P)^(-1) = #inv[P] #inv[A] P => #inv[A] ~ #inv[B]$ 

=== 4. $A~B => rk(A) = rk(B)$
因为$B = #inv[P] A P$ 相当于$B$ 由 $A$ 经过一系列初等行列变换得到，这个过程中不改变矩阵的秩

== 定义2. n阶矩阵$A_n$ 的主对角线上的元素之和称为$A$的迹，记作$tr(A)$
$
tr(A) = sum a_(i,i)
$
对于实数域上的矩阵，$tr(A) in RR$
=== 命题，矩阵的迹具有以下性质
1. 线性性质:
$
  tr(A + B) = tr(A) + tr(B) \
  tr(k A) = k tr(A)
$
证明略
2. 对称性质: $tr(A B) = tr(B A)$
证明:
$
tr(A B) = sum_k (A B)_(k, k) = sum_k {sum_l a_(k,l) b_(l, k)} \
tr(B A) = sum_k (B A)_(k, k) = sum_k {sum_l b_(k,l) a_(l, k)} = sum_l {sum_k a_(l, k) b_(k, l)} <=>^(l <-> k) sum_k {sum_l a_(k,l) b_(l,k)} = tr(A B)
$
这里注意下第二步的推导中交换求和顺序

一般来说$A B != B A$, 但是$tr(A B) = tr(B A)$

=== 相似的矩阵有相等的迹
设$A~B => tr(B) = tr(#inv[P] A P) = tr(#inv[P] (A P)) =^(数 值) tr((A P) #inv[P]) = tr(A)$

从而，矩阵的秩、行列式、迹 都是相似关系下的不变量，简称为#highlight()[相似不变量]

相似关系最主要的价值在于使用较为简单的相似矩阵，研究其性质，从而得出原矩阵的性质。

=== 可对角化定理
如何判定$A_n$是否可以找到$P s.t. A ~ D$($D$为对角矩阵)， 如果有这样的矩阵，即$A ~ D$ 则称$A$是#highlight()[可对角化的]
#let ba = $bold(a)$; #let avecs = $(ba_1,ba_2, ..., ba_n)$; #let larr = $(lambda_1, lambda_2, ..., lambda_n)$

可对角化定理，$A_n$ 可对角化的充要条件是
$
exists avecs, larr, lambda_i in K s.t. A ba_i = lambda_i ba_i, 1 <= i <= n
$<a7>
#let diag = $d i a g$
此时，令$P = avecs$ 则 $#inv[P]A P = diag larr$

证明:
$
A~D=diag larr <=> #inv[P] A P = D => A P = P D => A avecs = avecs D => \
(A ba_1, A ba_2, ..., A ba_n) = (ba_1 lambda_1, ba_2 lambda_2, ..., ba_n lambda_n) <=> \
A ba_i = lambda_i ba_i
$
此处证明需要注意矩阵乘法时，将左右矩阵看做行列向量时，矩阵乘法的作用

= 矩阵的特征值和特征向量（IMPORTANT）
#let A = $A$
#let lam = $lambda$
#let idef = $bold(I)$
== 矩阵特征值定义
#let lam = $lambda$
对于数据K上的n阶方阵，如果存在一个数$lam_0 in K$, 存在一个向量$#ba in K^n, #ba != #b0$, 使得,$A #ba = lam_0 #ba$,则$lam_0$ 称为A的一个特征值, #ba 称为A的属于$lam_0$的一个特征向量

显然，如果#ba 是A的属于$lam_0$的一个特征向量，则$k ba, forall k!=0 => A(k#ba)= k (A #ba) = k (lam_0 #ba) = lam_0 (k #ba)$， 即$k ba$也是A的属于$lam_0$的一个特征向量。

我们把矩阵看做一种变换，特征向量和特征值的含义就是，特征向量在矩阵A的变换下，以特征值做尺度变换，变换前后一定是共线的。某些情况下，矩阵变换一定会使得向量不共线（比如不是$n pi$的旋转）. 换句话说，矩阵的特征向量反映了矩阵在某些"方向上"的特殊作用.

矩阵的特征值、特征向量的概念十分重要，主成分分析、特征值分解等都需要利用特征向量。



== 矩阵特征值和特征向量的求解与判定

设#A 是一个n阶矩阵，#lam 是一个变量，则行列式$|lam idef - A| = mat(delim:"|", lam - a_11, -a_12, ..., -a_(1 n); ..., -a_(n 1), -a_(n 2), ..., lam - a_(n n))$ 称为#A 的#highlight()[特征多项式]， 接下来说明如何求解或判定特征值以及特征向量

设$lam_0$是A的一个特征值，#ba 是A的属于$lam_0$的一个特征向量，从而:
$
A#ba = lam_0 #ba, lam_0 in K, #ba in K^n, #ba != #b0 =>^(两 边 同 减 去 A#ba) #b0 = lam_0#ba - A#ba = (lam_0 idef #ba  - A#ba) = (lam_0 #idef - A)#ba = #b0 , #ba != #b0
$
从而#ba 是齐次方程组$(lam_0 idef - A)#bx =#b0$的一个非0解，这要求系数矩阵$(lam_0 idef - A)$的行列式必为0，这进一步要求$lam_0$是A的特征多项式$|lam idef - A| =0$的一个解。如果该多项式没有解，说明行列式必不为0，从而矩阵便不存在特征值和特征向量。

我们回忆齐次线性方程组的解集结构:将所有自由变量分别取1， 其余分量写成这些变量的表达式，这些解就构成了齐次线性方程组解的空间的一个基。

在$(lam_0 idef - A)#bx = #b0$ 有解的情况下，其解的空间的所有非0向量都是A 的属于$lam_0$的特征向量

这样可以总结求特征值和特征向量的步骤：
1. 求矩阵的特征多项式的根
2. 对于每一个根$lam_0$，求解其构成的齐次线性方程组的基础解系
3. 基础解系所张成的空间中的所有非0向量，都是矩阵的属于$lam_0$的特征向量

由步骤3.可知，从属于同一个特征值$lam_0$的特征向量，不一定就是共线的，齐次线性方程组的解的空间的基，是线性无关的，但是他们都是从属于$lam_0$的特征向量

= 矩阵对角化的条件
根据特征值定义，可以将@a7 表述为:$exists avecs$, 这是一个线性无关的向量组，使得$P=avecs, #inv[P]A P = diag{larr}$. 其中$lam_i 是 ba_i$所属的特征值。对角矩阵$diag{larr}$称为A的#highlight()[相似标准形],不考虑对角线元素的排列次序，$A$的相似标准形是唯一的
#let bb = $bold(b)$
#let bvecs = $(bb_1, bb_2, ..., bb_n)$
== 定理，设$lam_1 != lam_2$ 并且 $lam_1, lam_2$ 是$A_n$的特征值，$avecs, bvecs$分别是从属于$lam_1, lam_2$的向量，并且它们(向量组)线性无关。则$avecs, bvecs$ 线性无关
证明：
该定理是要证明以下等式:
$
  avecs bold(k) + bvecs bold(l) =  avecs vec(k_1, k_2, ..., k_n) + bvecs vec(l_1, l_2, ..., l_n) = b0
$ <a8>
中系数向量$bold(k), bold(l)$ 全为#b0. @a8 两侧同时左乘$A$：
$
  A avecs bold(k) + A bvecs bold(l) = b0 =>\
  lam_1 avecs bold(k) + lam_2 bvecs bold(l) = b0 
$ <a9>
$because lam_1 != lam_2$, 故 $lam_1, lam_2$ 不会全为0，设$lam_2$ 不为0，则@a8 左侧同乘以$lam_2$:
$
  lam_2 avecs bold(k) + lam_2 bvecs bold(l) = b0
$ <a10>
用@a10 - @a9 :
$
  (lam_2 - lam_1)avecs bold(k) = b0 => \ 
  (lam_2 - lam_1) k_1 ba_1  + (lam_2 - lam_1) k_2 ba_12 + ... + (lam_2 - lam_1) k_n ba_n 
$
因为$avecs$ 线性无关 且 $lam_1 != lam_2 => bold(k) = b0$，将其代入@a8 中:
$
  bvecs bold(l) = b0
$
因为$bvecs$线性无关，故而$bold(l) = b0$ 从而得出@a8 中各项系数均为0，从而$avecs, bvecs$ 中各向量线性无关