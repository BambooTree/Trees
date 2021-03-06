// C program for different tree traversals 
#include <iostream> 
#include <bits/stdc++.h> 
using namespace std;

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
	
}; 


/* Computes the number of nodes in a tree. */
int size(Node* root)  
{  
    if (root == NULL)  
        return 0;  
    else
    {
    	int leftsize = size(root->left);
    	int rightsize = size(root->right);
        int totalsize = leftsize+rightsize+1;
        return totalsize;
       
    }
}

int Height(Node* root)  
{  
    if (root== NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = Height(root->left);  
        int rDepth = Height(root->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* root) 
{ 
	if (root == NULL) 
		return; 

	// first recur on left subtree 
	printPostorder(root->left); 

	// then recur on right subtree 
	printPostorder(root->right); 

	// now deal with the node 
	cout << root->data << " "; 
} 

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* root) 
{ 
	if (root == NULL) 
		return; 

	/* first recur on left child */
	printInorder(root->left); 

	/* then print the data of node */
	cout << root->data << " "; 

	/* now recur on right child */
	printInorder(root->right); 
} 

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* root) 
{ 
	if (root == NULL) 
		return; 

	/* first print data of node */
	cout << root->data << " "; 

	/* then recur on left sutree */
	printPreorder(root->left); 

	/* now recur on right subtree */
	printPreorder(root->right); 
} 

void inOrder(struct Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right; 
  
    } /* end of while */
} 

// An iterative process to print preorder traversal of Binary tree 
void iterativePreorder(Node *root) 
{ 
    // Base Case 
    if (root == NULL) 
       return; 
  
    // Create an empty stack and push root to it 
    stack<Node *> nodeStack; 
    nodeStack.push(root); 
  
    /* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) 
    { 
        // Pop the top item from stack and print it 
        struct Node *Node = nodeStack.top(); 
        printf ("%d ", Node->data); 
        nodeStack.pop(); 
  
        // Push right and left children of the popped node to stack 
        if (Node->right) 
            nodeStack.push(Node->right); 
        if (Node->left) 
            nodeStack.push(Node->left); 
    } 
} 

vector<int> postorderTraversalusingSingleStack(Node* root)
 {
        vector<int> ans;
        if(!root)
            return ans;
        stack<Node*> st;
        Node* curr= root;
        while(st.empty() ==false || curr!=NULL)
        {
		   
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;   
            }
            else{
                Node* temp=st.top();
                if(temp->right==NULL)
                {
                    st.pop();
                    ans.push_back(temp->data);
                    while(st.empty() == false && st.top()->right==temp)
                    {
                        ans.push_back(st.top()->data);
                        temp=st.top();
                        st.pop();
                    }
                }
                else{
                    curr=temp->right;
                }
            }
        }
        return ans;
  }




 void Morrisinorder(Node* root) 
 {
        Node* current = root;
        while(current != NULL) 
        {
            //left is null then print the node and go to right
            if (current->left == NULL) 
            {
                cout<<current->data<<"\t";
                current = current->right;
            }
            else
             {
                //find the predecessor.
                Node* predecessor = current->left;
                //To find predecessor keep going right till right node is not null or right node is not current.
                while(predecessor->right != current && predecessor->right != NULL)
                {
                    predecessor = predecessor->right;
                }
                //if right node is null then go left after establishing link from predecessor to current.
                if(predecessor->right == NULL)
                {
                    predecessor->right = current;
                    current = current->left;
                }
                else
                { //left is already visit. Go rigth after visiting current.
                    predecessor->right = NULL;
                    cout<<current->data<<"\t";
                    current = current->right;
                }
            }
    }
}
 


void Morrispreorder(Node* root)
 {
	    Node* current = root;
        while(current != NULL) 
        {
            //left is null then print the node and go to right
            if (current->left == NULL) 
            {
                cout<<current->data<<"\t";
                current = current->right;
            }
            else
             {
                //find the predecessor.
                Node* predecessor = current->left;
                //To find predecessor keep going right till right node is not null or right node is not current.
                while(predecessor->right != current && predecessor->right != NULL)
                {
                    predecessor = predecessor->right;
                }
                //if right node is null then go left after establishing link from predecessor to current.
                if(predecessor->right == NULL)
                {
                    predecessor->right = current;
                    cout<<current->data<<"\t";
                    current = current->left;
                }
                else
                { //left is already visit. Go rigth after visiting current.
                    predecessor->right = NULL;
                    
                    current = current->right;
                }
            }
    }
}

void postOrderIterative(Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    // Create two stacks 
    stack<Node *> s1, s2;   // 2 
                              // 3 4 2
  
    // push root to first stack 
    s1.push(root); 
    Node* Node; 
  
    // Run while first stack is not empty 
    while (!s1.empty()) { 
        // Pop an item from s1 and push it to s2 
        Node = s1.top(); 
        s1.pop(); 
        s2.push(Node); 
  
        // Push left and right children 
        // of removed item to s1 
        if (Node->left) 
            s1.push(Node->left); 
        if (Node->right) 
            s1.push(Node->right); 
    } 
  
    // Print all elements of second stack 
    while (!s2.empty()) { 
        Node = s2.top(); 
        s2.pop(); 
        cout << Node->data << " "; 
    } 
} 

// An iterative process to search 
// an element x in a given binary tree  
bool iterativeSearch(Node *root, int x)  
{  
    // Base Case  
    if (root == NULL)  
        return false;  
  
    // Create an empty queue for  
    // level order traversal  
    queue<Node *> q;  
  
    // Enqueue Root and initialize height  
    q.push(root);  
  
    // Queue based level order traversal  
    while (q.empty() == false)  
    {  
        // See if current node is same as x  
        Node *root = q.front();  
        if (root->data == x)  
            return true;  
  
        // Remove current node and enqueue its children  
        q.pop();  
        if (root->left != NULL)  
            q.push(root->left);  
        if (root->right != NULL)  
            q.push(root->right);  
    }  
  
    return false;  
}  

// Function to traverse the tree in preorder 
// and check if the given node exists in it 
bool ifNodeExists(struct Node* root, int key) 
{ 
    if (root == NULL) 
        return false; 
  
    if (root->data == key) 
        return true; 
  
    /* then recur on left sutree */
    bool res1 = ifNodeExists(root->left, key); 
  
    if(res1) return true; // node found, no need to look further 
  
    /* node is not found in left, so recur on right subtree */
    bool res2 = ifNodeExists(root->right, key); 
  
    return res2; 
} 



