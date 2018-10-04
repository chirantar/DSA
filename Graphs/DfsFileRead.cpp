#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int, int> > *graph,int v, int u, int wt)
{
	graph[v].push_back(make_pair(u, wt));
	graph[u].push_back(make_pair(v, wt));
}
void DFSWorker(vector<pair<int, int> > *graph, bool * visited, int v)
{
	visited[v] = true;
	cout<<v<<endl;
	pair<int , int> p;
	vector<pair<int, int> >::iterator it;
	for(it = graph[v].begin();it!=graph[v].end();++it)
	{
		p=*it;
		if(visited[p.first] == false)
		{
			DFSWorker(graph, visited, p.first);
		}
	}
}
void DFS(vector<pair<int, int> > *graph, int startingNode)
{
	int v = graph->size();
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
        visited[i] = false;
	}
	DFSWorker(graph, visited, startingNode);
}
int main()
{
	int n,v,u;
	freopen("graphData.txt", "r", stdin);
	cin>>n>>v;
	vector<pair<int, int> > graph[v];
	for(int i=1;i<=n;i++)
	{
		int v_no, u_no,wt;
		cin>>v_no>>u_no>>wt;
		addEdge(graph, v_no, u_no, wt);
	}
	DFS(graph, 2);
	return 0;
}
