#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    Node();
    Node(const Node& other);
    Node(string name,string contents);
    void operator=(const Node& other);
    void build();
    void saveToFile(ofstream& infile);
    void erase(string xpath);
    void eraseHelper(Node &node,string xpath);
    void within(string tagName);
    void withinHelper(Node &node,string tagName);
    void find(string tagName);
    void findHelper(Node &node,string tagName);
    vector<Node> nodify(string text);
    void printOneLine();
    void print(int tab);
    ~Node();

    /**
    Build one level for all the available nodes, under this one
    */
    friend void buildNode(Node& node)
    {
        if(node.name.length()==0 && node.text.length()==0)
        {
            return;
        }
        if(node.text.length()>0)
        {
            node.build();
        }
        else
        {
            for(unsigned int i=0; i<node.nodes.size(); i++)
            {
                buildNode(node.nodes[i]);
            }
        }
    }

    string name;
    string text;
    vector<Node> nodes;
};

#endif // NODE_H
