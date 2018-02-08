# C note

## 循环语句篇

### for语句语法

> for (控制表达式1；控制表达式2；控制表达式3) 语句 

等价于下面这样的while语句：

> ```c
> 控制表达式1;
> while (控制表达式2) {
>         语句
>         控制表达式3;
> }
> ```

### i++ 和 ++i的区别：

++i：这个表达式相当于 `i = i + 1` ，++称为前缀自增运算符（Prefix Increment Operator）。类似地，–称为前缀自减运算符（Prefix Decrement Operator）， `--i` 相当于 `i = i - 1` 。如果把 `++i` 这个表达式看作一个函数调用，除了传入一个参数 `i` 返回一个值（返回值等于参数值加1）之外，还产生一个Side Effect，就是把变量 `i` 的值增加了1。

i++：后缀自增运算符（Postfix Increment Operator）和后缀自减运算符（Postfix Decrement Operator）。如果把 `i++` 这个表达式看作一个函数调用，传入一个参数 `i` 返回一个值，返回值就等于参数值（而不是参数值加1），此外也产生一个Side Effect，就是把变量 `i` 的值增加了1，它和 `++i` 的区别就在于返回值不同。 