#include<bits/stdc++.h>
using namespace std;
int gr[1000][1000];
int mindist(bool visited[],int dist[],int v)
{
	int d=INT_MAX;
	int indx;
	for(int i=0;i<v;i++)
	{
		if(!visited[i] && dist[i]<d)
		{
			d=dist[i];
			indx=i;
		}
	}
	return indx;
}
void f(int v,int strt)
{
	bool visited[v];
	int dist[v];
	int parent[v];
	for(int i=0;i<v;i++)visited[i]=0;
	for(int i=0;i<v;i++)dist[i]=INT_MAX;

	dist[strt]=0;
	parent[strt]=-1;
	for(int i=0;i<v;i++)
	{
		int d=mindist(visited,dist,v);
		visited[d]=true;
		for(int j=0;j<v;j++)
		{
			if(gr[d][j]!=-1 && !visited[j] && dist[j]>gr[d][j])
			{
				dist[j]=gr[d][j];
				parent[j]=d;
			}
		}
	}

	for(int i=0;i<v;i++)
	{
		cout<<parent[i]<<"---------->"<<i<<"="<<dist[i]<<"\n";
	}


}
int main()
{
	memset(gr,-1,sizeof(gr));
	cout<<"enter the no of vertex and edges\n";
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		int v1,v2,w;
		cout<<"enter the vertex which have edge and weight\n";
		cin>>v1>>v2>>w;
		gr[v1][v2]=w;
		gr[v2][v1]=w;
	}
	cout<<"enter the start vertex\n";
	int strt;
	cin>>strt;
	f(v,strt);

}
/*
refer geeks for geeks example as test case for verification */