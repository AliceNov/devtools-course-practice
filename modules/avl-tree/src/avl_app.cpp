// Copyright 2018 Tarakanov Kirill

#include "include/avl_app.h"
#include "include/avl_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

AVL_App::AVL_App() : message_("") {}

void AVL_App::help(const char* appname, const char* message) {
    message_ = message_ +
    std::string(message) +
    "This is a AVL_Tree application.\n\n";
    message_ =  message_ +"To make the AVL_Tree put argumets" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + "\n<count of nodes> <first_key> , <second_key> " +
    "<third_key> and e.t.c.\n\n";

    message_ = message_ + "While all arguments numbers type of int, " +
    "AVL Tree makes right \n" +
    "Then put one of the operation:\n" +
    "1) + - Add node in tree, put key then\n" +
    "2) - - Remove node from tree put key then\n" +
    "3) fmin - Find node with min key in tree\n" +
    "4) min- -  Remove node with min key tree\n" +
    "5) search - Search node in treeput key then\n" +
    "example: 3 4 5 2 fmin\n";
}

bool AVL_App::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc <= 4) {
        help(argv[0], "ERROR: Should be more then 4 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = atoi(arg);

    if (value == 0) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int parseOperation(const char* arg) {
    int op;
    if (strcmp(arg, "+") == 0) {
        op = 0;
    } else if (strcmp(arg, "-") == 0) {
        op = 1;
    } else if (strcmp(arg, "fmin") == 0) {
        op = 2;
    } else if (strcmp(arg, "min-") == 0) {
        op = 3;
    } else if (strcmp(arg, "search") == 0) {
        op = 4;
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

void Show(AVLNode *node, std::string *str) {
    if (node == NULL) {
        return;
    }
    Show(node->left, str);
    *str += std::to_string(node->key) + " ";
    Show(node->right, str);
}

std::string ShowAVL(AVL *tree) {
    // Output in ascending order
    std::string str;
    Show(tree->getRoot(), &str);
    return str;
}

std::string AVL_App::operator()(int argc, const char** argv) {
    AVL AVL_Tree;
    int node;
    int op;
    int valNode;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        valNode = parseInt(argv[1]);
    }
    catch (std::string& str) {
        return str;
    }

    try {
        for (int i = 2; i < 2 + valNode; i++) {
            int node = parseInt(argv[i]);
            AVL_Tree.insert(AVL_Tree.getRoot(), node);
        }
        op = parseOperation(argv[valNode + 2]);
        if (op != FindMin && op != RemoveMin)
            node = parseInt(argv[argc - 1]);
    }
    catch (std::string& str) {
        return str;
    }
    std::ostringstream stream;
    switch (op) {
    case Add:
        AVL_Tree.insert(AVL_Tree.getRoot(), node);
        stream << ShowAVL(&AVL_Tree);
        break;
    case Remove:
        AVL_Tree.remove(AVL_Tree.getRoot(), node);
        stream << ShowAVL(&AVL_Tree);
        break;
    case FindMin:
        stream << AVL_Tree.findMin(AVL_Tree.getRoot())->key;
        break;
    case RemoveMin:
        AVL_Tree.removeMin(AVL_Tree.getRoot());
        stream << ShowAVL(&AVL_Tree);
        break;
    case Search:
        AVLNode* Node = AVL_Tree.search(AVL_Tree.getRoot(), node);
        if (Node != NULL)
            stream << AVL_Tree.search(AVL_Tree.getRoot(), node)->key;
        else
            stream << "This element not in a tree";
        break;
    }

    message_ = stream.str();
    return message_;
}
