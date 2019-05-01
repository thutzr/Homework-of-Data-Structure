这是这学期数据结构课的作业repo，我将会吧所有作业都推送到这里。作业全部采用C++编写，VS2015编译，目前作业一共更新到第7次，第1，2，3，4，5，6，7次作业已经完成
~~~
    * HW1: 100
    * HW2: 100
    * HW3: 100
    * HW4: 100
    * HW5: 100
    * HW6: 100
    * HW7: 100
    * HW8: 100
    * HW9: 100
~~~
## 目录
* [HW1](Project1)
* [HW2](project2)
* [HW3](project3)
* [HW4](Project4)
* [HW5](Project5)
* [HW6](project6)
* [HW7](project7)
* [HW8](project8)
* [HW9](project10)
## HW6 - 判断括号是否匹配
### 题目描述
括号包括 ’(’, ’)’, ’{’, ’}’, ’[’ 和’]’,()[]、({()[]})是合法的,而({)}、{[}是非法的
### 输入
第一行为测试样本个数n，接下来每行为一个仅包含括号的字符串
### 输出
1表示合法，0不合法
### 样例输入
~~~
4
()[]
({()[]})
({)}
{[}
~~~
## 样例输出
~~~
1
1
0
0
~~~

# HW7-生成后序遍历
## 题目描述
给定一棵树的前序和中序遍历结果，要求输出后序遍历结果。
## 输入
第一行样本数N。

接下来每个样本，首先给定二叉树中的元素个数M<=30000，接下来分别给定前序和中序遍历结果。此二叉树中每个节点的数据类型均为整型，两个不同节点之间以空格分隔。
## 输出
对每个样本，输出后序遍历结果。
## 样例输入
~~~
2
7
0 1 2 3 4 5 6 
2 1 3 0 5 4 6 
5
0 1 2 3 4 
1 0 3 2 4 
~~~
## 样例输出
~~~
2 3 1 5 6 4 0 
1 3 4 2 0 
~~~
## 提示
可以建树遍历，也可以不建树直接递归`

# HW9
## 题目描述
给定一个二叉搜索树，对于其中任意两个节点，我们都可以发现其最小公共祖先。如下面这棵树
~~~
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
~~~
0和9的公共祖先为6，3和5的公共祖先为4。元素本身可以是其自己的祖先。所以4和5的祖先是4，6和6的祖先为6。
事实上，给定一个输入序列，在不做任何平衡操作的情况下，我们可以通过不断在对这颗二叉搜索树做插入操作，从而唯一的确定这颗二叉搜索树。如这棵树就可以由输入序列：6 2 8 0 4 7 9 3 5确定。当然，这样的输入序列并不是唯一的。

## 输入
第一行两个数N M。其中N代表数据的个数，M代表样本数。

接下来一行有N个数，代表输入序列，用于构造这个二叉搜索树。

接下来M行，每行两个数，代表待查询的数。

## 输出
M行，每行1个数，代表待查询数的最小公共祖先。
## 样例输出
~~~
9 5
6 2 8 0 4 7 9 3 5
0 9
3 5
5 4
6 6
0 5
~~~

## 样例输出
~~~
6
4
4
6
2
~~~

# HW9--是否同一棵二叉搜索树
## 题目描述
给定一个插入序列唯一确定一个二叉搜索树，但一棵二叉搜索树是可以由不同的插入序列构成的。对输入的各种插入序列，判断是否为同一棵二叉搜索树
## 输入
序列长度L，需要检查的序列数N

初始序列，由两两不同的正整数构成

待检查的N个序列
## 输出
对每一组待检查序列，如果生成的二叉搜索树与初始序列相同，则输出YES，否则输出NO

每个输出后换行

## 样例输入
~~~
4 2
3 1 4 2
3 4 1 2
3 2 4 1
~~~
## 样例输出
~~~
YES
NO
~~~
