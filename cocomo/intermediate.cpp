#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void calc(const float values[][4], const float ratings[][6], int kloc, int rating[], string types[]){
	int num = 3;

	for (int i = 0; i < num; ++i){
		float effApplied = 0.0;
		float devTime = 0.0;
		int numOfPeople = 0;

		float eaf = 1.0;

		for (int j = 0; j < 15; ++j){
				eaf = eaf * ratings[rating[i]];
		}

		cout << " *** For "<< types[i] << " *** " << endl;
		
		float effTemp = pow(kloc, values[i][1]) * eaf;
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
	//const float ratings[] = {3.66, 1.29, 1.0, 1.02, 1.51, 4.27};
	
	const float ratings[][6] = {
		{0.75, 0.88, 1.00, 1.15, 1.40, 0.00}, 
		{1.00, 0.94, 1.00, 1.08, 1.16, 1.00}, 
		{0.70, 0.85, 1.00, 1.15, 1.30, 1.65},

		{1.00, 1.00, 1.00, 1.11, 1.30, 1.66}, 
	 	{1.00, 1.00, 1.00, 1.06, 1.21, 1.56}, 
	 	{1.00, 0.87, 1.00, 1.15, 1.30, 1.00}, 
	 	{1.00, 0.87, 1.00, 1.07, 1.15, 1.00}, 
	 	{1.46, 1.19, 1.00, 0.86, 0.71, 1.00}, 

	 	{1.29, 1.13, 1.00, 0.91, 0.82, 1.00}, 
	 	{1.42, 1.17, 1.00, 0.86, 0.70, 1.00}, 
	 	{1.21, 1.10, 1.00, 0.90, 1.00, 1.00}, 
	 	{1.14, 1.07, 1.00, 0.95, 1.00, 1.00}, 

	 	{1.24, 1.10, 1.00, 0.91, 0.82, 1.00}, 
	 	{1.24, 1.10, 1.00, 0.91, 0.83, 1.00}, 
	 	{1.23, 1.08, 1.00, 1.04, 1.10, 1.00}
	};

	const float values[][4] = {
		{3.2, 1.05, 2.5, 0.38},
		{3.0, 1.12, 2.5, 0.35},
		{2.8, 1.20, 2.5, 0.32}
	};

	string ratingTypes[] = {
		"Very Low",
		"Low",
		"Nominal",
		"High",
		"Very High",
		"Extra High"
	};

	string attributes[] = {
		"Required software reliability",
		"Size of application database",
		"Complexity of the product",
		"Run-time performance constraints",
		"Memory constraints",
		"Volatility of the virtual machine environment",
		"Required turnabout time",
		"Analyst capability",
		"Applications experience",
		"Software engineer capability",
		"Virtual machine experience",
		"Programming language experience",
		"Application of software engineering methods",
		"Use of software tools",
		"Required development schedule"
	};

	string types[] = {
		"Organic",
		"Semi-detached",
		"Embedded"
	};

	int kloc, rating[15];

	cout << "Enter the lines of code (in kilos) : ";
	cin >> kloc;

	for (int i = 0; i < 15; ++i){
		cout << "Enter Rating for " << attributes[i] << " : ";
		cin >> rating[i];
	}

	calc(values, ratings, kloc, rating, types);

	return 0;
}