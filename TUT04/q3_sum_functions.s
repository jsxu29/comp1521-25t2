# Sum 4 numbers using function calls.
# Note the use of the stack to save $ra in main, 
# and $ra $a0, $a1, $s0 in sum2.
main:
	begin
	push	$ra


	li	$a0, 11
	li	$a1, 13
	li 	$a2, 17
	li	$a3, 19
	jal	sum4		# sum4(11, 13, 17, 19);

	move	$a0, $v0	# move function return result from $v0
	li	$v0, 1
	syscall			# printf("%d", result)

	li	$v0, 11
	li	$a0, '\n'
	syscall


	pop	$ra
	end

	li      $v0, 0          # return 0 from function main
        jr      $ra             

# We use $s0 for 'e' because its value must survive a function call to sum4. 
# So by convention we must store $s0's original value on the stack, and then
# we can restore it before sum4 returns.
#
# Note sum2 is simple function which changes only $v0.
# We could simplify sum4 by relying on this, 
# but in general we don't do this.
# We assume only registers $s0..$s7 survive function calls
#

# Registers:
# a,b,c,d are in $a0,$a1,$a2,$a3
# res1 is in $s0, res2 is in $s1
# c and d are in $s2,$s3 to be preserved across calls
# Final return is in $v0

sum4:
