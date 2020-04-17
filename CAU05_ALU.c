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

	}

	else { //subtract

	}
	return ret;
}

int logicOperation(int X, int Y, int C) {
	if (C < 0 || C > 3) {
	}
	else if (C == 0)
		return;
	else if (C == 2)
		return;
	else;

}

int ShiftOperation(int V, int Y, int C) {
	int ret;
	if (C < 0 || C>3) {
		printf("error in add//subtract operation \n");
		exit(1);
	}
	if (C == 0) {
		ret;

	}
	else if (C == 1) {

	}
	else if (C == 2) {

	}

	else {

	}
	return ret;
}

int checkZero(int S) {
	int ret;
	// check if S is zero,
	//  and return 1 if it is zero
	//  else return 0
	return ret;
}

int checkSetLess(int X, int Y) {
	int ret;

	// check if X < Y,
	//  and return 1 if it is true
	//  else return 0

	return ret;
}

int ALU(int X, int Y, int C, int* Z) {
	int c32, c10;
	int ret;

	c32 = (C >> 2) & 3;
	c10 = C & 3;    if (c32 == 0) { // shift        
		ret = shiftOperation(X, Y, c10);
	}
	else if (c32 == 1) {  // set less         
		//ret = ????;    
	}
	else if (c32 == 2) {  // addsubtract

		// * Z = ???;        ret = ????;
	}
	else {  // logic
		ret = logicOperation(X, Y, c10);
	}  return ret;
}


int main()
{
	int x, y, c, s, z;

	//x = input 32bit hexa;
	//y = input 32bit hexa;

	printf("x: % 8x, y : % 8x\n", x, y);

	for (int i = 0; i < 16; i++) {
		s = ALU(x, y, i, &z);
		printf("s: % 8x, z : % 8x\n");
	}

	return 0;
}