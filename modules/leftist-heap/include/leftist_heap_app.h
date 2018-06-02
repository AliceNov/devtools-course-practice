// Copyright 2018 Okunev Boris

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_

#include <string>
#include <vector>

#include "include/leftist_heap.h"

enum OP {MERGE = 1, INSERT, MINKEY, DELETEMIN };

using std::string;

class LeftistHeapApp {
 public:
    LeftistHeapApp();
    string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateArguments(int argc, const char** argv);
    void parseArguments(int argc, const char** argv);
    void parseOperation(const char* op);
    leftist_heap parseHeap(const char* heap) const;
    string message_;
    typedef struct {
        leftist_heap heapOne;
        leftist_heap heapTwo;
        OP operation;
    } Arguments;
    Arguments args_;
};

#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_
