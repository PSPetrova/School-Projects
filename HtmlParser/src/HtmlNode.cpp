#include "HtmlNode.h"
#include<iostream>
#include <iomanip>
#include<string>
using namespace std;

HtmlNode::HtmlNode()
{
    name="";
    text="";
}
HtmlNode::HtmlNode(const HtmlNode &other)
{

}

HtmlNode::HtmlNode(string name,string contents)
{
    this->name=name;
    this->text=contents;
}

void HtmlNode::operator=(const HtmlNode &other)
{
}

void HtmlNode::build()
{
    nodify(text);
    if(nodes.size()!=0)
    {
        text="";
    }
}
void HtmlNode::buildNode()
{
    cout<<"This "<<name<<endl;
    buildNodeHelper(*this);
}
void HtmlNode::buildNodeHelper(HtmlNode& node)
{
    if(node.name.length()==0 && node.text.length()==0 && node.nodes.size()==0)
    {
        //cout<<"Here"<<endl;
        return;
    }
    if(node.text.length()>0)
    {
        node.build();
    }
    else
    {
        for(int i=0; i<node.nodes.size(); i++)
        {
            buildNodeHelper(node.nodes[i]);
        }
    }
}
void HtmlNode::erase(string xpath)
{
    eraseHelper(*this,xpath);
}
void HtmlNode::eraseHelper(HtmlNode &node,string xpath)
{
    int index=xpath.find("/");
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
    if(currentTag==node.name && lastTag)
    {
        node.text="";
        node.name="";
    }
    else
    {
        for(int i=0; i<node.nodes.size(); i++)
        {
            eraseHelper(node.nodes[i],xpath.substr(index+1,xpath.length()));
        }
    }
}
void HtmlNode::within(string tagName)
{
    withinHelper(*this,tagName);
}
void HtmlNode::withinHelper(HtmlNode &node,string tagName)
{
    if(node.name==tagName)
    {
        //node.printOneLine();
        for(int i=0; i<node.nodes.size(); i++)
        {
            node.nodes[i].printOneLine();
            cout<<endl;
        }
    }
    for(int i=0; i<node.nodes.size(); i++)
    {
        withinHelper(node.nodes[i],tagName);
    }
}
void HtmlNode::find(string tagName)
{
    findHelper(*this,tagName);
}

void HtmlNode::findHelper(HtmlNode &node,string tagName)
{
    if(node.name==tagName)
    {
        node.printOneLine();
        cout<<endl;
    }
    for(int i=0; i<node.nodes.size(); i++)
    {
        findHelper(node.nodes[i],tagName);
    }
}

void HtmlNode::nodify(string text)
{

    while(text.length()>0)
    {
        HtmlNode n;
        int index = text.find('<');
        if(index>0)
        {

            n.name="";
            n.text=text.substr(0,index);
            text=text.substr(index,text.length());
        }
        else if(index>text.length())
        {
            n.name="";
            n.text=text;
            text="";
        }
        else
        {
            int tagEndIndex = text.find('>');
            string tagName= text.substr(index+1,tagEndIndex-1);
            string endTag="</"+tagName+">";
            int endTagIndex=text.find(endTag);
            if(endTagIndex>text.length())
            {

                n.text="";
                n.name=text.substr(index+1,tagEndIndex-1);
                text=text.substr(tagEndIndex+1,text.length());
            }
            else
            {
                int contentEndIndex=text.find(endTag)-endTag.length();
                string tagContents = text.substr(text.find('>')+1,contentEndIndex+1);
                n.text=tagContents;
                n.name=tagName;
                text=text.substr(contentEndIndex+endTag.length()*2,text.length());
            }
        }
        cout<<"Adding "<<n.name<<" with text "<<n.text<<endl;
        nodes.push_back(n);
    }
}


void HtmlNode::printOneLine()
{
    if(name.length()>0 && name!="root")
    {
        cout<<"<"<<name<<">";
    }
    if(text.length()>0 && name!="root")
    {
        cout<<text;
    }
    for(int i=0; i<nodes.size(); i++)
    {
        nodes[i].printOneLine();
    }
    if(name.length()>0 && name!="root")
    {
        cout<<"</"<<name<<">";
    }
}


void HtmlNode::print(int tab)
{
    if(name.length()>0 && name!="root")
    {
        cout<<setfill(' ') << setw(tab)<<"<"<<name<<">"<<endl;
    }
    if(text.length()>0 && name!="root")
    {
        cout<<setfill(' ') << setw(tab+4)<<text<<endl;
    }
    for(int i=0; i<nodes.size(); i++)
    {
        nodes[i].print(tab+5);
    }
    if(name.length()>0 && name!="root")
    {
        cout<<setfill(' ') << setw(tab)<<"</"<<name<<">"<<endl;
    }

}
HtmlNode::~HtmlNode()
{
}
