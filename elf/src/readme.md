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

#### ELF 入口
https://www.cnblogs.com/revercc/p/16294051.html
这里有比较详细的介绍
步骤
1. 加载文件，检查elf_header
    * 是否合法
2. 加载程序段，把代码copy过去
2. 对于动态库，则还需要检查有没有 interp(ld.so)，**让他去加载对应动态库（存疑）**
3. 