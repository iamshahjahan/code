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

  float effort,time,staff,productivity;

  float table[3][4]={2.4,1.05,2.5,0.38,3.0,1.12,2.5,0.35,3.6,1.20,2.5,0.32};

  int size,model;

  char mode[][15]={"Organic","Semi-Detached","Embedded"};

  
  printf("\nEnter size of project (in KLOC) : ");

  scanf("%d",&size);

  if(size>=2 && size<=50)

    model=0;     //organic

  else if(size>50 && size<=300)

    model=1;     //semi-detached

  else if(size>300)

    model=2;     //embedded

  printf("\nThe mode is %s\n",mode[model]);

  effort=table[model][0]*pow(size,table[model][1]);

  time=table[model][2]*pow(effort,table[model][3]);

  staff=effort/time;

  productivity=size/effort;

  printf("\nEffort = %f Person-Month",effort);

  printf("\n\nDevelopment Time = %f Months",time);

  printf("\n\nAverage Staff Required = %d Persons",fround(staff));

  printf("\n\nProductivity = %f KLOC/Person-Month",productivity);

getch();
return 0;
} 
