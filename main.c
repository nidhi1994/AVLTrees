/*
	Documentation:
-Author's Name: Nidhi Mehta(121029)
		Urja Patel(121058)
		Vaishali Upadhyay(121059)
-Course Name:Data structures and algorithms
-Project title:Build an AVL tree(Adelson-Vellinski Tree)
-Instructor's Name:Prof.Sanjay Chaudary
-Due date:13th October 2013
-Problem Statement:Firstly the construction the tree we would be balancing the tree with the principle of AVL trees.
 We would further be inserting and balancing it such that the resultant tree would be AVL tree. Moreover deletion facility would also be provided.There would
 also be a function to calculate the height and the balancing factor. The height would be of use when the deletion would occur and we have to check
 the ancestor's balance factor. The balance factor would be of use when you want to balance the tree in accordance to AVL properties.
 There would also be the search function which would be in use while searching for a particular node and while deleting a particular node.
 There would be function for the rotation which would be used for the balancing. There can be single rotation and double rotation depending where the
 insertion takes place. Thus the most important part in the project would be continuously checking and balancing of tree if required.If one wants to search
 for a particular node , then in case of BST it might be the 100th node because of lack of balancing and as a result one would have to traverse the whole tree
 which would decrease the efficiency. And in case of AVL tree the node    would be at least at the same position or lesser. This would result in a better search
 and better efficiency. Similarly deletion would also be better.But here it is important to note that AVL trees are rigidly balanced so insertion and removal
 is difficult.
-Programming Language:C programming.
*/

