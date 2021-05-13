#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int L=20;
int n,p,a[105][3][3][3],d[105];
ll t[2][2*L+3][101][101];
inline int s(int a)
{return (a>=p?a-p:a);}
inline int q(int a)
{return (a<0?a+p:a);}
int main (){
	int i,j,k,l,g,p1,p2,tl,tg;
	scanf ("%d%d",&n,&p);
	srand(13579);
	for (i=1;i<=n;i++) d[i]=i;
	for (i=1;i<=10*n;i++) swap(d[rand()%n+1],d[rand()%n+1]); 
	for (i=1;i<=n;i++)
	{for (j=0;j<=1;j++)
	{for (k=0;k<=2;k++)
	{scanf ("%d%d",&a[d[i]][k][j][0],&a[d[i]][k][j][1]);}
	}
	}
	scanf ("%d%d",&tl,&tg);
	t[0][L][0][0]=(1ll<<L);
	ll maxn=(1ll<<(2*L+3))-1;
	for (i=1;i<=n;i++)
	{int cur=(i&1),pre=(cur^1);
	for (p2=2;p2<=L+L;p2++)
	{//for (p2=((p1&1)?1:2);p2<=L+L+1;p2+=2)
	{for (l=0;l<p;l++)
	{for (g=0;g<p;g++)
	{t[cur][p2][l][g]=(t[pre][p2-1][q(l-a[i][0][0][0])][q(g-a[i][0][0][1])]<<1);
	t[cur][p2][l][g]|=(t[pre][p2+1][q(l-a[i][0][1][0])][q(g-a[i][0][1][1])]>>1);
	t[cur][p2][l][g]|=(t[pre][p2][q(l-a[i][1][0][0])][q(g-a[i][1][0][1])]<<2);
	t[cur][p2][l][g]|=(t[pre][p2][q(l-a[i][1][1][0])][q(g-a[i][1][1][1])]>>2);
	t[cur][p2][l][g]|=(t[pre][p2+1][q(l-a[i][2][0][0])][q(g-a[i][2][0][1])]<<1);
	t[cur][p2][l][g]|=(t[pre][p2-1][q(l-a[i][2][1][0])][q(g-a[i][2][1][1])]>>1);
	t[cur][p2][l][g]&=maxn;
	}
	}
	}
	}
	}
	if (t[n&1][L][tl][tg]&(1ll<<L)) {puts("Chaotic Evil");}
	else {puts("Not a true problem setter");}
	return 0;
}
