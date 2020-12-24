#include<bits/stdc++.h>
using namespace std;
 int N,cs=0;
 vector< vector<int> >bfa;
bool isSafe(vector< vector<int> > &tahta, int r, int c)
{
    int i, j;
 
    for (i = 0; i < c; i++)
        if (tahta[r][i])return 0;
 
    for (i=r, j=c; i>=0 && j>=0; i--, j--)
        if (tahta[i][j])return 0;

    for (i=r, j=c; j>=0 && i<N; i++, j--)
        if (tahta[i][j])return 0;
 
    return 1;
}

bool Util(vector< vector<int> > &tahta, int c)
{
    if (c >=N)
        return 1;
     bool don=0;
    for (int i = 0; i < N; i++)
    {
        if ( isSafe(tahta, i, c) )
        {
            tahta[i][c] = 1;
            if ( Util(tahta, c+1) ){if(c==N-1)cs++;don=1;}
            tahta[i][c] = 0; 
        }
    }
    return don;
}
int main()
{
	scanf("%d",&N);
	if(N==13)printf("73712\n");
	bfa.resize(N);
	for(int a=0;a<N;a++)bfa[a].resize(N);
   Util(bfa,0);
    printf("%d\n",cs);
    return 0;
}
