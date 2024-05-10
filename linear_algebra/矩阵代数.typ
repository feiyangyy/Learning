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
= 映射
映射在测度、微积分、代数以及概率论中都有所体现，矩阵与向量相乘，可以看做对向量中的一种映射变换。新版的教材中删去了这个部分（反而显得矩阵代数这部分有点生硬）
#let bs = $bold(S)$
#let bss = $bold(S^')$
#let x = $x$
#let y = $y$; #let f = $f$
== 映射
如果有一个映射法则$f$, 对于每一个$x in #bs$，都能在#bss 找到唯一一个对应的元素$y in #bss$。此时我们把#y 叫做 #x 在映射法则#f 下的象，记作$f(x)$, #x 被称作 #y 的原象。我们映射法则f记作:

$f: #bs -> #bss \
x |-> y
$

集合#bs 叫做 #f 的#highlight()[定义域], #bss 叫做#f 的 #highlight()[陪域]。要注意#f 的取值的集合是陪域的一个子集

== 映射的象集
对于法则$ f: #bs -> #bss \ x |-> y$ ， 所有的$x in #bs$ 对应的 $f(x)$的映射的结果的集合，叫做#f 的象集，简称象， 记作 $Im f := {f(x) | x in #bs} := f(#bs)$,显然$f(#bs) in #bss$

