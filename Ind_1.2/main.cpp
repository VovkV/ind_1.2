#include "Tree.h"

void main() 
{
	Tree t = *new Tree();

	t.AddWord("test");
	t.AddWord("term");
	auto s = t.CheckWord("test");
	s = t.CheckWord("tester");
	s = t.CheckWord("term");
}