.section .bss
	.lcomm s_in, 6
	.lcomm s_out, 6

.section .data
in_msg: .string "Enter a string: "

.section .text
	.globl _start

_start:
	movl $4, 	%eax
	movl $1, 	%ebx
	movl $in_msg, 	%ecx
	movl $17, 	%edx
	int  $0x80

	movl $3, 	%eax
	movl $0, 	%ebx
	movl $s_in, 	%ecx
	movl $6, 	%edx
	int  $0x80

	movb $10, 	s_out + 5
	movb s_in, 	%al
	movb %al, 	s_out + 4
	movb s_in + 1, 	%al
	movb %al, 	s_out + 3
	movb s_in + 2, 	%al
	movb %al, 	s_out + 2
	movb s_in + 3, 	%al
	movb %al, 	s_out + 1
	movb s_in + 4, 	%al
	movb %al, 	s_out

	movl $4, 	%eax
	movl $1, 	%ebx
	movl $s_out, 	%ecx
	movl $6, 	%edx
	int  $0x80

	movl $1, 	%eax
	xorl %ebx, 	%ebx
	int  $0x80
