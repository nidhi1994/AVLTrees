struct avl* successor(struct avl* root)
{	while(root->left!=NULL)
	root=root->left;
	return root;

}
struct avl* Delete(struct avl* root,int no)
{	
	int bfact;
	if(root==NULL)
	{
		return root;

	}
	else if(no<root->data)
	{
		root->left=Delete(root->left,no);
	}
	else if(no>root->data)
	{
	 	root->right=Delete(root->right,no);
	}
	else
	{
			if(root->left==NULL||root->right==NULL)
        	   	{
        	       		struct avl* temp;
        	       		if(root->left!=NULL)
        			        temp=root->left;
            			else if(root->right!=NULL)
                			temp=root->right;
            			else
                			temp=NULL;
            			if(temp==NULL)
	                	{
					temp=root;
		                	root=NULL;
	                	}
		        	else
                		{
                    			struct avl* temp2;
                    			temp2=root;
                    			root=temp;
                    			temp=temp2;
				}
				free(temp);
		  	}
		   	else
	  		{    
				struct avl* temp;
				temp=successor(root->right);
				//printf("%d",temp->data);
				root->data=temp->data;
				root->right=Delete(root->right,temp->data);

	  		}
	}
	if (root == NULL)
	return root;
	if(height(root->left)>height(root->right))
	root->height=height(root->left)+1;
	else
	root->height=height(root->right)+1;
	bfact = balanceFactor(root);
    	if (bfact > 1 && (balanceFactor(root->left))>=0)
        	return rightRotate(root);
    	if (bfact < -1 && balanceFactor(root->right)<=0)
        	return leftRotate(root);
    	if (bfact  > 1 && balanceFactor(root->right)<0)
    	{
        	root->left =  leftRotate(root->left);
        	return rightRotate(root);
    	}
    	if (bfact  < -1 && balanceFactor(root->left)>0)
    	{
        	root->right = rightRotate(root->right);
        	return leftRotate(root);
    	}
	return root;
}
