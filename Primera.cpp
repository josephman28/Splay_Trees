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


}

template <typename dataType>
typename BST<dataType>::BSTNode* BST<dataType>::copy(BST<dataType>::BSTNode* root, BST<dataType>::BSTNode* parent){


}
template <typename dataType>
void BST<dataType>::clear(BST<dataType>::BSTNode* &root){
  if(root != nullptr){
    BSTNode *left = root -> left;
    BSTNode *right = root -> right;
    delete root;
    clear(right);
    clear(left);
  }
}

template <typename dataType>
void BST<dataType>::display(BST<dataType>::BSTNode* root, std::ostream &out) const{


}
template <typename dataType>
void BST<dataType>::insert(BST<dataType>::BSTNode* & root, dataType key){

  
}

template <typename dataType>
typename BST<dataType>::BSTNode* find(BST<dataType>::BSTNode* root, dataType key){


}
template <typename dataType>
BST<dataType>::BST(){
  root = nullptr;
  count = 0;
}

template <typename dataType>
BST<dataType>::BST(const BST &rhs){

}
template <typename dataType>
BST<dataType>::~BST(){
  clear();
}
template <typename dataType>
void BST<dataType>::remove(dataType key){
  remove(root,key);
}
template <typename dataType>
bool BST<dataType>::empty(void) const{
  return count == 0;
}
template <typename dataType>
void BST<dataType>::clear(void){
  clear(root);
  root = nullptr;
  count = 0;
}
template <typename dataType>
bool BST<dataType>::find(dataType key) const{

}
template <typename dataType>
void BST<dataType>::insert(dataType key){

}
template <typename dataType>
void BST<dataType>::display(std::ostream &out) const{

}


/*template <typename dataType>

template <typename dataType>*/

#endif //_Primera_hpp_
