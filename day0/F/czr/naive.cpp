#include <bits/stdc++.h>
using namespace std;
const int L=15;
int n,p,a[105][3][3][3],d[105];
bool t[2][2*L+3][2*L+3][101][101];
inline int s(int a)
{return (a>=p?a-p:a);}
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
	t[0][L][L][0][0]=1;
	for (i=1;i<=n;i++)
	{int cur=(i&1),pre=(cur^1);
	memset(t[cur],0,sizeof(t[cur]));
	for (p1=2;p1<=L+L;p1++)
	{for (p2=((p1&1)?1:2);p2<=L+L+1;p2+=2)
	{for (l=0;l<p;l++)
	{for (g=0;g<p;g++)
	{if (!t[pre][p1][p2][l][g]) continue;
	t[cur][p1-1][p2+1][s(l+a[i][0][0][0])][s(g+a[i][0][0][1])]=1;
	t[cur][p1+1][p2-1][s(l+a[i][0][1][0])][s(g+a[i][0][1][1])]=1;
	t[cur][p1-2][p2][s(l+a[i][1][0][0])][s(g+a[i][1][0][1])]=1;
	t[cur][p1+2][p2][s(l+a[i][1][1][0])][s(g+a[i][1][1][1])]=1;
	t[cur][p1-1][p2-1][s(l+a[i][2][0][0])][s(g+a[i][2][0][1])]=1;
	t[cur][p1+1][p2+1][s(l+a[i][2][1][0])][s(g+a[i][2][1][1])]=1;
	}
	}
	}
	}
	}
	if (t[n&1][L][L][tl][tg]) {puts("Chaotic Evil");}
	else {puts("Not a true problem setter");}
	return 0;
}
