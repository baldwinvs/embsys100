# Assignment 1.b

### Description

**Why use 2's complement to represent negative numbers?**

2's complement is used to represent negative numbers because additions and subtractions can be done with a single operation.

###### Examples:
```
  9 + 3 = 12

  0000 1001
+ 0000 0011
= 0000 1100

  (-9) + 3 = -6

  1111 0111
+ 0000 0011
= 1111 1010

  9 + (-3) = 6

   0000 1001
+  1111 1101
= 10000 0110 -> 0000 0110 because the most significant bit is an overflow bit and it is dropped

  (-9) + (-3) = -12

  1111 0111
+ 1111 1101
= 1111 0100
```
