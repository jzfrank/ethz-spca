This experiments:

- gives an idea of how many cycles needed to sum over a million number;
- compares the speed of copying by copyij (iterate over row then column) and by copyji (iterate over column then row).

```bash
gcc -Wall timing.c -o timing.out

./timing.out
```

Result is like this:

```
Counter overhead is 34 cycles
Time taken to compute sum of 1,2,3,...,1000000 = 5168720 cycles
Result = 499999500000
Time taken for copyij = 66687728 cycles
Time taken for copyji = 297513880 cycles
```
