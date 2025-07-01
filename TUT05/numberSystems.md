## Number Systems

- Decimal (base 10)
- Hexadecimal (base 16) - represented as 0x... (0x11A)
- Octal (base 8) - represented as 0o... or 0... (01, 0o1, 0)
- Binary (base 2) - represented as 0b... (0b110)
    - There are (currently) no binary integer constants in C.

For decimal, to get the value we multiply every digit with 10^<position>.

I.e. 123
= 3 * 10^0 + 2 * 10^1 + 1 * 10^2

I.e. 0b 110
= 0 * 2^0 + 1 * 2^1 + 1 *2^2 = 2 + 4 = 6

To get the value generally it is: sum of digit * base ^ position.

### Hexadecimal
```
0123456789 A  B  CDE F 
           10 11 ... 15
```
