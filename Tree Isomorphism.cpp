class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL && root2 != NULL) return false;
        if(root1 != NULL && root2 == NULL) return false;
        if(root1->data != root2->data) return false;
        if(isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left)) return true;
        else if(isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right)) return true;
        else return false;
    }
};

//TIME COMPLEXITY - O(min(M,N)), SPACE COMPLEXITY - O(min(H1,H2) (height of tree)
// two root nodes are passed of the tree
