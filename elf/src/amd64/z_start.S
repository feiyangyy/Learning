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
	mov	%rsp,	%rdi /*;mov rdi, rsp*/
	mov	%rdx,	%rsi /*;mov rsi, rdx*/
	call	z_entry /*; 调用z_entry*/
	hlt

