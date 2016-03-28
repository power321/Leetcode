#include <cstdio>

int main()
{
	unsigned char BitsSetTable[256] = {0};

	for(int i=0; i<256; ++i)
	{
		BitsSetTable[i] = (i&1) + BitsSetTable[i/2];
	}

	unsigned int n;
	scanf("%u", &n);

	unsigned int c = 0;

	unsigned char* p = (unsigned char*)&n;

	c = BitsSetTable[p[0]] + BitsSetTable[p[1]] + BitsSetTable[p[2]] + BitsSetTable[p[3]];
	printf("Bit count=%u\n", c);
	
	return 0;
}
