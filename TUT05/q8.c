typedef unsigned int Word;

#include <assert.h>
#include <stdio.h>

// smaller example: 0101 -> 1010
// for each bit, get its value (whether its 0 or 1), and move it to the correct position

/* 
mask = 0 when we don't want to keep the value, 
and 1 where we want to keep the value

get the value for each bit

0101
1000 &
----
0000 == 0 

0101
0100 &
----
0100 != 0 -> 1

0101
0010 &
----
0000 == 0 -> 0

0101
0001 &
----
0001 != 0 -> 1
*/

/*
move it to the correct position

index: 0 1 2 3
       0 1 0 1

reversed word should have the order: 3 2 1 0

so, if you know there is a 1 at index 3, 
then there should be a 1 at index 0

0101 -> 1010
index in word vs index in reversed word:
<index in word> (<bit value>) -> <index in reversed word>
0 (0) -> 3
1 (1) -> 2
2 (0) -> 1
3 (1) -> 0

the pattern:
i -> (4 - 1) - i
i -> 3 - i

general pattern: i -> (n - 1) - i (where n is the number of bits)

to "add" the bit to the correct position, we can OR it with our result
OR with a number with 1s where you want that to be a 1, and 0 if you don't want to change the original value

i.e. 
res 0000
    1000 |
    ----
    1000

res 1000
    0000 |
    ----
    0000

res 1000
    0010 |
    ----
    1010

res 1010
    0000 |
    ----
    1010
*/

/* 
common strategy in questions

1. AND with a bit mask

mask is - 0 where we don't want the value, and 1 where we want to know what the bit value is, i.e. 0b1000

2. OR with our result to get all the bits in the right places

*/

Word reverseBits(Word w) {
    //    31 30                             ...4 3210
    // 0b 0  0  00 0001 0010 0011 0100 0101 0110 0111
    // 0b 111 ....                              0

    // bit at position 0 -> position 31
    // bit at position 1 -> position 30
    // bit at posiiton i -> position 31 - i
    // bit at position 31 -> position 0

    Word res = 0;
    // for each bit
    for (int i = 0; i < 32; i++) {
    //  1. extract bit at position i 
    //      mask = 1 at position i, and 0 everywhere else
    //      mask = 0b1 << i (i.e. i = 2, 0b 0000 0001 << 2 = 0b 0000 0100)
        Word mask = 0b1 << i;
    //      word & mask, if 0, then 0, if not 0, then there is a 1 at where we want
        if ((w & mask) != 0) {
    //  2. put it at position 31 - i
    //     res | (number with 0 or 1 at position 31 - i, and 0 everywhere else)
    //     res | ((0b1 or 0b0) << (31 - i))
    //     res = res | (0b1 << (31 - i));
            res |= (0b1 << (31 - i));
    //     a *= 2 -> a = a * 2;
    //     if bit is 0, we don't need to OR it as nothing will happen
        }
    }

    return res;
}

// testing
int main(void) {
    Word w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    printf("All tests passed!");
    return 0;
}
