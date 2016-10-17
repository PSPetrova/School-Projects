#include "NodeList.h"

NodeList::NodeList()
{
    head=NULL;
};
NodeList::NodeList(const NodeList& other)
{
    head=NULL;
    Node* c=other.head;

    while(c!=NULL)
    {
        push(*c);
        c=c->next;
    }
};
void NodeList::operator=(const NodeList& other)
{
    head=NULL;
    Node* c=other.head;

    while(c!=NULL)
    {
        push(*c);
        c=c->next;
    }
};
void NodeList::push(const Node& node)
{

    if(head!=NULL)
    {

        Node* current=head;

        while(current->next!=NULL)
        {
            current=current->next;
        }

        current->next=new Node(node);
        current->next->next=NULL;
    }
    else
    {
        head=new Node(node.name,node.text);
        head->next=NULL;

    }
};
void NodeList::print()
{
    Node* current=head;
    while(current!=NULL)
    {
        cout<<current->name<<" "<<current->text<<endl;
        current=current->next;
    }
}
int NodeList::size()
{
    int size=0;
    Node* current=head;
    while(current!=NULL)
    {
        current=current->next;
        size++;
    }
    return size;
}
Node& NodeList::operator[](int index)
{
    Node* current=head;

    for(int i=0; i<=index; i++)
    {
        current=current->next;

    }
    return *current;
}
void NodeList::remove(int index) {};
NodeList::~NodeList() {};
