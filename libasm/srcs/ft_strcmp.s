section .text
	global _ft_strcmp

_ft_strcmp :						// 길이가 다른 문자열 두개 비교하면 반대로 나옴
	xor rax, rax
	_start :
	cmp byte [rdi + rax], 0
	je _src_null
	cmp byte [rsi + rax], 0
	je _dst_null
	mov [rdi + rax], di
	mov [rsi + rax], si
	cmp si, di
	je _equal
	ja _above
	jb _below

_equal :
	inc rax
	jmp _start

_above :
	mov rax, 1
	ret

_below :
	mov rax, -1
	ret

_src_null :
	cmp byte [rsi + rax], 0
	jne _above
	je	_ret_zero
	
_dst_null :
	cmp byte [rdi + rax], 0
	jne _below
	je	_ret_zero

_ret_zero :
	xor rax,rax
	ret
