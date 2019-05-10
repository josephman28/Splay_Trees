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
void SplayT<dataType>::insert(SplayT<dataType>::STNode* & root, dataType key, SplayT<dataType>::STNode *parent){
	if(root==nullptr){
    root = new STNode;
    root -> key = key;
    root -> parent = parent;
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
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::find(SplayT<dataType>::STNode *root, dataType key){
  if(root==nullptr) return nullptr;
  else{
    if(key==root -> key) return root;
    else if(key<root->key) return find(root -> left, key);
    else return find(root -> right, key);

  }

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
  else return true;
}

template <typename dataType>
void SplayT<dataType>::insert(dataType key){
  insert(root, key);
  count ++;
}


template <typename dataType>
typename SplayT<dataType>::STNode * SplayT<dataType>::zizi_rotation(SplayT<dataType>::STNode *parent){
  STNode *temp;
  temp = parent -> left;
  parent -> left = temp -> right;
  temp -> right = parent;
  return temp;
}

template <typename dataType>
typename SplayT<dataType>::STNode * SplayT<dataType>::zaza_rotation(SplayT<dataType>::STNode *parent){
  STNode *temp;
  temp = parent -> right;
  parent -> right = temp -> left;
  temp -> left = parent;
  return temp;
}

template <typename dataType>
typename SplayT<dataType>::STNode * SplayT<dataType>::zazi_rotation(SplayT<dataType>::STNode *parent){
  STNode *temp;
  temp = parent -> left;
  parent -> left = zizi_rotation(temp);
  return zaza_rotation(parent);
}

template <typename dataType>
typename SplayT<dataType>::STNode * SplayT<dataType>::ziza_rotation(SplayT<dataType>::STNode *parent){
  STNode *temp;
  temp = parent -> right;
  parent -> right = zaza_rotation(temp);
  return zizi_rotation(parent);
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
  zig_rotation(root);
	zag_rotation(root);
  print2D(root, 0);
}

#endif //_Splay_Trees_
