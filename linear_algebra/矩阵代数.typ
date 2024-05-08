#import "@preview/cetz:0.2.2"
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

#set heading(numbering: "1.",)
= 矩阵的基本运算
前面章节中，矩阵是通过线性方程组求解，我们研究其系数矩阵而直接引入的，除了线性方程组外，矩阵还可以表示具有关系型的表格、空间或平面中的变换等。本文主要就是介绍矩阵本身支持的运算及其性质。

== 矩阵的加法、数量乘法
=== 定义1. 矩阵相等
#let A=$A$ ; #let B=$B$; #let K=$K$ ; #let C=$C$; #let sn=$s times n$
如果#A 与 #B 都是数域 #K 上的$s times n$ 的矩阵， 并且$a_(i,j) = b(i,j)$ 则称#A #B 相等，记作#A = #B

=== 加法定义
在数域#K 上，令$C_(s times n) = (c_(i, j))_(s times n) = (a_(i,j) + b_(i, j))_(s times n)$， 称#C  是 #A #B 的和，记作$C = A + B$。从定义可以看出，两个矩阵只有形状相同才能相加（即两者要在同一空间）

=== 数量乘法定义
设有矩阵$A_(#sn) = (a_(i , j))_(#sn), k in K$, 令$M = (k a_(i,j))_(#sn)$，称M为矩阵A和k的数量积，记为$M=k A$

在前面的向量空间中，我们除了要定义运算外，还要定义 0 元、 负元（回忆向量空间中，0元是所有分量为0的向量，$bold(a)$的负元是$-bold(a)$ ），类似的，我们定义$bold(0)_(s times n)$ (教材上没有个定义，我们暂且叫做0矩阵); 以及定义$-(a_(i,j))_(#sn) = -A$，把他叫做A的负矩阵。我们设有$C_(#sn)$，则可以验证 #A  #B  #C 满足以下8条规则:
1. 加法交换律 #A + #B  = #B  + #A 
2. 加法结合律 #A + #B + #C  = (#A + #B) + #C
3. #A 加上 0 矩阵等于 #A  $A + bold(0) = A$
4. #A 加上它的负矩阵(负元) 等于 0 矩阵 $A + (-A) = bold(0)$
  - 0 元也称为 加法的单位元
5. 1#A = #A
6. 数量乘法结合律 $k l#A = k(l#A)$
7. 数量乘法分配律 $(k+l)#A = k#A  + l #A$
8. $k (A + B)= k A + k B$

可见，如果我们把所有$#sn$ 这样的矩阵看做一个集合，这个集合也满足我们在向量空间中定义（对于加法和数量乘法封闭），但唯一不同的是，这些元素都是矩阵而不是向量

== 矩阵乘法定义

// #set page(width: auto, height: auto, margin: .5cm)
// 所有数学部分，填充色
// #show math.equation: block.with(fill: red, inset: 1pt)
#grid(
  columns: (1fr, 0.5fr),
  align(left)[
    #let t= $theta$
    #let p=$phi$

    如右图所示，在平面坐标系上有个两个单位向量$bold(a) = (x,y)^T$ 以及$bold(b) = (x^',y^')^T$, 它们与$x$ 轴夹角分别时#sym.alpha, #sym.beta+#sym.alpha. 那么易知$cases(x=cos(alpha), y=sin(beta)), cases(x^' = cos(alpha + beta), y^' = sin(alpha + beta))$;$bold(b)$ 可以看做$bold(a)$ 逆时针旋转$beta$ 角度得来。我们考虑两者的坐标关系:

    $cases(x^' = cos(alpha)cos(beta) + sin(alpha)sin(beta), y^' = sin(alpha)cos(beta) - cos(alpha)sin(beta)) => cases(
      x^' = cos(beta)x - sin(beta)y, y^' = sin(beta)x + cos(beta)y 
    ) => A=mat(cos(beta), -sin(beta);sin(beta), cos(beta))$ $A$为系数矩阵。即我们可以用$A$ 这样的矩阵（方程组）表达旋转，它将一个向量，变为另外一个向量并且它只和旋转度数$beta$有关（这个和前面方程组求解不同）由此对于平面空间中，任意旋转度数$phi$的旋转矩阵就定义为:$A = mat(cos(phi), -sin(phi); sin(phi), cos(phi))$.那么对于旋转$phi$ 再旋转$theta$度数而言，其旋转矩阵就表达为:$C = mat(cos(phi + theta), -sin(phi + theta); sin(phi + theta), cos(phi + theta)) = mat(cos(#p)cos(#t) - sin(phi)sin(theta), -(sin(#p)cos(#t)+ cos(#p)sin(#t));sin(#p)cos(#t)+ cos(#p)sin(#t), cos(#p)cos(#t) - sin(phi)sin(theta))$, 其中 #t 的旋转矩阵是$T= mat(cos(#t), -sin(#t); sin(#t), cos(#t))$  观察可得:$cases(c_11= a_11 t_11  + a_12  t_21 , c_12= a_211 t_12  + a_12  t_22, c_21= a_21 t_11  + a_22  t_21, c_22= a_21 t_12  + a_22  t_22)$
  ],
  align(right)[
  #cetz.canvas({
      import cetz.draw: *
      let vmin = -1.5; let vmax = 1.5
      let a_x = calc.cos(30deg)
      let a_y = calc.sin(30deg)

      let b_x = calc.cos(60deg)
      let b_y = calc.sin(60deg)
      grid((vmin, vmin), (1.5, 1.5), step: 0.5, stroke: gray + 0.2pt)
      circle((0,0), radius: 1)
      line((vmin, 0), (vmax, 0), mark: (end: "stealth"))
      content((), $x$, anchor: "west")
      line((0, vmin), (0, vmax), mark: (end: "stealth"))
      content((), $ y $, anchor: "south")
      // 原点， 原点-> 起始边， 原点到终边
      // 角度本身不画边
      // 只不过它通过边来画角度，即使终点定义错了，影响貌似也不大
      cetz.angle.angle((0,0), (1,0), (calc.cos(30deg), calc.sin(30deg)),
        label: text(black, [$alpha$]), inner:true)
      
      cetz.angle.angle((0,0), (calc.cos(30deg), calc.sin(30deg)), (calc.cos(60deg), calc.sin(60deg)),
        label: text(black, [$beta$]), mark: (end: "stealth"), radius: 0.8)

      // 第一个应该是原点，第二个是终点
      line((0,0), (calc.cos(30deg), calc.sin(30deg)))
      content((a_x+0.3, a_y), $(x,y)$, anchor: "south")
      line((0,0), (calc.cos(60deg), calc.sin(60deg)))
      content((b_x+0.3, b_y+0.1), $(x^',y^')$, anchor: "south")
    }) 
  ]
)

由此$C$ 可以由$A T$的某种运算关系表示，这种运算我们定义为矩阵的乘法（个人认为这个例子不是太好，作为引出矩阵乘法定义有点生硬，这里主要是为了练习排版和作图，才把这段记下来）
== 矩阵乘法
设$A=(a_(i j))_(#sn), B = (b_(i j))_(n times m), C = (c_(i j))_(s times m)$  并且有$c_(i j) = sum_k a_(i, k) b_(k, j)$ 用文字表达即，$c_(i j)$ 通过选定A 矩阵的第$i$ 行， 选定B矩阵的第$j$列，然后，从$k = 1->n$, 依次取A的第$i$行的第k个(列)元素 与 B矩阵第$j$列的第k个(行)元素相乘，然后求和

由矩阵乘法可见，能使得$a(i, k), b(k, j)$ 均有意义的条件是A矩阵的列数与B矩阵的行数相等，A矩阵也叫做#highlight()[左矩阵]， B矩阵也叫#highlight()[右矩阵]。 矩阵的乘法运算中涉及到 乘法和加法，有时候这个运算会被定义到计算机的DSP指令集中，叫做乘加运算(muladd)

== 矩阵乘法性质
以下均假设所引用的矩阵可以相乘
=== 结合律 $A B C = (A B)C = A(B C)$
#let nm = $n times m$
#let mr = $m times r$
#let sr = $s times r$
#let ma= $A_(#sn)$;#let mb =$B_(#nm)$ 
#let b0 =$bold(0)$
设$A=(a_(i j))_(#sn), B = (b_(i j))_(#nm) C= (c_(i j))_(m times r)$
在矩阵的形状上， 等式两边都是#sr 矩阵。 下面证明其每个元素相等

$((A B)C)_(i j) = sum_k [(A B)_(i k) c_(k j)] = sum_k {[sum_l a_(i l) b_(l k)] c_(k j)}  = sum_k sum_l [a_(i l) b_(l k) c_(k j)] -> c_(k j) 乘 法 分 配 到 左 侧\
(A(B C))_(i j) = sum_k [a_(i k) (B C)_(k j)] = sum_k {a_(i k) [sum_l b_(k l) c_(l j)]} = sum_k sum_l [a_(i l) b_(l k) c_(k j)]
 -> a_(i l) 乘 法 分 配 到 右 侧$
 可见两者相等

 与实数域里面的乘法的交换律不同，矩阵乘法一般不满足交换律，首先$A B$ 交换的$B A$ 就不一定能相乘。当$s != m$ 时，$#mb #ma$ 就没有定义。其次即便是$B A$ 能够相乘，其结果也可能和$A B$ 不同。比如 $s = m != n$时，$#ma #mb = C_(s times s), #mb #ma= D_(n times n)$. $C$ $D$形状不同

 === 零因子
 设$A = mat(0, 1; 0, 0) , B = mat(0, 0; 0, 1;)，则 A B = mat(0, 1; 0, 0); B A = mat(0, 0;0, 0)$ 可见 $A != 0 且 B != 0 <==>^(不 能 得 出) A B != 或 B A = 0$

对于#A，如果存在一个矩阵$#B != 0$能够使得 #A #B = #b0, 则把#A 称作一个左零因子，如果存在一个$#C  != #b0$，并且#C #A = #b0 则把A叫做一个右零因子。左右零因子统称为零因子

=== 左分配律
$A(B+C) = A B + A C$
=== 右分配律
$(B + C) A = B A + C A$
#let bdef = $(b_(i j))_(#sn)$; #let cdef = $(c_(i j))_(#sn)$; #let aef = $(a_(i j))_(#nm)$

下面对右分配律证明，设$B=#bdef,C = #cdef, A = #aef$，那么$[(B + C) A]_(i j) = sum_k (A+B)_(i k) c_(k j) = sum_k [(a_(i k) + b_(i k))]c_(k j) = sum_k a_(i k) c_(k j) + sum_k b(i k) c(k j) = B A + C A$ 得证

左分配律证明方法类似

可见矩阵乘法相比较数域中的乘法性质较差一些，矩阵间的乘法不一定存在，且，矩阵的乘法定律也比较受限

=== 数量乘法规律
$k(A B) = (k A)B = A (k B)$ 这是因为数量乘法可以提到求和符号外边，从而自然得证

=== 单位矩阵
#let idef =$bold(I)$
对于n阶#highlight()[方阵]，只有对角线上的元素为1，其他全为0的矩阵，称为单位矩阵，记作$#idef _n$ 或者#idef, 容易验证:
$#idef _s A_(#sn) = A_(#sn); A_(#sn) #idef _n = A_(#sn)$ ，我们证一下第一个$(#idef _s A_(#sn))_(i j) = sum_k #idef _(i k) a_(k j) = a_(i j) <== because cases(#idef _(i k) = 0 当 (k != i), #idef _(i k) = 1 当 (k = i))$ 

如果 #A 是n阶方阵，那么$#idef A = A #idef = A$

=== 数量矩阵
对角线元素全为$k$，其余元素全为0的方阵称为数量矩阵，那么显而易见其可以表示为$k #idef in W$, 那么很自然有
$
k#idef + l#idef = (k + l)#idef in W \
k(l #idef) = (k l)#idef in W \
(k#idef)(l#idef) = (k l)#idef in W
$
因此可见$W$ 是一个封闭的空间（特别是第三个公式），注意其中第三个公式需要展开得出