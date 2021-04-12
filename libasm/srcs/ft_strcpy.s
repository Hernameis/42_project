section .text
	global _ft_strcpy
	mov rax, 0

_ft_strcpy :
	cmp byte [rsi + rax], 0
	jne _if_value
	je _if_null

_if_value :
	mov dl, byte [rsi + rax]
	mov byte [rdi + rax], dl
	inc rax
	jmp	_ft_strcpy

_if_null :
	mov byte [rdi + rax], 0
	mov rax, rdi
	ret

