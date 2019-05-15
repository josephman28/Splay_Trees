#ifdef _Splay_Trees_

template <typename dataType>
typename SplayT<dataType>::STNode * SplayT<dataType>::insert(SplayT<dataType>::STNode* & root, dataType key, SplayT<dataType>::STNode *parent){
	if(root==nullptr){
    root = new STNode;
    root -> key = key;
    root  -> parent = parent;
    root -> left = nullptr;
    root -> right = nullptr;

  }

  else if(key < root -> key) {
    insert(root -> left, key, root);

  }

  else if(key > root -> key) {
    insert(root -> right, key, root);

  }
  else{
    std::cout << key << " is already in the tree" << std::endl;
  }

  return root;
}

template <typename dataType>
SplayT<dataType>::SplayT(){
  root = nullptr;
  count = 0;
}

// template <typename dataType>
// SplayT<dataType>::~SplayT(){
//   clear();
// }
template <typename dataType>
void SplayT<dataType>::remove(dataType key){
  remove(root,key);
}

template <typename dataType>
bool SplayT<dataType>::empty(void) const{
  return count == 0;
}

template <typename dataType>
bool SplayT<dataType>::find(dataType key){
  if(find(root, key)==nullptr) return false;
  else{
    //splaying(root);
    return true;
  }
}

template <typename dataType>
void SplayT<dataType>::insert(dataType key){
  insert(root, key);

  count ++;

}


template <typename dataType>
void SplayT<dataType>::zigzig_rotation(SplayT<dataType>::STNode *&root){
  zig_rotation(root);
  zig_rotation(root);
}

template <typename dataType>
void SplayT<dataType>::zagzag_rotation(SplayT<dataType>::STNode *&root){
  zag_rotation(root);
  zag_rotation(root);
}
//Hijo derecho de uno izquierdo
template <typename dataType>
void SplayT<dataType>::zagzig_rotation(SplayT<dataType>::STNode *&root){
  zag_rotation(root -> left);
  zig_rotation(root);
}
//Hijo izquierdo de uno derecho
template <typename dataType>
void SplayT<dataType>::zigzag_rotation(SplayT<dataType>::STNode *&root){

  zig_rotation(root -> right);
  zag_rotation(root);


}
template<typename dataType>
void SplayT<dataType>::zig_rotation(STNode * &root){
  STNode * temp = root;
  root = root -> left;
  root->parent = temp->parent;
  temp -> left = (temp -> left) -> right;
  temp->parent = root;
  root -> right = temp;
  // STNode *y = x->left;
  //   if(y) {
  //     x->left = y->right;
  //     if( y->right ) y->right->parent = x;
  //     y->parent = x->parent;
  //   }
  //   if( !x->parent ) root = y;
  //   else if( x == x->parent->left ) x->parent->left = y;
  //   else x->parent->right = y;
  //   if(y) y->right = x;
  //   x->parent = y;
}
template<typename dataType>
void SplayT<dataType>::zag_rotation(STNode * &root){
  STNode * temp = root;
  root = root -> right;
  temp -> right = (temp -> right) -> left;
  root -> left = temp;
}

template <typename dataType>
size_t SplayT<dataType>::size(void) const{
  return count;
}

template <typename dataType>
void SplayT<dataType>::print2D(SplayT<dataType>::STNode  *root, size_t space){
	if (root == nullptr)
        return;

    // Increase distance between levels
    space += count;

    // Process right child first
    print2D(root->right, space);

    // Print current node after space
    // count
    std::cout<<std::endl;
    for (unsigned i = count; i < space; i++)
        std::cout<<" ";
    std::cout<<root->key<<"\n";

    // Process left child
    print2D(root->left, space);
}

template<typename dataType>
void SplayT<dataType>::debug(){
  print2D(root, 0);
  std:: cout << "---------------------" << std::endl;

  //splaying(root);

  //zig_rotation(root);
	// zag_rotation(root);
  //std::cout << root -> left -> parent ->  key << std::endl;		void zig_rotation(STNode * &root);

  //print2D(root, 0);
}


template<typename dataType>
void SplayT<dataType>::splaying(SplayT<dataType>::STNode * &root){
  if(root == nullptr) std::cout << "end" << std::endl;
  else if(root -> parent == nullptr) {

    if((root -> key) > (root-> left -> key)) {
      zig_rotation(root);

    }
    else if(root -> key < root -> right -> key) {
			zag_rotation(root);
		}
  }
  else{
    if(root -> key > root -> left -> key && root -> parent -> key > root -> key) {
			zigzig_rotation(root -> parent);
		}

    else if(root -> key < root -> right -> key && root -> parent -> key < root -> key) {
			zagzag_rotation(root -> parent);
		}

    else if(root -> key > root -> left -> key && root -> parent -> key < root -> key) {
			zigzag_rotation(root -> parent);
		}

    else if(root -> key < root -> right -> key && root -> parent -> key > root -> key) {
			zagzig_rotation(root -> parent);
		}
  }
}

#endif //_Splay_Trees_
