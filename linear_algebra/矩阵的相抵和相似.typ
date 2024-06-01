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

=