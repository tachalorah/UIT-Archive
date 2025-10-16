.section .bss
	.lcomm str, 4

.section .text
	.globl _start

_start:
	movl $3, %eax
	movl $0, %ebx
	movl $str, %ecx
	movl $4, %edx
	int $0x80

	movb str, %al
	subb $32, %al
	movb %al, str
	movb str + 1, %al
	subb $32, %al
	movb %al, str + 1
	movb str + 2, %al
	subb $32, %al
	movb %al, str + 2

	movl $4, %eax
	movl $1, %ebx
	movl $str, %ecx
	movl $4, %edx
	int $0x80

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
