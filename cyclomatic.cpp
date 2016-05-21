#include <iostream>
#include <fstream>
#include<vector>
#include<string.h>
using namespace std;
int topS=-1;
static int adj[100][100];
int main () {
    string line;
    vector<string> mat;
    int stak[1000];

    string stgs[100];

    int count=0,len=0,i,find_index1,find_index2,find_index3;
    string contant;
    i=0;
    ifstream myfile ("input-cyclo.c");

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            mat.push_back(line);
            cout<<mat[i]<<"\n";
            i++;
        }
        myfile.close();
    }
//    for(i=0;i<26;i++)
//    {
//        cout<<i<<"\n";
//        for(int j=0;j<26;j++)
//        {
//            adj[i][j]=1;
//            cout<<j<<"\n";
//        }
//    }
    for(int j=0;j<i;j++)
    {
        //cout<<mat[j]<<"\n";
        int x,y,z,br;
        x=mat[j].find("if");
        y=mat[j].find("while");
        z=mat[j].find("for");
        br=mat[j].find("}");
        //cout<<br<<"\n";
        if(x>0)
        {
            topS++;
            stak[topS]=j;
            stgs[topS]="if";
            //cout<<"abdul";
           // cout<<stak[topS]<<"\n";
        }
        else if(y>0||z>0)
        {
            topS++;
            stak[topS]=j;
            if(y>0)
            stgs[topS]="while";
            else if(z>0)
                    stgs[topS]="for";
        }
        else if(br>0)
        {

            if(topS>=0)
            {
            if(stgs[topS].compare("for")==0||stgs[topS].compare("while")==0)
            {
                //adj[j][stak[topS]]=1;

            }
            adj[stak[topS]][j+1]=1;
            topS--;
            }
        }
            adj[j][j+1]=1;


    }
    for(int j=0;j<=topS;j++)
    {
        cout<<stak[j]<<"  "<<stgs[j]<<"\n";
    }
   // cout<<i;
    count=0;
    for(int j=0;j<i;j++)
    {
        int c=0;
        for(int k=0;k<i;k++)
        {
            cout<<adj[j][k];
            if(adj[j][k]==1)
                c++;
        }
        if(c>=2)
        {
            //cout<<count;
            count+=c-1;

        }
        cout<<"\n";
    }


    //else cout << "Unable to open file";
    cout<<"cyclometric complexity = "<<count+1<<"\n";
    return 0;
}




/*
Input file - (input.c)

int main(int argc, char const *argv[])
{
int a,b,c,d;

if(a>2){
    c = 2;
} else{
    a = 3;
    d = 12;
}
while(a >= 0){
    b = 1;
    if(d==2){
        cout<<d;
    }
    a--;
}
return 0;
}
*/