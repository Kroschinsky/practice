#pragma once

// Created: 27 - 02 - 23

#include <iostream>
#include <vector>
#include <string>

class QuadTreeNode
{
public:

    QuadTreeNode();
    QuadTreeNode(bool val, bool isLeaf);
    QuadTreeNode(bool val, bool isLeaf, QuadTreeNode* tLeft, QuadTreeNode* tRight, QuadTreeNode* bLeft, QuadTreeNode* bRight);

    ~QuadTreeNode();

    static void print(QuadTreeNode* node);

    bool m_val = false;
    bool m_isLeaf = false;
    QuadTreeNode* m_topLeft = nullptr;
    QuadTreeNode* m_topRight = nullptr;
    QuadTreeNode* m_bottomLeft = nullptr;
    QuadTreeNode* m_bottomRight = nullptr;

    //QuadTreeNode* m_parent = nullptr;
};

