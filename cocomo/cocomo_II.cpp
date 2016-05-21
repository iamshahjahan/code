#include <iostream>
#include <cmath>

using namespace std;

void cocomo(){
	float eaf=1, e=0, effort, duration, se, person, ksloc;
	float cd[8];
	float sd[6];
	int loc;
	cout<<"** COCOMO   II **"<<endl;
	cout<<"Enter Number of Lines Of Code (LOC): ";
	cin>>loc;
	// cout<<"** CULCULATE EAF ** "<< endl;
	cout<<"** Please input the cost driver **"<<endl;
	cout<<"1. RCPX Product Reliability and ComPleXity (0.5 – 1.5): ";cin>>cd[1];
	cout<<"2. RUSE required reusability (0.5 – 1.5): ";cin>>cd[2];
	cout<<"3. PDIF Platform DIFficulty (0.5 - 1.5): ";cin>>cd[3];
	cout<<"4. PERS PERSonnel capability (0.5 – 1.5): ";cin>>cd[4];
	cout<<"5. PREX PeRsonnel EXperience (0.5 – 1.5): ";cin>>cd[5];
	cout<<"6. FCIL FaCILities available (0.5 – 1.5): ";cin>>cd[6];
	cout<<"7. SCED SChEDule pressure (0.5 – 1.5): ";cin>>cd[7];

	for(int i=1;i<8;i++)
		eaf*=cd[i];
	cout<<"EAF = "<<eaf<<endl;

	cout<<"** Please enter the Scale Drivers (0.00 - 0.05) **"<<endl;
	cout<<"1. Precedentedness: ";cin>>sd[1];
	cout<<"2. Development Flexibility: ";cin>>sd[2];
	cout<<"3. Architeture/Rise Resolution: ";cin>>sd[3];
	cout<<"4. Team Cohesion: ";cin>>sd[4];
	cout<<"5. Process Maturity: ";cin>>sd[5];

	for(int i=1;i<6;i++)
		e += sd[i];
	e += 1.01;
	cout<<"E = "<<e<<endl;

	ksloc=loc/1000;
	cout<<"KSLOC = "<<ksloc<<endl;

	effort=2.45*eaf*pow(ksloc,e);
	cout<<"Effort(in person-months) = "<<effort<<endl;

	se= 0.28 + (0.2 * (e - 1.01));
	cout<<"SE = "<<se<<endl;

	duration = 3.67 * pow(effort,se);
	cout<<"Duration(in months) = "<<duration<<endl;

	person=effort/duration;
	cout<<"Number of Persons = "<<person<<endl;
}

int main() {
	cocomo();
	return 0;
}