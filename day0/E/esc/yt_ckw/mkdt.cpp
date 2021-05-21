#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define lint long long
#define ull unsigned lint
#define db long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define gc getchar()
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
int c[55];FILE *fp=fopen("data.in","w");
int cnt=0;const int max_cnt=200000;
inline int show(int n)
{
//	cerr<<n<<endl;
	cnt++;if(cnt>=max_cnt) return 0;
	fprintf(fp,"%d\n",n);
	rep(i,1,n) fprintf(fp,"%d ",c[i]);fprintf(fp,"\n");
	return 0;
}
int dfs(int x,int m,int n)
{
	if(cnt>=max_cnt) return 0;
	if(x==n+1) return show(n);
	rep(i,1,m+1) c[x]=i,dfs(x+1,max(i,m),n);
	return 0;
}
int main()
{
	int l=11,r=11;
	rep(n,l,r)
	{
		dfs(1,0,n);
		debug(n)sp,cerr<<"has been checked."<<endl;
	}
	fclose(fp);
	system("std.exe");
	cerr<<"std done."<<endl;
	system("my_std.exe");
	cerr<<"my_std done."<<endl;
	system("fc std.out my_std.out");
	return 0;
}
