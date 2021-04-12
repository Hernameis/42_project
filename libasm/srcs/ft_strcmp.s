	section .text
global _ft_strcmp

ft_strcmp :
	xor rax, rax
	start :
	cmp byte [rsi + rax], 0
	je src_null
	cmp byte [rdi + rax], 0
	je dst_null
	mov [rdi + rax], di
	mov [rsi + rax], si
	cmp di, si
	je equal
	ja above
	jb below

equal :
	jmp start
	inc rax

above :
	mov rax, 1
	ret

below :
	mov rax, -1
	ret

src_null :
	cmp byte [rdi + rax], 0
	jne above
	je	ret_zero
	
dst_null :
	cmp byte [rsi + rax], 0
	jne below
	je	ret_zero

ret_zero :
	xor rax,rax
	ret
