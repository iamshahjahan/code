#include<bits/stdc++.h>
#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    int i,j,s=0,k,l,m,f=0,c=0,e,st[100],a[100][3]={0};
    char tm[100];
    FILE * ptr=fopen("program.txt","r");
    while(!feof(ptr))
    {
        fgets(tm,100,ptr);
        for(i=0;i<strlen(tm);i++) 
        {
                if(f==0)
                {
                    if(tm[i]=='m'&&tm[i+1]=='a'&&tm[i+2]=='i'&&tm[i+3]=='n')
                    {
                        f=1;c=1;
                        a[c][0]=1;
                        a[c][1]=2;
                        i=l;
                    }
                }
                else{
                    if(tm[i]=='}'&&s!=0)
                    {
                        c++;
                        a[c][0]++;
                        a[c][1]=c+1;
                        a[st[s]][2]=c+1;
                        a[st[s]][0]++;
                        s--;
                        break;
                    }
                    
                    else if((tm[i]=='i'&&tm[i+1]=='f')||(tm[i]=='e'&&tm[i+1]=='l'&&tm[i+2]=='s'&&tm[i+3]=='e'&&tm[i+5]=='i'&&tm[i+6]=='f'))
                    {
                        c++;
                        a[c][0]++;
                        a[c][1]=c+1;
                        s++; 
                        st[s]=c;
                        
                        break;
                        
                    }

                    else{
                        c++;
                        a[c][0]++;
                        a[c][1]=c+1;
                        break;
                    }
                   
                }
            
        }}
	printf("Branched Nodes \n");
        for(i=1;i<c;i++)
        {
		if(a[i][0]>1){ 
			printf("%d -> ",i);
            		for(j=1;j<=a[i][0];j++)
            		{
              			printf("%d ",a[i][j]);
				if(j<a[i][0])printf(",");
            		}
			printf("\n");
            	}
        }
    
    e=0;
    for(i=1;i<=c;i++)
    {
        for(j=1;j<=a[i][0];j++)
        {
            e++;
        }
    }
    e--;
    printf("\n\nEdges(E) : %d and Nodes(N) : %d\n",e,c);
    
    
    printf("\nCyclomatic complexity (E-N+2) = %d\n",e-c+2);
    scanf("%d",&e);
	return(0);   
}	
