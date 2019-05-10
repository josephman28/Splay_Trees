#ifndef _Splay_Trees_
#define _Splay_Trees_
template <typename dataType>
class SplayT {
	private:
		struct STNode {
			dataType key;
			STNode *left;
			STNode *right;
			STNode *parent;
		};

		size_t count;
		STNode *root;

		STNode * min(STNode *root) const;
		STNode * max(STNode *root) const;
		STNode * succesor(STNode *root) const;
		STNode * predecessor(STNode *root) const;

		void remove(STNode * &root, dataType key);
		void insert(STNode * &root, dataType key, STNode *parent = nullptr);
		STNode * find(STNode *root, dataType key);
		void print2D(STNode  * root, size_t space);
		void zig_rotation(STNode * &root);
    void zag_rotation(STNode * &root);

	public:
		SplayT();
		//SplayT(const ST & rhs);
		//~SplayT();
		STNode * zizi_rotation(STNode *parent);
		STNode * zaza_rotation(STNode *parent);
		STNode * zazi_rotation(STNode *parent);
		STNode * ziza_rotation(STNode *parent);
		void remove(dataType key);
		bool empty(void) const;
		size_t size(void) const;
		bool find(dataType key);
		void insert(dataType key);
		void debug();
};
#include "Splay_T.cpp"
#endif //_Splay_Trees_

//The way of displaying the tree was obtained from GeeksforGeeks
