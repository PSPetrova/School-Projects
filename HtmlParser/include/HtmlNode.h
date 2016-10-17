#ifndef HTMLNODE_H
#define HTMLNODE_H
#include<string>
#include<vector>
using namespace std;
class HtmlNode
{
public:
    HtmlNode();
    HtmlNode(const HtmlNode&);
    void operator=(const HtmlNode&);
    HtmlNode(string name,string contents);
    void print(int tab);
    void printOneLine();
    void nodify(string text);
    void buildNode();
    void find(string tagName);
    void within(string tagName);
    void erase(string xpath);
    void build();



    virtual ~HtmlNode();


    string name;
    string text;
    vector<HtmlNode> nodes;

private:
    void findHelper(HtmlNode &node,string tagName);
    void withinHelper(HtmlNode &node,string tagName);
    void eraseHelper(HtmlNode &node,string xpath);
    void buildNodeHelper(HtmlNode &node);
};

#endif // HTMLNODE_H
