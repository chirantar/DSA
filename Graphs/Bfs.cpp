#include<bits/stdc++.h>

using namespace std;

void addEdge(vector< pair<int, int> >* graph, int u, int v, int wt)
{
	graph[u].push_back(make_pair(v, wt));
	graph[v].push_back(make_pair(u, wt));
}

void BFSWorker(vector< pair<int, int> > *graph, int v, bool* visited)
{
	queue <int> q;
	q.push(v);
	visited[v] = true;
	while(q.empty() == false)
	{
		v = q.front();
		q.pop();
		cout<<v<<", ";
		pair<int, int> temp;
		vector<pair<int, int> >::iterator it;
		for(it = graph[v].begin(); it!=graph[v].end(); ++it)
		{
			temp = *it;
			if(visited[temp.first] == false)
			{
				q.push(temp.first);
				visited[temp.first] = true;
			}
		}
	}
}

void BFS(vector< pair<int , int> >* graph, int startingNode)
{
	int v= graph->size();
	bool *visited = new bool[v];
	for(int i=0; i<v; i++)
	{
		visited[i] = false;
	}
	BFSWorker(graph, startingNode, visited);
}
int main()
{
	freopen("graphData.txt", "r", stdin);
	int n, v;
	cin>>n>>v;
	vector< pair<int, int> > graph[v];
	while(n--)
	{
		int a, b, wt;
		cin>>a>>b>>wt;
		addEdge(graph, a, b, wt);
	}
	BFS(graph, 2);
	return 0;
}
