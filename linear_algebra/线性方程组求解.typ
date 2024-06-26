#set text(
  font: "New Computer Modern",
  size: 6pt
)
#set page(
  paper: "a6",
  margin: (x: 1.8cm, y: 1.5cm),
)
#set par(
  justify: true,
  leading: 0.52em,
)
= 摘要
这些系列文档主要是复习线性代数的课堂笔记，现在稍微涉及到数学算法的地方通常都和线性代数脱不了关系，以下是一些不完全的举例：
#list(
[OpenGL中图形的生成、位置变换、投影变换等],
[数字信号分析中的各类变换的向量表示],
[数字图像处理中的卷积过程，图像变换等]
)

线性代数的出发点是求解线程方程组，线性方程组是指$n$元_一次_方程组。研究线性方程组的规律可以指导我们编写程序来求解这些线性方程组

线性方程组的解，是由$n$个有序数，可以理解$n$维的向量，有这个向量就可以引入线性空间的概念，比如二元一次方程组的解是一个平面向量，三元一次方程组的解是一个三维向量等等。

对于非线性问题，可以用线性问题来近似。



= 线性方程组求解及解的判定
以下是一个3元一次方程组

$cases(
2x_1 + 3x_3 = 1,
x_1 - x_2 + 2x_3 = 1,
x_1 - 3x_2 + 4x_3 = 2)$

我们写出其矩阵，第$m$行表示第$m$个方程，第$n$列表示第$n$个未知数的系数，最后一列表示方程的右边，即常数项

$mat(
2, 0, 3, 1;
1, 1, 2, 1;
1, -3, 4, 2;
)$

这样包含常数项的矩阵叫做增广矩阵，现在，按照方式来化简:
1. 第1行除以2, 第二行减去第一行

$mat(
1, 0, 1.5, 0.5;
0, 1, 0.5, 0.5;
1, -3, 4, 2;
)$

2. 第3行减去第1行
$mat(
1, 0, 1.5, 0.5;
0, 1, 0.5, 0.5;
0, -3, 2.5, 1.5;
)$

3. 第3行加上第2行的3倍

$mat(
1, 0, 1.5, 0.5;
0, 1, 0.5, 0.5;
0, 0, 4, 3;
)$

到这个地步，我们可以自下而上的求解出$x_3,x_2, x_1$, 上面的这些步骤，称为#highlight[*矩阵的初等行变换*]，矩阵的初等变换还包括行交换

观察3这个矩阵，我们可以发现矩阵自下而上，自右而左的出现非0项
$mat(
  1, X,  X, 0.5;
  0, 1, X, 0.5;
  0, 0, 4, 3;
)
$

这样的矩阵称为阶梯形，记作$J$，阶梯形对于判定方程组的解十分重要。每一行的第一个非0元称为主元，可以发现，#highlight[*主元的列指标随着行指标增加严格增加*]。
并且主元所在列的下方元素全为0（化简过程中被消去）

我们的化简过程，各行通过加减第一行的线性倍数，消去第一个元素（后方的先不管），这样第一个主元生成了（第1列的主元），接下来，我们操作第2行，将第$b_2^2$下方的元素消去,如果第一步使得第2行的第2列为0，我们通过寻找一个第2列不为0的行，让其与第2行交换（等价），如果找不到这样的行（即除了$b_1^2$之外），其余的都为0，说明第2列没有主元，则我们直接操作第3列，以此类推，只要某一列有主元，则该主元左侧都为0（被前面的列的主元消去）

假设第2列有主元，我们通过各行（3开始）加上第2行的各线性倍数消除第2列的元素，同时，这个过程中，第1列都是0（这些行的第1列在生成第1列主元的过程中已经清理为0，线性叠加$b_2^1= 0$的各倍数仍然是0）

我们还可以继续化简这个矩阵，#highlight[使得每一行的主元都为1，主元所在列的其他元素都为0]:
接下来我们以$r_n$ 表示第$n$行，$c_m$ 表示第m列，以减少篇幅
1. $r_3/4; r_2 - r_3/2$
$
mat(
  1, 0, 1.5, 0.5;
0, 1, 0, -1/4;
0, 0, 1, 3/4;
)
$
2. $r_1 - 3/2 r_3$
$
mat(
  1,0,0, -5/8;
  0,1,0, -1/4;
  0,0,1, 3/4
)
$
这样，我们就直接得到了原方程组的解$(x_1 = -5/8, x_2 = -1/4, x_3 = 3/4)$

