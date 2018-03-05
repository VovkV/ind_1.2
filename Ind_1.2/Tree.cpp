#include "Tree.h"



Tree::Tree()
{
	root = new Node();
}


Tree::~Tree()
{
	FreeNode(root);
}

void Tree::AddWord(std::string word)
{
	AddSymbol(root, word, 0);
}

bool Tree::CheckWord(std::string word)
{
	return CheckSymbol(root, word, 0);
}

void Tree::FreeNode(Node * node)
{
	if (node->left != nullptr)
		FreeNode(node->left);
	if (node->right != nullptr)
		FreeNode(node->right);
	delete node;
}

void Tree::AddSymbol(Node * node, std::string word, int counter)
{
	Node** nextNode;
	if (node->symbol == NULL)
	{
		node->symbol = word[counter];
		node->isFullWord = false;
		counter++;
		nextNode = &node->left;
	}
	else
	{
		if (node->symbol == word[counter])
		{
			nextNode = &node->left;
			counter++;
		}
		else
		{
			nextNode = &node->right;
		}
	}
	if (word.size() != counter)
	{
		if (*nextNode == nullptr)
			*nextNode = new Node();
		AddSymbol(*nextNode, word, counter);
	}
	else
		node->isFullWord = true;
}

bool Tree::CheckSymbol(Node * node, std::string word, int counter)
{
	Node* nextNode;
	if (node == nullptr)
		return false;
	if (node->symbol == word[counter])
	{
		nextNode = node->left;
		counter++;
	}
	else
	{
		nextNode = node->right;
	}
	if (word.size() != counter)
		return CheckSymbol(nextNode, word, counter);
	else
		if (node->isFullWord)
			return true;
		else
			return false;
}
