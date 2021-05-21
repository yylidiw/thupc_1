#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io
{
	int F()
	{
		int n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
	long long G()
	{
		long long n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
}
int R(int l,int r)
{
    return rand()%(r-l+1)+l;
}
int Abs(int x)
{
    return x>0?x:-x;
}
int P;
struct po
{
    int x,y;
    int dis()
    {
        int tmp=0;
        cmax(tmp,Abs(x));
        cmax(tmp,Abs(y));
        cmax(tmp,Abs(x+y));
        return tmp;
    }
};
po operator +(const po& x,const po& y)
{
    return (po){(x.x+y.x)%P,(x.y+y.y)%P};
}
po operator -(const po& x,const po& y)
{
    return (po){(P+x.x-y.x)%P,(P+x.y-y.y)%P};
}
po operator -(const po& y)
{
    return (po){P-y.x,P-y.y};
}
po Rpo(int p)
{
    return (po){R(0,p-1),R(0,p-1)};
}
const po d[6]={{-1,1},{-1,0},{0,-1},{1,-1},{1,0},{0,1}};
struct it
{
    po f[6];
}a[111];
int main()
{
	char s[111];
    int ta=1;
    while(1)
    {
        sprintf(s,"D:/OI/thupc_1/day0/F/data/%d.in",ta);
        FILE *p=fopen(s,"r");
        if(p)
        {
            fclose(p);
            ++ta;
        }
        else break;
    }
    freopen(s,"w",stdout);
    int n=100,p=100;
    P=p;
    printf("%d %d\n",n,p);
    srand(time(0));
    po fixed=(po){0,0},target=(po){0,0};
    po pos=(po){0,0};
    po ex=Rpo(p),ey=Rpo(p);
    po ed[6]={ey-ex,-ex,-ey,ex-ey,ex,ey};
    po key=(po){0,23};
    int Dir[111];
    for(int i=n;i;--i)
    {
        po fi=Rpo(p);   
        for(int j=0;j<6;++j)
            a[i].f[j]=ed[j]+fi;
        fixed=fixed+fi;
    }
    int vis[111]={0};
    int left=n;
    for(int i=1;i<=p/2-2;++i)
    {
        int x;
        do x=R(1,n); while(vis[x]);
        vis[x]=1;
        int dir=R(0,5);
        pos.x+=d[dir].x;
        pos.y+=d[dir].y;
        a[x].f[dir]=a[x].f[dir]+key;
        Dir[x]=dir;
        --left;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<6;++j)
        {
            int xx=R(0,p-1);
            int yy=R(0,1)*p/2;
            a[i].f[j]=a[i].f[j]+(po){xx,yy};
        }
        if(!vis[i])
        {
            --left;
            int dir=R(0,5);
            while(1)
            {
                po to=pos;
                to.x+=d[dir].x;
                to.y+=d[dir].y;
                if(to.dis()<=left)
                    break;
                dir=R(0,5);
            }
            pos.x+=d[dir].x;
            pos.y+=d[dir].y;
            Dir[i]=dir;
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=0;j<6;++j)
            printf("%d %d%c",a[i].f[j].x,a[i].f[j].y," \n"[j==5]);
    for(int i=1;i<=n;++i)
        target=target+a[i].f[Dir[i]];
    target=target+key;
    printf("%d %d\n",target.x,target.y);
	return 0;
}