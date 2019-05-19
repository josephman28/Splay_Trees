#ifndef _Splay_Trees_
#define _Splay_Trees_

#include <string>

template <typename dataType>
class SplayT {
	private:
		struct STNode {
			dataType key;
			STNode *left;
			STNode *right;
			STNode *parent;

			void print(std::ostream &os, std::string label = "") {
				os << "Node:  " << label << std::endl;
				os << "this   " << this->key << std::endl;
				os << "parent " << (parent == nullptr ? "nullptr" : std::to_string(parent->key)) << std::endl;
				os << "left   " << (left == nullptr ? "nullptr" : std::to_string(left->key)) << std::endl;
				os << "right  " << (right == nullptr ? "nullptr" : std::to_string(right->key)) << std::endl;
			}
		};

		size_t count;
		STNode *root;
		STNode *ultimate;


		STNode * min(STNode *root) const;
		STNode * max(STNode *root) const;
		STNode * succesor(STNode *root) const;
		STNode * predecessor(STNode *root) const;

		STNode * remove(STNode * &root, dataType key, STNode *ultimate = nullptr);
		STNode * insert(STNode * &root, dataType key, STNode *parent = nullptr);
		STNode * find(STNode *&root, dataType key, STNode *ultimate = nullptr);
		void clear(STNode *root);
		void print2D(STNode  * root, size_t space);
		void zig_rotation(STNode * &root);
    void zag_rotation(STNode * &root);
		void zigzig_rotation(STNode *&root);
		void zagzag_rotation(STNode *&root);
		void zagzig_rotation(STNode *&root);
		void zigzag_rotation(STNode *&root);
		void splaying(STNode *&root);

	public:
		SplayT();
		~SplayT();
		void remove(dataType key);
		bool empty(void) const;
		size_t size(void) const;
		bool find(dataType key);
		void insert(dataType key);
		void clear(void);
		void debug();
};
#include "Splay_Tree.cpp"
#endif //_Splay_Trees_

//The way of displaying the tree was obtained from GeeksforGeeks
