/*
 * setbits.c
 * 
 * Copyright 2019 graf <g@raspberrypi>
 * 
 */


#include <stdio.h>

unsigned getbits(unsigned x, int n, int p);
unsigned getbits2(unsigned x, int n, int p); 
unsigned setbits(unsigned x, int n, int p, unsigned y);
unsigned invert(unsigned x, int n, int p);
unsigned rightrot(unsigned x, int n);
unsigned setmask(unsigned x, int n);

int main(int argc, char **argv)
{
	unsigned field = 0b1101;	
	int c = 0;
	while (field != 0) {
		field >>= 1;
		c++;
	}
	
	printf("c = %d\n", c);
	
	return 0;
}

unsigned rightrot(unsigned x, int n) 
{
	/* get the most right bit */
	unsigned r, temp;
	r = getbits(x, 1, 0);
	
	/* shift the array to the right */
	temp = x;
	temp >>= 1;
	
	/* put the right most bit back at the end */
	
	
	return x;
}

/* setbits: returns x with the n bits that begins at position
 * p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int n, int p, unsigned y) 
{
	unsigned right,left, set, temp;
	/* get the right-most bits */
	right = getbits(x, (p - n + 1), (p - n));
	printf("the right most bits = %u\n", right);
	/* get the set bits from y */
	set = getbits(y, n, (n - 1));
	printf("set bits = %u\n", set);
	set <<= (p - (n - 1));
	/* get the left most bits */
	left = x;
	left >>= p + 1;
	left <<= p + 1;
	printf("the left most bits = %u\n", left);
	
	/* | the stuff together */
	temp = 0;
	temp |= left;
	temp |= right;
	temp |= set;
	printf("temp = %u\n", temp);
	
	return temp;
} 

unsigned setmask(unsigned x, int n) 
{
	x = ~0;  /* raise all bits */
	x <<= n; /* shift over n bits */
	x = ~x;	 /* n right bits are masked */
	return x;
}

unsigned invert(unsigned x, int n, int p) 
{
	unsigned right,left, set, temp;
	/* get the right-most bits */
	right = getbits(x, (p - n + 1), (p - n));
	printf("the right most bits = %u\n", right);
	
	
	/* get the set bits from y */
	temp = x;
	temp = ~temp;
	set = getbits(temp, n, p);
	printf("set bits = %u\n", set);
	
	set <<= (p - (n - 1));
	
	
	/* get the left most bits */
	left = x;
	left >>= p + 1;
	left <<= p + 1;
	printf("the left most bits = %u\n", left);
	
	/* | the stuff together */
	temp = 0;
	temp |= left;
	temp |= right;
	temp |= set;
	printf("temp = %u\n", temp);
	
	return temp;
	
	
}

unsigned getbits2(unsigned x, int n, int p) 
{
	unsigned temp = 0;
	temp = ~(~0 << n);  /* create mask of rightmost n bits */
	x >>= (p + 1 - n); 	/* move desired field to right end of word */
	x &= temp; 			/* and the mask with the desired the desired bits*/		
	return x;
}


/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int n, int p) 
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}
