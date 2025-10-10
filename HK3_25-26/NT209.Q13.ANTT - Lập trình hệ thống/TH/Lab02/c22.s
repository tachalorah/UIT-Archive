.section .bss
	.lcomm d_in,  9
	.lcomm d_out, 9

.section .data
in_msg:  .string "Date (DDMMYYYY): "
out_msg: .string "Date (YYYYDDMM): "

.section .text
	.globl _start

_start:
	movl $4, 	%eax
	movl $1, 	%ebx
	movl $in_msg, 	%ecx
	movl $18, 	%edx
	int  $0x80

	movl $3, 	%eax
	movl $0, 	%ebx
	movl $d_in, 	%ecx
	movl $9, 	%edx
	int  $0x80

	movl $4, 	%eax
	movl $1, 	%ebx
	movl $out_msg, 	%ecx
	movl $18, 	%edx
	int  $0x80

	movl d_in + 4, 	%eax
	movl %eax, 	d_out
	movl d_in, 	%eax
	movl %eax, 	d_out + 4
	movl $10, 	d_out + 8

	movl $4, 	%eax
	movl $1, 	%ebx
	movl $d_out, 	%ecx
	movl $9, 	%edx
	int  $0x80

	movl $1, 	%eax
	xorl %ebx, 	%ebx
	int $0x80
