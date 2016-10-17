#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Node.h>
using namespace std;
/**
Third party libraries.

- String  -> used for stirng manipulations. (substring,'==','=',find)
- Vector  -> used to store the html tree nodes. (push,delete,'[]')
- fstream -> for File I/O
- iostream and iomanip - used for std out stream manipulations. (cout,cin,setfill,setw)
*/



/**
Returns builded ,from the html contents defined by the path to the file, Node
*/
Node loadFile(const char* path)
{
    ifstream infile(path);
    string content;

    char c;
    while(infile >> c)
    {
        if(c!='\n')
        {
            content+=c;
        }

    }
    infile.close();
    Node n("root",content);//root is ignored in print erase etc.
    for(int i=0; i<500; i++)
    {
        buildNode(n);
    }
    return n;

}

int main()
{
    string command;// to store the command
    string fileSourceName;// to store the last opened file
    Node n;

    /*Program will run an wait for input args
    - Enter command until exit is typed.
    - open <path to file> - will load html contents from the spesified file
    - save - saves the current html into the file
    - print -displays formated html
    - erase <xpath> - example html/body/b will delete all b tags under html-body
    - find <tag name> - displays all tags with the specified name
    - within <tag name> - displays the contents of all tags with the specified name
    */
    while(command!="exit")
    {
        getline(cin, command);
        string firstWord=command.substr(0,command.find(" "));// Get the first word, this is the command
        if(firstWord=="open")
        {
            command=command.substr(command.find(' ')+1,command.length());
            n=loadFile(command.c_str());
            cout<<"Successfully opened "<<command.c_str()<<endl;
            fileSourceName=command;
            command="";
        }
        else if(firstWord=="save")
        {
            ofstream outfile;
            outfile.open(fileSourceName.c_str());
            n.saveToFile(outfile);
            outfile.close();
        }
        else if(firstWord=="print")
        {
            n.print(2);
        }
        else if(firstWord=="erase")
        {
            command=command.substr(command.find(' ')+1,command.length());//we expekt a second arg
            n.erase(command);
        }
        else if(firstWord=="find")
        {
            command=command.substr(command.find(' ')+1,command.length());//we expekt a second arg
            n.find(command);
        }
        else if(firstWord=="within")
        {
            command=command.substr(command.find(' ')+1,command.length());//we expekt a second arg
            n.within(command);
        }



    }
    return 0;
}
