/***************************************************************************************
 * Jeffrey LeBlanc
 * CSCI-210-M01 CRN: 10525
 *  Professor: Lynette Jackson
 *  10/21/15
 *  This program implements a linked list.
 *  PLEASE NOTE: This program uses the C++11 standard.
 *  It may be necessary to enable this in your compiler settings or flags.
 *  Although Visual Studio should compile it.
 *  If you are using minGW to compile it, you may need to add the flag "-std=c++11" to enable the newest standard
 *  g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 is what I used.
 *  I have instructions to enable this via eclipse on the discussion board, or you can google
 *  "enabling c++11" for whatever IDE and compiler you are using.
 ****************************************************************************************/
#include <iostream>
#include <cmath>
#include "LinkedListFinal.h"
using namespace std;

namespace linkedList
{

double myRound( double x ) //Used to cut off the long trailing numbers after the decimal point in the randomly generated double.
{
	return truncf(x * 100000.0) / 100000.0;  //Use truncf to change the double to one with only 5 decimal places
}

 void LinkedList::appendNode(double num) //Insert a node at the end of the list.
{
	 ListNode *newNode; //To point to a new node
	 ListNode *nodePtr;	//to move through the list
	 num = myRound(num); //Call myRound to format the number of decimal places to only 5. Allows comparison using '=='
	 newNode = new ListNode; //Allocate a new node
	 newNode->value = num; //and store num there.
	 newNode->next = nullptr; //Set the next value to nullptr

	 if(!head)//If there are no nodes in the list, make newNode the first node.
	 {
		 head = newNode;
	 }
	 else //Otherwise, insert newNode at end.
	 {
		 //Init. nodePtr to head of list.
		 nodePtr = head;

		 while (nodePtr->next) //While the next node after nodePtr is not null
		 {
			 nodePtr = nodePtr->next; //Assign nodePtr to that node
		 }
		 nodePtr->next = newNode;  //Insert newNode as the last node.
	 }
}

 void LinkedList::displayList() const //Step through the list and display each node, as well as it's position in the list.

 {
	 ListNode *nodePtr; //To move through the list
	 int nodeCount = 0; //Used to keep track of the nodes
	 nodePtr = head; //Assign nodePtr to the head node of the list

	 while (nodePtr) //While nodePtr is not pointing to a null (Or while the linked list is not empty), traverse the list.
	 {
		 nodeCount++; //Increase the node count
		 cout << "#"<<nodeCount<<": " << nodePtr->value << endl; 	 //Display the value in this node.
		 nodePtr = nodePtr->next;  //Move to the next node.
	 }
 }

int LinkedList::countNode() const //Step through the list, count the number of nodes, and return the number as an int.
	 {
	 	 ListNode *nodePtr; //To move through the list
	 	 int nodeCount = 0; //Used to keep track of the nodes
	 	 nodePtr = head; //Assign nodePtr to the head node of the list

	 	 //While nodePtr points to a node, traverse the list.
	 	 while (nodePtr) //While nodePtr is not pointing to a null (Or while the linked list is not empty)
	 	 {
	 		 nodeCount++; //Increase the node count
	 		 nodePtr = nodePtr->next;  //Move to the next node.
	 	 }
	 	 return nodeCount; //Return the number of nodes.
	  }

 void LinkedList::insertNode(double num)	//Insert a node in the list at the location before the first value that is higher than it's value (double)
 {
	 ListNode *newNode;	//A new node
	 ListNode *nodePtr; //To traverse the list
	 ListNode *previousNode = nullptr; //The previous node
	 num = myRound(num); //Round the number entered
	 newNode = new ListNode; //Allocate a new node and
	 newNode->value = num; // store num there.

	//If there are no nodes in the list make newNode the first node
	 if (!head)
	 {
		 head = newNode; //Assign head pointer to the newNode
		 newNode->next = nullptr; //Assign new node's next pointer to nullptr
	 }
	 else //Otherwise, insert newNode
	 {
		 nodePtr=head; //Position nodePtr at head of list.
		 previousNode = nullptr; //Assign previousNode to nullptr

		 //skip all nodes whose value is less than num.
		 while((nodePtr != nullptr) && (nodePtr->value < num))
		 {
			 previousNode = nodePtr; //Previous node is assigned to nodePtr
			 nodePtr = nodePtr->next; //nodePtr is assigned to the next node in it's list
		 }
		 //If the new node is to be the 1st on the list, insert it before all other nodes.
		 if(previousNode == nullptr)
		 {
			 head = newNode; //place newNode as the new head
			 newNode->next = nodePtr; // newNode points to the old head, where nodePtr is still pointing to
		 }
		 else //Otherwise insert after the previous node.
		 {
			 previousNode->next = newNode; // Change the previousNode next pointer to the new node
			 newNode->next = nodePtr; //Have the newNode point to the Node that was identified as the value greater than num
		 }
	 }
 }

