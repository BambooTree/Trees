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
	// if null then return 
	if (!root) 
		return; 

	// declare two stacks 
	stack<struct Node*> currentlevel; 
	stack<struct Node*> nextlevel; 

	// push the root 
	currentlevel.push(root); 

	// check if stack is empty 
	bool lefttoright = true; 
	while (!currentlevel.empty()) { 

		// pop out of stack 
		struct Node* temp = currentlevel.top(); 
		currentlevel.pop(); 

		// if not null 
		if (temp) { 

			// print the data in it 
			cout << temp->data << " "; 

			// store data according to current 
			// order. 
			if (lefttoright) { 
				if (temp->left) 
					nextlevel.push(temp->left); 
				if (temp->right) 
					nextlevel.push(temp->right); 
			} 
			else { 
				if (temp->right) 
					nextlevel.push(temp->right); 
				if (temp->left) 
					nextlevel.push(temp->left); 
			} 
		} 

		if (currentlevel.empty()) { 
			lefttoright = !lefttoright; 
			swap(currentlevel, nextlevel); 
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

    root = insert_nrec(root, 80);
    root = insert_rec(root, 90);
    printInorder(root);

     root =  deleteNode(root, 80);
     cout<<" \n After Deleting 80"<<endl;
     printInorder(root);

     cout << "\nMedian of BST is "
		<< findMedian(root)<<endl; 


	zizagtraversal(root);

	cout << " the last node "<<deepestNode(root)<<endl;

	leftView(root);


    cout << "Level Order traversal of binary tree is \n"; 
    printLevelOrder(root); 

     if(isBST(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  

    bool same = isSameTree(root,root1);
    if(same)
    	cout<< "Same Tree"<<endl;
    else
    	cout<<"Not a Same Tree"<<endl;

    bool Symmetric = isSymmetric(root);
      if(Symmetric)
    	cout<< "Symmetric Tree "<<endl;
    else
    	cout<<"Not a Symmetric Tree "<<endl;

    int minDepth = minDepthofTree(root);
    cout<<" Min Depth"<<minDepth<<endl;
    cout<<" lowestCommonAncestorBST  "<<lowestCommonAncestorBST(root,3,4)->data<<endl;
    cout<<" lowestCommonAncestorBT  "<<lowestCommonAncestorBT(root,3,4)->data<<endl;
    
		

	return 0; 
} 
