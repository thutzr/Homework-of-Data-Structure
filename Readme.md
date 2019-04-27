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
可以建树遍历，也可以不建树直接递归

`
