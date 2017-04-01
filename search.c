/*DOCUMENTATION
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)
-Program use:It is used to check whether a value exists or not.It is also used to search a particular value.
-Parameters:Address of the root node and the number to be searched.
-Return type:It is integer.It returns the value to be searched if it exists otherwise it returns 0. 
*/

int search(struct avl* root,int num)
{
	struct avl* temp;	//Declaring a temporary object temp of structure avl.
	temp=root;		//Initializing temp with root.
	while(temp!=NULL)	//Checking if temp is not NULL.Loop will terminate if it is NULL.
    	{
        	if(temp->data==num)	//Checking if data of temp is equal to number to be searched.
            		return temp->data; //it will return the number if it is true.
        	else if(temp->data<num)		//Checking if data of temp is less than number to be searched.
            		temp=temp->right;	//Incrementing temp to temp->right.
        	else if(temp->data>num)		//Checking if data of temp is greater than number to be searched.
           		temp=temp->left;	//Incrementing temp to temp->left
    	}
    	return 0;		//It will return 0 if it comes out of the loop
}
