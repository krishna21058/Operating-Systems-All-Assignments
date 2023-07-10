section .bss
	var :	resb 4

section.data
	msg : db "Enter your no",10,0
	input : db "%d",0

section .text
	global main	
	extern printf
	extern scanf

main:
	push msg
	call printf

	push var
	push input
	call scanf
	
	push dword[var]
	push input
	call printf
	ret	
