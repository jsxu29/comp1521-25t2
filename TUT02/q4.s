# code
main:

# x - $t0
# y - $t1

	li 	$v0, 4 		# set $v0 to 4
	la	$a0, prompt_str # $a0 to string
	syscall 		# print(str)

	li	$v0, 5
	syscall			# scanf(int) into $v0

	move	$t0, $v0	# x from $v0 -> $t0

	mul	$t1, $t0, $t0 	# y = x * x

	li	$v0, 1
	move	$a0, $t1
	syscall			# printf("%d", y)

	li	$v0, 11
	li	$a0, '\n'
	syscall			# printf("\n")

	jr 	$ra

.data

# global variables
# string literals
prompt_str:
.asciiz  "Enter a number: "
