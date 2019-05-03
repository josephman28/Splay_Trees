#ifndef _Primera_hpp_
#define _Primera_hpp_
template <typename datatype>
class BST {
	private:
		struct BSTNode {
			datatype key;
			BSTNode *left;
			BSTNode *right;
			BSTNode *parent;
		};

		size_t count;
		BSTNode *root;

		BSTNode * min(BSTNode *root) const;
		BSTNode * max(BSTNode *root) const;
		BSTNode * succesor(BSTNode *root) const;
		BSTNode * predecessor(BSTNode *root) const;

		void remove(BSTNode * &root, datatype key);
		void display(BSTNode *root, std::ostream & out, size_t times) const;
		void insert(BSTNode * &root, datatype key, BST<datatype>::BSTNode *parent = nullptr);
		BSTNode * Find(BSTNode *root, datatype key) const;

	public:
		BST();
		BST(const BST & rhs);
		~BST();
		void remove(datatype key);
		bool empty(void) const;
		bool find(datatype key) const;
		void insert(datatype key);
		void display(std::ostream &out = std::cout) const;
};

#endif //_Primera_hpp_
