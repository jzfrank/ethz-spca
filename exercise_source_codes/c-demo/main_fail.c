#include <stdio.h>

int i = 79;

int main(int argc, char *argv[])
{
	print_name();
	return 0;
}

void print_name(void)
{
	const char s[] = "Mothy";
	printf("My name is %s and I work in CAB F %d\n", s, i);
	return;
}

