#ifdef _Primera_hpp_

template <typename dataType>
typename BST<dataType>::BSTNode* BST<dataType>::min(BST<dataType>::BSTNode *root) const{
  BSTNode *aux = root;
  if(aux!=nullptr){
    while(aux -> left! = nullptr) aux = aux -> left;
  }
  return aux;
}

template <typename dataType>
typename BST<dataType>::BSTNode* BST<dataType>::max(BST<dataType>::BSTNode *root) const{
  BSTNode *aux = root;
  if(aux!=nullptr){
    while(aux->right != nullptr) aux = aux -> right;
  }
}
template <typename dataType>
typename BST<dataType>::BSTNode* BST<dataType>::succesor(BST<dataType>::BSTNode *root) const{
  BSTNode *aux = root;
  if(aux == nullptr) return aux;

  else{
    if(aux -> right == nullptr) return aux -> right;

    aux = aux -> right;
    while(aux -> left != nullptr) aux = aux -> left;

    return aux;
  }
}

template <typename dataType>
typename BST<dataType>::BSTNode* BST<dataType>::predecessor(BST<dataType>::BSTNode *root) const{
  BSTNode *aux = root;
  if(aux == nullptr) return aux;

  else{
    if(aux -> left == nullptr) return aux -> left;

    aux = aux -> left;
    while(aux -> right != nullptr) aux = aux -> right;

    return aux;
  }
}

template <typename dataType>
void BST<dataType>::remove(BST<dataType>::BSTNode* &root, dataType key){
  if(root==nullptr) return root;
  else if(key < root -> key) root -> left = remove(root -> left, key);
  else if(key > root -> key) root -> right = remove(root -> right, key);

  else{

    if(root -> left == nullptr && root -> right == nullptr){
      delete root;
      root= nullptr;
    }

    else if(root -> left == nullptr){
      BSTNode *aux = root;
      root = root -> right;
      delete aux;
    }
    else if(root -> right == nullptr){
      BSTNode *aux = root;
      root = root -> left;
      delete aux;
    }
    else{
      BSTNode *aux = min(root -> right);
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
void BST<dataType>::insert(BST<dataType>::BSTNode* & root, dataType key){
	if(root==nullptr) return newBSTNode(key);

  else if(key < root -> key) root -> left = insert(root -> left, key);
  else if(key > root -> key) root -> right = insert(root -> right, key);
}

template <typename dataType>
typename BST<dataType>::BSTNode* find(BST<dataType>::BSTNode* root, dataType key){
  if(root==nullptr) return nullptr;
  else{
    if(key==root -> key) return root;
    else if(key<root->key) return find(root -> left, key);
    else return find(root -> right, key);
      
  }

}
template <typename dataType>
BST<dataType>::BST(){
  root = nullptr;
  count = 0;
}

/*template <typename dataType>
BST<dataType>::~BST(){
  clear();
}*/
template <typename dataType>
void BST<dataType>::remove(dataType key){
  remove(root,key);
}
template <typename dataType>
bool BST<dataType>::empty(void) const{
  return count == 0;
}

template <typename dataType>
bool BST<dataType>::find(dataType key) const{
  if(find(root, key)==nullptr) return false;
  else return true;
}
template <typename dataType>
void BST<dataType>::insert(dataType key){
  insert(root, key);
  count ++;
}
/*template <typename dataType>
void BST<dataType>::display(std::ostream &out) const{

}*/

#endif //_Primera_hpp_
