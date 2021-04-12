section .text
	global _ft_strlen

_ft_strlen :
	mov RAX, 0
_start :
	cmp byte [RDI + RAX], 0
	je	_end
	jne	_value_exist
_value_exist :
	inc	RAX
	jmp _start
_end :
	ret
