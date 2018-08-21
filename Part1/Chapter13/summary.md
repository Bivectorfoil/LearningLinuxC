# C语言入门总结

## C的语法规则。

1. 源文件中所有函数定义之外可以出现哪些语法元素？

   语句，全局变量定义。


1. 函数定义之中可以出现哪些语法元素？

   变量声明，赋值，语句，函数调用

2. 语句有哪几种？

   赋值语句，循环语句，函数调用语句，控制语句


1. 哪些语法元素需要遵循标识符的命名规则？

   变量，结构体，枚举常量，函数

2. 表达式由哪些语法元素组成？

   运算符和操作数

3. 到目前为止学过哪些运算符？它们的优先级和结合性是怎样的？

   \+ - * / | ~ &&

4. 哪些运算符取操作数的左值？哪些运算符的操作数必须是整型？哪些运算符有Side Effect？

5. 哪些表达式可以做左值？哪些表达式只能做右值？

6. 哪些地方必须用常量表达式？哪些地方必须用整数常量表达式？

## 思维方法与编程思想。

- 以概念为中心，[第 1 节 “程序和编程语言”](https://akaedu.github.io/book/intro.program.html)
- 组合规则，[第 5 节 “表达式”](https://akaedu.github.io/book/expr.expression.html)
- Least Surprise，[第 3 节 “形参和实参”](https://akaedu.github.io/book/ch03s03.html#func.paraarg)
- 充分条件与必要条件，[第 4 节 “全局变量、局部变量和作用域”](https://akaedu.github.io/book/ch03s04.html#func.localvar)
- 封装，[第 2 节 “if/else语句”](https://akaedu.github.io/book/ch04s02.html#cond.ifelse)
- 布尔逻辑，[第 3 节 “布尔代数”](https://akaedu.github.io/book/ch04s03.html#cond.bool)
- 递归，[第 3 节 “递归”](https://akaedu.github.io/book/ch05s03.html#func2.recursion)
- 函数式编程，[第 1 节 “while语句”](https://akaedu.github.io/book/ch06s01.html#iter.while)
- 迭代（[第 6 章 *循环语句*](https://akaedu.github.io/book/ch06.html#iter)）与增量式求解（[第 2 节 “插入排序”](https://akaedu.github.io/book/ch11s02.html#sortsearch.insertion)）
- 抽象，[第 2 节 “数据抽象”](https://akaedu.github.io/book/ch07s02.html#struct.abstract)
- 数据驱动，[第 5 节 “多维数组”](https://akaedu.github.io/book/ch08s05.html#array.multidimension)
- 分而治之，[第 4 节 “归并排序”](https://akaedu.github.io/book/ch11s04.html#sortsearch.merge)
- 折半查找，[第 6 节 “折半查找”](https://akaedu.github.io/book/ch11s06.html#sortsearch.binary)
- 回溯，[例 12.3 “用深度优先搜索解迷宫问题”](https://akaedu.github.io/book/ch12s03.html#stackqueue.dfs)

## 调试方法

- 编译错误、运行时错误与语义错误，[第 3 节 “程序的调试”](https://akaedu.github.io/book/ch01s03.html#intro.debug)
- 增量式开发，[第 2 节 “增量式开发”](https://akaedu.github.io/book/ch05s02.html#func2.incremental)
- 打印语句与Scaffold，[第 2 节 “增量式开发”](https://akaedu.github.io/book/ch05s02.html#func2.incremental)
- gdb，[第 10 章 *gdb*](https://akaedu.github.io/book/ch10.html#gdb)
- DbC与Assertion，[第 6 节 “折半查找”](https://akaedu.github.io/book/ch11s06.html#sortsearch.binary)