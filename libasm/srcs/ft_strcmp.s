section .text
	global _ft_strcmp

_ft_strcmp :
	xor rax, rax
	_start :
	cmp byte [rdi + rax], 0
	je _rdi_null
	cmp byte [rsi + rax], 0
	je _rsi_null
	mov dl, byte [rdi + rax]
	mov cl, byte [rsi + rax]
	cmp dl, cl
	je _equal
	ja _below
	jb _above

_equal :
	inc rax
	jmp _start

_above :
	mov rax, -1
	ret

_below :
	mov rax, 1
	ret

_rdi_null :
	cmp byte [rsi + rax], 0
	jne _above
	je	_ret_zero
	
_rsi_null :
	cmp byte [rdi + rax], 0
	jne _below
	je	_ret_zero

_ret_zero :
	mov rax, 0
	ret
