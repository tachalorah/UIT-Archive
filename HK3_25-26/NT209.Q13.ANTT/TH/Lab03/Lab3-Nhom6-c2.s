.section .bss
	.lcomm input, 256
	.lcomm output, 256

.section .data
prompt: .string "Enter a string (<= 255 chars): "

.section .text
	.globl _start

_start:
	movl $4, %eax
	movl $1, %ebx
	movl $prompt, %ecx
	movl $32, %edx
	int $0x80

	movl $3, %eax
	movl $0, %ebx
	movl $input, %ecx
	movl $256, %edx
	int $0x80

	xorl %ebx, %ebx
	xorl %ecx, %ecx
	xorl %edi, %edi
	xorl %esi, %esi

	movl $1, %ecx

loop:
	cmp %eax, %edi
	jg print

	movb input(%edi), %bl

	cmpb $10, %bl
	je write

check_space:
	cmpb $32, %bl
	jne check_uppercase

	cmpl $1, %ecx
	je write_skip
	movl $1, %ecx
	jmp write

check_uppercase:
	cmpb $65, %bl
	jl check_lowercase
	cmpb $90, %bl
	jg check_lowercase

	cmpl $1, %ecx
	je write
	addb $32, %bl
	jmp write

check_lowercase:
	cmpb $97, %bl
	jl write
	cmpb $122, %bl
	jg write

	cmpl $0, %ecx
	je write
	subb $32, %bl

write:
	movb %bl, output(%esi)

	cmpb $32, %bl
	je write_2
	movl $0, %ecx

write_2:
	incl %edi
	incl %esi

	cmpb $10, %bl
	je print
	jmp loop

write_skip:
	incl %edi
	jmp loop

print:
	movl $4, %eax
	movl $1, %ebx
	movl $output, %ecx
	movl %esi, %edx
	int $0x80

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
