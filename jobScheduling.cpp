#include<bits/stdc++.h>


using namespace std;

typedef pair<int,int> pint;
pint dizi[100000];

int main()
{
	freopen("planlama.gir","r",stdin);
	freopen("planlama.cik","w",stdout);
	int n,a;
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		scanf("%d %d",&dizi[a].second,&dizi[a].first);
	}
	sort(dizi,dizi+n);
	int im=0,son=0;
	for(a=0;a<n;a++)
	{
		if(dizi[a].second >= im)
		{
			im=dizi[a].first;
			son++;
		}
	}
	printf("%d\n",son);
	return 0; 
}

