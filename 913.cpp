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
	int n, m;
	fin >> n >> m;
    vector <vector <int>> sp;
    for (int i = 0; i < n; i++){
        int di, li, hi;
        fin >> di >> li >> hi;
        vector <int> prov(3);
        prov[0] = di;
        prov[1] = li;
        prov[2] = hi;
        sp.push_back(prov);
    }
    double minitime = 10000000000;
    int answer = -1;
    for (int i = 1; i <= m; i++){
        double counttime = 0;
        for (int j = 0; j < n; j++){
            counttime += (double)sp[j][0] / (double)i;
            if (i > sp[j][1]){
                counttime += sp[j][2];
            }
        }
        if (counttime < minitime){
            minitime = counttime;
            answer = i;
        }
    }
    fout << answer;
    return 0;
}
