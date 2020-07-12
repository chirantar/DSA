#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class GraphNode{
public:
    int data;
    vector<GraphNode* > adjList;
};

/*
    1--2--5
    |  |
    4--3
*/
GraphNode* buildNode(){

    GraphNode* node1 = new GraphNode();
    node1->data = 1;

    GraphNode* node2 = new GraphNode();
    node2->data = 2;

    GraphNode* node3 = new GraphNode();
    node3->data = 3;

    GraphNode* node4 = new GraphNode();
    node4->data = 4;

    GraphNode * node5 = new GraphNode();
    node5->data = 5;

    vector<GraphNode*> v;

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

void DFSIterative(GraphNode* src){

    map<GraphNode*, bool> visited;
    stack<GraphNode*> s;

    s.push(src);
    visited[src] = true;

    while(!s.empty()){
        GraphNode* node = s.top();
        s.pop();
        cout<<node->data<<", ";

        for(int i = 0; i < node->adjList.size(); i++){
            if (!visited[node->adjList[i]]){
                visited[node->adjList[i]] = true;
                s.push(node->adjList[i]);
            }
        }
    }
    cout<<endl;
}

int main(){

    GraphNode* src = buildNode();
    DFSIterative(src);
    return 0;
}
