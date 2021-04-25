section .text						;	int		ft_strcmp(char *dst, char *src)
	global _ft_strcmp

_ft_strcmp :
	xor rax, rax					;	rax = rax;
	_start :
	cmp byte [rdi + rax], 0			;	compare(rdi[rax], 0);
	je _rdi_null					;	if (rdi[rax], == 0)			_rdi_null;
	cmp byte [rsi + rax], 0			;	compare(rsi[rax], 0);
	je _rsi_null					;	if (rsi[rax], == 0)			_rsi_null;
	mov dl, byte [rdi + rax]		;	dl = (char)rdi[rax];
	mov cl, byte [rsi + rax]		;	cl = (char)rsi[rax];
	cmp dl, cl						;	compare(dl, cl);
	je _equal						;	if (dl  == cl)
	ja _below						;	if (dl > cl)
	jb _above						;	if (dl < cl)

_equal :
	inc rax							;	rax++;
	jmp _start

_above :
	mov rax, -1						;	rax = -1;
	ret								;	return (rax);

_below :
	mov rax, 1						;	rax = 1;
	ret								;	return (rax);

_rdi_null :
	cmp byte [rsi + rax], 0			;	compare(rsi[rax], 0);
	jne _above						;	if (rsi[rax] != 0)
	je	_ret_zero					;	if (rsi[rax] == 0)
	
_rsi_null :
	cmp byte [rdi + rax], 0			;	compare((char)(rdi[rax]), 0);
	jne _below						;	if ((char)(rdi[rax]) != 0)
	je	_ret_zero					;	if ((char)(rdi[rax]) == 0)

_ret_zero :
	mov rax, 0						;	rax = 0;
	ret								;	return (rax);
