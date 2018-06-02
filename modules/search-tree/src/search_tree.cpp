// Copyright 2018 Gorelova Ksenia

#include <string>
#include "include/search_tree.h"

SearchTree::SearchTree(Tree * pRoot) {
    this->pRoot = pRoot;
}

void SearchTree::AddTree(int val, Tree** pRoot) {
    if (*pRoot == nullptr) {
        *pRoot = new Tree;
        (*pRoot)->value = val;
        (*pRoot)->left = (*pRoot)->right = nullptr;
        return;
    }
    if (val > (*pRoot)->value)
        AddTree(val, &(*pRoot)->right);
    else
        AddTree(val, &(*pRoot)->left);
}

Tree * SearchTree::SearchNode(Tree * pRoot, int key) {
    if (pRoot == nullptr)
        return nullptr;
    if (pRoot->value == key)
        return pRoot;
    if (key < pRoot->value)
        return SearchNode(pRoot->left, key);
    else
        return SearchNode(pRoot->right, key);
}

void SearchTree::DestroyBTree(Tree * pRoot) {
    if (pRoot != nullptr) {
        DestroyBTree(pRoot->left);
        DestroyBTree(pRoot->right);
        delete(pRoot);
    }
}

void SearchTree::Insert(int val) {
    AddTree(val, &pRoot);
}

Tree* SearchTree::Search(int val) {
    return SearchNode(pRoot, val);
}

std::string SearchTree::PrintTree() {
    std::ostringstream os;

    if (pRoot != nullptr) {
        os << "\nElements of the tree:\n";
        DrawTree(pRoot, 0, &os);
    }

    return os.str();
}

void SearchTree::DrawTree(Tree* pNode, int Level, std::ostringstream * os) {
    if (pNode != nullptr) {
        DrawTree(pNode->right, Level + 1, os);
        for (int i = 0; i < 2 * Level; i++)
            *os << " ";
        pNode->Print(os);
        *os << std::endl;
        DrawTree(pNode->left, Level + 1, os);
    }
}
