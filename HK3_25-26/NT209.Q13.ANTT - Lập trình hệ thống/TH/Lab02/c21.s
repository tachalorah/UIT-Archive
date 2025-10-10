.section .bss
	.lcomm len_out, 2

.section .data
str:	.string "NT209UIT"
strlen = . -str

.section .text
	.globl _start

_start:
	movl $47, 	%eax
	addl $strlen, 	%eax
	movb %al, 	len_out
	movb $10, 	len_out + 1

	movl $4, 	%eax
	movl $1, 	%ebx
	movl $len_out, 	%ecx
	movl $2, 	%edx
	int  $0x80

	movl $1, 	%eax
	xorl %ebx, 	%ebx
	int  $0x80
