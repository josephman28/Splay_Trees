#include <iostream>
#include "Splay_Tree.hpp"

using namespace std;

int main() {

	SplayT<int> mytree;
	mytree.insert(10);
	mytree.debug();
	mytree.insert(8);
	mytree.debug();
	mytree.insert(7);
	mytree.debug();
  mytree.insert(9);
	mytree.debug();
  mytree.insert(13);
	mytree.debug();
  mytree.insert(12);
	mytree.debug();
  mytree.insert(15);
	mytree.debug();
	mytree.insert(5);
	mytree.debug();
	mytree.insert(11);
	mytree.debug();
	mytree.insert(14);
	mytree.debug();
	mytree.insert(18);
	mytree.debug();
	mytree.insert(16);
	mytree.debug();
	mytree.find(6);
  mytree.debug();
	mytree.find(16);
	mytree.debug();
	mytree.remove(11);
	mytree.debug();
  return 0;
}
