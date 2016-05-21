#include<iostream>
#include<math.h>
using namespace std;
int main()
{
float arr[3][4]={{3.2,1.05,2.5,0.38},{3.0,1.12,2.5,0.35},{2.8,1.20,2.5,0.32}};
//float arr[3][4]={{2.4,1.05,2.5,0.38},{3.0,1.12,2.5,0.35},{3.6,1.2,2.5,0.32}};
	float tab[15][6] = {{0.75,0.88,1.00,1.15,1.4,0},{0,0.94,1.00,1.08,1.16,0},{0.7,0.85,1.00,1.15,1.30,1.65}, {0,0,1.00,1.11,1.30,1.66},
					 	{0,0,1.00,1.06,1.21,1.56}, {0,0.87,1.00,1.15,1.30,0}, {0,0.87,1.00,1.07,1.15,0}, {1.46,1.19,1.00,0.86,0.71,0},
					 	{1.29,1.13,1.00,0.91,0.82,0}, {1.42,1.17,1.00,0.86,0.70,0}, {1.21,1.10,1.00,0.90,0,0}, {1.14,1.07,1.00,0.95,0,0},
					 	 {1.24,1.10,1.00,0.91,0.82,0}, {1.24,1.10,1.00,0.91,0.83,0}, {1.23,1.08,1.00,1.04,1.10,0}};

float eaf,k,e[3],d[3],p[3];
int i,c,avg[3];
eaf=1.0;
cout<<"\n Enter KLOC?";
cin>>k;
eaf=1.0;
char str[15][5]={"RELY","DATA","CPLX","TIME","STOR","VIRT","TURN","ACAP","AEXP","PCAP","VEXP","LEXP","MODP","TOOL","SCED"};
for(i=0;i<15;i++)
	{
	cout<<str[i];
cout<<"\n Enter Rating?";
cout<<"\n 1. Very Low";
cout<<"\n 2. Low";
cout<<"\n 3. Nominal";
cout<<"\n 4. High";
cout<<"\n 5. Very High";
cout<<"\n 6. Extra High  ";
cin>>c;
c--;
	if(tab[i][c]!=0)
		eaf*=tab[i][c];

}

for(i=0;i<3;i++)
	{
		
		e[i]=arr[i][0]*pow(k,arr[i][1])*eaf;
		d[i]=arr[i][2]*pow(e[i],arr[i][3]);
		avg[i]=e[i]/d[i]+1;
		p[i]=k/e[i];
	}

cout<<"\n EAF = "<<eaf;
if(k>2&&k<50){
cout<<" \n ORGANIC MODE";
cout<<"\n\t EFFORT (person-months) = "<<e[0];
cout<<"\n\t DEVELOPMENT (months) = "<<d[0];
cout<<"\n\t AVG STAFF SIZE = "<<avg[0];
cout<<"\n\t PRODUCTIVITY (KLOC/PM)  = "<<p[0];
}
else if(k>50&&k<300){
cout<<" \n SEMI DETACHED MODE";
cout<<"\n\t EFFORT (person-months) = "<<e[1];
cout<<"\n\t DEVELOPMENT (months) = "<<d[1];
cout<<"\n\t AVG STAFF SIZE = "<<avg[1];
cout<<"\n\t PRODUCTIVITY (KLOC/PM)  = "<<p[1];
}else{
cout<<" \n EMBEDDED MODE";
cout<<"\n\t EFFORT (person-months) = "<<e[2];
cout<<"\n\t DEVELOPMENT (months) = "<<d[2];
cout<<"\n\t AVG STAFF SIZE = "<<avg[2];
cout<<"\n\t PRODUCTIVITY (KLOC/PM)  = "<<p[2]<<"\n";
}
}