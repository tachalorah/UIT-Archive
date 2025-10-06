#include <stdio.h>

/* 1.x */
int 		bitAnd(int, int);
int 		bitOr(int, int);
int 		negative(int);
int 		getBit(int, int);
int 		getHexcha(int, int);
int 		getByte(int, int);
int 		getnbit(int, int);
int 		flipByte(int, int);
int 		mod2n(int, int);
unsigned int 	divpw2(int, int);
int 		isOpposite(int, int);

/* 2.x */
int 		isSameSign(int, int);
int 		isEven(int);
int 		is16x(int);
int 		is8x(int);
int 		isPositive(int);
int 		isLess2n(int, int);
int 		isGE2n(int, int);

int
main(void)
{
	if (bitAnd(3, -9) == (3 & -9))
		puts("bitAnd: xong");
	if (bitOr(3, -9) == (3 | -9))
		puts("bitOr: xong");
	if (negative(0) == 0 && negative(9) == -9
			&& negative(-5) == 5)
		puts("negative: xong");
	if (getBit(8,3) == 1 && getBit(5,0) == 1 && getBit(32,3) == 0)
		puts("getBit: xong");
	if (getHexcha(26, 0) == 0xa && getHexcha(0x11223344, 1) == 0x4)
		puts("getHexcha: xong");
	if (getByte(8, 0) == 8 && getByte(0x11223344, 1) == 0x33)
		puts("getByte: xong");
	if (getnbit(15,3)==7 && getnbit(63,6)==63 && getnbit(30,2)==2)
		puts("getnbit: xong");
	if (getnbit(64, 32) == 64 && getnbit(-65000, 40) == -65000)
		puts("getnbit nc: xong");
	if (flipByte(10, 0) == 245 && flipByte(0, 1) == 65280
			&& flipByte(0x5501, 1) == 0xaa01)
		puts("flipByte: xong");
	if (mod2n(2, 1) == 0 && mod2n(30, 2) == 2 && mod2n(63, 6) == 63)
		puts("mod2n: xong");
	if (divpw2(10, -1) == 20 && divpw2(15, -2) == 60 && divpw2(2, -4) == 32)
		puts("divpw2: xong");
	if (divpw2(20, 1) == 10 && divpw2(60, 2) == 15 && divpw2(32, 4) == 2)
		puts("divpw2_nc: xong");
	if (isSameSign(4, 10) && !isSameSign(-5, 2) && isSameSign(-5, -9))
		puts("isSameSign: xong");
	if (isEven(4) && !isEven(13) && isEven(50))
		puts("isEven: xong");
	if (is16x(16) && !is16x(31) && is16x(0))
		puts("is16x: xong");
	if (is8x(8) && !is8x(15) && is8x(0))
		puts("is8x: xong");
	if (isPositive(10) && !isPositive(-5) && !isPositive(0))
		puts("isPositive: xong");
	if (isLess2n(12,4) && !isLess2n(8,3) && !isLess2n(15,2))
		puts("isLess2n: xong");
	if (!isGE2n(12,4) && isGE2n(8,3) && isGE2n(15,2))
		puts("isGE2n: xong");
	if (!isOpposite(2, -2)&& !isOpposite(5, -1) && !isOpposite(0, 16) &&
			isOpposite(-4, 4))
		puts("isOpposite: xong");
	return (0);
}

int
bitAnd(int x, int y)
{
	return ~(~x | ~y);
}

int
bitOr(int x, int y)
{
	return ~(~x & ~y);
}

int
negative(int x)
{
	return (~x + 1);
}

int
getBit(int x, int n)
{
	return (x >> n) & 0x1;
}

int
getHexcha(int x, int n)
{
	return (x >> (n << 2)) & 0xF;
}

int
getByte(int x, int n)
{
	return (x >> (n << 3)) & 0xFF;
}

int
getnbit(int x, int n) {
	int mask = (1ULL << n) + (~1 + 1);
	return x & mask;
}


int
flipByte(int x, int n)
{
	return x ^ (0xFF << (n << 3));
}

int
mod2n(int x, int n)
{
	return x & ((1 << n) + (~1 + 1));
}

unsigned int
divpw2(int x, int n)
{
	int is_neg = n >> 31;
	int l_push = (~n + 1) & is_neg;
	int r_push = n & ~is_neg;
	return (x << l_push) >> r_push;
}

int
isSameSign(int x, int y)
{
	return !((x >> 31) ^ (y >> 31));
}

int
isEven(int x)
{
	return !(x & 1);
}

int
is16x(int x)
{
	return !(x & 0xF);
}

int
is8x(int x)
{
	return !(x & 0x7);
}

int
isPositive(int x)
{
	return !(x >> 31) ^ !x;
}

int
isLess2n(int x, int n)
{
	return !(x >> n);
}

int
isGE2n(int x, int n)
{
	return !!(x >> n);
}

int
isOpposite(int x, int y)
{
	return !(x + y);
}
