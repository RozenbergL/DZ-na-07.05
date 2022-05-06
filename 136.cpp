#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int MAX = 101;
    int g[MAX][MAX];
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n;
	fin >> n;
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
	        int k;
	        fin >> k;
	        if (k == -1){
	            g[i][j] = 1000000000;
	        }else{
	            g[i][j] = k;
	        }
	    }
	}
	int i, j, k;
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if (g[i][k] + g[k][j] < g[i][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    int answer = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j <  n; j++){
            if ((g[i][j] > answer) && (g[i][j] < 1000000000)){
                answer = g[i][j];
            }
        }
    }
    fout << answer;
    return 0;
}