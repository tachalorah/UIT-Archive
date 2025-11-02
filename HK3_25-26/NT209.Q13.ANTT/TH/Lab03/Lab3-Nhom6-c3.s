.section .bss
	.lcomm input, 2
	.lcomm count, 2
	.lcomm index, 1

.section .data
prompt: .string "Enter number 1st (1-digit): "
msg_out: .string "Count (>= 5): "

.section .text
	.globl _start

_start:
	movw $0, count
	movb $0, index

loop:
	movl $4, %eax
	movl $1, %ebx
	movl $prompt, %ecx
	movl $29, %edx
	int $0x80

	movl $3, %eax
	movl $0, %ebx
	movl $input, %ecx
	movl $2, %edx
	int $0x80

	cmpb $53, input
	jl skip
	incb count

skip:
	incl index

	cmpb $1, index
	je loop_2
	cmpb $2, index
	je loop_3
	cmpb $3, index
	je loop_4
	cmpb $4, index
	je loop_5
	cmpb $5, index
	jge print

loop_2:
	movb $50, prompt + 13
	movb $110, prompt + 14
	movb $100, prompt + 15
	jmp loop
loop_3:
	movb $51, prompt + 13
	movb $114, prompt + 14
	jmp loop
loop_4:
	movb $52, prompt + 13
	movb $116, prompt + 14
	movb $104, prompt + 15
	jmp loop
loop_5:
	movb $53, prompt + 13
	jmp loop

print:
	addl $48, count
	movb $10, count + 1

	movl $4, %eax
	movl $1, %ebx
	movl $msg_out, %ecx
	movl $15, %edx
	int $0x80

	movl $4, %eax
	movl $1, %ebx
	movl $count, %ecx
	movl $2, %edx
	int $0x80

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
