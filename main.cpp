#include <iostream>
#include "Splay_Tree.hpp"

using namespace std;

int main() {
	cout << boolalpha;
	SplayT<int> mytree;

	mytree.insert(10);
	mytree.insert(8);
	mytree.insert(7);
	mytree.debug();
  mytree.insert(9);
  mytree.insert(13);
  mytree.insert(12);
	mytree.debug();
  mytree.insert(15);
	mytree.insert(5);
	mytree.insert(11);
	mytree.debug();
	mytree.insert(14);
	mytree.insert(18);
	mytree.insert(16);
	mytree.debug();
	mytree.find(6);
  mytree.debug();
	mytree.find(16);
	mytree.debug();
	mytree.remove(7);
	mytree.debug();
  return 0;
}
