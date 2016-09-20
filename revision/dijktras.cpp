#include<bits/stdc++.h>
using namespace std;
int gr[1000][1000];
int mindist(int a[],int v,bool visited[])
{
	int indx;
	int dist=INT_MAX;;
	for(int i=0;i<v;i++)
	{
		if(a[i]<dist && !visited[i])
		{
			indx=i;
			dist=a[i];
		}
	}
	return indx;
}
void func(int v,int strt)
{
	//memset(gr,0,sizeof(gr));
	bool visited[v];
	int dist[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		dist[i]=INT_MAX;

	}
	dist[strt]=0;
	for(int i=0;i<v;i++)
	{
		int d=mindist(dist,v,visited);
		visited[d]=true;
		for(int j=0;j<v;j++)
		{
			if((dist[j]>(dist[d]+gr[d][j])) && (!visited[j]) && (gr[d][j]!=-1))
			{
				dist[j]=dist[d]+gr[d][j];
			}
		}
	}

	cout<<"the distance of start vertex from all the nodes are :-\n";
	for(int i=0;i<v;i++)
		cout<<dist[i]<<" ";
	cout<<"\n";


}
int main()
{
	int v,strt;
	cin>>v>>strt;
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			cin>>gr[i][j];
	func(v,strt);
}

/*
 * TEST CASE OF EXAMPLE GIVEN IN RAHUL CLASES REFER THAT FOR DIAGRAM
 * 5 0
-1 5 3 -1 -1
5 -1 1 3 -1
3 1 -1 6 2
-1 3 6 -1 1
-1 -1 2 1 -1
 */
