#ifndef __INPUT_H__
#define	__INPUT_H__

#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <sys/wait.h>

#include "BaseNode.h"
class baseNode;


class Input {
    protected: 
        std::string userInput; 
        std::vector<baseNode*> parsedNode; // this vector holds the parsed baseExec objects with arg
        std::vector<std::vector<std::string> > parsedNoSpace; // this vector holds the parsed string w/o spaces
        std::vector<std::string> parsedStrings; // these two vectors are just to help in storing 
        std::vector<Connector* > connectors;    // the data to create the executable tree
        baseNode* head; // pointer to top of executable tree

        // ADDITION FOR ASSIGNMENT 3
        std::vector<std::string> parenthesis;

        // ADDITION FOR ASSIGNMENT 4
        //std::vector<std::string> PreIORedirect; // vector that holds the substrings that contain IOredirect
        std::vector<baseNode*> IORedirect; // vector that holds baseNode* objects that will be later used to create executables during makeExec
    
    public:
		Input();
        ~Input();
        Input(std::string userString);
        void clearInput();
        void removeComment();

        std::vector<baseNode* > returnParsedNode();
        std::vector<std::vector <std::string> > returnParsedNoSpace();
        std::string returnStrings();
        std::vector<Connector* > returnConnectors();
        baseNode* returnHead();

		void runInput();
        // ****** NEW ADDITIONS FOR ASSN3 ******//
        std::vector<std::string> parsePar(std::string &userString);
        void parseTest(std::string &userString);
        // ****** NEW ADDITIONS FOR ASSN3 ******//
        
        // ****** NEW ADDITIONS FOR ASSN4 ******//
        void makeIOTree(std::string containsRedirect);
        void parseIO(std::string &userString);
        std::string containsRedirect;        
        void parsePipe(std::string &userString);
        void parseOCon(std::string &userString);
        std::vector<Connector* > parseIOConnector(std::string containsRedirect);
        // ****** NEW ADDITIONS FOR ASSN4 ******//
        void parseInput();
        std::vector<std::string>parseOutConnectors(std::string withConnectors);
        std::vector<std::string> parseSpaces(std::string withSpaces); // helper function to remove spaces from withSpaces input
        void parseConnectors();
        baseNode* makeNode(std::vector<std::string> exec); // instantiates baseExec objects and arglist pointer

        void makeExecutableTree(); // instantiates baseExec tree with connectors
        void callExecute(); //executes on top head node of the tree, execute function should go down tree 
        std::string returnUser();
        std::string returnHost();
};


#endif



