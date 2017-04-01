/*DOCUMENTATION:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)

-Program use: To print the complete tree in inorder pattern

-inorder: left node---node----right node.

-Parameters: the address of the root.

-Return type:Void as the output is generated on the console itself.


*/

void inOrder(struct avl *temp)
{
	if(temp != NULL)//checking whether we have reached the leaf node or not.
	{
        	inOrder(temp->left);// calling function recursively passing the left node's address as parameter.
		printf("%d ", temp->data);//printing the data element.
        	inOrder(temp->right);//calling function recursively passing the right node's address as parameter.
    	}
}
