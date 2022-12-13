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

void copyij(int src[2048][2048],
	    int dst[2048][2048])
{
    int i,j;
    for (i = 0; i < 2048; i++)
	for (j = 0; j < 2048; j++)
	    dst[i][j] = src[i][j];
}

void copyji(int src[2048][2048],
	    int dst[2048][2048])
{
    int i,j;
    for (j = 0; j < 2048; j++)
	for (i = 0; i < 2048; i++)
	    dst[i][j] = src[i][j];
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
    printf("Time taken to compute sum of 1,2,3,...,1000000 = %lu cycles\n", t2 );
    printf("Result = %lu\n", result );

    // timing copyij vs copyji 
    static int src[2048][2048];
    static int dst[2048][2048];

    t1 = access_counter();
    copyij(src,dst);
    t2 = access_counter() - t1 - overhead;
    printf("Time taken for copyij = %lu cycles\n", t2 );

    t1 = access_counter();
    copyji(src,dst);
    t2 = access_counter() - t1 - overhead;
    printf("Time taken for copyji = %lu cycles\n", t2 );
    
    return 0;
}
    
