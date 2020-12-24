#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define heap priority_queue

#define foor(x,y,z) for(x = y;x <= z;x++)
#define roof(x,y,z) for(x = y;x >= z;x--)
#define mmst(x,y) memset(x , y , sizeof(x))

#define sf(x) scanf("%d",&x)
#define sfl(x) scanf("%I64d",&x)
#define sff(x,y) scanf("%d %d",&x,&y)
#define sffl(x,y) scanf("%I64d %I64d",&x,&y)
#define sfff(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define pf(x) printf("%d\n",x)
#define pfl(x) printf("%I64d\n",x)
#define pff(x,y) printf("%d %d\n",x,y)
#define pfff(x,y,z) printf("%d %d %d\n",x,y,z)

#define Size(x) ((int)x.size())
#define All(x) x.begin(),x.end()

#define dbg(x) cout<<(#x)<<" --> "<<(x)<<endl

#define endl '\n'
#define bos ' '

#define pif printf
#define sif scanf
#define sifon fflush(stdout)
#define bul(x,y,z) (pre[x][z] - pre[x][y-1])


using namespace std;

typedef long long int ll;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vpii;

const double eps = 1e-9;
const double pi = 3.1415926535;
const int inf = 5e8;
const int maxn = 1e5 + 7;
const ll mod = 1e9 + 7;

#define foku(x) freopen(x,"r",stdin)
#define fyaz(x) freopen(x,"w",stdout)

string s1;
string s2;
int n1 , n2;

vector<int> gec;

int pre[1000007];

void build()
{
	int i = 0, j = 1;
	
	while(j < n2)
	{
		if(s2[i] == s2[j])
		{
			pre[j]= i+1;
			i++;
			j++;
			continue;
		}
		if(i == 0)
		{
			pre[j] = 0;
			j++;
			continue;
		}
		while(i != 0 && s2[i] != s2[j])i = pre[i-1];
	}
}

void ara()
{
	int i1 = 0,i2 =0;
	
	foor(i1,i1,n1-1)
	{
		if(i2 == n2)
		{
			gec.pb(i1 - n2);
			i2 = pre[n2-1];
		}
		
		if(s1[i1] == s2[i2])
		{
			i2++;
			continue;
		}
		
		if(i2 == 0)continue;
		
		while(i2 != 0 && s1[i1] != s2[i2])i2 = pre[i2-1];
		i1--;
	}
	
	
}

int main()
{
	foku("kmp.gir");
	fyaz("kmp.cik");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>s1>>s2;
	
	n1 = Size(s1);
	n2 = Size(s2);
	
	build();
	
	ara();
	
	cout<<Size(gec)<<"\n";
	int i;
	foor(i,0,Size(gec)-1)cout<<gec[i] +1 <<" ";
	cout<<"\n";
    return 0;
}

