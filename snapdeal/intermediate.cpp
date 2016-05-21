#include<stdio.h>
#include<conio.h>
#include<math.h>

int fround(float x)
{
  int a;
  x=x+0.5;
  a=x;
  return(a);
}

int main()
{
  float table[3][4]={3.2,1.05,2.5,0.38,3.0,1.12,2.5,0.35,2.8,1.20,2.5,0.32};
  int i,j,size,model,rating;
  char mode[][15]={"Organic","Semi-Detached","Embedded"};
  char driver[15][6]={"RELY","DATA","CPLX","TIME","STOR","VIRT","TURN","ACAP","AEXP","PCAP",
  "VEXP","LEXP","MODP","TOOL","SCED"};

  float effort,EAF,a,time,staff,productivity;
  float costdrivers[15][6]={

                {0.75,0.88,1,1.15,1.40,-1},

                {-1,0.94,1,1.08,1.16,-1},

                {0.70,0.85,1,15,1.30,1.65},

                {-1,-1,1,1.11,1.30,1.66},

                {-1,-1,1,1.06,1.21,1.56},

                {-1,0.87,1,1.15,1.30,-1},

                {-1,0.87,1,1.07,1.15,-1},

                {1.46,1.19,1,0.86,0.71,-1},

                {1.29,1.13,1.00,0.91,0.82,-1},

                {1.42,1.17,1,0.86,0.70,-1},

                {1.21,1.10,1,0.90,-1,-1},

                {1.14,1.07,1,0.95,-1,-1},

                {1.24,1.10,1.00,0.91,0.82,-1},

                {1.24,1.10,1,0.91,0.83,-1},

                {1.23,1.08,1,1.04,1.10,-1}

                };


  printf("\nEnter the size of project : ");

  scanf("%d",&size);

  if(size>=2 && size<=50)

    model=0;

  else if(size>50 && size<=300)

    model=1;

  else if(size>300)

    model=2;

  printf("\nMode = %s",mode[model]);

  EAF=1;

  for(i=0;i<15;i++)

  {

    do

    {

    printf("\nRate cost driver %s on scale of 0-5 : ",driver[i]);

    printf("\n0-Very Low\t1-Low\t2-Nominal\t3-High\t4-Very High\t5-Extra High\n");

    scanf("%d",&rating);

    a=costdrivers[i][rating];

    if(a==-1)

    {

       printf("\nNo value exist for this rating..Enter another rating...\n");

    }

    }while(a==-1);

    EAF=EAF*a;

  }

  printf("\nEAF = %f",EAF);

  effort=(table[model][0]*pow(size,table[model][1])) * EAF;

  time=table[model][2]*pow(effort,table[model][3]);

  staff=effort/time;

  productivity=size/effort;

  printf("\n\nEffort = %f Person-Month",effort);

  printf("\nDevelopment Time = %f Months",time);

  printf("\nAverage Staff Required = %d Persons",fround(staff));

  printf("\nProductivity = %f KLOC/Person-Month",productivity);

getch();
return 0;
}
