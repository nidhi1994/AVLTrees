/*DOCUMENTATION:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)

-Program use: To print the complete tree in inorder pattern in the file and console.

-post order: left node---right node---root.

-Parameters: the address of the root and the file pointer pointing to the file.

-Return type:Void as the output is generated on the console itself and also stored on file.


*/

void postorder(struct avl *temp,FILE *fo)
{
	if(temp != NULL)//checking whether we have reached the leaf node or not.
    	{       
		postorder(temp->left,fo);// calling function recursively passing the left node's address as parameter as well as the file 						pointer.
		postorder(temp->right,fo);// calling function recursively passing the right node's address as parameter as well as the file 						pointer.
		printf("%d ", temp->data);//printing the data element.
		fprintf(fo,"%d\t",temp->data);//printing the data element on the file.
    	}
}
