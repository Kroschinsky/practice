#pragma once

#include "QuadTree.h"

/*
Created: 27-02-23

427. Construct Quad Tree [Medium]

Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.
Return the root of the Quad-Tree representing the grid.
Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
*/

QuadTreeNode* checkQuadTree(std::vector<std::vector<int>>& grid)
{
	// check if all values is same
	int size = grid.size();
	int check = grid[0][0];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (check != grid[i][j])
			{
				return new QuadTreeNode(1, 0);
			}
		}
	}

	return new QuadTreeNode(check, 1);
}

QuadTreeNode* constructQuadTree(std::vector<std::vector<int>> grid)
{
	int size = grid.size();
	if (size == 0)
		return nullptr;

	// check if all values is same
	QuadTreeNode* node = checkQuadTree(grid);

	if (node->m_isLeaf == true)
		return node;

	// create 4 nodes
	std::vector<std::vector<int>> grid_tl;
	std::vector<std::vector<int>> grid_tr;
	std::vector<std::vector<int>> grid_bl;
	std::vector<std::vector<int>> grid_br;	

	for (int i = 0; i < size; i++)
	{
		std::vector<int> v_tl;
		std::vector<int> v_tr;
		std::vector<int> v_bl;
		std::vector<int> v_br;

		for (int j = 0; j < size; j++)
		{
			if (i < (size / 2))
			{
				if (j < (size / 2))
				{
					// tl
					v_tl.push_back(grid[i][j]);
				}
				else
				{
					// tr
					v_tr.push_back(grid[i][j]);
				}
			}
			else
			{
				if (j < (size / 2))
				{
					// bl
					v_bl.push_back(grid[i][j]);
				}
				else
				{
					// br
					v_br.push_back(grid[i][j]);
				}
			}
		}

		if (i < (size / 2))
		{
			grid_tl.push_back(v_tl);
			grid_tr.push_back(v_tr);
		}
		else
		{
			grid_bl.push_back(v_bl);
			grid_br.push_back(v_br);
		}
	}

	node->m_topLeft = constructQuadTree(grid_tl);
	node->m_topRight = constructQuadTree(grid_tr);
	node->m_bottomLeft = constructQuadTree(grid_bl);
	node->m_bottomRight = constructQuadTree(grid_br);

	return node;
}

/*
	auto node1 = constructQuadTree({ {0, 1}, {1, 0} });
	QuadTreeNode::print(node1);
	std::cout << std::endl;
	delete node1;

	auto node2 = constructQuadTree({ {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0} });
	QuadTreeNode::print(node2);
	std::cout << std::endl;
	delete node2;
*/