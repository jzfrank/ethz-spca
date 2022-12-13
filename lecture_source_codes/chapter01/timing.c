#include <stdint.h>
#include <stdio.h>
//
// Note: only compiles on 64-bit x86
//

uint64_t access_counter()
{
    uint32_t lo, hi;
    
    asm volatile("rdtsc; movl %%edx,%0; movl %%eax,%1"
	: "=r" (hi), "=r" (lo)
	:
	: "%edx", "%eax");

    
    return (lo | (((uint64_t)hi) << 32));
}

unsigned long calc()
{
    unsigned long t = 0;
    for(int i=0; i < 1000000; i++) {
	t += i;
    }
    return t;
}    
    

int main(int argc, char *argv[])
{
    uint64_t t1, t2;
    uint64_t overhead;
    unsigned long result;

    //
    // Measure the overhead.
    // We should really repeat this many times, warm up the cache, etc. 
    //
    t1 = access_counter();
    t2 = access_counter();
    overhead = t2-t1;
    printf("Counter overhead is %lu cycles\n", overhead);

    //
    // Time the function
    // It's important that we print the result, due to the optimizer
    //
    t1 = access_counter();
    result = calc();
    t2 = access_counter() - t1 - overhead;
    printf("Time taken = %lu cycles\n", t2 );
    printf("Result = %lu\n", result );
    return 0;
}
    
