#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

/**
Default constructor
*/
Node::Node()
{
    name="";
    text="";
};

/**
Constructor with name and html contents
*/
Node::Node(string name,string contents)
{
    this->name=name;
    this->text=contents;
}
/**
Copy constructor
*/
Node::Node(const Node& other)
{
    name=other.name;
    text=other.text;
    nodes=other.nodes;
}
/**
Assigment operator
*/
void Node::operator=(const Node& other)
{
    name=other.name;
    text=other.text;
    nodes=other.nodes;
}
/**
Build one level of the html tree for this node. Need to be called the depth of the three times to build the whole html tree
*/
void Node::build()
{
    vector<Node> nodes = nodify(text);//Generate the level
    if(nodes.size()!=0)//If there are no Nodes ( Nodes can be text only ), we have reached level after the leafs
    {
        this->nodes=nodes;
        text="";
    }
}
/**
Deletes elements by xpath
*/
void Node::erase(string xpath)
{
    eraseHelper(*this,xpath);//recursive call, starting from the root
}
/**
Helper for erase method
*/
void Node::eraseHelper(Node &node,string xpath)
{
    int index=xpath.find("/");//Find the first tag from the xpath
    string currentTag;

    bool lastTag=index>xpath.length();
    if(lastTag)
    {
        currentTag=xpath;
    }
    else
    {
        currentTag=xpath.substr(0,index);
    }
    //If we have reached the last tag, defined by the xpath and
    //we have element with the searched tag name we can delete it
    if(currentTag==node.name && lastTag)
    {
        node.text="";
        node.name="";
    }
    else//else go 1 level deeper
    {
        for(unsigned int i=0; i<node.nodes.size(); i++)
        {
            //go through each of the children of this node
            eraseHelper(node.nodes[i],xpath.substr(index+1,xpath.length()));
        }
    }
}
/**
Displays contents of all tags with the specified tagName
*/
void Node::within(string tagName)
{
    withinHelper(*this,tagName);
}
/**
Helper for the within method, travers the whole tree.
*/
void Node::withinHelper(Node &node,string tagName)
{
    if(node.name==tagName)
    {
        for(unsigned int i=0; i<node.nodes.size(); i++)
        {
            node.nodes[i].printOneLine();
            cout<<endl;
        }
    }
    for(unsigned int i=0; i<node.nodes.size(); i++)
    {
        withinHelper(node.nodes[i],tagName);
    }
}
/**
Displays all tags with the specified tagName
*/
void Node::find(string tagName)
{
    findHelper(*this,tagName);
}

/**
Helper for the find method, travers the whole tree.
*/
void Node::findHelper(Node &node,string tagName)
{
    if(node.name==tagName)
    {
        node.printOneLine();
        cout<<endl;
    }
    for(unsigned int i=0; i<node.nodes.size(); i++)
    {
        findHelper(node.nodes[i],tagName);
    }
}

/**
Takes an html string and builds the first level ot the HTML tree
Example: <html> <head>  <b> B </b></head> </html> <t> </t> will generate: Node(html,"<head>  <b> B </b></head>"), Node(t);
*/
vector<Node> Node::nodify(string text)
{
    vector<Node> nodes;// start with empty node list
    while(text.length()>0)// loop until we have traversed the whole string
    {
        Node n;
        int index = text.find('<'); // get the first opening tag
        if(index>0) // Means we have text ( not enclosed by tag ) before the first tag
        {
            //We just save it to a node
            n.name="";
            n.text=text.substr(0,index);
            text=text.substr(index,text.length());// cut the processed part from the string
        }
        // If index is greater than the string size, that means there is no such string. Thus we don't have any opening tags
        else if(index>text.length())
        {
            n.name="";
            n.text=text;
            text="";// The whole remaining string is just a text
        }
        else
        {
            int tagEndIndex = text.find('>');//Find the first closing symbol
            string tagName= text.substr(index+1,tagEndIndex-1);
            string endTag="</"+tagName+">";//The closing tag
            int endTagIndex=text.find(endTag);//Search for the closing tag
            if(endTagIndex>text.length())//There is no closing tag => this is a "free" element. Example <doctype html>
            {
                n.text="";
                n.name=text.substr(index+1,tagEndIndex-1);
                text=text.substr(tagEndIndex+1,text.length());// cut the processed part from the string
            }
            else
            {
                int contentEndIndex=text.find(endTag)-endTag.length();
                //The tag contents. From the end of the opening tag to the start of the closing tag. <tag> TAG CONTENTS </tag>
                string tagContents = text.substr(text.find('>')+1,contentEndIndex+1);
                n.text=tagContents;
                n.name=tagName;
                text=text.substr(contentEndIndex+endTag.length()*2,text.length());// cut the processed part from the string
            }
        }
        nodes.push_back(n);// Save the node
    }
    return nodes;
}

/**
Prints the whole html tree on one line
*/
void Node::printOneLine()
{
    if(name.length()>0 && name!="root")//Hide empty tags and the root tag
    {
        cout<<"<"<<name<<">";
    }
    if(text.length()>0 && name!="root")
    {
        cout<<text;
    }
    for(unsigned int i=0; i<nodes.size(); i++)
    {
        nodes[i].printOneLine();
    }
    if(name.length()>0 && name!="root")
    {
        cout<<"</"<<name<<">";
    }
}

/**
Saves the html tree to file
*/
void Node::saveToFile(ofstream &myfile)
{
    if(name.length()>0 && name!="root")//Hide empty tags and the root tag
    {
        myfile<<"<"<<name<<">"<<endl;
    }
    if(text.length()>0 && name!="root")
    {
        myfile<<text<<endl;
    }
    for(unsigned int i=0; i<nodes.size(); i++)
    {
        nodes[i].saveToFile(myfile);
    }
    if(name.length()>0 && name!="root")
    {
        myfile<<"</"<<name<<">"<<endl;
    }
}
/**
Prints the html tree formated. tab is the tab size for each tag.
*/
void Node::print(int tab)
{
    if(name.length()>0 && name!="root")//Hide empty tags and the root tag
    {
        //setfill ,specifies which character to be used as tab.
        //setw , specifies how many times the char from setfill to be outputed
        cout<<setfill(' ') << setw(tab)<<"<"<<name<<">"<<endl;
    }
    if(text.length()>0 && name!="root")
    {
        cout<<setfill(' ') << setw(tab+4)<<text<<endl;
    }
    for(unsigned int i=0; i<nodes.size(); i++)
    {
        nodes[i].print(tab+5);
    }
    if(name.length()>0 && name!="root")
    {
        cout<<setfill(' ') << setw(tab)<<"</"<<name<<">"<<endl;
    }

}
/**
Destructor
*/
Node::~Node()
{
}
