/*DOCUMENTATION:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)

-Program use: To calculate the height of tree/ subtree which is used in case there is a new node or a node is deleted that is there is change in height. This program is also used in balance factor.

-Parameters: the address of the node whose height you want to calculate.

-Return type: integer as we want the heihgt of the desired node.
*/
int height(struct avl* temp)
{
    if (temp == NULL)//checking whether head is NULL that is whether the tree is empty or not 
        return 0;//returns zero if confition is true
    else
    return temp->height;//return height of the node which is passed as parameter.
}
