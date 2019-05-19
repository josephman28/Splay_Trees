#include <iostream>
#include "Splay_Tree.hpp"

using namespace std;

int main() {
	cout << boolalpha;
	SplayT<int> mytree;

	mytree.insert(10);
	cout << "1" << endl;
	mytree.debug();
	mytree.insert(8);
	cout << "2" << endl;
	mytree.debug();
	mytree.insert(7);
	cout << "" << endl;
	mytree.debug();
  mytree.insert(9);
	cout << "4" << endl;
	mytree.debug();
  mytree.insert(13);
	cout << "5" << endl;
	mytree.debug();
  mytree.insert(12);
	cout << "6" << endl;
	mytree.debug();
  mytree.insert(15);
	cout << "7" << endl;
	mytree.debug();
	mytree.insert(5);
	cout << "8" << endl;
	mytree.debug();
	mytree.insert(11);
	cout << "9" << endl;
	mytree.debug();
	mytree.insert(14);
	cout << "10" << endl;
	mytree.debug();
	mytree.insert(18);
	cout << "11" << endl;
	mytree.debug();
	mytree.insert(16);
	cout << "12" << endl;
	mytree.debug();
	mytree.find(6);
	cout << "f1" << endl;
  mytree.debug();
	mytree.find(16);
	cout << "f2" << endl;
	mytree.debug();
	mytree.remove(11);
	cout << "r1" << endl;
	mytree.debug();
  return 0;
}
