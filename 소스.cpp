#include <iostream>
//배열 크기얻는법 https://codechacha.com/ko/cpp-array-size/

float affine(int x_arr[], float w_arr[], float b) {
	int xlen = sizeof(x_arr) / sizeof(*x_arr);
	int wlen = sizeof(w_arr) / sizeof(*w_arr);
	float retv = 0;
	if (xlen == wlen) {
		for (int i = 0; i < xlen + 1; i++) {
			retv += x_arr[i] * w_arr[i];
		}
		retv += b;
	}
	return retv;
}

int AND_gate(int x1, int x2) {
	int arrx[2] = { x1, x2 };
	float arrw[2] = { 0.5,0.5 };
	float b = -0.7;
	float hypothesis = affine(arrx, arrw, b);
	if (hypothesis <= 0) return 0;
	else return 1;
}

int OR_gate(int x1, int x2) {
	int arrx[2] = { x1, x2 };
	float arrw[2] = { 0.5,0.5 };
	float b = -0.2;
	float hypothesis = affine(arrx, arrw, b);
	if (hypothesis <= 0) return 0;
	else return 1;
}

int NAND_gate(int x1, int x2) {
	int arrx[2] = { x1, x2 };
	float arrw[2] = { -0.5,-0.5 };
	float b = 0.7;
	float hypothesis = affine(arrx, arrw, b);
	if (hypothesis <= 0) return 0;
	else return 1;
}

int XOR_gate(int x1, int x2) {
	int nand = NAND_gate(x1, x2);
	int OR = OR_gate(x1, x2);
	int y = AND_gate(nand, OR);
	return y;
}

int main() {
	int arrX[4][2] = { {0,0},{0,1},{1,0},{1,1} };
	for (int i = 0; i < 4; i++) {
		std::cout << arrX[i][0] << " xor " << arrX[i][1] << " = " << XOR_gate(arrX[i][0], arrX[i][1]) << std::endl;
	}
}