#ifndef _SplayT_hpp_
#define _SplayT_hpp_
template <typename datatype>
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

		void remove(STNode * &root, datatype key);
		void display(STNode *root, std::ostream & out, size_t times) const;
		void insert(STNode * &root, datatype key, BST<datatype>::STNode *parent = nullptr);
		STNode * Find(STNode *root, datatype key) const;


	public:
		ST();
		ST(const ST & rhs);
		~ST();
		STNode * zizi_rotation(STNode *);
		STNode * zaza_rotation(STNode *);
		STNode * zazi_rotation(STNode *);
		STNode * ziza_rotation(STNode *);
		void remove(datatype key);
		bool empty(void) const;
		bool find(datatype key) const;
		void insert(datatype key);
		void display(std::ostream &out = std::cout) const;
};

#endif //_Primera_hpp_
//the way to do the insertion of elements was obtained at GeeksforGeeks
