#include<bits/stdc++.h>
using namespace std;
int gr[1000][1000];
bool bipartite(int v,int src)
{
	int color[v];
	memset(color,-1,sizeof(color));

	queue<int>q;
	q.push(src);
	color[src]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int j=0;j<v;j++)
		{
			if(  gr[u][j] && color[j]==-1)
			{
				color[j]=1-color[u];
				q.push(j);
			}
			else if(gr[u][j] && color[j]==color[u])
				return false;
		}
	}
	return true;
}
int main()
{
	memset(gr,0,sizeof(gr));
	int v,e;
	cout<<"enter the number of edges and vertex\n";
	cin>>e>>v;
	for(int i=0;i<e;i++)
	{
		int a,b,w;
		cin>>a>>b;
		gr[a][b]=1;
		gr[b][a]=1;
	}
	int src;
	cout<<"enter the starting vertex\n";
	cin>>src;
	cout<<bipartite(v,src);


}
