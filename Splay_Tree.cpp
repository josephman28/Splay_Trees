#ifdef _Splay_Trees_

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::min(SplayT<dataType>::SplayT::STNode *root) const{
  checkrep();
  STNode *aux = root;
  if(aux!=nullptr){
    while((aux -> left) != nullptr) aux = aux -> left;
  }
  checkrep();
  return aux;
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::max(SplayT<dataType>::STNode *root) const{
  checkrep();
  STNode *aux = root;
  if(aux!=nullptr){
    while((aux->right) != nullptr) aux = aux -> right;
  }
  checkrep();
  return aux;
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::succesor(SplayT<dataType>::SplayT::STNode *root) const{
  checkrep();
  STNode *aux = root;
  if(aux == nullptr) return aux;

  else{
    if((aux -> right) == nullptr) return aux -> right;

    aux = aux -> right;
    while((aux -> left) != nullptr) aux = aux -> left;

    return aux;
  }
  checkrep();
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::predecessor(SplayT<dataType>::STNode *root) const{
  checkrep();
  STNode *aux = root;
  if(aux == nullptr) return aux;

  else{
    if(aux -> left == nullptr) return aux -> left;

    aux = aux -> left;
    while(aux -> right != nullptr) aux = aux -> right;

    return aux;
  }
  checkrep();
}

template <typename dataType>
typename SplayT<dataType>::STNode * SplayT<dataType>::remove(SplayT<dataType>::STNode* &root, dataType key, SplayT<dataType>::STNode *ultimate){
  checkrep();
  if(root==nullptr) {
    std::cout << key <<" is not in the tree"<< std::endl;
    return ultimate;
  }
  else if(key < root -> key) {
    return remove(root -> left, key, root);
  }
  else if(key > root -> key){
    return remove(root -> right, key, root);
  }
  else{
    if(root -> left == nullptr && root -> right == nullptr){
      root -> parent = ultimate;
      if(root -> parent -> left == root){
        root -> parent -> left = nullptr;
      }
      else{
        root -> parent -> right = nullptr;
      }
      delete root;
      return ultimate;
    }
    else if(root -> left == nullptr){
      STNode *aux = root;
      root -> right -> parent = root -> parent;
      root = root -> right;
      delete aux;
      return root;
    }
    else if(root -> right == nullptr){
      STNode *aux = root;
      root -> left -> parent = root -> parent;
      root = root -> left;
      delete aux;
      return root;
    }
    else{
      STNode *aux = min(root -> right);
      root -> key = aux -> key;
      remove(root -> right,aux->key, root);
      count ++;
      return root;
    }
    count --;
  }
  checkrep();
}

template <typename dataType>
typename SplayT<dataType>::STNode * SplayT<dataType>::insert(SplayT<dataType>::STNode* & root, dataType key, SplayT<dataType>::STNode *parent){
  checkrep();
	if(root==nullptr){
    root = new STNode;
    root -> key = key;
    root  -> parent = parent;
    root -> left = nullptr;
    root -> right = nullptr;
    return root;
  }
  else if(key < root -> key) {
    return insert(root -> left, key, root);
  }
  else if(key > root -> key) {
    return insert(root -> right, key, root);
  }
  else{
    std::cout << key << " is already in the tree" << std::endl;
    return root;
  }
  checkrep();
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::find(SplayT<dataType>::STNode *&root, dataType key, SplayT<dataType>::STNode * ultimate){
  checkrep();
  if(root==nullptr){
    std::cout << key <<" Is not in the tree" << std::endl;
    return ultimate;
  }
  else{
    if(key==root -> key) {
      std::cout << key <<" is in the tree" << std::endl;
      return root;
    }
    else if(key<root->key) {
      return find(root -> left, key, root);
    }
    else{
      return find(root -> right, key, root);
    }
  }
  checkrep();
}

template <typename dataType>
void SplayT<dataType>::clear(SplayT<dataType>::STNode * root){
  checkrep();
  if(root!=nullptr){
    STNode * aux1 = root -> left;
    STNode * aux2 = root -> right;
    delete root;
    clear(aux1);
    clear(aux2);
  }
  checkrep();
}

template <typename dataType>
SplayT<dataType>::SplayT(){
  root = nullptr;
  count = 0;
  checkrep();
}

template <typename dataType>
SplayT<dataType>::~SplayT(){
  clear();
  checkrep();
}

template <typename dataType>
void SplayT<dataType>::remove(dataType key){
  checkrep();
  auto nodo = remove(root,key);
  splaying(nodo);
  root = nodo;
  checkrep();
}

template <typename dataType>
bool SplayT<dataType>::empty(void) const{
  checkrep();
  return count == 0;
}

template <typename dataType>
void SplayT<dataType>::clear(void){
  checkrep();
  clear(root);
  root = nullptr;
  count = 0;
  checkrep();
}

template <typename dataType>
bool SplayT<dataType>::find(dataType key){
  checkrep();
  auto node = find(root, key);
  if(node!=nullptr) {
    splaying(node);
    root = node;
    if(key==root->key){
      return true;
    }
    else return false;
  }
  else{
    if(node->parent==nullptr){
      std::cout << "nullptr" << std::endl;
    }
    else{
      node = node -> parent;
      splaying(node);
      root = node;
    }
    return false;
  }
  checkrep();
}

template <typename dataType>
void SplayT<dataType>::insert(dataType key){
  checkrep();
  auto n_nod = insert(root, key);
  splaying(n_nod);
  root = n_nod;
  count ++;
  checkrep();
}

template <typename dataType>
void SplayT<dataType>::zigzig_rotation(SplayT<dataType>::STNode *&root){
  checkrep();
  zig_rotation(root);
  zig_rotation(root);
  checkrep();
}

template <typename dataType>
void SplayT<dataType>::zagzag_rotation(SplayT<dataType>::STNode *&root){
  checkrep();
  zag_rotation(root);
  zag_rotation(root);
  checkrep();
}

template <typename dataType>
void SplayT<dataType>::zagzig_rotation(SplayT<dataType>::STNode *&root){
  checkrep();
  zag_rotation(root -> left);
  zig_rotation(root);
  checkrep();
}

template <typename dataType>
void SplayT<dataType>::zigzag_rotation(SplayT<dataType>::STNode *&root){
  checkrep();
  zig_rotation(root -> right);
  zag_rotation(root);
  checkrep();
}

template<typename dataType>
void SplayT<dataType>::zig_rotation(SplayT<dataType>::STNode * &root){
  checkrep();
  STNode * temp = root;
  root = root -> left;
  root->parent = temp -> parent;
  if(temp -> parent != nullptr){
    if(temp -> parent -> key < temp -> key){
      temp -> parent -> right = root;
    }
    else temp -> parent -> left = root;
  }
  temp -> left = root -> right;
  if(root -> right != nullptr) root -> right -> parent = temp;
  root -> right = temp;
  temp -> parent = root;
  checkrep();
}

template<typename dataType>
void SplayT<dataType>::zag_rotation(SplayT<dataType>::STNode * &root){
  checkrep();
  STNode * temp = root;
  root = root -> right;
  root->parent = temp -> parent;
  if(temp -> parent != nullptr){
    if(temp -> parent -> key < temp -> key){
      temp -> parent -> right = root;
    }
    else temp -> parent -> left = root;
  }
  temp -> right = root -> left;
  if(root -> left != nullptr) root -> left -> parent = temp;
  root -> left = temp;
  temp -> parent = root;
  checkrep();
}

template <typename dataType>
size_t SplayT<dataType>::size(void) const{
  checkrep();
  return count;
}

template <typename dataType>
void SplayT<dataType>::print2D(SplayT<dataType>::STNode  * root, size_t space){
  checkrep();
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
    int x = (root->parent!=nullptr) ? root -> parent -> key : 0;
    std::cout<< x << "|"<< root -> key <<'\n';
    // Process left child
    print2D(root->left, space);
    checkrep();
}

template<typename dataType>
void SplayT<dataType>::debug(){
  checkrep();
  print2D(root, 0);
  std::cout << std::endl;
  std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
  checkrep();
}

template<typename dataType>
void SplayT<dataType>::splaying(SplayT<dataType>::STNode *&root){
  checkrep();
  if(root == nullptr) return;
  else if(root-> parent==nullptr) return;
  else if(root -> parent -> parent == nullptr) {
    if((root-> parent-> key) > (root-> key)) {
      auto n_nod = root -> parent;
      zig_rotation(n_nod);
      root = n_nod;
    }
    else {
      auto n_nod = root -> parent;
			zag_rotation(n_nod);
      root = n_nod;
		}
  }
  else{
    if((root->parent->parent->key) > (root->parent->key) && (root->parent->key) > (root->key)) {
      auto n_nod = root->parent->parent;
			zigzig_rotation(n_nod);
      root = n_nod;
		}
    else if((root->parent->parent->key) < (root->parent->key) && (root->parent->key < root->key)) {
      auto n_nod = root->parent->parent;
			zagzag_rotation(n_nod);
      root = n_nod;
		}
    else if((root->parent->parent->key) < (root->parent->key) && (root->parent->key) > (root->key)) {
      auto n_nod = root->parent->parent;
			zigzag_rotation(n_nod);
      root = n_nod;
		}
    else if(root->parent->parent->key > root->parent->key && root->parent->key < root->key) {
      auto n_nod = root->parent->parent;
			zagzig_rotation(n_nod);
      root = n_nod;
		}
  }
  splaying(root);
  checkrep();
}

template<typename dataType>
void SplayT<dataType>::checkrep() const{
  assert(count>=0);
  if(root==nullptr) assert(count == 0);
}

#endif //_Splay_Trees_
