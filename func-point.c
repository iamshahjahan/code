#include<stdio.h>


int fround(float x)
{
  int a;
  x=x+0.5;
  a=x;
  return(a);
}

int main()
{
  int weights[5][3]={3,4,6,4,5,6,3,4,6,7,10,15,5,7,10};
  int UFP=0,F=0,rating,i,j;
  char func_units[][30]={"External Inputs","External Outputs","External Enquiries","Internal Logical Files","External Interface Files"};
  char complexity[3][10]={"low","average","high"};
  int input[5][3];
  float FP,CAF;


  for(i=0;i<5;i++)
  {
    for(j=0;j<3;j++)
    {
      printf("\nEnter number of %s %s : ",complexity[j],func_units[i]);
      scanf("%d",&input[i][j]);
    }
  }

  for(i=0;i<5;i++)
  {
    for(j=0;j<3;j++)
    {
      UFP=UFP+(input[i][j]*weights[i][j]);
    }
  }

  printf("\nUnadjusted Function Point(UFP) = %d",UFP);

  printf("\nEnter Rating of 14 factors on the scale of 0-5 :\n");
  printf("\n 0 - No Influence");
  printf("\n 1 - Incidental");
  printf("\n 2 - Moderate");
  printf("\n 3 - Average");
  printf("\n 4 - Significant");
  printf("\n 5 - Essential");

  printf("\n");

  for(i=0;i<14;i++)
  {
    scanf("%d",&rating);
    F=F+rating;
  }

  CAF=0.65+0.01*F;

  FP=UFP*CAF;

  printf("\nAdjusted Function Point = %f",FP);

return 0;
}
