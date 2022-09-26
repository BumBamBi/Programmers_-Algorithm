#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int answer = 0;

class Node{
public:
    string name;
    int w;

    Node(string name, int w){
        this->name = name;
        this->w = w;
    }
};

class compare{
public:
    bool operator()(Node a, Node b){
        return a.w < b.w;
    }
};

int main() {
    
    priority_queue<Node, vector<Node>, compare> pq;

    pq.push(Node("test1", 1));
    pq.push(Node("test2", 2));
    pq.push(Node("test3", 3));

    int qSize = pq.size();
    for (int i = 0; i < qSize ; i++)
    {
        Node temp = pq.top();
        pq.pop();
        cout << temp.name << temp.w << endl;
    }

    return answer;
}