 void LinkedList::insertNode(long insertPos)	//Insert  a node into location (long)
 {
	     ListNode *newNode;	//A new node
	 	 ListNode *nodePtr; //To traverse the list
	 	 ListNode *previousNode = nullptr; //The previous node
	 	 int nodeCount = 0; //Counter to keep track of how many nodes we are traversing in the list
		 newNode = new ListNode; //Allocate a new node and store num there.
	 	 double inputValue;  //Get the value to input at the posNode

	 	 cout << "\nPlease enter the value you want to input in node #" << insertPos <<" "<<endl;
	 	 cin >> inputValue;
	 	 inputValue = myRound(inputValue); //Call this function to cut off any trailing decimal's in the double
	 	 newNode->value = inputValue; //assign newNode's value that of inputValue

	 	//If there are no nodes in the list make newNode the first node
	 		 if (!head)
	 		 {
	 			 head = newNode; //Assign head newNode's value
	 			 newNode->next = nullptr; //assign newNode-> to a null pointer
	 		 }
	 		else //Otherwise, insert newNode
	 			 {
	 				 nodePtr=head; //Position nodePtr at head of list.
	 				 previousNode = nullptr;  //Init previousNode to nullptr

	 				 while((nodePtr != nullptr) && (nodeCount < insertPos-1)) //Traverse the list until the position indicated is reached
	 					 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	//Subtract one to convert to machine format from human input
	 						 {
	 							 previousNode = nodePtr; //assign previousNode to the nodePtr
	 							 nodePtr = nodePtr->next; //assign nodePtr to the next node
	 							 nodeCount++; //increase the nodeCount
	 						 }

	 						 if(previousNode == nullptr)	//If the new node is to be the 1st on the list, insert it before all other nodes.
	 						 {
	 							 head = newNode; //place newNode as the new head
	 							 newNode->next = nodePtr; // newNode points to the old head, where nodePtr is still pointing to

	 						 }
	 						else //Otherwise insert after the previous node.
	 						 {
	 							 previousNode->next = newNode; // Change the previous Node next pointer to the new node
	 							 newNode->next = nodePtr; //Have the newNode point to the Node that was identified as the value greater than num

	 						 }
	 			 }
 }

 void LinkedList::deleteNode(double num) //Search for a node whose value is equal the double value and delete it

 {
	 ListNode *nodePtr;	//To traverse the list
	 ListNode *previousNode; //To point to the previous node

	 if (!head) //If head is null, the list is empty & do nothing
		 return;

	 if (head->value == num)	 //Determine if the first node is the one to delete.
	 {
		 nodePtr = head->next; //Assign nodePtr to the node after head, or head's next *
		 delete head; //Delete the node structure that head points to
		 cout<<"\nDeleted first node! "<<endl;
		 head = nodePtr; //Update head with the new nodePtr's structure
	 }

	 else
	 {
		nodePtr = head; //Initialize nodePtr to head of list

		 //Skip all nodes whose value member is not equal to num
		 while (nodePtr != NULL && (nodePtr->value != num)) //Check if nodePtr is not null and if its value is = to num
		 {
			 previousNode = nodePtr; //Assign the previous node to the current node pointer
			 nodePtr = nodePtr->next; //Update the nodePtr to the next node, then again compare value to num
		 }

		 //If nodePtr is not at the end of the list, link the previous node to the node after nodePtr, then delete nodePtr
		 if (nodePtr  )
		 {
			 previousNode->next = nodePtr->next; //Assign the previous node's next pointer to the one "after" nodePtr; its next *
			delete nodePtr; //Delete the node structure nodePtr is pointing to
			 cout<<"\nDeleted node "<<endl;
		 }
		 else
			 cout<<"Value not found!"<<endl;
	 }
 }

 void LinkedList::deleteNode(long numNode) //Delete a specific node number.
 {
	 //This must traverse the list and count each node down until it finds the int that it is going to delete
	 if(numNode  <=0)
	 {
		 cout<< "\nYou must enter a number greater than 0."<<endl;
		 return;
	 }

	 int nodeCount = 0;
	 ListNode *nodePtr;	 //To move through the list
	 ListNode *previousNode; //To point to the previous node
	 //If the list is empty, do nothing.
		 if (!head) //If head is null, the list is empty
			 return;

		 //Determine if the first node is the one.
		 if (numNode == 1)
		 {
			 nodePtr = head->next; //Assign nodePtr to the node after head, or head's next *
			 delete head; //Delete the node structure that head points to
			 head = nodePtr; //Update head with the new nodePtr's structure
			 cout<<"\nDeleted node #1"<<endl;

		 }
		 else
		 {
		 nodePtr = head; 	//Position nodePtr at the head of the list.


		 while (nodePtr && nodeCount < numNode-1)		 //While nodePtr points to a non empty node, traverse the list until the number asked for is reached
		 {
				previousNode = nodePtr; //Assign the previous node to the current node pointer
			    nodePtr = nodePtr->next; // Set nodePtr to the next node.
			    nodeCount++; 	//Increment the count of each node as we traverse the list
		}

		 //If a node is entered that dosen't exist in this list.
		 if(numNode-1 > nodeCount)
		 {
			 cout << "\nThere is not a node # " << numNode << " in this list. The number of nodes in this list is " << nodeCount  <<endl;
		 }
		 else
		 {
			 //If nodePtr is not at the end of the list, link the previous node to the node after nodePtr, then delete nodePtr
					 if (nodePtr)
					 {
						 previousNode->next = nodePtr->next; //Assign the previous node's next pointer to the one "after" nodePtr; its next *
						 delete nodePtr; //Delete the node structure nodePtr is pointing to
						 cout<<"\nDeleted node #"<<numNode;
					 }
		 }
		}
 }
}
