#include <stdio.h>
#include<stdlib.h>


int addSubtract(int X, int Y, int C)
{
	int ret;
	if (C < 0 || C>1) {
		printf("error in add//subtract operation \n");
		exit(1);

	}
	if (C == 0) {//add
		ret = X + Y;
	}

	else { //subtract
		ret = X - Y;	
	}
	return ret;
}

int logicOperation(int X, int Y, int C) {
	if (C < 0 || C > 3) {
	}
	else if (C == 0)
		return X & Y;
	else if (C == 1)
		return X | Y;
	else if (C == 2)
		return X ^ Y;
	else
		return ~(X|Y);

}

int ShiftOperation(int V, int Y, int C) {
	int ret;
	int x;
	x= V & 31; 
	//5비트
  
	if (C < 0 || C>3) {
		printf("error in add//subtract operation \n");
		exit(1);
	}
	if (C == 0) {
		ret = Y;

	}
	else if (C == 1) {
		ret = Y << x;

	}
	else if (C == 2) {
	int val = Y >> x ; 
	const size_t int_bits = sizeof(int) * 8;
	unsigned int mask = (1u << x)-1; 
	mask = mask << (int_bits-x);     
	mask = ~mask;      
              
	val = val & mask;

	ret=val;
	}

	else {
		ret = Y >> x; //원래 sra 처리됨

	}
	return ret;
}

int checkZero(int S) {
	int ret;

	if (S == 0) {
		ret = 1;
	}
	else {
		ret = 0;
	}
	
	return ret;
}

int checkSetLess(int X, int Y) {
	int ret;


	if (addSubtract(X, Y, 1) < 0) {
		ret = 1;
	}
	else {
		ret = 0;
	}

	return ret;
}

int ALU(int X, int Y, int C, int* Z) {
	int c32, c10;
	int ret;

	c32 = (C >> 2) & 3;  //--> 4비트 11 2비트랑 and 할려고
	c10 = C & 3;    
	if (c32 == 0) { // shift        
		ret = shiftOperation(X, Y, c10);
	}
	else if (c32 == 1) {  // set less      
		checkSetLess(X, Y);
	}
	else if (c32 == 2) {  // addsubtract
		
		ret = addSubtract(X, Y, c10);
		*Z=checkZero(ret);
		
	}
	else {  // logic
		ret = logicOperation(X, Y, c10);
	}  
return ret;
}


void test(void) {
	int x, y, i, s,z;

	//x = input 32bit hexa;
	//y = input 32bit hexa;

	printf("x: %8x, y : %8x\n", x, y);

	for (i = 0; i < 16; i++) {
		s = ALU(x, y, i, &z);
		printf("s: %8x, z : %8x\n",s,z);
	}
}

int main()
{
	test();


	return 0;
}