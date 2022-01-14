	.file	"Q1_process.c"
	.text
	.section	.rodata
.LC0:
	.string	"student_record.csv"
	.align 8
.LC1:
	.string	"An error occurred, Error Number: %d\n"
	.align 8
.LC2:
	.string	"Parent Process: Error in Opening File \n"
	.align 8
.LC3:
	.string	"Parent Process: Error in reading file \n"
.LC4:
	.string	"\n"
.LC5:
	.string	","
.LC6:
	.string	"B"
	.align 8
.LC7:
	.string	"Parent Process: Problem in closing file \n"
	.align 8
.LC8:
	.string	"\nThere are no students in section A "
	.align 8
.LC9:
	.string	"\n Assignment %d average for section B is: %.6f \n"
	.text
	.globl	parentProcess
	.type	parentProcess, @function
parentProcess:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4096, %rsp
	orq	$0, (%rsp)
	subq	$4096, %rsp
	orq	$0, (%rsp)
	subq	$2736, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -10876(%rbp)
	cmpl	$0, -10876(%rbp)
	jns	.L2
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC2(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L2:
	leaq	-10016(%rbp), %rcx
	movl	-10876(%rbp), %eax
	movl	$10000, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movl	%eax, -10872(%rbp)
	cmpl	$0, -10872(%rbp)
	jns	.L3
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC3(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L3:
	leaq	-10016(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -10864(%rbp)
	movl	$0, -10900(%rbp)
	movl	$0, -10896(%rbp)
	jmp	.L4
.L5:
	movl	-10900(%rbp), %eax
	cltq
	movq	-10864(%rbp), %rdx
	movq	%rdx, -10816(%rbp,%rax,8)
	addl	$1, -10900(%rbp)
	leaq	.LC4(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -10864(%rbp)
.L4:
	cmpq	$0, -10864(%rbp)
	jne	.L5
	movl	$1, -10892(%rbp)
	jmp	.L6
.L11:
	movl	-10892(%rbp), %eax
	cltq
	movq	-10816(%rbp,%rax,8), %rax
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -10856(%rbp)
	movl	$0, -10888(%rbp)
	movl	$0, -10884(%rbp)
	jmp	.L7
.L10:
	addl	$1, -10888(%rbp)
	cmpl	$1, -10888(%rbp)
	je	.L8
	cmpl	$2, -10888(%rbp)
	jne	.L9
	movq	-10856(%rbp), %rax
	leaq	.LC6(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L8
	movl	$1, -10884(%rbp)
	addl	$1, -10896(%rbp)
	jmp	.L8
.L9:
	cmpl	$1, -10884(%rbp)
	jne	.L8
	movl	-10888(%rbp), %eax
	subl	$2, %eax
	cltq
	movss	-10848(%rbp,%rax,4), %xmm2
	movss	%xmm2, -10916(%rbp)
	movq	-10856(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cvtsi2ssl	%eax, %xmm0
	movl	-10888(%rbp), %eax
	subl	$2, %eax
	addss	-10916(%rbp), %xmm0
	cltq
	movss	%xmm0, -10848(%rbp,%rax,4)
.L8:
	leaq	.LC5(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -10856(%rbp)
.L7:
	cmpq	$0, -10856(%rbp)
	jne	.L10
	addl	$1, -10892(%rbp)
.L6:
	movl	-10892(%rbp), %eax
	cmpl	-10900(%rbp), %eax
	jl	.L11
	movl	-10876(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	%eax, -10868(%rbp)
	cmpl	$-1, -10868(%rbp)
	jne	.L12
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC7(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L12:
	cmpl	$0, -10896(%rbp)
	jne	.L13
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	jmp	.L18
.L13:
	movl	$1, -10880(%rbp)
	jmp	.L15
.L16:
	movl	-10880(%rbp), %eax
	cltq
	movss	-10848(%rbp,%rax,4), %xmm0
	cvtsi2ssl	-10896(%rbp), %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	-10880(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC9(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -10880(%rbp)
.L15:
	cmpl	$6, -10880(%rbp)
	jle	.L16
.L18:
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L17
	call	__stack_chk_fail@PLT
.L17:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	parentProcess, .-parentProcess
	.section	.rodata
	.align 8
.LC10:
	.string	"Child Process: Error in Opening File\n"
	.align 8
.LC11:
	.string	"Child Process: Error in reading file\n"
.LC12:
	.string	"A"
	.align 8
.LC13:
	.string	"\n Assignment %d average for section A is: %.6f \n"
	.text
	.globl	childProcess
	.type	childProcess, @function
childProcess:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4096, %rsp
	orq	$0, (%rsp)
	subq	$4096, %rsp
	orq	$0, (%rsp)
	subq	$2736, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -10876(%rbp)
	cmpl	$0, -10876(%rbp)
	jns	.L20
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC10(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L20:
	leaq	-10016(%rbp), %rcx
	movl	-10876(%rbp), %eax
	movl	$10000, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movl	%eax, -10872(%rbp)
	cmpl	$0, -10872(%rbp)
	jns	.L21
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC11(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L21:
	leaq	-10016(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -10864(%rbp)
	movl	$0, -10900(%rbp)
	movl	$0, -10896(%rbp)
	jmp	.L22
.L23:
	movl	-10900(%rbp), %eax
	cltq
	movq	-10864(%rbp), %rdx
	movq	%rdx, -10816(%rbp,%rax,8)
	addl	$1, -10900(%rbp)
	leaq	.LC4(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -10864(%rbp)
.L22:
	cmpq	$0, -10864(%rbp)
	jne	.L23
	movl	$1, -10892(%rbp)
	jmp	.L24
.L29:
	movl	-10892(%rbp), %eax
	cltq
	movq	-10816(%rbp,%rax,8), %rax
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -10856(%rbp)
	movl	$0, -10888(%rbp)
	movl	$0, -10884(%rbp)
	jmp	.L25
.L28:
	addl	$1, -10888(%rbp)
	cmpl	$1, -10888(%rbp)
	je	.L26
	cmpl	$2, -10888(%rbp)
	jne	.L27
	movq	-10856(%rbp), %rax
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L26
	movl	$1, -10884(%rbp)
	addl	$1, -10896(%rbp)
	jmp	.L26
.L27:
	cmpl	$1, -10884(%rbp)
	jne	.L26
	movl	-10888(%rbp), %eax
	subl	$2, %eax
	cltq
	movss	-10848(%rbp,%rax,4), %xmm2
	movss	%xmm2, -10916(%rbp)
	movq	-10856(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cvtsi2ssl	%eax, %xmm0
	movl	-10888(%rbp), %eax
	subl	$2, %eax
	addss	-10916(%rbp), %xmm0
	cltq
	movss	%xmm0, -10848(%rbp,%rax,4)
.L26:
	leaq	.LC5(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -10856(%rbp)
.L25:
	cmpq	$0, -10856(%rbp)
	jne	.L28
	addl	$1, -10892(%rbp)
.L24:
	movl	-10892(%rbp), %eax
	cmpl	-10900(%rbp), %eax
	jl	.L29
	movl	-10876(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	%eax, -10868(%rbp)
	cmpl	$-1, -10868(%rbp)
	jne	.L30
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC7(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L30:
	cmpl	$0, -10896(%rbp)
	jne	.L31
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	jmp	.L32
.L31:
	movl	$1, -10880(%rbp)
	jmp	.L33
.L34:
	movl	-10880(%rbp), %eax
	cltq
	movss	-10848(%rbp,%rax,4), %xmm0
	cvtsi2ssl	-10896(%rbp), %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	-10880(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC13(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -10880(%rbp)
.L33:
	cmpl	$6, -10880(%rbp)
	jle	.L34
.L32:
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE7:
	.size	childProcess, .-childProcess
	.section	.rodata
	.align 8
.LC14:
	.string	"Child Process could not be created"
.LC15:
	.string	"Error in waitpid \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	call	fork@PLT
	movl	%eax, -16(%rbp)
	cmpl	$0, -16(%rbp)
	jns	.L37
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC14(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L37:
	cmpl	$0, -16(%rbp)
	jle	.L38
	movl	$0, %eax
	call	parentProcess
	leaq	-20(%rbp), %rcx
	movl	-16(%rbp), %eax
	movl	$0, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	waitpid@PLT
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jns	.L40
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC15(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L38:
	movl	$0, %eax
	call	childProcess
.L40:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L42
	call	__stack_chk_fail@PLT
.L42:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
