{{ self.title() }}

作者: 程泽瑞 

## 题目简述

一个环上有$n$个点，要求任意连续的$(k+1)$个点不同色，求最少颜色数。

敏珂同学会给你一个答案，你只需要判断这个答案是大了/小了/正好/无法判断。

数据范围：$1 \le n \le 10^{10^6} $ 且 $ 1 \le k \le 100 $

## 子任务设计

对于所有数据，满足$ n \le 10^5 $ 或 $n \ge 10^{100} $

## 题解

这道题的题面主要起迷惑作用 （不会吧不会吧，不会有人真的对于 $n \ge 10^{100} $ 的部分输出无法判断了吧）

实际上，只需要解决敏珂同学所声称解决的问题，然后比较敏珂的答案和实际答案就可以了。

首先，对于$n \le 2k+1$的情况，任意两个点都不可以同色，于是最少颜色数就是$n$ (注意 $n \le k$的情况)；

否则，既然要求连续$(k+1)$个点不同色，那么这道题的答案至少为$(k+1)$,

可以发现，将$n$个点按照$(k+1)$的长度分成若干段，需要$ m = \lfloor \frac{n}{k+1} \rfloor $段，还剩下$ n \bmod (k+1)$ 个点没有分配颜色；

对于没有分配颜色的点，可以把它们均匀分配在这些段中，而答案就是最长段长度的最小值，也就是$ k+1+ \lceil \frac{ n \bmod (k+1)}{m} \rceil $

因此，我们只需要计算出$ ans = k+1+ \lceil \frac{ n \bmod (k+1)}{m} \rceil $ ，然后与敏珂的答案作比较就可以了。

同时，可以注意到当$n \ge k^2+k $ 时，答案一定为$ k+1 $ 或 $k+2$ （若$n$能整除$(k+1)$，则答案为前者，反之为后者）

因此，对于较大的$n$只需要做一次高精度模单精度（扫一遍即可），较小的$n$直接计算即可，时间复杂度  $O\left(\log{n} \right)$。

其实，这道题完全可以把$k$出到$10^{10^6}$ 变成一道FFT题，或者把$k$出大一点变成高精度除法题，

但良心出题人为了大家签到愉快就没有这么做啦，希望大家签到愉快~



| 不推荐写法          | 推荐写法                                    | 解释                                       |
| -------------- | --------------------------------------- | ---------------------------------------- |
| $O(n^3)$       | $O\left(n^3 \right)$                    | 长得比较高的括号里的东西，要告诉括号把高出来的部分括进去             |
| $log(n)$       | $\log{n}$                               | `log` 是有专门的正体符号，不要用斜体的变量格式               |
| $max$          | $\max$                                  | 同上                                       |
| $a~mod~Q$      | $a\bmod Q$                              | 我们常用的 `mod` 是 `\bmod`                    |
| $O(n*m/32)$    | $O\left(\frac{nm}{w}\right)$，其中 $w$ 是字长 | 大O的常数是忽略的，没有意义；这么写容易误导人在O里面写常数；星号不是乘号，可以不写或用 `\times` 或 `\cdot` |
| 第k(k<j)个       | 第 $k$（$k<j$）个                           | 数学表达式应当用表达式，行文中的标点符号（这里是表解释的圆括号）要统一用中文标点（也可以像数学书上统一用英文标点） |
| $d[a[i][b[j]]$ | $d\left(a_i, b_j\right)$                | 方括号表下标比较少见，一般用圆括号和下标                     |
| $a~xor~b$      | $a~\mathrm{xor}~b$                      | 不存在的算符可以用 `\mathrm{}` 造出来                |
| 输出“Yes”（不包含引号） | 输出 `Yes`                                | 字符串有专门的格式可以用，不用使用引号加正文                   |

