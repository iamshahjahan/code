# include <iostream>
# include <math.h>

using namespace std;

int main()
{

	float arr[3][4]={{2.4,1.05,2.5,0.38},{3.0,1.12,2.5,0.35},{3.6,1.2,2.5,0.32}};

	float k,e[3],d[3],avg[3],p[3];
	int i;
	cout<<"\n Enter KLOC:";
	cin>>k;

	for(i=0;i<3;i++)
	{

		e[i]=arr[i][0]*pow(k,arr[i][1]);
		d[i]=arr[i][2]*pow(e[i],arr[i][3]);
		avg[i]=e[i]/d[i];
		p[i]=k/e[i];
	}

	cout<<" \n ORGANIC MODE";
	cout<<"\n\t Effort: "<<e[0];
	cout<<"\n\t Developement: "<<d[0];
	cout<<"\n\t Avg staff size: "<<avg[0];
	cout<<"\n\t Productivity: "<<p[0];

	cout<<" \n SEMI DETACHED MODE";
	cout<<"\n\t Effort: "<<e[1];
	cout<<"\n\t Developement: "<<d[1];
	cout<<"\n\t Avg staff size: "<<avg[1];
	cout<<"\n\t Pruductivity: "<<p[1];

	cout<<" \n EMBEDDED MODE";
	cout<<"\n\t Effort: "<<e[2];
	cout<<"\n\t Developement: "<<d[2];
	cout<<"\n\t Avg staff size: "<<avg[2];
	cout<<"\n\t Productivity: "<<p[2]<<"\n";

}