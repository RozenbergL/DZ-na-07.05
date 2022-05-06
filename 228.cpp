#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n;
	fin >> n;
	double prdol, preuro, dol, euro, answer;
	answer = 100;
	fin >> prdol >> preuro;
	for (int i = 0; i < n - 1; i++){
	    fin >> dol >> euro;
	    if (prdol < dol || preuro < euro){
	        answer = max((answer - prdol * (answer / prdol) + (answer / prdol) * dol), (answer - preuro * (answer / preuro) + (answer / preuro) * euro));
	    }
	    prdol = dol;
	    preuro = euro;
	}
	fout << answer;
    return 0;
}