main:

	li 	$v0, 4 		# set $v0 to 4
	la	$a0, prompt_str # $a0 to string
	syscall 		# print(str)

	li	$v0, 5
	syscall			# scanf(int) into $v0

	move	$t0, $v0	# x from $v0 -> $t0

	ble	$t0, 100, small_or_big	# if (x <= 100) goto small_or_big
	bge	$t0, 1000, small_or_big

medium:
	li	$v0, 4
	la	$a0, medium_str
	syscall 		# printf("medium\n")
	j	epilogue 	# goto epilogue

small_or_big:
	li	$v0, 4
	la 	$a0, small_big_str
	syscall

epilogue:




	jr 	$ra

.data
	prompt_str: .asciiz "Enter a number: "
	medium_str: .asciiz "medium\n"
	small_big_str: .asciiz "small/big\n"
