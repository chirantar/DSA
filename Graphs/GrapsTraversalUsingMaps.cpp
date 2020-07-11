#include <bits/stdc++.h>

using namespace std;
class Graph{
    public:
        int data;
        vector<Graph *> adjList;
};
/*
    1--2--5
    |  |
    4--3
*/
Graph* buildNode(){
    Graph* node1 = new Graph();
    node1->data = 1;

    Graph* node2 = new Graph();
    node2->data = 2;

    Graph* node3 = new Graph();
    node3->data = 3;

    Graph* node4 = new Graph();
    node4->data = 4;

    Graph * node5 = new Graph();
    node5->data = 5;

    vector<Graph*> v;

    v.push_back(node2);
    v.push_back(node4);
    node1->adjList = v;

    v.clear();

    v.push_back(node1);
    v.push_back(node3);
    v.push_back(node5);

    node2->adjList = v;

    v.clear();

    v.push_back(node2);
    v.push_back(node4);

    node3->adjList = v;
    v.clear();

    v.push_back(node1);
    v.push_back(node3);
    node4->adjList = v;
    v.clear();

    v.push_back(node2);

    node5->adjList = v;

    return node1;

}

void bfs(Graph* src){

    map<Graph*, bool> visited;
    queue<Graph*> q;

    visited[src] = true;
    q.push(src);

    while(!q.empty()){
        Graph * node = q.front();
        cout<<node->data<<", ";

        q.pop();

        for(int i = 0; i < node->adjList.size(); i++)
        {
            if (!visited[node->adjList[i]]){
                visited[node->adjList[i]] = true;
                q.push(node->adjList[i]);
            }
        }
    }

    cout<<endl;
}
map<Graph*, bool> visited;

void dfsTraversal(Graph *src)
{

        //cout<<"isVisited ="<<visited[src]<<endl;
        visited[src] = true;

        cout<<src->data<<", ";
        for(int i = 0; i < src->adjList.size(); i++)
        {
            if (!visited[src->adjList[i]])
                dfsTraversal(src->adjList[i]);
        }
}

void dfs(Graph* src)
{

    dfsTraversal(src);
    cout<<endl;
}
int main(){

    Graph *src = buildNode();
    cout<<"BFS"<<endl;
    bfs(src);
    cout<<"DFS"<<endl;
    dfs(src);

    return 0;
}
