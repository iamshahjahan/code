# include <stdio.h> 
# include <math.h> 

int main() 
{ 
    int size,i,rating; 
    float PM_nominal,PM_adjusted; 
    float B,F,EM,a; 
    char scale_factors[][30]={"Precedentedness","Development Flexibility","Risk Resolution","Team Cohesion","Process Maturity"}; 

    float scale_table[5][6]={ 
        {6.20,4.96,3.74,2.48,1.24}, 
        {5.07,4.05,3.04,2.03,1.01}, 
        {7.07,5.65,4.24,2.83,1.41}, 
        {5.48,4.38,3.29,2.19,1.10}, 
        {7.80,6.24,4.68,3.12,1.56} 
    }; 

    char cost_drivers[7][6]={"RCPX","RUSE","PDIF","PERS","PREX","FCIL","SCED"}; 

    float driver[7][7]={ 
        {0.73,.81,.98,1,1.30,1.74,2.38}, 
        {-1,-1,.95,1,1.07,1.15,1.24}, 
        {-1,-1,.87,1,1.29,1.81,2.61}, 
        {2.12,1.62,1.26,1,.83,.63,.50}, 
        {1.59,1.33,1.12,1,.87,.71,.62}, 
        {1.43,1.30,1.10,1,1,.73,.62}, 
        {-1,1.43,1.14,1,-1,1,-1} 
    }; 

    printf("\nEnter size of project (in KLOC) : "); 
    scanf("%d",&size); 

    printf("\n\n0 - Very Low\t1 - Low\t2 - Nominal\t3 - High\t4 - Very High\t5 - Extra High\n\n"); 

    for(i=0;i<5;i++) 
    { 
        printf("\nRate Scaling Factor %s on the scale of 0-5 : \n",scale_factors[i]); 
        scanf("%d",&rating); 
        F=F+scale_table[i][rating]; 
    } 

    B=1.01+(0.01*F); 
    printf("\nB (scale factor) = %f",B); 
    PM_nominal=2.45*pow(size,B); 

    printf("\nNominal Effort = %f Person-Month",PM_nominal); 
    EM=1; 

    printf("\n\n0 - Extra Low\t1 - Very Low\t2 - Low\t3 - Nominal\t4 - High\t5 - Very High\t6 -   Extra High\n\n"); 

    for(i=0;i<7;i++) 
    { 
        do 
        { 
            printf("\nRate Cost Driver '%s' on scale of (0-6) : ",cost_drivers[i]); 
            scanf("%d",&rating); 
            a=driver[i][rating]; 
            if(a==-1) 
                printf("\nNo value exists for this Rating..Enter another rating..\n"); 
        } while(a==-1); 

        EM=EM*a; 
    } 

    PM_adjusted=PM_nominal * EM; 
    printf("\nAdjusted Effort (PM_adjusted) = %f Person-Month",PM_adjusted); 
    printf("\nB (scale factor) = %f",B); 
    printf("\nNominal Effort = %f Person-Month",PM_nominal); 
}
