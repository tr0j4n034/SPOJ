#include<bits/stdc++.h>
using namespace std;
#define N 30001
struct t
{
    int open,close;
}
tree[4*N+1];
char a[N];
void build(int node,int start,int end)
{
    if(start==end)
    {
        if(a[start-1]=='(')
            tree[node].open=1,tree[node].close=0;
        else
            tree[node].close=1,tree[node].open=0;
        return;
    }
    else
    {
        int mid=start+((end-start)>>1);
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        int w=min(tree[2*node].open,tree[2*node+1].close);
        tree[node].open=tree[2*node].open-w+tree[2*node+1].open;
        tree[node].close=tree[2*node].close-w+tree[2*node+1].close;
    }
}
void que(int node,int start,int end)
{
    if(!tree[node].open && !tree[node].close)
        printf("YES\n");
    else
        printf("NO\n");
}
void update(int node,int start,int end,int ind)
{
    if(start==end)
    {
        if(tree[node].open==1)
            tree[node].close=1,tree[node].open=0;
        else
            tree[node].close=0,tree[node].open=1;
        return;
    }
    int mid=start+((end-start)>>1);
    if(ind<=mid)
        update(2*node,start,mid,ind);
    else
        update(2*node+1,mid+1,end,ind);
    int w=min(tree[2*node].open,tree[2*node+1].close);
    tree[node].open=tree[2*node].open-w+tree[2*node+1].open;
    tree[node].close=tree[2*node].close-w+tree[2*node+1].close;
}
int main()
{
    int n,q,k,t=1;
    while(scanf("%d",&n)==1)
    {
        scanf("%s",a);
        scanf("%d",&q);
        build(1,1,n);
        printf("Test %d:\n",t++);
        while(q--)
        {
            scanf("%d",&k);
            if(!k)
                que(1,1,n);
            else
                update(1,1,n,k);
        }
    }
}
