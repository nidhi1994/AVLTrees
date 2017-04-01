/*DOCUMENTATION:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)

-Program use: To calculate the balance factor which is used to check whether the rotation is required or not and if required then which rotation is also decided with the help of balance factor.

-formula used:balance factor = height of the left subtree - height of right subtree.

-Parameter: the node address whose balance factor is to be found

-Return type: integer as we would be returning the balance factor.

-Other program used for the functioning of this program is height which calculates the height of tree and returns it.
*/
int balanceFactor(struct avl* temp)
{
    if (temp == NULL)//checking whether head is NULL that is whether the tree is empty or not 
        return 0;// if the tree is empty then return zero
    else
    return height(temp->left) - height(temp->right);//if not then calculate the height of left subtree and right subtree and subtracting them,result is balance factore which is returned.
}