#include<stdio.h>	//Contains the standard input and output.
#include<stdlib.h>	//Contains the standard input and output for file.
#include"avl.h"		//Contains the declaration of structure avl and related functions.
#include"height.c"	//Contains the definition of height function.
#include"rightrotate.c"	//Contains the definition of right rotate function.
#include"leftrotate.c"	//Contains the definition of left rotate function.
#include"balancefact.c" //Contains the definition of balance factor function.
#include"preorder.c"	//Contains the definition of function to print in preorder on the console.
#include"delete.c"	//Contains the definition of succesor and delete function.
#include"preorder_file.c"	//Contains the definition of function to store output according to preorder traversal.
#include"search.c"	//Contains the defintion of search function.
#include"insert.c"	//Contains the definition of newNode and insertNode function.
#include"inorder.c"	//Contains the definition of function to print in inorder on the console.
#include"inorder_file.c"//Contains the definition of function to store output according to inorder traversal.
#include"postorder.c"	//Contains the definition of function to print in inorder on the console.
#include"postorder_file.c"//Contains the definition of function to store output according to inorder traversal.
int main()
{
	struct avl* root;		//declaring root node.
	root=NULL;			//initializing it with NULL value.
	int no,op,ch;			//no=for taking the input number,op=selecting option from menu.ch=choosing option from the nested 							switch case in case 8.
	FILE* fp;			//fp=file pointer for input file.
	FILE* fo;			//fo=file pointer for output files.
	fp=fopen("input.txt","w");
 int c, n;	//Opening the file to read.
	do
	{
		printf("\n----------Menu----------\n");
		printf("1)Insert\n2)Preorder Print\n3)Inorder Print");
        	printf("\n4)Postorder Print\n5)Search\n6)Height\n7)Delete\n8)Store output\n9)Exit");
        	printf("\nEnter Your Choice :");
        	scanf("%d",&op);	//inputs option selected by the user.
        	switch(op)
        	{
	        	case 1:

				for (c = 1; c <= 6000000; c++) // loop for taking 6000000 numbers
				{
    					n = rand()% 6000000+1;//random generation of numbers
					if(search(root,n))// checking whether the number belongs to tree.
					{
						continue;//if not then continue with the loop
					}
					else
					{
						root=insertNode(root,n);//inserting the randomly got the number in the avl.
    						fprintf(fp,"%d\n",n);//printing in the file
					}
				}
				fclose(fp);//closing the file.

  			break;


        		case 2:
				if(root==NULL)					//Checking if tree is empty.
				{
					printf("Sorry no values there in the tree to be displayed\n");
					break;
				}
				preOrder(root);					//Calling the function preOrder to print in preorder traversal.
				break;


        		case 3:
				if(root==NULL)					//Checking if tree is empty.
				{
					printf("Sorry no values are there to be displayed\n");
					break;
				}
				inOrder(root);					//Calling the function inOrder to print in inorder traversal.
				break;

			case 4:
				if(root==NULL)					//Checking if tree is empty.
				{
					printf("Sorry no values are there to be displayed\n");
					break;
				}
				postOrder(root);				//Calling the function postOrder to print in postorder 											traversal.

			break;

			case 5:
				if(root==NULL)					//Checking if tree is empty.
				{
					printf("Sorry no values are there in tree to search \n");
					break;
				}
				printf("Enter the value to be searched\n");
				scanf("%d",&no);				//inputs number to be searched.
				if(search(root,no)==0)				//Calling the function search checking if the value to be 											searched does not exist.
                		{
					printf("Value does not exist\n");
                   			 break;
                		}
				printf("The value is %d",search(root,no));	//Calling the function search and displaying the value if it 											exists.
				break;

			case 6:
				if(root==NULL)					//Checking if tree is empty.
				{
					printf("Sorry no values are inserted to display the height\n");
					break;
				}
				printf("%d",root->height);			//displays the height of the height of the tree that is the 											height of the root.
				break;
			case 7:
				if(root==NULL)					//Checking if tree is empty.
				{
					printf("Sorry no values are there to be deleted\n");
					break;
				}
				fo=fopen("delete_nums.txt","w");//opening the file for storing the numbers deleted
				fp=fopen("delete_not.txt","w");//opening the file for storing the numbers that were inserted but not deleted
				for (c = 1; c <= 600000; c++)//loop for taking 500 numbers
				{

					n = rand()%6000000+1;//random generation of numbers between 1 to 6000000
					if(search(root,n)==0)//checking whether the number to be deleted is not in tree
					{
					fprintf(fp,"%d\n",n);//printing in file

                    			continue;//continue with the loop
                		        }
					else
					{

					fprintf(fo,"%d\n",n);//printing in the file
					root=Delete(root,n);//calling the delete function with the number passed.

					}
				}
				fclose(fo);//closing files
				fclose(fp);//closing files

				break;
			case 8:
				if(root==NULL)					//Checking if tree is empty.
				{
					printf("Sorry no contents are there to be written into the file\n");
					break;
				}
				printf("Choose traversal to be stored in a file:\n");
				printf("1.preorder\n2.inorder\n3.postorder\n");
				scanf("%d",&ch);				//Inputs the choice of the user to choose a particular traversal.
				printf("Writting into the file\n");
				if(ch==1)					//checks if choice is 1 then performs the operations.
				{

					printf("The contents of the output file are:\n");
					fo=fopen("output_pre.txt","w");		//Opens the file to write and hence store the output.
					preorder(root,fo);			//Calls the function preorder to store in output in preorder 											traversal.
					fclose(fo);				//closes the file.
					break;
				}
				else if(ch==2)					//checks if choice is 2 then performs the operations.
				{
					printf("The contents of the output file are:\n");
					fo=fopen("output_in.txt","w");		//Opens the file to write and hence store the output.
					inorder(root,fo);			//Calls the function inorder to store in output in inorder 											traversal.
					fclose(fo);				//closes the file.
					break;
				}
				else if(ch==3)
				{

					printf("The contents of the output file are:\n");
					fo=fopen("output_post.txt","w");	//Opens the file to write and hence store the output.
					postorder(root,fo);			//Calls the function inorder to store in output in inorder 											traversal.
					fclose(fo);				//closes the file.
					break;
				}
				else
					printf("Wrong choice!!\n");		//In case user enters some other number apart from 1,2,3.
			case 9:
				break;						//Exit

			default:
				printf("Wrong Choice!!\nPlease enter a choice less than or equal to 9!!");//In case the user does not select 															any of the above choices
				break;
 	        }
 	    }while(!(op==9));							//The loop terminates if selected option is 9.That is it 											exits.


 		 return 0;
}
