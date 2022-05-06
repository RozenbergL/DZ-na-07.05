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
    string n;
    long long k;
    fin >> n >> k;
    long long answer = ((int)n[0] - 48) % k;
    for (int i = 1; i < n.length(); i++){
        int ind = (int)n[i] - 48;
        answer = ((answer * 10) % k + ((int)n[i]) - 48) % k;
    }
    fout << answer;
    return 0;
}
