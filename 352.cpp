#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n;
	fin >> n;
	int m;
	if (n % 2 == 0){
	    m = n / 2 - 1;
	}else{
	    m = n / 2;
	}
	int k = n - m;
	while (m >= 1){
	    if (gcd(m, k) == 1){
	        break;
	    }else{
	        m--;
	        k++;
	    }
	}
	fout << m << " " << k;
    return 0;
}
