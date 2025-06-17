# constants
N_SIZE = 10

main:
	# $t0 - i

add42_init:
	li	$t0, 0		# i = 0

add42_cond:
	bge	$t0, N_SIZE, add42_post

add42_body:
				# get value of numbers[i]
	mul	$t1, $t0, 4	# offset = i * sizeof(int)
	la	$t2, numbers	# base array address 
	add	$t3, $t1, $t2	# &numbers[i]
	lw	$t4, ($t3)	# numbers[i]

	blt 	$t4, 0, add42_if # if (numbers[i] < 0) goto add42_if
	j 	add42_step	 # else

add42_if:
	
	addi	$t4, $t4, 42	# numbers[i] + 42
	sw	$t4, ($t3)	# numbers[i] = numbers[i] + 42;

add42_step:

	addi	$t0, $t0, 1
	j	add42_cond

add42_post:

	jr 	$ra

	.data
# put things in memory 
numbers: .word 	0, 1, 2, -3, 4, -5, 6, -7, 8, 9

