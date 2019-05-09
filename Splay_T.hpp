#ifndef _Splay_Trees_
#define _Splay_Trees
template <typename dataType>
class SplayT {
	private:
		struct STNode {
			datatype key;
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
		void display(STNode *root, std::ostream & out, size_t times) const;
		void insert(STNode * &root, dataType key, SplayT<dataType>::STNode *parent = nullptr);
		STNode * find(STNode *root, dataType key) const;


	public:
		ST();
		//ST(const ST & rhs);
		//~ST();
		STNode * zig_rotation(STNode *);
		STNode * zag_rotation(STNode *);
		STNode * zizi_rotation(STNode *);
		STNode * zaza_rotation(STNode *);
		STNode * zazi_rotation(STNode *);
		STNode * ziza_rotation(STNode *);
		void remove(dataType key);
		bool empty(void) const;
		size_t size(void) const;
		bool find(dataType key) const;
		void insert(dataType key);
		void display(std::ostream &out = std::cout) const;
};
#include "Splay_T.cpp"
#endif //_Splay_Trees_
//the way to do the insertion of elements was obtained at GeeksforGeeks
