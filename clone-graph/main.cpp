#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    void delete_graph(Node* node)
    {
        if (!node)
            return;
        set<Node*> visited;
        queue<Node*> node_queue;
        node_queue.push(node);
        visited.insert(node);
        while (!node_queue.empty())
        {
            Node* current = node_queue.front();
            node_queue.pop();

            for (Node* neighbor: current->neighbors)
            {
                if (neighbor && visited.find(neighbor) == visited.end())
                {
                    node_queue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
            delete current;
        }
    }

    /**
     * Prints graph nodes of a connected node using BFS.
     */
    void print_graph(Node* node)
    {
        if (!node)
            return;
        set<Node*> visited;
        queue<Node*> node_queue;
        node_queue.push(node);
        visited.insert(node);
        while (!node_queue.empty())
        {
            Node* current = node_queue.front();
            node_queue.pop();

            cout << "Node " << current->val << "; address: " << current << endl;
            for (Node* neighbor: current->neighbors)
            {
                if (neighbor && visited.find(neighbor) == visited.end())
                {
                    node_queue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
    
    Node* cloneGraph(Node* node)
    {
        if (!node)
            return NULL;

        unordered_map<Node*, Node*> node_map; // first node is the original node, second one is it's clone
        queue<Node*> node_queue;

        // cloning the source node
        Node* new_node = new Node(node->val);

        node_map[node] = new_node;
        node_queue.push(node);

        while (!node_queue.empty())
        {
            Node* current = node_queue.front();
            node_queue.pop();

            vector<Node*>& v = current->neighbors;
            for (int i = 0; i < (int)v.size(); ++i)
            {
                if (node_map[v[i]] == NULL)
                {
                    new_node = new Node(v[i]->val);
                    new_node->neighbors.reserve(2); // at least two reserved fields for the neighbors
                    node_map[v[i]] = new_node;
                    node_queue.push(v[i]);
                }
                node_map[current]->neighbors.push_back(node_map[v[i]]);
            }
        }
        return node_map[node];
    }
};

int main()
{
    Node* node_1 = new Node(1);
    Node* node_2 = new Node(2);
    Node* node_3 = new Node(3);
    Node* node_4 = new Node(4);

    node_1->neighbors.reserve(2);
    node_2->neighbors.reserve(2);
    node_3->neighbors.reserve(2);
    node_4->neighbors.reserve(2);

    node_1->neighbors.push_back(node_2);
    node_1->neighbors.push_back(node_4);

    node_2->neighbors.push_back(node_1);
    node_2->neighbors.push_back(node_3);

    node_3->neighbors.push_back(node_2);
    node_3->neighbors.push_back(node_4);

    node_4->neighbors.push_back(node_1);
    node_4->neighbors.push_back(node_3);

    Solution sol;
    sol.print_graph(node_1);

    Node* clone = sol.cloneGraph(node_1);
    sol.print_graph(clone);

    sol.delete_graph(node_1);
    sol.delete_graph(clone);
    
    return 0;
}
