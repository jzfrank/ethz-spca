
void copyij(int src[2048][2048],
	    int dst[2048][2048])
{
    int i,j;
    for (i = 0; i < 2048; i++)
	for (j = 0; j < 2048; j++)
	    dst[i][j] = src[i][j];
}

int main(int argc, char *argv[])
{
    static int src[2048][2048];
    static int dst[2048][2048];
    copyij(src,dst);
    return 0;
}
