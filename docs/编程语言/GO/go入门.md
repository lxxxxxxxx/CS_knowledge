
# go命令

   
    //编译多个以go结尾的源文件，链接库文件，生成可执行文件并执行
    go run hello.go world.go
    
    //编译生成可执行文件
    go build hello.go



# 包
GO语言通过“包”组织来组织源代码，以目录结构定义包，通过`package`关键字来定义波阿，通过`import`关键字来导入包（与java类似），GO只能到如用到的包，导入多余的包也会报错。


# 变量
变量用`var`关键字声明



# 常量
常量用`const`关键字声明


# 函数
函数用`func`关键字声明，后面跟函数名，形参列表，返回值列表以及函数体，返回值列表可省略。
```
func name (parameter-list) (return-list) {
    body;
}
```

几种函数声明的方法

```
//完整声明
func min(a int,b int)(c int){return a>b?b:a}

//多个同类形参只需写一个类型，省略返回值变量名
func min(a,b int) (int) {return a>b?b:a}

//


```





# 类型
类型用`type`关键字声明

- GO语言原生支持UNICODE，可以处理全世界任何语言
- 
