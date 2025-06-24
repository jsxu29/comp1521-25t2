INT_SZ = 4

max:
    # Frame:    [$ra, $s0] - registers push/pop to stack frame 
    # Uses:     [$ra, $s0, $t0, $a0, $a1, ...] - all registers you use
    # Clobbers: [$t0, $a0, $a1, ...] - registers that are not saved, and can be overwritten
    #
    # Locals:           
    #   - $s0: first_element
    #   - $t0: max_so_far
    #   - $a0: array
    #   - $a1: length
    #
    # Structure: 
    #   max
    #   -> [prologue]
    #       -> body
    #		-> base_case
    # 		-> recursive_case
    #		    -> first_is_max
    #		    -> first_is_not_max
    #   -> [epilogue]
max__prologue:
	begin
	push	$ra
	push	$s0

max__body:
	lw	$s0, ($a0)			# int first_element = array[0];

	bne	$a1, 1, max__recursive_case	# if (length != 1) goto recursive_case

max__base_case: 				# <function name>__<state>

	move	$v0, $s0			# return first_element;
	j	max__epilogue

	# b vs j - for our course, no difference, both jump instructions
	# b is relative
	# j is absolute 

max__recursive_case:
	add	$a0, $a0, INT_SZ		# &array[1]
	addi	$a1, $a1, -1			# length - 1
	jal	max				# max(...)
	move	$t0, $v0			# $t0 - max_so_far

	ble	$s0, $t0, max__first_is_not_max	# if (first_element <= max_so_far) goto max__first_is_not_max

max__first_is_max:
	move	$v0, $s0			# max_so_far = first_element
	b	max__epilogue

max__first_is_not_max:
						# max_so_far is in $v0 already
max__epilogue:
	pop	$s0
	pop	$ra
	end

	jr	$ra


# some simple test code which calls max
main:
main__prologue:
	push	$ra

main__body:
	la	$a0, array
	li	$a1, 10
	jal	max			# result = max(array, 10)

	move	$a0, $v0
	li	$v0, 1			# syscall 1: print_int
	syscall				# printf("%d", result)

	li	$a0, '\n'
	li	$v0, 11			# syscall 11: print_char
	syscall				# printf("%c", '\n');

	li	$v0, 0

main__epilogue:
	pop	$ra
	jr	$ra			# return 0;


.data
array:
	.word 1, 2, 3, 4, 5, 6, 4, 3, 2, 1
	