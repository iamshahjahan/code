#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void calc(const float values[][4], int kloc, string types[]){
	int num = 3;

	for (int i = 0; i < num; ++i){
		float effApplied = 0.0;
		float devTime = 0.0;
		int numOfPeople = 0;

		cout << " *** For "<< types[i] << " *** " << endl;
		
		float effTemp = pow(kloc, values[i][1]);
		effApplied = values[i][0] * effTemp;

		float devTemp = pow(effApplied, values[i][3]);
		devTime = values[i][2] * devTemp;

		numOfPeople = effApplied / devTime;

		cout << "Effort Applied : " << effApplied << endl;
		cout << "Development Time : " << devTime << endl;
		cout << "Number of People Required : " << numOfPeople << endl << endl;
	}
}

int main(int argc, char const *argv[]){
	const float values[][4] = {
		{2.4, 1.05, 2.5, 0.38},
		{3.0, 1.12, 2.5, 0.35},
		{3.6, 1.20, 2.5, 0.32}
	};

	string types[] = {
		"Organic",
		"Semi-detached",
		"Embedded"
	};

	int kloc;

	cout << "Enter the lines of code (in kilos) : ";
	cin >> kloc;

	calc(values, kloc, types);

	//cout << "Hello!" << endl;
	return 0;
}