
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
    static int src[2048][2048];
    static int dst[2048][2048];
    copyji(src,dst);
    return 0;
}
