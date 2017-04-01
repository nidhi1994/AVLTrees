/*DOCUMENTATION
-Author's Name:Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)

-Program use:It is used when the balance factor of a node is +2.It is used to balance the tree.It is used in Insertion and Deletion.

-Parameters:The address of the node on which rotation is to be performed is passed.

-Return type:The current address of the node which was passed as a parameter.

-Program used is height.To compare the heights and hence update.
*/

struct avl* leftRotate(struct avl* temp)
{
	struct avl* T1 = temp->right;	//Declaring T1 as the temporary object of type struct avl and hence storing  temp->right in it.
	struct avl* T2 = T1->left;	//Declaring T2 as the temporary object of type struct avl and hence storing   T1->left in it.
	T1->left = temp;		//Assigning temp to T1->left.
	temp->right = T2;		//Assigning T2 to temp->right.
	if(height(temp->left)>height(temp->right))	//Comparing the height of right and left subtrees of temp.
		temp->height=height(temp->left)+1;	//updating the height of temp.
	else
		temp->height=height(temp->right)+1;	//updating the height of temp.
	if(height(T1->left)>height(T1->right))		//Comparing the height of right and left subtrees of T1.
		T1->height=height(T1->left)+1;		//updating the height of T1.
	else
		T1->height=height(T1->right)+1;		//updating the height of T1.
	return T1;					//Returning T1.
}
