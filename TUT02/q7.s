main:
	# x - $t0
	li	$t0, 24			# x = 24

loop_cond:
	bge	$t0, 42, loop_post	# if (x >= 42) goto loop_post;

	li	$v0, 1
	move	$a0, $t0
	syscall				# printf("%d", x)

	li	$v0, 11
	li	$a0, '\n'
	syscall				# printf("\n")

	addi	$t0, $t0, 3		# x = x + 3

	j	loop_cond	

loop_post:

	jr 	$ra