struct Node * insert_nrec(Node * root,int key)  // 2 3  4  push 4
{

     Node *temp, *parent , *ptr;
     ptr= root;
     parent = NULL;
     while(ptr!=NULL)
     {
           parent = ptr;
           if(key <= ptr->data)
              ptr = ptr ->left;
        else if (key > ptr->data)        	   
          	  ptr = ptr->right;
         else
        return root ;
    }
      temp = new Node(key);
      if(parent == NULL)
      	    root =temp;
      else if(key <= parent ->data)
      	   parent->left = temp;
      else
           parent->right = temp;
   return root;

     

}

/* Given a non-empty binary search tree, return the node with minimum 
   key value or succedor found in that tree. Note that the entire tree does not 
   need to be searched. */
struct Node * minValueNode(Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 




struct Node * insert_rec(Node * root,int key)
{
    if(root == NULL)
    {
         root = new Node (key);
    }
    else if ( key <= root ->data)
    	root->left = insert_rec(root->left, key);
    else 
    	root->right = insert_rec(root->right,key);
    return root ;
}

/* Given a binary search tree and a key, this function deletes the key 
and returns the new root */
struct Node* deleteNode(struct Node* root, int key) 
{ 
	// base case 
	if (root == NULL) return root; 

	// If the key to be deleted is smaller than the root's key, 
	// then it lies in left subtree 
	if (key < root->data) 
		root->left = deleteNode(root->left, key); 

	// If the key to be deleted is greater than the root's key, 
	// then it lies in right subtree 
	else if (key > root->data) 
		root->right = deleteNode(root->right, key); 

	// if key is same as root's key, then This is the node 
	// to be deleted 
	else
	{ 
		// node with only one child or no child 
		if (root->left == NULL) 
		{ 
			struct Node *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct Node *temp = root->left; 
			free(root); 
			return temp; 
		} 

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		struct Node* temp = minValueNode(root->right); 

		// Copy the inorder successor's content to this node 
		root->data = temp->data; 

		// Delete the inorder successor 
		root->right = deleteNode(root->right, temp->data); 
	} 
	return root; 
} 

/* Function to count nodes in a binary search tree 
using Morris Inorder traversal*/
int counNodes(struct Node *root) 
{ 
	struct Node *current, *pre; 

	// Initialise count of nodes as 0 
	int count = 0; 

	if (root == NULL) 
		return count; 

	current = root; 
	while (current != NULL) 
	{ 
		if (current->left == NULL) 
		{ 
			// Count node if its left is NULL 
			count++; 

			// Move to its right 
			current = current->right; 
		} 
		else
		{ 
			/* Find the inorder predecessor of current */
			pre = current->left; 

			while (pre->right != NULL && 
				pre->right != current) 
				pre = pre->right; 

			/* Make current as right child of its 
			inorder predecessor */
			if(pre->right == NULL) 
			{ 
				pre->right = current; 
				current = current->left; 
			} 

			/* Revert the changes made in if part to 
			restore the original tree i.e., fix 
			the right child of predecssor */
			else
			{ 
				pre->right = NULL; 

				// Increment count if the current 
				// node is to be visited 
				count++; 
				current = current->right; 
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */

	return count; 
} 


/* Function to find median in O(n) time and O(1) space 
using Morris Inorder traversal*/
int findMedian(struct Node *root) 
{ 
if (root == NULL) 
		return 0; 

	int count = counNodes(root); 
	int currCount = 0; 
	struct Node *current = root, *pre, *prev; 

	while (current != NULL) 
	{ 
		if (current->left == NULL) 
		{ 
			// count current node 
			currCount++; 

			// check if current node is the median 
			// Odd case 
			if (count % 2 != 0 && currCount == (count+1)/2) 
				return prev->data; 

			// Even case 
			else if (count % 2 == 0 && currCount == (count/2)+1) 
				return (prev->data + current->data)/2; 

			// Update prev for even no. of nodes 
			prev = current; 

			//Move to the right 
			current = current->right; 
		} 
		else
		{ 
			/* Find the inorder predecessor of current */
			pre = current->left; 
			while (pre->right != NULL && pre->right != current) 
				pre = pre->right; 

			/* Make current as right child of its inorder predecessor */
			if (pre->right == NULL) 
			{ 
				pre->right = current; 
				current = current->left; 
			} 

			/* Revert the changes made in if part to restore the original 
			tree i.e., fix the right child of predecssor */
			else
			{ 
				pre->right = NULL; 

				prev = pre; 

				// Count current node 
				currCount++; 

				// Check if the current node is the median 
				if (count % 2 != 0 && currCount == (count+1)/2 ) 
					return current->data; 

				else if (count%2==0 && currCount == (count/2)+1) 
					return (prev->data+current->data)/2; 

				// update prev node for the case of even 
				// no. of nodes 
				prev = current; 
				current = current->right; 

			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
} 

// function to print the zigzag traversal 
void zizagtraversal(struct Node* root) 
{ 
	        if (root==NULL) 
	        	return ;
        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(root);
        Node* node;
        while (s1.empty()==false || s2.empty()== false) 
        {
           
              
                while(s1.empty()==false) 
                {
                    node = s1.top();
                    s1.pop();
                    cout<<" " <<node->data<<"\t";
                    if (node->left!=NULL) 
                        s2.push(node->left);
                    if (node->right!=NULL)
                        s2.push(node->right);
                }
              
          
                 while (s2.empty()==false)
                {
                    node = s2.top();
                    s2.pop();
                     cout<<" " <<node->data<<"\t";
                    if (node->right!=NULL) 
                        s1.push(node->right);
                    if (node->left!=NULL) 
                        s1.push(node->left);
                }
             
            
        }
      
} 


// maxLevel : keeps track of maximum level seen so far. 
// res : Value of deepest node so far. 
// level : Level of root 
void find(Node *root, int level, int &maxLevel, int &res) 
{ 
	if (root != NULL) 
	{ 
		find(root->left, ++level, maxLevel, res); 

		// Update level and resue 
		if (level > maxLevel) 
		{ 
			res = root->data; 
			maxLevel = level; 
		} 

		find(root->right, level, maxLevel, res); 
	} 
} 

// Returns value of deepest node 
int deepestNode(Node *root) 
{ 
	// Initialze result and max level 
	int res = -1; 
	int maxLevel = -1; 

	// Updates value "res" and "maxLevel" 
	// Note that res and maxLen are passed 
	// by reference. 
	find(root, 0, maxLevel, res); 
	return res; 
} 

// Recursive function to print left view of a binary tree. 
void leftViewUtil(Node* root, int level, int* max_level) 
{ 
	// Base Case 
	if (root == NULL) 
		return; 

	// If this is the first node of its level 
	if (*max_level < level) { 
		cout << root->data << "\t"; 
		*max_level = level; 
	} 

	// Recur for left and right subtrees 
	leftViewUtil(root->left, level + 1, max_level); 
	leftViewUtil(root->right, level + 1, max_level); 
} 

// A wrapper over leftViewUtil() 
void leftView(Node * root) 
{ 
	int max_level = 0; 
	leftViewUtil(root, 1, &max_level); 
} 

// Iterative method to find height of Binary Tree 
void printLevelOrder(Node *root) 
{ 
    // Base Case 
    if (root == NULL)  return; 
  
    // Create an empty queue for level order tarversal 
    queue<Node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        // Print front of queue and remove it from queue 
        Node *node = q.front(); 
        cout << node->data << " "; 
        q.pop(); 
  
        /* Enqueue left child */
        if (node->left != NULL) 
            q.push(node->left); 
  
        /*Enqueue right child */
        if (node->right != NULL) 
            q.push(node->right); 
    } 
} 

bool isSameTree(Node * p, Node * q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        
        if(p->data != q->data) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(Node * node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values  
}  

int isBST(Node * node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  

 bool isMirrorTree(Node * p ,Node * q)
    {
     if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        
        if(p->data != q->data) return false;
        return isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
    }
 bool isSymmetric(Node *  root) 
 {
            if(root==NULL)
                return true;
            return isMirrorTree(root->left,root->right);
         
        
 }

 int minDepthofTree(Node* root) {
         // Corner case. Should never be hit unless the code is 
    // called on root = NULL
    if (root == NULL)
        return 0;
 
    // Base case : Leaf Node. This accounts for height = 1.
    if (root->left == NULL && root->right == NULL)
       return 1;
 
    // If left subtree is NULL, recur for right subtree
    if (!root->left)
       return minDepthofTree(root->right) + 1;
 
    // If right subtree is NULL, recur for left subtree
    if (!root->right)
       return minDepthofTree(root->left) + 1;
 
    return min(minDepthofTree(root->left), minDepthofTree(root->right)) + 1;
        
    }


// Lowest Common Ancestor of Binary  Search Tree, not BinaryTree
    Node* lowestCommonAncestorBST(Node* root, int n1, int n2) 
    {
    
    if (root == NULL) return NULL;
 
    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lowestCommonAncestorBST(root->left, n1, n2);
 
    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lowestCommonAncestorBST(root->right, n1, n2);
 
    return root;
        
    }
// Lowest Common Ancestor of binary Tree , not Binary Search Tree
    Node* lowestCommonAncestorBT(Node* root, int n1, int n2) 
    {
           // Base case
    
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->data == n1 || root->data == n2)
        return root;
 
    // Look for keys in left and right subtrees
    struct Node *left_lca  = lowestCommonAncestorBT(root->left, n1, n2);
    struct Node *right_lca = lowestCommonAncestorBT(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca!= NULL && right_lca!= NULL) 
        return root;
  if (left_lca== NULL && right_lca== NULL) 
        return NULL;
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
        
    }

// Is Tree is Balanced Tree ? Balance Tree is diff(left ,right) should be max 1
     bool isBalanced(Node* root) {
         int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */ 
 
   /* If tree is empty then return true */
   if(root == NULL)
    return 1; 
 
   /* Get the height of left and right sub trees */
   lh = Height(root->left);
   rh = Height(root->right);
 
   if( abs(lh-rh) <= 1 &&                  // difference between hieght of left and subtree should be atmost 1 ( i.e. 0,1)
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;
 
   /* If we reach here then tree is not height-balanced */
   return 0;
        
    }

    void printArray(vector<int> vect) 
	{ 
      for (int i = 0; i < vect.size(); i++) { 
       
            cout << vect[i] << " "<<"\t"; 
      //  cout << endl; 
    }
    cout<<endl;
   
}

Node* BuildTreeInPo(const vector<int>& inorder, const vector<int>& postorder,
                     int start, int end, int *pIndex,  unordered_map<int, int> &mp ) {
        if (start >= end) {
            return nullptr;
        }
        int root_val = postorder[*pIndex];
        Node* root = new Node(root_val);
        (*pIndex)--;
        int inorder_idx = mp[root_val];
        // postorder requires build right then left
        root->right = BuildTreeInPo(inorder, postorder, inorder_idx + 1, end,pIndex,mp);
        root->left = BuildTreeInPo(inorder, postorder, start, inorder_idx,pIndex,mp);
        return root;
    }
    
    Node* buildTreeInorderPostorder(vector<int>& inorder, vector<int>& postorder) {
        int len = postorder.size();
         unordered_map<int, int> mp;
      
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int postoder_Index = len-1;
        return BuildTreeInPo(inorder, postorder, 0, inorder.size(),&postoder_Index,mp);
    }

  Node* BuildTreeInOrderPreOrder(vector<int> &Inorder,vector<int> &pre,int inStart, int inEnd, int *pIndex, unordered_map<int,int>& mp) 
 {

        if(inStart > inEnd) // case to return 
            return NULL;
        
        int curr = pre[*pIndex];
        Node* root = new Node(curr);
        int inorder_idx = mp[curr];
        (*pIndex)++; // preoder traveral 
        root->left = BuildTreeInOrderPreOrder(Inorder,pre,inStart, inorder_idx -1,pIndex,mp);
        root->right = BuildTreeInOrderPreOrder(Inorder ,pre ,inorder_idx +1, inEnd,pIndex,mp);
        return root;
    }

     // global varible to indicate the preorder array index
    Node *buildTreeInPre(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();

        unordered_map<int, int> mp;// use hashmap to improve search speed
        for (int i = 0; i < n; ++i) {
            mp[inorder[i]] = i;
        }
         int pre_order_Index = 0;
     //   return helper(0, inorder.size()-1, &preS, preorder, mp);
        return BuildTreeInOrderPreOrder(inorder, preorder, 0,inorder.size()-1,&pre_order_Index,  mp);
    }

    void mirrorImage(struct Node* root)  
{ 
    if (root == NULL)  
        return;  
    else
    { 
        struct Node* temp; 
          
        /* do the subtrees */
        mirrorImage(root->left); 
        mirrorImage(root->right); 
      
        /* swap the pointers in this node */
        temp     = root->left; 
        root->left = root->right; 
        root->right = temp; 
    } 
}

bool hasPathSum(Node* root, int sum) 
{
	if(root == NULL)
	{
		return false;
	}

	if(root->left == NULL && root->right == NULL)
	{
		if(root->data == sum)
		{

			return true;
		}
		else
		{
			return false;
		}
	}
	if(hasPathSum(root->left, sum-root->data) || hasPathSum(root->right, sum - root->data))
	{
		return true;
	}
	return false;

}


/* Driver program to test above functions*/
int main() 
{ 
	struct Node *root = new Node(1); 
	root->left			 = new Node(2); 
	root->right		 = new Node(3); 
	root->left->left	 = new Node(4); 
	root->left->right = new Node(5); 

	struct Node *root1 = new Node(1); 
	root1->left			 = new Node(2); 
	root1->right		 = new Node(3); 
	root1->left->left	 = new Node(4); 
	root1->left->right = new Node(5);

	cout << "\nPreorder traversal of binary tree is \n"; 
	printPreorder(root); 

    
	cout << "\nInorder traversal of binary tree is \n"; 
	printInorder(root); 

	cout << "\nPostorder traversal of binary tree is \n"; 
	printPostorder(root); 
    
    cout << "\n Inorder iterative traversal of binary tree is \n";
	inOrder(root);

	cout << "\n Preorder iterative traversal of binary tree is \n";
	postOrderIterative(root);

   int height = Height(root);
    cout<< "\n Height of the binary Tree " <<height<<endl;
   

     bool search = iterativeSearch(root,5);
    cout<<" \n search_nrec in the binary key wiht key 5" <<search<<endl;
   

    
    bool searchrec = ifNodeExists(root,5);
    cout<<" \n search recursively in the binary with key 5 "<<searchrec<<endl;

    int Bsize = size(root);
    cout<<" \n Size of the Binary  Tree "<<Bsize<<endl;

  //  root = insert_nrec(root, 80);

    root = insert_rec(root, 90);
    printInorder(root);

     root =  deleteNode(root, 80);
     cout<<" \n After Deleting 80"<<endl;
     printInorder(root);

     cout << "\n Median of BST is "
		<< findMedian(root)<<endl; 


     cout<<" \n zizagtraversal"<<endl;
	zizagtraversal(root);

	cout << "\n the last node "<<deepestNode(root)<<endl;

    cout << "\n leftView of the tree"<<endl;
	leftView(root);


    cout << "\n Level Order traversal of binary tree is "<<endl; 
    printLevelOrder(root); 

     if(isBST(root))  
        cout<<"\nIs BST";  
    else
        cout<<"\nNot a BST";  

    bool same = isSameTree(root,root1);
    if(same)
    	cout<< "\n Same Tree"<<endl;
    else
    	cout<<"\n Not a Same Tree"<<endl;

    bool Symmetric = isSymmetric(root);
      if(Symmetric)
    	cout<< "\nSymmetric Tree "<<endl;
    else
    	cout<<"\nNot a Symmetric Tree "<<endl;

    int minDepth = minDepthofTree(root);
    cout<<"\n Min Depth"<<minDepth<<endl;
    cout<<"\n lowestCommonAncestorBST  "<<lowestCommonAncestorBST(root,3,4)->data<<endl;
    cout<<"\n  lowestCommonAncestorBT  "<<lowestCommonAncestorBT(root,3,4)->data<<endl;

    bool isBalancedBT = isBalanced(root);
      if(isBalancedBT)
    	cout<< "\nBalanced Tree "<<endl;
    else
    	cout<<"\n Not a Balanced Tree "<<endl;

    vector<int>postorderwithonestack = postorderTraversalusingSingleStack(root);
    cout<< "\n postorderTraversalusingSingleStack"<<endl;
    printArray(postorderwithonestack);


    cout<<endl;

    cout<<" Morrisinorder  Traversal"<<endl;
    Morrisinorder(root);

    cout<<endl;
    cout<< " Morrispreorder Traversal"<<endl;
    Morrispreorder(root);



   vector<int>inorder{9,3,15,20,7};
   vector<int>postorder{9,15,7,20,3};
   vector<int>preorder{9,15,7,20,3};
    struct Node *build = buildTreeInorderPostorder(inorder, postorder);

   cout<<"\nConstruct a Treee with Inorder and Postorder"<<endl;
     printInorder(build);

   struct Node *buildInPre=  buildTreeInPre(inorder, preorder);
     cout<<"\nConstruct a Treee with Inorder and PreOder"<<endl;
     printInorder(build);


     cout<<"\n Mirror Image of a Tree"<<endl;
     mirrorImage(root);
     printInorder(root);

    cout<<"\n Has sum 20 in the Tree from Root to Leef "<<hasPathSum(root,20)<<endl;
    
		

	return 0; 
} 
