1. x64 调用约定:
RDI：第一个参数
RSI：第二个参数
RDX：第三个参数
RCX：第四个参数
R8 ：第五个参数
R9 ：第六个参数

注意参数肯定是调用方设置的，被调用方至多是解析。。。


汇编入口：
```C++
	.text
	.align	4
	.globl	z_start
	.hidden	z_start
	.type	z_start,@function
z_start:
	/*rdi 第一个参数*/
	/*; rsi 第二个参数...*/
	/*; 因此这里传了两个参数*/
	/*; z_start 这里至少rdi可能都是设置过了（如果有参数的话）*/
  // 这个地方实际上对z_entry 搞了特殊的参数(赋值了rsp)， 相当于魔改了
  // 对于正常代码，参数就是通过rsp 传递的
	mov	%rsp,	%rdi /*;mov rdi, rsp*/
	mov	%rdx,	%rsi /*;mov rsi, rdx*/
	call	z_entry /*; 调用z_entry*/
	hlt


```

```C++
	.text
	.align	4
	.globl	z_trampo
	.type	z_trampo,@function
z_trampo:
	/*; 这里相当于设置栈（不是入栈），让我想起了caller-save 和 callee-save；这里把第二个参数舍之道rsp上（设置栈）
	mov	%rsi,	%rsp 
	/*; 另外这里rsi 被原封不动的传递给了被调用者*/
	/*; 跳转到rdi 注意此时rdi 已经设置，是第一个参数， 剩余的像 rsi 会被作为第二个参数传递，等等等等，他这里相当于直接复用了rsp的东西*/
	// 注意这里的SB 汇编语法
  jmp	*%rdi 
	/* Should not reach. */
	hlt

```

代码总结，这个更像是一个启动装饰器，即实现了程序加载的文件解析和内存映射、参数配置和跳转。没有实现对应用程序的堆栈设置等

#### ELF 入口
https://www.cnblogs.com/revercc/p/16294051.html
这里有比较详细的介绍
步骤
1. 加载文件，检查elf_header
    * 是否合法
2. 加载程序段，把代码copy过去
2. 对于动态库，则还需要检查有没有 interp(ld.so)，**让他去加载对应动态库（存疑）**
3. 

错误认识:
1. 进程可以在用户程序中直接创建
		* 这里的直接创建的意思是: 用户程序可以直接设置堆栈空间以及哪些乱七八糟的参数等，然后跳转到程序入口等。
				* **经过测试，是可以通过用户代码mmap一段内存作为exec的栈的，要注意步长问题，这里跳转不过去是因为别的问题，可能参数设置的不正确**
		* 目前还不确认是否不可以，不过在C++ 代码中，因为入口的问题(main不是真正的入口)，栈早就被改的面目全非了，如何在现有的栈
		上配置哪些参数不知道。
				* 在往入口跳转时，能否自己mmap一段内存作为栈? 如何copy 哪些参数
		* 还有比如auxv 这种东西（Kernel 提供的一些信息）
2. 跳转时，内核只传递sp/fini, 应用程序通过解析栈以及fini 从而加载程序

C 语言更适合学机制，特别是面向硬件、系统的机制。Java更适合学设计、业务。C++ 夹在两者中间，想用C加上一些额外的东西，完成C++的功能
但是C语言表达能力不够强，因此制作调试器以及业务较为复杂的系统工具时，C++可能更为合适
#### cheat sheet学习
https://gist.github.com/x0nu11byt3/bcb35c3de461e5fb66173071a2379779

#### chunk 分块
##### 1. section view

section 是elf的单元，以section为单位分析elf时，可主要用于连接处理

##### 2. programing view （segments）

一个segments 包含一个或者多个section, segments 是真正要加载到内存中的东西

常见的text  data bss rodata
还有hash dynsym synstr plt rel.got dynamic ...
