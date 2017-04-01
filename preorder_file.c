/*DOCUMENTATION:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)

-Program use: To print the complete tree in inorder pattern on console and as well on file

-pre order:root---left node--right node.

-Parameters: the address of the root and file pointer pointing to file.

-Return type:Void as the output is generated on the console itself and on the file.


*/
void preorder(struct avl *temp,FILE *fo)
{
	
	
	if(temp != NULL)//checking whether we have reached the leaf node or not.
    	{       
		printf("%d ", temp->data);//printing the data element.
		fprintf(fo,"%d\t",temp->data);//printing the data element on the file.
        	preorder(temp->left,fo);// calling function recursively passing the left node's address as parameter as well as the file 						pointer.
        	preorder(temp->right,fo);// calling function recursively passing the right node's address as parameter as well as the file 						pointer.
    	}
}
