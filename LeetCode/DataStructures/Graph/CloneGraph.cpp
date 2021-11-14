#include <stack>
#include <unordered_map>

#include "Node.h"

using namespace std;



// Problem: https://leetcode.com/problems/clone-graph/
Node* CloneGraph_Recursive(Node* node, unordered_map<Node*, Node*>& cloned);

Node* CloneGraph_Recursive(Node* node)
{
    if (!node)
        return nullptr;

    unordered_map<Node*, Node*> cloned;
    return CloneGraph_Recursive(node, cloned);
}

Node* CloneGraph_Recursive(Node* node, unordered_map<Node*, Node*>& cloned)
{
    Node* clone{ new Node{node->val} };
    cloned[node] = clone;
    for (Node* neighbor : node->neighbors)
    {
        if (!cloned.count(neighbor))
            cloned[neighbor] = CloneGraph_Recursive(neighbor, cloned);

        clone->neighbors.push_back(cloned[neighbor]);
    }

    return clone;
}



Node* CloneGraph_Iterative(Node* node)
{
    if (!node)
        return nullptr;

    unordered_map<int, Node*> original;
    unordered_map<int, Node*> cloned;

    stack<Node*> s;
    s.push(node);
    while (!s.empty())
    {
        Node* org_p = s.top();
        s.pop();
        if (!cloned.count(org_p->val))
        {
            original[org_p->val] = org_p;
            cloned[org_p->val] = new Node(org_p->val);
        }

        for (const auto org_n : org_p->neighbors)
        {
            if (!cloned.count(org_n->val))
                s.push(org_n);
        }
    }


    for (auto& org : original)
    {
        Node* op = original[org.first];
        Node* cp = cloned[org.first];

        for (auto org_n : op->neighbors)
        {
            Node* cn = cloned[org_n->val];
            cp->neighbors.push_back(cn);
        }
    }

    return cloned[node->val];
}
