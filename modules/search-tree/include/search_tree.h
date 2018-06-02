// Copyright 2018 Gorelova Ksenia

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_

#include <string>
#include <sstream>

struct Tree {
 public:
    int value;
    Tree * left;
    Tree * right;

    void Print(std::ostringstream * os) { *os << std::endl << value; }
};

class SearchTree {
 private:
    Tree * pRoot;
    void DestroyBTree(Tree * pRoot);
    void AddTree(int val, Tree** pRoot);
    Tree * SearchNode(Tree * pRoot, int key);
    void DrawTree(Tree* pNode, int Level, std::ostringstream * os);
 public:
    explicit SearchTree(Tree * pRoot = nullptr);
    ~SearchTree() { DestroyBTree(pRoot); }

    void Insert(int val);
    Tree * Search(int val);

    std::string PrintTree(void);
};

#endif   // MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
