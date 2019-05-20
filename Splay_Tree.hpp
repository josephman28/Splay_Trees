#ifndef _Splay_Trees_
#define _Splay_Trees_
#include <cassert>
#include <string>

//Class that recrates the ADT Splay Tree
template <typename dataType>
class SplayT {
	private:
		/*
		*Struct for the nodes of the Tree
		*key: value of each node
		*left: pointer to the left child of the node
		*right: pointer to the right child of the node
		*parent: pointer to the parent of the node
		*/
		struct STNode {
			dataType key;
			STNode *left;
			STNode *right;
			STNode *parent;
			//Function that tells each attribute of the node
			void print(std::ostream &os, std::string label = "") {
				os << "Node:  " << label << std::endl;
				os << "this   " << this->key << std::endl;
				os << "parent " << (parent == nullptr ? "nullptr" : std::to_string(parent->key)) << std::endl;
				os << "left   " << (left == nullptr ? "nullptr" : std::to_string(left->key)) << std::endl;
				os << "right  " << (right == nullptr ? "nullptr" : std::to_string(right->key)) << std::endl;
			}
		};
		//number of nodes in the tree
		size_t count;
		//pointer to the root of the tree
		STNode *root;
		//pointer to the last node visited of the tree
		STNode *ultimate;

		/*
		*Function that searches the minimum key at the tree
		*root: root of the subtree
		*return: pointer to the node with the minimum key, nullptr if root has no left child
		*/
		STNode * min(STNode *root) const;
		/*
		*Function that searches the maximum key at the tree
		*root: root of the subtree
		*return: pointer to the node with the maximum key, nullptr if root has no right child
		*/
		STNode * max(STNode *root) const;
		/*
		*Function that searches the lowest key of the largest keys
		*root: root of the subtree
		*return: pointer to the node with the successor, nullptr if root has no right child
		*/
		STNode * succesor(STNode *root) const;
		/*
		*Function that searches the largest key of the smallest keys
		*root: root of the subtree
		*return: pointer to the node with the predecessor, nullptr if root has no left child
		*/
		STNode * predecessor(STNode *root) const;
		/*
		*Function that removes the node with an specific key
		*key: key for the node
		*return: node that takes its place in the tree, if the tree has not key in it, return the posible parent for key
		*/
		STNode * remove(STNode * &root, dataType key, STNode *ultimate = nullptr);
		/*
		*Function that inserts a node with an specific key
		*key: key for the node
		*return: node that contains the key
		*/
		STNode * insert(STNode * &root, dataType key, STNode *parent = nullptr);
		/*
		*Function that finds the node with an specific key
		*key: key for the node
		*return: node that contains the key, if the tree has not key in it, return the posible parent for key
		*/
		STNode * find(STNode *&root, dataType key, STNode *ultimate = nullptr);
		/*
		*Method that clears a subtree
		*root: pointer to the root of the subtree
		*/
		void clear(STNode *root);
		/*
		*Method that displays the tree in a particular way
		*/
		void print2D(STNode  * root, size_t space);
		/*
		*Method that rotates a node with his left child
		*root: pointer to the node's parent
		*/
		void zig_rotation(STNode * &root);
		/*
		*Method that rotates a node with his right child
		*root: pointer to the node's parent
		*/
    void zag_rotation(STNode * &root);
		/*
		*Method that uses two times zig_rotation function
		*root: pointer to the node's grandparent
		*/
		void zigzig_rotation(STNode *&root);
		/*
		*Method that uses two times zag_rotation function
		*root: pointer to the node's grandparent
		*/
		void zagzag_rotation(STNode *&root);
		/*
		*Method that uses zag_rotation and then zig_rotation function
		*root: pointer to the node's grandparent
		*/
		void zagzig_rotation(STNode *&root);
		/*
		*Method that uses zig_rotation and then zag_rotation function
		*root: pointer to the node's grandparent
		*/
		void zigzag_rotation(STNode *&root);
		/*
		*Method that takes a node to the root of the tree
		*root: pointer to the node we want to splay
		*/
		void splaying(STNode *&root);
		/*
		*Method that ckecks splay tree properties
		*/
		void checkrep() const;

	public:
		/*
		Constructor, creates a new Splay Tree
		*/
		SplayT();
		/*
		Destructor, deletes the actual Splay Tree
		*/
		~SplayT();
		/*
		*Method that removes a key in the tree
		*key: key to delete from the tree
		*/
		void remove(dataType key);
		/*
		*Function that determines if the tree is empty
		*return: true if the tree is empty, false if not
		*/
		bool empty(void) const;
		/*
		*Function that determines the number of elements at the tree
		*return: the number of elements at the tree
		*/
		size_t size(void) const;
		/*
		*Function that searches a key
		*key: key that will be searched
		*return: true if there is that key in the tree, false if not
		*/
		bool find(dataType key);
		/*
		*Method that inserts a key on the tree
		*key: key to be inserted
		*/
		void insert(dataType key);
		/*
		*Method that clears a subtree
		*root: pointer to the root of the subtree
		*/
		void clear(void);
		/*
		*Method that uses the print2D function for displaying the tree
		*/
		void debug();
};

#include "Splay_Tree.cpp"

#endif //_Splay_Trees_

//The way of displaying the tree was obtained from GeeksforGeeks
