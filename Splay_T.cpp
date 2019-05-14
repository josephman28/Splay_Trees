#ifdef _Splay_Trees_

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::min(SplayT<dataType>::SplayT::STNode *root) const{
  STNode *aux = root;
  if(aux!=nullptr){
    while((aux -> left) != nullptr) aux = aux -> left;
  }
  return aux;
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::max(SplayT<dataType>::STNode *root) const{
  STNode *aux = root;
  if(aux!=nullptr){
    while((aux->right) != nullptr) aux = aux -> right;
  }
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::succesor(SplayT<dataType>::SplayT::STNode *root) const{
  STNode *aux = root;
  if(aux == nullptr) return aux;

  else{
    if((aux -> right) == nullptr) return aux -> right;

    aux = aux -> right;
    while((aux -> left) != nullptr) aux = aux -> left;

    return aux;
  }
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::predecessor(SplayT<dataType>::STNode *root) const{
  STNode *aux = root;
  if(aux == nullptr) return aux;

  else{
    if(aux -> left == nullptr) return aux -> left;

    aux = aux -> left;
    while(aux -> right != nullptr) aux = aux -> right;

    return aux;
  }
}

template <typename dataType>
void SplayT<dataType>::remove(SplayT<dataType>::STNode* &root, dataType key){
  if(root==nullptr) std::cout << key <<" is not in the tree"<< std::endl;
  else if(key < root -> key) remove(root -> left, key);
  else if(key > root -> key) remove(root -> right, key);

  else{

    if(root -> left == nullptr && root -> right == nullptr){
      delete root;
      root= nullptr;
    }

    else if(root -> left == nullptr){
      STNode *aux = root;
      root = root -> right;
      delete aux;
    }
    else if(root -> right == nullptr){
      STNode *aux = root;
      root = root -> left;
      delete aux;
    }
    else{
      STNode *aux = min(root -> right);
      root -> key = aux -> key;
      remove(root -> right,aux->key);
      count ++;
    }
    count --;
  }

}

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
  //cur_nod = root;
  //std::cout << cur_nod -> key << std::endl;
  return cur_nod = root;
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::find(SplayT<dataType>::STNode *root, dataType key){
  if(root==nullptr) return nullptr;
  else{
    if(key==root -> key) return root;
    else if(key<root->key) return find(root -> left, key);
    else return find(root -> right, key);

  }
  cur_nod = root;

}
template <typename dataType>
SplayT<dataType>::SplayT(){
  root = nullptr;
  count = 0;
}

/*template <typename dataType>
SplayT<dataType>::~SplayT(){
  clear();
}*/
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
    splaying(cur_nod);
    return true;
  }
}

template <typename dataType>
void SplayT<dataType>::insert(dataType key){
  insert(root, key);
  //splaying(cur_nod);
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
  //STNode *temp
  //gra_pa = root;
  //temp = root -> right -> left;
  zig_rotation(root -> right);
  zag_rotation(root);
//  root -> right = zaza_rotation(temp);

}
template<typename dataType>
void SplayT<dataType>::zig_rotation(STNode * &root){
  STNode * temp = root;
  root = root -> left;
  temp -> left = (temp -> left) -> right;
  root -> right = temp;
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
void SplayT<dataType>::print2D(SplayT<dataType>::STNode  * root, size_t space){
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
  splaying(root->left);
  // zig_rotation(root);
	// zag_rotation(root);
  //std::cout << root -> left -> parent ->  key << std::endl;
  print2D(root, 0);
}


template<typename dataType>
void SplayT<dataType>::splaying(SplayT<dataType>::STNode *&root){
  // while (root -> parent != nullptr) {
  //   if(root == root -> parent -> left){
  //     zig_rotation(root -> parent);
  //
  //   }
  //   else if(root == root -> parent -> right){
  //     zag_rotation(root -> parent);
  //
  //   }
  //   //splaying(root -> parent);
  //   break;
  // }
  if(root->parent==nullptr) std::cout << "Paila";
  else std::cout << root -> parent -> key;
}

#endif //_Splay_Trees_
