#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int r,c,i,j,x,y,a[50][50],ma,cs=1;
    //m1 and m2 store the possiblities of traversal in the 2D grid
    int m1[]={-1,0,1,1,1,0,-1,-1}; //store the possible x location traversal
    int m2[]={-1,-1,-1,0,1,1,1,0}; //stores the possible y location traversal

    char s[50][50];  //input array
    bool visited[50][50];

    queue < pair<int,int> > q; // queue to hold the coordinates of 2D array for BFS
    pair <int,int> p;

    while (scanf("%d %d",&r,&c), r!=0, c!=0) {
        memset(a,0,sizeof(a));
        memset(visited, false , sizeof(visited));

        //taking input
        for (ma=i=0;i<r;i++)
            scanf("%s",&s[i]);

        for (i=0;i<r;i++){
            for (j=0;j<c;j++){
                if (s[i][j]=='A'){
                    a[i][j]=1;
                    ma=1;
                    q.push(make_pair(i,j));
                    visited[i][j]=true;
                }
            }
        }

        // Initializing BFS & continuing till queue is empty (BFS is complete)
        while (!q.empty()){
            p=q.front();
            q.pop();
            //checking all 8 possibilities from a position
            for (i=0;i<8;i++){
                x=m1[i]+p.first;
                y=m2[i]+p.second;
                //checking if the new coordinate is within bounds and is next
                if (x>=0 && x<r && y>=0 && y<c && (s[x][y]==(1+s[p.first][p.second]))){
                    if (visited[x][y]==false){
                        a[x][y]=1+a[p.first][p.second];
                        visited[x][y]=true;
                        if (a[x][y] > ma)
                            ma=a[x][y];
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
        printf("Case %d: %d\n",cs++,ma);
    }
    return 0;
}
