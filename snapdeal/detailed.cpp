#include<stdio.h> 
#include<math.h> 
#include<stdlib.h>

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
  int i,j,size,model,rating,S; 
  char mode[][15]={"Organic","Semi-Detached","Embedded"}; 
  char driver[15][6]={"RELY","DATA","CPLX","TIME","STOR","VIRT","TURN","ACAP","AEXP","PCAP","VEXP","LEXP","MODP","TOOL","SCED"}; 
  float effort,EAF,a,time,staff,productivity; 
  float driverv[15];
  char rat[6][15]={"Very Low","Low","Nominal","High","Very High","Extra High"};
  int driverv1[15];
  float costdrivers[15][6]={ 
                {0.75,0.88,1,1.15,1.40,-1}, 
                {-1,0.94,1,1.08,1.16,-1}, 
                {0.70,0.85,1,1.15,1.30,1.65}, 
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

  float mp[6][5]={ 
            {0.06,0.16,0.26,0.42,0.16}, 
            {0.06,0.16,0.24,0.38,0.22}, 
            {0.07,0.17,0.25,0.33,0.25}, 
            {0.07,0.17,0.24,0.31,0.28}, 
            {0.08,0.18,0.25,0.26,0.31}, 
            {0.08,0.18,0.24,0.24,0.34} 
          }; 
  float tp[6][5]={ 
            {0.10,0.19,0.24,0.39,0.18}, 
            {0.12,0.19,0.21,0.34,0.26}, 
            {0.20,0.26,0.21,0.27,0.26}, 
            {0.22,0.27,0.19,0.25,0.29}, 
            {0.36,0.36,0.18,0.18,0.28}, 
            {0.40,0.38,0.16,0.16,0.30} 
          }; 

  char phases[5][40]={"Planning and Requirements Phase\t","System Design Phase\t\t","Detail Design Phase\t\t","Module Code and Test Phase\t","Integration and Test Phase\t"};  
  printf("\nEnter the size of project :\t"); 
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
       printf("\nNo Value for this Rating, Enter Again\n"); 
    } 
    }while(a==-1);
    driverv[i]=a;
    driverv1[i]=rating;
    EAF=EAF*a; 
  }
  
  system("clear");
  printf("\n\n");
  printf("Driver\t\tRating\t\t\tValue\n");  
  for(j=0;j<15;j++)
  {
     printf("%s\t\t%s\t\t\t%f\n",driver[j],rat[driverv1[j]],driverv[j]);
  }
  printf("\nEAF =\t%f",EAF); 

  effort=(table[model][0]*pow(size,table[model][1])) * EAF; 
  time=table[model][2]*pow(effort,table[model][3]); 
  staff=effort/time; 
  productivity=size/effort; 

  printf("\n\nEffort \t\t\t=\t%f Person-Month",effort); 
  printf("\nDevelopment Time \t=\t%f Months",time); 
  printf("\nAverage Staff Required \t=\t%d Persons",fround(staff)); 
  printf("\nProductivity \t\t=\t%f KLOC/Person-Month",productivity); 
  printf("\n\n"); 

  if(model==0) 
  { 
    printf("\nEnter Ogranic - Small(0) or Medium(1) :\t"); 
    scanf("%d",&S); 
  } 
  else if(model==1) 
  { 
    printf("\nEnter Semi-Detached - Medium(2) or Large(3) :\t"); 
    scanf("%d",&S); 
  } 
  else if(model==2) 
  { 
    printf("\nEnter Embedded - Large(4) or Extra Large(5) :\t"); 
    scanf("%d",&S); 
  } 
  printf("\n\nPhase-wise Distribution of Effort is :\n\n"); 
  for(i=0;i<5;i++) 
  { 
     printf("\n%s = \t\t",phases[i]);
     printf("%f",effort*mp[S][i]); 
  } 
  printf("\n\nPhase-wise Distribution of Development Time is :\n\n"); 
  for(i=0;i<5;i++) 
  { 
     printf("\n%s = \t\t",phases[i]);
     printf("%f",time*tp[S][i]); 
  } 
    printf("\n\n");
return 0;
}
