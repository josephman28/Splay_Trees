#ifdef _Primera_hpp_

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::min(SplayT<dataType>::STNode *root) const{
  STNode *aux = root;
  if(aux!=nullptr){
    while(aux -> left! = nullptr) aux = aux -> left;
  }
  return aux;
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::max(SplayT<dataType>::STNode *root) const{
  STNode *aux = root;
  if(aux!=nullptr){
    while(aux->right != nullptr) aux = aux -> right;
  }
}

template <typename dataType>
typename SplayT<dataType>::STNode* SplayT<dataType>::succesor(SplayT<dataType>::STNode *root) const{
  STNode *aux = root;
  if(aux == nullptr) return aux;

  else{
    if(aux -> right == nullptr) return aux -> right;

    aux = aux -> right;
    while(aux -> left != nullptr) aux = aux -> left;

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
  if(root==nullptr) return root;
  else if(key < root -> key) root -> left = remove(root -> left, key);
  else if(key > root -> key) root -> right = remove(root -> right, key);

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
      root -> right = remove(root -> right,aux->key);
    }
  }
  return root;
}

/*template <typename dataType>
void BST<dataType>::display(BST<dataType>::BSTNode* root, std::ostream &out) const{


}*/
template <typename dataType>
void SplayT<dataType>::insert(SplayT<dataType>::STNode* & root, dataType key){
	if(root==nullptr) return newSTNode(key);

  else if(key < root -> key) root -> left = insert(root -> left, key);
  else if(key > root -> key) root -> right = insert(root -> right, key);
}

template <typename dataType>
typename SplayT<dataType>::STNode* find(SplayT<dataType>::STNode* root, dataType key){
  if(root==nullptr) return nullptr;
  else{
    if(key==root -> key) return root;
    else if(key<root->key) return find(root -> left, key);
    else return find(root -> right, key);

  }

}
template <typename dataType>
SplayT<dataType>::ST(){
  root = nullptr;
  count = 0;
}

/*template <typename dataType>
SplayT<dataType>::~ST(){
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
bool SplayT<dataType>::find(dataType key) const{
  if(find(root, key)==nullptr) return false;
  else return true;
}

template <typename dataType>
void SplayT<dataType>::insert(dataType key){
  insert(root, key);
  count ++;
}

/*template <typename dataType>
void SplayT<dataType>::display(std::ostream &out) const{

}*/
template <typename dataType>
SplayT<dataType>::STNode * zizi_rotation(STNode *parent){
  STNode *temp;
  temp = parent -> left;
  parent -> left = temp -> right;
  temp -> right = parent;
  return temp;
}

template <typename dataType>
SplayT<dataType>::STNode * zaza_rotation(STNode *parent){
  STNode *temp;
  temp = parent -> right;
  parent -> right = temp -> left;
  temp -> left = parent;
  return temp;
}

template <typename dataType>
SplayT<dataType>::STNode * zazi_rotation(STNode *parent){
  STNode *temp;
  temp = parent -> left;
  parent -> left = zizi_rotation(temp);
  return zaza_rotation(parent);
}

template <typename dataType>
SplayT<dataType>::STNode * ziza_rotation(STNode *parent){
  STNode *temp;
  temp = parent -> right;
  parent -> right = zaza_rotation(temp);
  return zizi_rotation(parent);
}

#endif //_Primera_hpp_
