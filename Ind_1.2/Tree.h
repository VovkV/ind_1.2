#pragma once
#include <iostream>

struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
	char symbol = NULL;
	bool isFullWord = false;
};
class Tree
{
public:
	Tree();
	~Tree();
	void AddWord(std::string word);
	bool CheckWord(std::string word);
private:
	Node* root;

	void FreeNode(Node* node);
	void AddSymbol(Node* node, std::string word, int counter);
	bool CheckSymbol(Node* node, std::string word, int counter);
};

