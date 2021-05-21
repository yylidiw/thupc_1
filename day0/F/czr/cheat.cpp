#include <bits/stdc++.h>
using namespace std;
const int L=10;
const int MAXN=300000;
struct node
{int p1,p2,l,g;
};
int n,p,tl,tg,d[105],a[105][3][2][2];
int cnt[2],vs[2*L+1][2*L+1][101][101];
node que[2][MAXN+1];
inline node make(int a,int b,int d,int e)
{node tp;
tp.p1=a;tp.p2=b;
tp.l=d;tp.g=e;
return tp;
}
inline int s(int a)
{return (a>=p?a-p:a);} 
inline void add(int o,int p1,int p2,int l,int g)
{if (p1<0||p1>2*L||p2<0||p2>2*L) return;
if (o==n)
{if (p1==L&&p2==L&&l==tl&&g==tg) {puts("Chaotic Evil");exit(0);}
return;
}
if (vs[p1][p2][l][g]==o) return;
if (cnt[o&1]>=MAXN) return;
vs[p1][p2][l][g]=o;
que[o&1][++cnt[o&1]]=make(p1,p2,l,g);
}
int main (){
	int i,j,k,l;
	scanf ("%d%d",&n,&p);
	srand(66666666);
	for (i=1;i<=n;i++) d[i]=i;
	for (i=1;i<=10*n;i++) swap(d[rand()%n+1],d[rand()%n+1]); 
	for (i=1;i<=n;i++)
	{for (j=0;j<=1;j++)
	{for (k=0;k<=2;k++)
	{scanf ("%d%d",&a[d[i]][k][j][0],&a[d[i]][k][j][1]);}
	}
	}
	memset(vs,-1,sizeof(vs));
	scanf ("%d%d",&tl,&tg);
	add(0,L,L,0,0);
	for (i=1;i<=n;i++)
	{int cur=(i&1),pre=(cur^1);
	if (cnt[pre]>=MAXN) {puts("Chaotic Evil");exit(0);}
	cnt[cur]=0;
	for (j=1;j<=cnt[pre];j++)
	{node tp=que[pre][j];
	int p1=tp.p1,p2=tp.p2,l=tp.l,g=tp.g;
	add(i,p1-1,p2+1,s(l+a[i][0][0][0]),s(g+a[i][0][0][1]));
	add(i,p1+1,p2-1,s(l+a[i][0][1][0]),s(g+a[i][0][1][1]));
	add(i,p1-2,p2,s(l+a[i][1][0][0]),s(g+a[i][1][0][1]));
	add(i,p1+2,p2,s(l+a[i][1][1][0]),s(g+a[i][1][1][1]));
	add(i,p1-1,p2-1,s(l+a[i][2][0][0]),s(g+a[i][2][0][1]));
	add(i,p1+1,p2+1,s(l+a[i][2][1][0]),s(g+a[i][2][1][1]));
	}
	}
	puts("Not a true problem setter");
	return 0;
}
