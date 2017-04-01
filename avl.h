/*DOCUMENTATION
Structure's Name:avl
Author's Name:Nidhi Mehta(121029)
	      Urja Patel(121058)
	      Vaishali Upadhyay(121059)
Brief Description: Structure is used to represent each node of the tree.It has 4 elements:
1.Data is used to store the number/data at each node.
2.Pointer to the left is used to point to the left child of the node.Hence sets the link between left child and the parent node.
3.Similarly ,pointer to the right points to the right child of the node.Hence sets the link between right child and the parent node.
4.Height stores the current height of each node.
*/
struct avl
{
    int data;		
    struct avl* left;
    struct avl* right;
    int height;
};
int height(struct avl* temp);		//function to find height of tree.
struct avl* newNode(int no);		//function to locate the newnode.
struct avl* rightRotate(struct avl* temp);	//Function to right rotate about a particular node.
struct avl* leftRotate(struct avl* temp);	//Function to left rotate about a particular node.
int balanceFactor(struct avl* temp);		//Function to calculate the balance factor at each node.
struct avl* insertNode(struct avl* temp, int no);	//Function to insert the node in a tree.
void preOrder(struct avl* temp);		//Function to display elements according to preorder tree traversal.
struct avl* successor(struct avl* root);	//Function to find the left most element of right subtree.
int search(struct avl* root,int num);		//Function to search element.
struct avl* Delete(struct avl* root,int no);	//Function to delete a node.
void preorder(struct avl* temp,FILE *fo);	//Function to store output in a file in preorder traversal.
void inOrder(struct avl*);			//Function to display elements according to inorder tree traversal.
void inorder(struct avl* temp,FILE *fo);	//Function to store output in a file in inorder traversal.
void postOrder(struct avl*);			//Function to display elements according to postorder tree traversal.
void postorder(struct avl* temp,FILE *fo);	//Function to store output in a file in postorder traversal.
