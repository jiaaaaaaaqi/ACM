#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node{
    int pre[10];
    int n;
};
struct Node{
    int cnt;
    char way;
};
int numx;
Node path[380000];
int vis1[380000];
int vis2[380000];
int fac[10]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int str[10]={0};
char dir1[ ]="durl";
char dir2[ ]="udlr";

int cantuo(int a[])
{
    int ans=0;
    for(int i=0; i<9; i++)
    {
        int k=0;
        for(int j=i+1; j<9; j++)
            if(a[i]>a[j])
                k++;
        ans+=k*fac[8-i];
    }
    return ans;
}

void print(int x)
{
    if(path[x].cnt==-1)
        return ;
    print(path[x].cnt);
    printf("%c", path[x].way);
}
int judge(int x, int i)
{
    int num1=x/3;
    int num2=x%3;
    if(i==0&&(num1>1))
        return 0;
    if(i==1&&(num1<1))
        return 0;
    if(i==2&&(num2>1))
        return 0;
    if(i==3&&(num2<1))
        return 0;
    return 1;
}
void bfs()
{
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    memset(path, 0, sizeof(path));
    int a[10]={1,2,3,4,5,6,7,8,0};
    
    int count=2;
    queue<node> q1, q2;
    node p1, p2;
    for(int i=0; i<9; i++)
    {
        p1.pre[i]=str[i];
        p2.pre[i]=a[i];
    }
        
    p1.n=numx;
    p2.n=8;
    q1.push(p1);
    q2.push(p2);
    
    vis1[cantuo(str)]=1;
    vis2[cantuo(a)]=2;

    path[1].cnt=-1;
    path[2].cnt=-1;
        
    while(!q1.empty()&&!q2.empty())
    {
        node u=q1.front();
        q1.pop();
        int p=cantuo(u.pre);
        if(vis2[p])
        {
            print(vis1[p]);
            int k=vis2[p];
            while(path[k].cnt!=-1)
            {
                printf("%c", path[k].way);
                k=path[k].cnt;
            }
            printf("\n");
            return ;
        }
        else
        { 
            node u2;
            for(int i=0; i<4; i++)
            {
                u2=u;
                if (!judge(u.n, i))  
                     continue;
                int newx=u.n/3+dis[i][0];
                int newy=u.n%3+dis[i][1];
                u2.n=newx*3+newy;
                u2.pre[u.n]=u2.pre[u2.n];
                u2.pre[u2.n]=0;
                int v=cantuo(u2.pre);
                if(vis1[v])
                    continue;
                vis1[v]=++count;
                path[count].way=dir1[i];
                path[count].cnt=vis1[p];
                q1.push(u2);
            }
        }
        
        u=q2.front();
        q2.pop();
        p=cantuo(u.pre);
        if(vis1[p])
        {
            print(vis1[p]);
            int k=vis2[p];
            while(path[k].cnt!=-1)
            {
                printf("%c", path[k].way);
                k=path[k].cnt;
            }
            printf("\n");
            return ;
        }
        else
        {
            node u2;
            for(int i=0; i<4; i++)
            {
                u2=u;
                if (!judge(u.n, i))  
                     continue;
                int newx=u.n/3+dis[i][0];
                int newy=u.n%3+dis[i][1];
                u2.n=3*newx+newy;
                u2.pre[u.n]=u2.pre[u2.n];
                u2.pre[u2.n]=0;
                int v=cantuo(u2.pre);
                if(vis2[v])
                    continue;
                vis2[v]=++count;
                path[count].way=dir2[i];
                path[count].cnt=vis2[p];
                q2.push(u2);
            }
        }
    }
    printf("unsolvable\n");
}

int main()
{
    char prestr[30]={0};
    while(gets(prestr)!=NULL)
    {
        int j;
        for(int i=0,j=0; prestr[i]!='\0'; i++)
        {
            if(prestr[i]=='x')
            {
                numx=j;
                str[j]=0;
            }
            else if(prestr[i]==' ')
                continue;
            else
                str[j]= prestr[i]-'0';
            j++;
        }
        str[j]='\0';
        int num=0;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(str[j]<str[i])
                    num++;
            } 
        }
        if(num&1)
            printf("unsolvable\n");
        else
            bfs();
    }
    return 0;
} 