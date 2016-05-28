#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SQR(x) ((x)*(x))
#define TOINT(s) strtol(s, NULL, 10)
#define TODBL(s) strtod(s, NULL)
#define ARGTOINT(n) TOINT(argv[n])
#define ARGTODBL(n) TODBL(argv[n])

double length, width, height, x, y, z;

double getR(int n, double length, double width, double height, double x, double y, double z);

int main(int argc, char *argv[])
{
	if(argc <= 6)
	{
		printf("Usage:\n");
		printf("%s X Y Z LENGTH WIDTH HEIGHT\n\n", argv[0]);
		return 1;
	}
	
	length = ARGTODBL(4);
	width  = ARGTODBL(5);
	height = ARGTODBL(6);
	x = ARGTODBL(1);
	y = ARGTODBL(2);
	z = ARGTODBL(3);
	
	printf("R0 = %f\nR1 = %f\nR2 = %f\n", getR(0, length, width, height, x, y, z), getR(1, length, width, height, x, y, z), getR(2, length, width, height, x, y, z));
}

double getR(int n, double length, double width, double height, double x, double y, double z)
{
	switch(n)
	{
		case 0:
			return sqrt(SQR(height-z) + SQR(y) + SQR(x));
		case 1:
			return sqrt(SQR(height-z) + SQR(y) + SQR(length-x));
		case 2:
			return sqrt(SQR(height-z) + SQR(width-y) + SQR(x - length/2));
	}
	return -INFINITY;
}
