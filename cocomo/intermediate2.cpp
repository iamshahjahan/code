#include <iostream>
#include <cmath>
#include <string>

const std::string types[] = {
	"Organic",
	"Semi-detached",
	"Embedded"
};

const float eaf[] = {
	3.66,
	1.29,
	1.0,
	1.02,
	1.51,
	4.27
};

const float ratings_tab[15][6] = {
	{0.75, 0.88, 1.00, 1.15, 1.40, 1.00}, 
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

const std::string attributes[] = {
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
	"Required development schedule",
};

int main() {
	int kloc, rating;

	std::cout<<"Enter kloc: ";
	std::cin>>kloc;

	std::cout<<"Enter ratings for attributes."<<std::endl;
	std::cout<<"0 - Very low; 1 - Low; 2 - Nominal; 3 - High; 4 - Very high; 5 - Extra high"<<std::endl;

	float eaf = 1.0;
	for (int i = 0; i < 15; ++i) {
		int value;
		std::cout<<attributes[i]<<" : ";
		std::cin>>value;
		eaf *= ratings_tab[i][value];
	}

	float effort[3], dev_time[3];
	int people[3];

	for (int i = 0; i < 3; ++i)	{
		effort[i] = values[i][0] * pow(kloc, values[i][1]) * eaf;
		dev_time[i] = values[i][2] * pow(effort[i], values[i][3]);
		people[i] = effort[i] / dev_time[i];
	}

	for (int i = 0; i < 3; ++i) {
		std::cout<<types[i]<<std::endl;
		std::cout<<"Effort Applied: "<<effort[i]<<" person months"<<std::endl;
		std::cout<<"Development time: "<<dev_time[i]<<" months"<<std::endl;
		std::cout<<"People required: "<<people[i]<<std::endl<<std::endl;
	}

	return 0;
}