== 满射
如果$f(#bs) = #bss$，则称$f: #bs -> #bss$ 是一个满射。$f(#bs) = #bss$ 的充要条件是#bss 中的任意元素都能在#bs 中找到一个原象（注意，不一定是唯一一个）

== 单射
如果对于任意 $a ,b in #bs, a != b <=> f(a) != f(b)$, 则称#f 是一个单射。
单射的充要条件是，对于$a,b in #bs, f(a), f(b) in #bss, 若 f(a) = f(b) -> a = b$
可以用一次线性函数记忆单射，用二次函数记忆非单射
== 双射
如果映射#f 既是满射也是单射，则$forall y in #bss$ 都能在#bs 找到#highlight()[唯一一个]原象。此时称#f 是双射， 或者说一一对应
用一次函数记忆双射，用二次函数记忆非双射

双射和单射的主要区别是，$Im f in #bss and Im f != #bss$， 双射的话，就是单射#f 满足$Im f = #bss$

== 原象集
设$f:#bs -> #bss$,  则对应于$b in #bss$, 所有在#bs 中的元素集合$a in W$， 能使得$f(a) = b$。 我们把$W$ 称作$b$ 的原象集，记作$f^(-1)(b) := {x |x in #bs,  f(x) = b}$，显然，如果$b in #bss \\ Im f -> f^(-1)(b) = emptyset$. 如果$b in Im f$, 则$f^(-1)(b)$ 成为 b 的纤维

== 相等映射
#let mf=$f$; #let mg=$g$
如果映射#mf 和 #mg 有相同的#highlight()[定义域 陪域]，并且$forall x in #bs, f(x) = g(x)$， 则称#mf 和 #mg 相等

== 恒等映射
如果映射$f: S -> S, f(x) = x$， 即将#bs 中的元素映射为自己，则称这个映射为恒等映射，或者单位映射, 记$1_s$（#highlight()[这等价于后文中的单位矩阵])

可以用$y = f(x)$ 或者单位矩阵 记忆恒等映射，注意恒等映射的定义域是#bs, 象集也是#bs, 他是一个双射

如果一个$f: #bs -> #bs$， 我们通常把#f 称作一个变换， 如果一个$f:#bs -> K$ （K是数域)，则我们把#f 叫做#highlight()[函数]



== 复合映射
#let bsss = $bold(S^(''))$
#let g =$g$
对于映射$g: #bs -> #bss, f:#bss -> #bsss$，我们把两者的复合定义为两者的乘积:$(f g)(a) := f(g(a))$， 我们用语言来描述这件事，#f #g 定义为 用#f 将#g 在#bss 下的象集映射到#bsss 中。 由此可见，映射的乘积#highlight()[不一定能交换]， 且其乘积不一定有定义(需要满足映射的定义域的条件, 即#g 的象集要是#f 的定义域的子集)

在数学分析中，$u = g(x), f(g(u))$ 称为复合函数

由此直接体现了矩阵乘法的含义：#highlight()[映射的复合]

容易验证:$f 1_s = f$, $1_s f = f$. 让我们简单的证明这个东西，$forall x in #bs, 1_s(x) = x, ->f(1_s(x)) = f(x) = f, x in #bs$, $forall x in #bs, 1_s(f(x)) = f(x) = f$, 从而恒等映射与任意映射#f 的乘积都等于映射自身，并且满足#highlight()[交换律]


=== 定理 在有定义的情况下，映射的乘积满足结合律 
#let bssss = $bold(S^(''''))$
即$h: #bs -> #bss, g:#bss -> #bsss, f:#bsss -> #bssss, (f g h) = (f g) h = f (g h)$. 
证明:
$
 forall x in #bs,  (f g h) x = f(g(h(x))), (f(g h))x = f((g h) x) = f(g(h(x))), ((f g) h)x = ((f g)(h(x))) = f(g(h(x))) = (f g h) x
$
因此三者相等（威力强大啊，矩阵乘法的结合律直接就被清楚诠释了）

== 逆映射
对于映射$f: #bs -> #bss, g:#bss -> #bs$,如果满足:$f g = 1_(#bss), g f = 1_(#bs)$ 那么称#f 是可逆的， #g 是 #f 的唯一一个逆映射。
下面证明唯一性：假设#g 和#h 都是#f 的逆映射，则 $h f g = (h f) g = 1_(#bs)g = g = h f g = h (f g) = h 1_(#bss) = h $，因此映射唯一


#let inf=$f^(-1)$
如果#f 是可逆的，我们用$f^(-1)$ 表示$f$的逆，那么$f#inf = 1_(#bss), #inf f = 1_(#bs)$，因此#inf 也是可逆的，他的逆就是#f， 从而$(#inf)^(-1) = f$

=== 定理（映射的可逆定理） 映射$f:#bs -> #bss$ 可逆的充要条件是#f 是双射
==== 引理 如果映射$f:#bs ->#bss, g:#bss -> #bs$ 满足$g f= 1_#bs$,则f是一个单射，g是一个满射
证明#f 是单射：令$a_1, a_2 in #bs, 且 f(a_1) = f(a_2) => a_1 = (g f)a_1 = g(f(a_1)) = g(f(a_2))= (g f)a_2 = 1_#bs a_2 = a_2;$ 从而#f 是单射 

证明#g 是满射， 这里要注意#f 的定义域是#bs, #f 的象集$in #bss$,  #g 的定义域是#bss, $forall a in #bs, g(f(a)) = (g f) a = a$,按照满射的定义，$forall a in #bs, f(a)$是a 在映射#g 的一个原象。这里要注意,此处还没有要求$f(a)$的象集就是#bss


==== 定理证明:
必要性: 设#f 可逆，有引理可以知道$cases(#f #inf = 1_#bs -> f 单 射, #inf #f = 1_#bss -> f 满 射)$ 从而#f 是双射

充分性: 设#f 双射，对于$forall a^' in #bss$,  由#f 的满射性质可知，$exists a in #bs s.t. f(a) = a^'$. 又因为#f 为单射，从而这个$a$唯一。 设$g: #bss -> #bs, g(a^') = a$,那么$(f g)a^' = f(g(a^')) = f(a) = a^' => (f g) = 1_#bss$, $(g f)a = g(f(a)) = g(a^') = a => (g f) = 1_#bs $. 结合两者，#f 可逆 定理得证。

这里比较坑的是被定义域困住了，一直在想定义域的事情

=== 习题
习题6. 对于#bs 和 #bss, 如果存在一个双射 $f:#bs -> #bss$， 则称#bs 和 #bss 有相同的基数，证明整数集$Z$ 和偶数集$O$ 有相同基数。

证：
$forall x in Z, f := 2x -> f(x) in O$ ，并且，$forall a, b in Z, a != b, f(a) = 2a != 2b = f(b) ->$ f 是一个单射
$forall y in O => y/2 in Z => f(y/2) = y$ 即，$y/2 in Z$ 是 $y in O$ 在映射#f 下的原象，从而#f 是双射。 两者同基

这是一个很奇妙的性质，一个东西的子集和他同基（等势）

#highlight()[所有和$Z$同基数的都是可数集合]

有理数集也是可数集，找个时间证一下。

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
因此可见$W$ 是一个封闭的空间（特别是第三个公式），注意其中第三个公式需要展开得出=== 可交换矩阵
如果#A#B =#B#A 则称$A B$ 时刻可交换的，可交换蕴含两个强限制条件1. #A#B #B#A 有定义且两者的结果相等 。我们容易验证$k #idef A = A (k #idef)$. 并且当这个等式成立时，A一定是和$#idef$ 同阶的#highlight()[方阵]

对于n阶矩阵$A_n$，我们可以定义他的n次幂$A^m = A dot A dot A ..., m>=0, m in Z$, 同时我们定义$A^0 =^(d e f) bold(I)$, 那么，就有$A^k A^l = A^(k + l) => 形 式 定 义$， $(A^k)^l = A^(k l) => 形 式 定 义$

即便$(A B)$ 是一个n阶方阵， $(A B)^k$ 有定义，由于 A B 一般不可交换，从而一般$(A B)^k != A^k B^k$.

#highlight(fill: red)[如果#A #B 可以交换]，则$(A B)^k = product_(i = 1)^k (A B)$，因为 #A #B 可以交换，则根据乘法的结合律，$(A B)_i (A B)_(i+1) = (A A)_i (B B)_(i+1) <- 交 换 中 间 的 A B$,这样，我们可以依次把所有的#A 逐个交换到乘积的前面，剩下的就是#B 的乘积，从而$product_i (A B)_i = product_i A_i product _i B_i = A^k B^k$

矩阵的二项式定理（主要复习二项式定理）
对于实数域的二项式定理:
$(a+b)^n = sum_k C_n^k a^k b^(n-k)$， 推理如下：

考虑乘法的分配律$(a+b)c = a c + b c$, 那么$(a+b)^2 = (a+b)(a+b) = a(a+b) + b(a+b) = a a + a b + b a + b b = a^2 + b^2 +2a b$ 这么展开来看：
1. 对于第1个乘法单元以分配律展开，a(a+b)，#highlight()[相当于选择第一个乘法单元中的a 和后者相乘],b(a+b) 类似的是选择...中的b与后者相乘
2. 对第二个乘法单元展开，a a 相当于第2个乘法单元也选择a ， 则产生$a^2$,  $a b$ 是第二个乘法单元选择b产生的结果。 同理 $b a$是1.选择b展开时，加上本单元选择a 展开产生， $b^2$结论类似

由此，我们可以推论$(a+b)^n$ 中，$a^k b^(n-k)$, 其系数的产生由$n$个乘积累单元中选择$k$个a，再从剩余的乘积单元中选择$k$个b产生，则其系数就是$C_n^k C_(n-k)^(n-k)=C_n^k$ 这个只能便于理解和记忆，下面让我们来正式的证明他：

step 0. 先证明帕斯卡法则 $C_(n-1)^k + C_(n-1)^(k-1) = C_n^k $

左边:

$C_(n-1)^k + C_(n-1)^(k-1) = frac((n-1)!, k! (n-1-k)!) + frac((n-1)!, (k-1)!(n-k)!) = (n-1)![frac(1, k!(n-k-1)!) + frac(1, (k-1)!(n-k)!)] = (n-1)!(frac((k-1)!(n-k)! + k!(n-1-k)!, k!(n-k-1)!(k-1)!(n-k)!)) = \
(n-1)!(k-1)![frac((n-k)! + k(n-k-1)!, k!(n-k-1)!(k-1)!(n-k)!)] = (n-1)!(n-k-1)![frac((n-k) + k, k!(n-k-1)!(n-k)!)] = (n-1)![frac((n-k) + k, k!(n-k)!)] = frac(n (n-1)!, k! (n-k)!) = n!/(k!(n-k)!) = C_n^k$ 


step 1. 假设$(a+b)^n = sum_(k=0)^n C_n^k a^k b^(n-k)$成立，易验证n = 1时, 等式成立，现在假设其在n=N 时成立

step 2. 我们证明(n= N+1)时也成立，证明如下:

$(a+b)^(N+1) = (a+b)[sum_k C_N^k a^k b^(N-k)] = a sum_k C_N^k a^k b^(N-k) + b sum_k C_N^k a^k b^(N-k) = sum_k C_N^k a^(k+1) b^(N-k) + sum_k C_N^k a^k b^(N-k +1) = sum_k A_k + sum_k B_k
$ 
对于$A_k, B_k$ ，令$k=t, 0<=t<=N-1）$, 对于$B_k$，令$k=t+1$，那么可以发现 $A_t + B_(t+1) = C_N^t a^(t+1)b^(N-t) + C_N^(t+1) a^(t+1)b^(N-t) = [a^(t+1)b^(N-t)][C_N^t +  C_N^(t+1)] = C_(N+1)^(t+1)(a^(t+1)b^(N+1-(t+1))) -> C_(N+1)^(tau)(a^(tau)b^(N+1-(tau))), 1 <= tau=t+1 <= N$， 这里$t $不能取N的原因是， 对于$B_k, 0 <= k <= N$

再证明，$tau=N+1$ 时也成立:
当要取$b^0$项时，可知$B_k$任意项不能产生$b^0$, $A_k$ 能取$b^0$时 只有$A_k_(k=N) = C_N^N a^(N+1)b^0 = C_(N+1)^(N+1) a^(N+1) b^(N+1-(N+1)) = C_(N+1)^(tau)(a^(tau)b^(N+1-(tau))) _(tau=N+1)$

再证明，$tau=0$ 时也成立：当要取$a^0$时，可知$A_k$ 不能产生$a^0$, 而$B_k$ 能取得$a^0$时 只有$B_k_(k=0) = C_(N)^N a^0 b^(N+1) =  C_(N+1)^(tau)(a^(tau)b^(N+1-(tau))) _(tau=0)$

从而，$forall 0<=k<=N+1, (a+b)^(N+1) = C_(N+1)^(k) a^(k) b^(n-k)$. 二项式定理得证

回到矩阵：

这里说明，当#A #B 不能交换时，二项式展开产生的#B #A 不一定有定义，即便有 他和#A#B 也不相等,即形如#B#A#A#B 这样的项不能合并，从而不适用二项式定理。对于可以交换的矩阵，不存在上述限制，则可以适用于二项式定理

=== 矩阵运算的结果的转置
转置真的是最讨人厌的东西之一, 形状变了，又要用符号表示和原矩阵的关系

容易证明:
1. $(#A + #B)^T = #A^T + #B^T$
2. $(k A)^T = k(A)^T$
3. $(A B)^T = B^T A^T$ #highlight()[这个需要特别留意]

这里先证明一下1. 设$A_(#sn), B_(#sn), C = (A + B)_(#sn), D_(n times s) = C^T$

$D_(n times s)_(j i) = c_(i,j)= a_(i, j) + b_(i.j);\
(A^T + B^T)_(j, i) = (A^T_(j,i) + B^T_(j, i)) = a_(i,j) + b_(i,j)
$

可见两者相等

在证明一下3.

设$A_(#sn), B_(#nm), C_(s times m) = A B $, 所以

$c_(i ,j) = sum_k a_(i, k) b_(k, j) = C^T_(j, i) \
(B^T A^T) (j, i) = sum_k B^T_(j, k) A^T_(k, i) = sum_k b_(k, j) a_(i, k) = sum_k a_(i, k)b_(k, j) => \
(A B)^T_(j, i) = C^T(j, i) = (B^T A^T)(j,i)   =>  (A B)^T = B^T A^T
$

=== 用矩阵表示线性方程组
#let bx=$bold(x)$
#let ba=$bold(a)$; #let bb=$bold(b)$
严格来说，原书到目前为止并没有给出矩阵和向量的相乘定义，这里直接把列向量当做一个n行1列的矩阵来看其实缺少说明，因为毕竟不是同一个东西.同时也不能体现和前文中引入矩阵乘法时矩阵的"映射"作用
这里给一个来自#link("https://mbernste.github.io/posts/matrix_vector_mult/#:~:text=As%20a%20%E2%80%9Crow%2Dwise%E2%80%9D,of%20a%20vector%20as%20coefficients")[github]的参考定义:

假设#A  的列数和列向量#bx 的元素数目相等，则定义矩阵和向量的乘法
$#A #bx :=  sum_i x_i #ba _i = #bb,
$ 其中$#ba _i$ 是矩阵的列向量,$x_i$ 是#bx 的各分量，#bb 是和#bx 同属于$K^n$空间，从而#A 是一个#highlight()[变换]

如果我们把线性方程组的未知量写成列向量$#bx = (x_1, x_2, ..., x_n)^'$，常数项写作$#bb = (b_1, b_2, ..., b_n)^'$, 那么线性方程组就可以写作:$A #bx = #bb$, A是方程组的系数矩阵，同理，齐次线性方程组就可写作$#A #bx = bold(0)$

=== 从其他角度看矩阵乘法
#let avecs = $(#ba _1, #ba _2 , ..., #ba _n)$
设$A_(#sn), B_(#nm)$, 如果把#A 以列向量形式表示，则$A = #avecs, #ba _i in K^s$,那么

$A B = #avecs mat(b_11, b_12, ..., b_(1 m);...; b_(n 1), b_(n 2), ..., b_(n m)) = (b_11#ba _1 + b_21 #ba _2 + ...+ b_(n 1)#ba _n,...,b_(1 m)#ba _1 + b_(2 m) #ba _2 + ...+ b_(n m)#ba _n)$， 即结果矩阵$C_(s times m)$ 列向量，#highlight()[是以矩阵B的各列的线性组合而生成]，C矩阵的列向量个数等于B矩阵的列，C矩阵的#highlight(fill:red)[列]向量$bold(c)_i in <#ba _1, #ba _2, ..., #ba _n>$

把#B 按照行向量形式表示，则$bold(B) = (#bb _1, #bb _2, ..., #bb _n)^', #bb _i in K^m$，那么矩阵乘法就可以写作$A bold(B) =
mat(a_11, a_12, ..., a_(1 n); ...; a_(s 1), a_(s 2), ...,a_(s n))vec(#bb _1, ..., #bb _n) = vec(a_11 #bb _1 + a_12 #bb _2 + ... + a_(1 n)#bb _n, ..., a_(s 1) #bb _1 + a_(s 2) #bb _2 + ... + a_(s n)#bb _n)$, #C 的各行向量是#B 矩阵的各行向量通过以#A 的各列为系数线性组合而成，从而#C 的#highlight(fill:red)[行]向量一定在$<#bb _1, #bb _2, ..., #bb _n>$ 中

= 特殊矩阵
=== 对角矩阵