而这样的阶梯形，称作简化阶梯形，记作$J_1$


我们可以看到，在化简阶梯形时，#highlight(fill: yellow)[我们可以将主元列除主元之外的其他元素全部清理为0]

这个过程中，我们自下而上，自右往左的操作消去主元所在列的元素，我们这样操作的理由是：每个主元的左侧及下方都是0，我们从最后一个主元开始，通过各线性叠加消除所在列的元素时，不会给其左侧列带入额外的元素，后者重复如此，因而最终能化成这种简化阶梯型的

同时我们注意到右侧是不保证的


== 方程组解的判定
定理:
$n$元线性方程组的解有且只有以下三种情况:
1. 有唯一解
2. 有无穷多解
3. 无解

=== 推论： 阶梯形的矩阵的非0行的行数不可能超过未知量数目
设主元的位置为$b_r^t$, 表示主元在第r行第t列，并且主元不能处于最后一列$(n+1)$, 故$t <= n$， 又由主元定义可知，主元的列随着行的增加而严格增加，即$t>=r$，因此 $r<=n$，即非0行数目不会超过未知量数目


=== 无解
先说明无解的情况, 当一个方程($n$)的增广矩阵的简化阶梯形的最后一个主元出现在最后一列时，此时该方程组无解，这是因为$(0_1, 0_2, ..., 0_n, 1)$ 相当于方程$0x_1 + 0x_2 + ... + 0x_n = 1 => 0 = 1$, 显然不存在解

=== 唯一解
再说明有唯一解的情况，
当此方程组有m个，并且$m>=n$，当该方程组矩阵的简化阶梯形可以化简到具有$n$个主元的情况是，我们参考简化阶梯形的定义 #highlight(fill: red.darken(20%))[所在行的第一个非0元以及所在列的唯一一个非零元, 并且值为1]

我们有$n$个主元要放置到$n$列，所以抛开所有0行，剩下的每一行都有且只有一个非0项即主元项，形式如下:
$
mat(
  1, 0, 0, ..., d_0;
  0, 1, 0, ..., d_1;
  ..., 0, 0, 1, d_n;
  0, ..., 0, 0, 0;
  ..., ..., ..., ..., ...;
)
$
自 第$n$行以下，全为0行，第$1 - n$行，每行有且只有一个主元，他们的值都是1，则$(d_0, d_1, ..., d_n)$ 就是原方程组的唯一解。#highlight(fill: red.darken(20%))[主元不能出现在最后一列]

=== 无穷多解
当方程组的简化阶梯形的主元数量$K$小于$n$时, 假设这些主元位于$c_k, c_k in [1, n]$列, 那么，没有主元的列则为$n-K$个，假设这些列式$c_l, c_l in [1, n]$, 一种可能得形式如下:
$
mat(
  1, 0, 0, 0, 1, 3;
  0, 1, 0, 1, 0, 3;
  0, 0, 1, 0, 0, 2;
  0, 0, 0, 0, 0, 0;
  0, 0, 0, 0, 0, 0;
)
$ 

这个例子中，主元位于$(1,2,3)$列， $4, 5$列没有主元，所以这些方程就得写作:
$
cases(
  x_1 + x_5 = 3,
  x_2 + x_4 = 3,
  x_3  = 2,
) =>
cases(
  x_1 = 3 - x_5,
  x_2 = 3 - x_4,
  x_3 = 2
)
$
对于任何一个$x_4, x_5$的取值，原方程组都有一个解，而这两者的取值是无穷多，因此解也有无穷多个。 回到出发点，简化阶梯形中，主元所在的行的$c_l$列可能不为0，因而主元位置的未知量就是和$c_l$未知量 组成一个方程，$c_l$位置的未知量无法被消或者通过主元固定，所以这样的解就有无穷多个了

