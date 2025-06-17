# Assume that the variable s is implemented as register $t0
# and variable length is implemented as register $t1.
# the character '\0' can be represented by a value of zero.

length_counter_init:
	# s - $t0, legnth - $t1
	la	$t0, string
	li 	$t1, 0

length_counter_cond:
	lb	$t2, ($t0) 			# *s
	beq	$t2, 0, length_counter_post	# if *s == '\0' goto post

length_counter_body:
	addi	$t1, $t1, 1

length_counter_step:
	addi	$t0, $t0, 1
	j	length_counter_cond

length_counter_post:


   	.data
string:
   	.asciiz "...."
