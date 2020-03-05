#include <stdio.h>

int cmmdc(int a, int b) {
	/*
		Programul returneaza cmmdc-ul a 2 numere a - int, b - int
		Preconditii - b != 0
		Postconditii - Valoarea retunata este int
	*/
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int prim(int a) {
	/*
		Programul returneaza 0 in cazul in care numarul nu este prim, 0 in caz contrar.
		Preconditii - a - int
		Postonditii - Rezultat - int
	*/
	if (a == 2) return 1;
	if (a % 2 == 0) return 0;
	for (int i = 3; i <= a / 2; ++i)
		if (a % i == 0)
			return 0;
	return 1;
}

void problema() {
	/*
		Programul cauta primele 10 numere mai mari decat 2 care sunt primele cu toate numerele mai mici decat ele 
		iar toate numerele mai mici decat ele cu care sunt prime, sunt prime insele
		Preconditii - %
		Postconditii - %
	*/
	int n = 0, nr = 3;
	while (n != 10) {
		int k = 0;
		for (int i = 2; i < nr; ++i) {
			int cmmdcV = cmmdc(nr, i);
			if (cmmdcV == 1) {
				//printf("cmmdc(%d, %d) = %d- caz\n",nr, i, cmmdcV);
				if (prim(i) == 0) {
					k = 1;
					break;
				}
			}
		}
		if (k == 0) {
			printf("%d %d\n", n, nr);
			++n;
		}
		++nr;
	}
}

void menu() {
	/*
		Meniu pt problema 17
		Preconditii - %
		Postconditii - %
	*/
	int m = 0;
	char meniu[100] = "1 - Solutii problema 17\n2 - Inchide programul\n";
	char comanda[10] = "Comanda: ";
	while (m != 2) {
		printf("%s", meniu);
		printf("%s", comanda);
		scanf("%d", &m);
		if (m == 1) problema();
		else break;
	}
}

int main() {
	menu();
	//system("PAUSE");
	return 0;
}