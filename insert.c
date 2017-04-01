/*DOCUMENTATION:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)
-Program use: this program is used to allocate memory to a newly inserted node and also find appropriate place where the insertion should take place.This is also used to detect where and which rotation should take place and also updation of height. 

-parameters:for insertNode--> the root node is passed and the data which is to be inserted.
		newNode-->the number that is to be inserted.

-Return type:for both the function return type is the address pointer of the node.

-other program use: height- this is used to update height.
		    balance factor- to calculate the balance factor of the node.
		    left rotate- for rotating the node on left.   
		    right rotate- for rotating the node on right.


*/
struct avl* newNode(int no)
{
    struct avl* temp = (struct avl*)malloc(sizeof(struct avl));//allocates memory
    temp->data   = no;//allocate the data
    temp->left   = NULL;//allocate NULL to the left node 
    temp->right  = NULL;//allocate NULL to the right node 
    temp->height = 1;//height is 1 as insertion will be on the leaf only everytime.
    return(temp);//returning the address of the newly created node
}

struct avl* insertNode(struct avl* temp, int no)
{

    if (temp == NULL)//check whether null or not that is checking if we reach the leaf node
        return(newNode(no));//if null then we have reached the leaf and now we need to allocate memory.

    if (no < temp->data)//checking whether the data to be entered is less than the data of the node 
        temp->left  = insertNode(temp->left, no);//if so then go on left side and call recursively passing the left node address as parameter with the number
    else
        temp->right = insertNode(temp->right, no);//calling the function recursively passing the right node address as parameter with the number
    if(height(temp->left)>height(temp->right))//comparing the height.
	temp->height=height(temp->left)+1;//update height
    else
	temp->height=height(temp->right)+1;//update height
    int balance = balanceFactor(temp);//taking balance factor and storing in balance
    if (balance > 1 && no < temp->left->data)//checking if the balance factor is more than 1 i.e 2 and whether insertion occured on the left side.
        return rightRotate(temp);//call rotation
    if (balance < -1 && no > temp->right->data)//checking if the balance factor is less than 1 i.e-2 and whether insertion occured on the right side.
        return leftRotate(temp);//call rotation
    if (balance > 1 && no > temp->left->data)//checking if the balance factor is more than 1 i.e 2 and whether insertion occured on the right side.
    {
        temp->left =  leftRotate(temp->left);//call rotation
        return rightRotate(temp);//call rotation
    }
    if (balance < -1 && no < temp->right->data)//checking if the balance factor is less than 1 i.e-2 and whether insertion occured on the right side.
    {
        temp->right = rightRotate(temp->right);//call rotation
        return leftRotate(temp);//call rotation
    }
return temp;//returning the new address
}
