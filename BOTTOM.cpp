#include <bits/stdc++.h>
using namespace std;
int visited[5010];
int color[5010];
int val[5010];
vector < pair<int,int> > ed;
vector <int> g[5010];
vector <int> gr[5010];
stack <int> st;

void dfs1(int u)
{
    int i;
    if (visited[u]==1)
        return;
    visited[u]=1;
    for (i=0;i<g[u].size();i++){
        int v=g[u][i];
        if (visited[v]==0)
            dfs1(v);
    }
    st.push(u);
}


void dfs2(int u,int col)
{
    int i;
    if (visited[u]==1)
        return;
    visited[u]=1;
    color[u]=col;
    for (i=0;i<gr[u].size();i++){
        int v=gr[u][i];
        if (visited[v]==0)
            dfs2(v,col);
    }
}

void func()
{
    int i;
    for (i=0;i<ed.size();i++){
        int x=ed[i].first;
        int y=ed[i].second;
        if (color[x]!=color[y]){
           // cout<<"*";
            val[color[x]]=0;
        }
    }
}


int main ()
{
    //freopen("input.txt","r",stdin);
    while (1){
        int v,e,i;
        scanf("%d %d",&v,&e);
        if (v==0)
            break;
        memset(visited,0,sizeof(visited));
        memset(color,0,sizeof(color));
        //memset(yes,0,sizeof(yes));
        memset(val,0,sizeof(val));
        ed.clear();
        for (i=0;i<=v;i++){
            g[i].clear();
            gr[i].clear();
        }
        while (!st.empty())
            st.pop();

        for (i=0;i<e;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            ed.push_back(make_pair(x,y));
            g[x].push_back(y);
            gr[y].push_back(x);
        }

        for (i=1;i<=v;i++){
            if (visited[i]==0)
                dfs1(i);
        }

        memset(visited,0,sizeof(visited));
        int cow=1;


        while (!st.empty()){
            int po=st.top();
            st.pop();
            if (visited[po]==0)
                dfs2(po,cow);
            val[cow]=1;
            cow++;
        }

        func();
        for (i=1;i<=v;i++){
            if (val[color[i]]==1)
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
