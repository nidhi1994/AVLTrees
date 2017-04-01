/*DOCUMENTATION:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)

-Program use: To print the complete tree in inorder pattern on console and as well on file

-pre order:root---left node--right node.

-Parameters: the address of the root .

-Return type:Void as the output is generated on the console itself.


*/

void preOrder(struct avl *temp)
{
	if(temp != NULL)//checking whether we have reached the leaf node or not.
	{
        	printf("%d ", temp->data);//printing the data element.
		preOrder(temp->left);// calling function recursively passing the left node's address as parameter as well as the file pointer.
        	preOrder(temp->right);// calling function recursively passing the right node's address as parameter as well as the file 					pointer.
    	}
}
