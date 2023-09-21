;a NASM assembly calculator program
section .data
prompt1 db "Enter a number: ", 0
prompt2 db "Enter another number: ", 0
prompt3 db "Enter an operator: ", 0
resultPrompt db "Result: ", 0
newline db 10, 0

section .bss
num1 resb 5
num2 resb 5
operator resb 1
result resb 5

section .text
global _start

_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, prompt1
	mov edx, 16
	int 80h

	mov eax, 3
	mov ebx, 0
	mov ecx, num1
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, 1
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, prompt2
	mov edx, 22
	int 80h

	mov eax, 3
	mov ebx, 0
	mov ecx, num2
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, 1
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, prompt3
	mov edx, 19
	int 80h

	mov eax, 3
	mov ebx, 0
	mov ecx, operator
	mov edx, 1
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, 1
	int 80h

	mov eax, [num1]
	sub eax, 48
	mov ebx, [num2]
	sub ebx, 48
	mov ecx, [operator]
	cmp ecx, 43
	je add
	cmp ecx, 45
	je sub
	cmp ecx, 42
	je mul
	cmp ecx, 47
	je div
	jmp exit

add:
	add eax, ebx
	jmp print

sub:
	sub eax, ebx
	jmp print

mul:
	mul ebx
	jmp print

div:
	div ebx
	jmp print

print:
	add eax, 48
	mov [result], eax
	mov eax, 4
	mov ebx, 1
	mov ecx, result
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, 1
	int 80h

exit:
	mov eax, 1
	mov ebx, 0
	int 80h

