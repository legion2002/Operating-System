	.file	"Q1_thread.c"
	.text
	.comm	tid1,8,8
	.comm	tid2,8,8
	.comm	records,800,32
	.comm	AssignmentSumsB,28,16
	.comm	AssignmentSumsA,28,16
	.globl	row
	.bss
	.align 4
	.type	row, @object
	.size	row, 4
row:
	.zero	4
	.globl	rowsB
	.align 4
	.type	rowsB, @object
	.size	rowsB, 4
rowsB:
	.zero	4
	.globl	rowsA
	.align 4
	.type	rowsA, @object
	.size	rowsA, 4
rowsA:
	.zero	4
	.comm	list,32000,32
	.section	.rodata
	.align 8
.LC0:
	.string	"\n There are no students in the file"
	.align 8
.LC1:
	.string	"\n Combined Assignment %d average is: %.6f \n"
	.text
	.globl	finalAverages
	.type	finalAverages, @function
finalAverages:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	rowsB(%rip), %edx
	movl	rowsA(%rip), %eax
	addl	%edx, %eax
	testl	%eax, %eax
	jne	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	jmp	.L3
.L2:
	movl	$1, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	AssignmentSumsB(%rip), %rax
	movss	(%rdx,%rax), %xmm1
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	AssignmentSumsA(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movl	rowsB(%rip), %edx
	movl	rowsA(%rip), %eax
	addl	%edx, %eax
	cvtsi2ssl	%eax, %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L4:
	cmpl	$6, -4(%rbp)
	jle	.L5
.L3:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	finalAverages, .-finalAverages
	.section	.rodata
	.align 8
.LC2:
	.string	"\n There are no students in section B "
	.align 8
.LC3:
	.string	"\n Assignment %d average for section B is: %.6f \n"
	.align 8
.LC4:
	.string	"An error occurred, Error Number: %d\n"
.LC5:
	.string	"Error in joining threads \n "
	.text
	.globl	parentProcess
	.type	parentProcess, @function
parentProcess:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1, -12(%rbp)
	jmp	.L7
.L9:
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	4+list(%rip), %rax
	movl	(%rdx,%rax), %eax
	cmpl	$1, %eax
	jne	.L8
	movss	4+AssignmentSumsB(%rip), %xmm1
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	8+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 4+AssignmentSumsB(%rip)
	movss	8+AssignmentSumsB(%rip), %xmm1
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	12+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 8+AssignmentSumsB(%rip)
	movss	12+AssignmentSumsB(%rip), %xmm1
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	16+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 12+AssignmentSumsB(%rip)
	movss	16+AssignmentSumsB(%rip), %xmm1
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	20+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 16+AssignmentSumsB(%rip)
	movss	20+AssignmentSumsB(%rip), %xmm1
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	24+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 20+AssignmentSumsB(%rip)
	movss	24+AssignmentSumsB(%rip), %xmm1
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	28+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 24+AssignmentSumsB(%rip)
	movl	rowsB(%rip), %eax
	addl	$1, %eax
	movl	%eax, rowsB(%rip)
.L8:
	addl	$1, -12(%rbp)
.L7:
	movl	row(%rip), %eax
	cmpl	%eax, -12(%rbp)
	jl	.L9
	movl	rowsB(%rip), %eax
	testl	%eax, %eax
	jne	.L10
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	jmp	.L11
.L10:
	movl	$1, -8(%rbp)
	jmp	.L12
.L13:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	AssignmentSumsB(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	movl	rowsB(%rip), %eax
	cvtsi2ssl	%eax, %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -8(%rbp)
.L12:
	cmpl	$6, -8(%rbp)
	jle	.L13
.L11:
	movq	tid1(%rip), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L14
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC5(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L14:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	parentProcess, .-parentProcess
	.section	.rodata
	.align 8
.LC6:
	.string	"\nThere are no students in section A "
	.align 8
.LC7:
	.string	"\n Assignment %d average for section A is: %.6f \n"
	.text
	.globl	childProcess
	.type	childProcess, @function
childProcess:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1, -8(%rbp)
	jmp	.L16
.L18:
	movl	-8(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	4+list(%rip), %rax
	movl	(%rdx,%rax), %eax
	testl	%eax, %eax
	jne	.L17
	movss	4+AssignmentSumsA(%rip), %xmm1
	movl	-8(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	8+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 4+AssignmentSumsA(%rip)
	movss	8+AssignmentSumsA(%rip), %xmm1
	movl	-8(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	12+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 8+AssignmentSumsA(%rip)
	movss	12+AssignmentSumsA(%rip), %xmm1
	movl	-8(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	16+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 12+AssignmentSumsA(%rip)
	movss	16+AssignmentSumsA(%rip), %xmm1
	movl	-8(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	20+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 16+AssignmentSumsA(%rip)
	movss	20+AssignmentSumsA(%rip), %xmm1
	movl	-8(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	24+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 20+AssignmentSumsA(%rip)
	movss	24+AssignmentSumsA(%rip), %xmm1
	movl	-8(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	28+list(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	%xmm0, 24+AssignmentSumsA(%rip)
	movl	rowsA(%rip), %eax
	addl	$1, %eax
	movl	%eax, rowsA(%rip)
.L17:
	addl	$1, -8(%rbp)
.L16:
	movl	row(%rip), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L18
	movl	rowsA(%rip), %eax
	testl	%eax, %eax
	jne	.L19
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
	jmp	.L20
.L19:
	movl	$1, -4(%rbp)
	jmp	.L21
.L22:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	AssignmentSumsA(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	movl	rowsA(%rip), %eax
	cvtsi2ssl	%eax, %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L21:
	cmpl	$6, -4(%rbp)
	jle	.L22
.L20:
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE8:
	.size	childProcess, .-childProcess
	.section	.rodata
.LC8:
	.string	"student_record.csv"
.LC9:
	.string	"Error in Opening File \n"
.LC10:
	.string	" Error in reading file\n"
.LC11:
	.string	"\n"
.LC12:
	.string	","
.LC13:
	.string	"A"
.LC14:
	.string	"B"
	.align 8
.LC15:
	.string	"Parent Process: Problem in closing file \n"
.LC16:
	.string	"Error in Creating Thread \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
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
	subq	$1872, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %esi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -10052(%rbp)
	cmpl	$0, -10052(%rbp)
	jns	.L24
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC9(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L24:
	leaq	-10016(%rbp), %rcx
	movl	-10052(%rbp), %eax
	movl	$10000, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movl	%eax, -10048(%rbp)
	cmpl	$0, -10048(%rbp)
	jns	.L25
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC10(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L25:
	leaq	-10016(%rbp), %rax
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -10032(%rbp)
	jmp	.L26
.L27:
	movl	row(%rip), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	leaq	records(%rip), %rdx
	movq	-10032(%rbp), %rax
	movq	%rax, (%rcx,%rdx)
	movl	row(%rip), %eax
	addl	$1, %eax
	movl	%eax, row(%rip)
	leaq	.LC11(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -10032(%rbp)
.L26:
	cmpq	$0, -10032(%rbp)
	jne	.L27
	movl	$1, -10060(%rbp)
	jmp	.L28
.L41:
	movl	-10060(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	records(%rip), %rax
	movq	(%rdx,%rax), %rax
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -10024(%rbp)
	movl	$0, -10056(%rbp)
	movl	$0, -10036(%rbp)
	jmp	.L29
.L40:
	cmpq	$0, -10024(%rbp)
	jne	.L30
	jmp	.L29
.L30:
	addl	$1, -10056(%rbp)
	cmpl	$1, -10056(%rbp)
	jne	.L31
	movq	-10024(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	-10060(%rbp), %edx
	movslq	%edx, %rdx
	movq	%rdx, %rcx
	salq	$5, %rcx
	leaq	list(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	jmp	.L32
.L31:
	cmpl	$2, -10056(%rbp)
	jne	.L33
	movq	-10024(%rbp), %rax
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L34
	movl	-10060(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	4+list(%rip), %rax
	movl	$0, (%rdx,%rax)
	jmp	.L32
.L34:
	movq	-10024(%rbp), %rax
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L32
	movl	-10060(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	4+list(%rip), %rax
	movl	$1, (%rdx,%rax)
	jmp	.L32
.L33:
	cmpl	$3, -10056(%rbp)
	jne	.L35
	movq	-10024(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cvtsi2ssl	%eax, %xmm0
	movl	-10060(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	8+list(%rip), %rax
	movss	%xmm0, (%rdx,%rax)
	jmp	.L32
.L35:
	cmpl	$4, -10056(%rbp)
	jne	.L36
	movq	-10024(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cvtsi2ssl	%eax, %xmm0
	movl	-10060(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	12+list(%rip), %rax
	movss	%xmm0, (%rdx,%rax)
	jmp	.L32
.L36:
	cmpl	$5, -10056(%rbp)
	jne	.L37
	movq	-10024(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cvtsi2ssl	%eax, %xmm0
	movl	-10060(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	16+list(%rip), %rax
	movss	%xmm0, (%rdx,%rax)
	jmp	.L32
.L37:
	cmpl	$6, -10056(%rbp)
	jne	.L38
	movq	-10024(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cvtsi2ssl	%eax, %xmm0
	movl	-10060(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	20+list(%rip), %rax
	movss	%xmm0, (%rdx,%rax)
	jmp	.L32
.L38:
	cmpl	$7, -10056(%rbp)
	jne	.L39
	movq	-10024(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cvtsi2ssl	%eax, %xmm0
	movl	-10060(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	24+list(%rip), %rax
	movss	%xmm0, (%rdx,%rax)
	jmp	.L32
.L39:
	cmpl	$8, -10056(%rbp)
	jne	.L32
	movq	-10024(%rbp), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	cvtsi2ssl	%eax, %xmm0
	movl	-10060(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	28+list(%rip), %rax
	movss	%xmm0, (%rdx,%rax)
.L32:
	leaq	.LC12(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -10024(%rbp)
.L29:
	cmpq	$0, -10024(%rbp)
	jne	.L40
	addl	$1, -10060(%rbp)
.L28:
	movl	row(%rip), %eax
	cmpl	%eax, -10060(%rbp)
	jl	.L41
	movl	-10052(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	%eax, -10044(%rbp)
	cmpl	$-1, -10044(%rbp)
	jne	.L42
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC15(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L42:
	movl	$0, %ecx
	leaq	childProcess(%rip), %rdx
	movl	$0, %esi
	leaq	tid1(%rip), %rdi
	call	pthread_create@PLT
	movl	%eax, -10040(%rbp)
	cmpl	$0, -10040(%rbp)
	je	.L43
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC16(%rip), %rdi
	call	perror@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L43:
	movl	$0, %eax
	call	parentProcess
	movl	$0, %eax
	call	finalAverages
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L45
	call	__stack_chk_fail@PLT
.L45:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
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
