// Copyright 2018 Okunev Boris

#include <string>
#include <vector>
#include <sstream>

#include "include/leftist_heap.h"
#include "include/leftist_heap_app.h"


using std::string;
using std::vector;

LeftistHeapApp::LeftistHeapApp() : message_("") {}

void LeftistHeapApp::help(const char* appname, const char* message) {
    message_ = string(message) +
        "This is leftist heap application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <operation> <heap_one> <heap_two>\n\n" +

        "Where heaps is array of keys in the round brackets," +
        "comma is delimited character;\n" +
        "and <operation> is one of 'merge', 'insert', 'minKey', " +
        " 'deleteMin'. Output is nodes of heap divided by space.\n" +
        "If you use one of the last two operations," +
        " the last argument is ignored and may be missing. \n";
}

bool LeftistHeapApp::validateArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc > 4) {
        help(argv[0], "ERROR: Too mush arguments. \n\n");
        return false;
    }

    return true;
}


void LeftistHeapApp::parseArguments(int argc, const char** argv) {
    try {
        parseOperation(argv[1]);
        args_.heapOne = parseHeap(argv[2]);
        if (args_.operation < MINKEY)
            args_.heapTwo = parseHeap(argv[3]);
    }
    catch (std::string& str) {
        message_ = str;
    }
}

void LeftistHeapApp::parseOperation(const char* op) {
    string str = op;
    if (op == (string)"merge")
        args_.operation = MERGE;
    else if (op == (string)"insert")
        args_.operation = INSERT;
    else if (op == (string)"minKey")
        args_.operation = MINKEY;
    else if (op == (string)"deleteMin")
        args_.operation = DELETEMIN;
    else
        throw string("Wrong operation format!");
}

leftist_heap LeftistHeapApp::parseHeap(const char* op) const {
    string str = op;
    std::stringstream ss(str);
    char c;
    int key;
    leftist_heap h;

    ss >> c;
    if (c != '(')
        throw string("Wrong heap format!");

    if (str.size() == 2) {
        if (str[1] == ')')
            return h;
        else
            throw string("Wrong heap format!");
    }

    ss >> key;
    h.insert(key);
    ss >> c;

    while (c == ',') {
        ss >> key;
        h.insert(key);
        ss >> c;
    }

    if (c != ')')
        throw string("Wrong heap format!");

    return h;
}

string LeftistHeapApp::operator()(int argc, const char** argv) {
    if (!validateArguments(argc, argv)) {
        return message_;
    }
    parseArguments(argc, argv);

    if (message_.size())
        return message_;

    try {
        switch (args_.operation) {
        case MERGE: {
            leftist_heap h = args_.heapOne;
            h.merge(&args_.heapTwo);
            message_ = h;
            break;
        }
        case INSERT: {
            leftist_heap h = args_.heapOne;
            int min = args_.heapTwo.minKey();
            h.insert(min);
            message_ = h;
            break;
        }
        case MINKEY: {
            int min = args_.heapOne.minKey();
            message_ = std::to_string(min);
            break;
        }
        case DELETEMIN: {
            args_.heapOne.deleteMin();
            message_ = args_.heapOne;
            break;
        }
        }
    }
    catch (std::string& str) {
        message_ = str;
    }

    return message_;
}

