/* File : futoshiki.cpp */
/* Author : Michael Alexander Wangsa 13512046 */

using namespace std;
#include <iostream>
#include <fstream>
#include <ctime>

class Board {
	public:
	int mat[10][10];
};

bool CheckBlank (Board B);
bool CheckRowColumn (Board B, int i,int j);
bool CheckRule (Board B);
bool Solve(Board *B, int *usaha);
void SearchKotak(Board B, int *x, int *y);
void PrintBoard(Board B);

int main () {
	/* Kamus Lokal */
	Board B;
	int j, in,usaha;
	bool solve;
	/* Input process */
	j = 1;
	ifstream input;
	input.open("input.txt");
	if (input.is_open()) {
		while (!input.eof()) {
			for (int i = 1;i<=9;i++) {
				input >> in;
				B.mat[i][j] = in;
			}
			j++;
		} 
	}
	input.close();
	/* End Input */
	/* Cetak hasil input */
	cout << "Masukan : " << endl;
	cout << "------------------------------" << endl;
	PrintBoard(B);
	cout << "------------------------------" << endl;	
	/* Solver */	
	clock_t t0 = clock();
	usaha = 0;

	solve = Solve(&B, &usaha);
	
	clock_t t1 = clock();
	clock_t msecs = t1-t0;	
	/* End Solver */
	
	if (!solve) cout << endl << "Tidak ditemukan solusi yang valid untuk masukan diatas" << endl;
	else {
		cout << "Solusi : " << endl;
		cout << "------------------------------" << endl;
		PrintBoard(B);
	}
	cout << endl << "Jumlah usaha pengisian= " << usaha << " kali" << endl;	
	cout << "Waktu eksekusi= " << msecs << " ms" << endl;
	/* End Print */
	getchar();
return 0;
}

void PrintBoard(Board B) {
	/* Print process */
	for (int j = 1; j < 10; j++) {
		for (int i = 1; i < 10; i++) {
			int a = B.mat[i][j];
			if (i % 2 == 0) {
				if (a == -1) cout << ">" << "\t";
				else if (a == -2) cout << "<" << "\t";
				else if (a == -3) cout << " " << "\t";
				else if (a == 0) cout << "[]" << "\t";			
				else cout << a << "\t";
			} else {
				if (a == -1) cout << "v" << "\t";
				else if (a == -2) cout << "^" << "\t";
				else if (a == -3) cout << " " << "\t";
				else if (a == 0) cout << "[]" << "\t";			
				else cout << a << "\t";
			}
		}
		cout << endl;
	}
}

bool Solve(Board *B, int *usaha) {
	/* Basis */
	if(CheckBlank(*B)) return true;
	/* Rekurens */
	int x;
	int y;
	SearchKotak(*B, &x, &y);
	/* Bruteforce mengisi suatu kotak sampai sesuai dengan aturan */
	for (int i = 1; i <= 5; i++) {
		B->mat[x][y] = i;
		(*usaha)++;
		if (CheckRowColumn(*B,x,y) && Solve(B, usaha) && CheckRule(*B)) return true;
	}
	B->mat[x][y] = 0;
	(*usaha)++;
	/* Tidak ditemukan pengisian yang bisa sesuai dengan aturan, kembali ke kotak sebelumnya */
	return false;
}

void SearchKotak(Board B, int *x, int *y) {	
	int i,j;
	bool stop;
	stop = false;i = 1; j = 1;
	while (j < 10 && !stop) {
		while (i < 10 &&!stop) {
			if(B.mat[i][j] == 0) {
				stop = true;
				*x = i;
				*y = j;
			} else { 
			i+=2; 
			}
		}
		i = 1;
		j+=2;
	}
}

bool CheckBlank (Board B) {
	int i,j;
	bool stop,ok;
	stop = false;
	i = 1;
	j = 1;
	ok = true;
	while (j < 10 && !stop) {
		while (i < 10 &&!stop) {
			if(B.mat[i][j] == 0) {
				stop = true;
				ok = false;
			} else { 
			i+=2; 
			}
		}
		i = 1;
		j+=2;
	}
	return ok;
}

bool CheckRowColumn (Board B, int i, int j) {
	bool res = true;
	bool stop = false;
	while (res && !stop) {
		for (int a = 1; a <=9; a +=2) {
			if (a != i) {
				if (B.mat[i][j] == B.mat[a][j]) {
					res = false;
				}
			}
		}
		for (int a = 1; a<=9; a +=2) {
			if (a!=j) {
				if(B.mat[i][j] == B.mat[i][a]) {
					res = false;
				}
			}
		}
		stop = true;
	}
	return res;
}

bool CheckRule (Board B) {
	int i,j;
	bool stop, ok;
	i = 1;
	j = 1;
	ok = true;
	stop = false;
	while (j < 10 && !stop) {
		while (i < 10 &&!stop) {
			if (j % 2 == 1) {
			i++;
				if(B.mat[i][j] == -1) {
					if(B.mat[i-1][j] < B.mat[i+1][j]) {
					stop = true;
					ok = false;
					} 
				} else if (B.mat[i][j] == -2) {
					if(B.mat[i-1][j] > B.mat[i+1][j]) {
					stop = true;
					ok = false;
					} 					
				}
			i++; 
			}
			else {
				if (B.mat[i][j] == -1) {
					if(B.mat[i][j-1] < B.mat[i][j+1]) {
					stop = true;
					ok = false;
					} 
				} else if (B.mat[i][j] == -2) {
					if(B.mat[i][j-1] > B.mat[i][j+1]) {
					stop = true;
					ok = false;
					}
				}			
			i+=2;
			}	
		}
		i = 1;
		j++;
	}
	return ok;
}
