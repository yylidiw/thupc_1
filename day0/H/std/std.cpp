#include <bits/stdc++.h>
using namespace std;
const int N=1000000;
char n[N+5],x[N+5];
int k;
inline void fail(int p)
{puts("Wrong, don't cheat me, you are too far away from the Turing Award.");printf("%d\n",p);exit(0);}
inline void ok()
{puts("Correct, but it doesn't necessarily mean that you can win the Turing Award.");exit(0);}
inline void check(int ans,int xx)
{if (ans==xx) ok();
if (xx>ans) fail(1);
fail(0);
}
inline int ceil(int a,int b)
{return a/b+(a%b==0?0:1);}
int main (){
	scanf ("%s",n+1);
	scanf ("%d",&k);
	scanf ("%s",x+1);
	int m=strlen(n+1),i,nn=0;
	int p=strlen(x+1),xx=0;
	if (p>6) fail(1);
	for (i=1;i<=p;i++) xx=xx*10+(x[i]-'0');
	if (m<=6)
	{for (i=1;i<=m;i++) nn=nn*10+(n[i]-'0');
	if (nn<=2*k+1) check(nn,xx);
	int m=nn/(k+1),rem=nn%(k+1);
	check(k+1+ceil(rem,m),xx);
	}
	for (i=1;i<=m;i++) nn=(nn*10+(n[i]-'0'))%(k+1);
	if (nn==0) check(k+1,xx);
	check(k+2,xx);
	return 0; 
}

