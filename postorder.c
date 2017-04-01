/*DOCUMENTATION:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)

-Program use: To print the complete tree in inorder pattern

-postorder: left node--right node--root.

-Parameters: the address of the root.

-Return type:Void as the output is generated on the console itself.


*/
void postOrder(struct avl *temp)
{
	if(temp != NULL)//checking whether we have reached the leaf node or not.
	{
        	postOrder(temp->left);// calling function recursively passing the left node's address as parameter.
		postOrder(temp->right);//calling function recursively passing the right node's address as parameter.
		printf("%d ", temp->data);//printing the data element.
    	}
}
