#include <iostream>
#include "Splay_T.hpp"

using namespace std;

int main() {
	SplayT<int> mytree;
	// mytree.insert(5);
	// mytree.insert(1);
	// mytree.insert(10);
	// mytree.insert(7);
	// //SplayT<int> other = mytree;
	// mytree.debug();
	// cout << "My actual size is: " << mytree.size() << endl;
	// cout << "-----------------------------------" << endl;
	// mytree.remove(5);
	// mytree.debug();
	// cout << "My actual size is: " << mytree.size() << endl << "-----------------------------------" << endl;
	// mytree.remove(1);
	// mytree.remove(10);
	// mytree.remove(11);
	// mytree.debug();
	// cout << "My actual size is: " << mytree.size() << endl;
	// cout << "-----------------------------------" << endl;
  // cout << "Empty: "<<boolalpha<<mytree.empty()<<endl;
	mytree.insert(10);
	mytree.insert(8);
	// mytree.insert(7);
  // mytree.insert(9);
  // mytree.insert(13);
  // mytree.insert(12);
  // mytree.insert(15);


  mytree.debug();
  return 0;
}
