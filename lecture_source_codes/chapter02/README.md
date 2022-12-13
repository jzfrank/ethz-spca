this experiment gives intro to C

## printargs.c

```bash
$ ./printargs.out arg1 arg2 arg3
argc = 4

argv[0]: ./printargs.out
argv[1]: arg1
argv[2]: arg2
argv[3]: arg3
```

## string.c

if size of mixed is changed to 12, it will not have enough space for strcat two names.

## unpredictable behaviour of integer overflow

in factorial.c, we used int to store the result. The overflow behaviour is interesting but not predictable.

```bash
Enter a number: 38
Factorial of 0 is 1.
Factorial of 1 is 1.
Factorial of 2 is 2.
Factorial of 3 is 6.
Factorial of 4 is 24.
Factorial of 5 is 120.
Factorial of 6 is 720.
Factorial of 7 is 5040.
Factorial of 8 is 40320.
Factorial of 9 is 362880.
Factorial of 10 is 3628800.
Factorial of 11 is 39916800.
Factorial of 12 is 479001600.
Factorial of 13 is 1932053504.
Factorial of 14 is 1278945280.
Factorial of 15 is 2004310016.
Factorial of 16 is 2004189184.
Factorial of 17 is -288522240.
Factorial of 18 is -898433024.
Factorial of 19 is 109641728.
Factorial of 20 is -2102132736.
Factorial of 21 is -1195114496.
Factorial of 22 is -522715136.
Factorial of 23 is 862453760.
Factorial of 24 is -775946240.
Factorial of 25 is 2076180480.
Factorial of 26 is -1853882368.
Factorial of 27 is 1484783616.
Factorial of 28 is -1375731712.
Factorial of 29 is -1241513984.
Factorial of 30 is 1409286144.
Factorial of 31 is 738197504.
Factorial of 32 is -2147483648.
Factorial of 33 is -2147483648.
Factorial of 34 is 0.
Factorial of 35 is 0.
Factorial of 36 is 0.
Factorial of 37 is 0.
```
