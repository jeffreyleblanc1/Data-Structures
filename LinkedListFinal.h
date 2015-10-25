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
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace linkedList
{
class LinkedList
{
private:
	//Declare a structure for the list
	struct ListNode
	{
		double value;	//Value in this node
		struct ListNode *next; //To point to the next node
	};

	ListNode *head; //Pointer to point to the head of the list

public:
	//Constructor
	LinkedList()
	{ head = nullptr; } //Make the head pointer point to null (there isn't a first node upon constructing yet

	//Destructor - releases all the memory used by the list, by stepping through the list, deleting one node at a time.
	 ~LinkedList()
	 {
		 {
			 ListNode *nodePtr; 	//To traverse the list
			 ListNode *nextNode;		//To point to the next node
			 nodePtr = head; //Position nodePtr at the head of the list.

			 //While nodePTR is not at the end of the list...
			 while(nodePtr)
			 {
				 nextNode = nodePtr->next; //Save a pointer to the next node.
				 delete nodePtr; //Delete the current node.
				 nodePtr = nextNode; //Position nodePtr at the next node.
			 }
		 }
	 }

	//Linked list operations
	void appendNode(double); //Insert a node at the end of the list.
	void insertNode(double); //Insert a node in the list at the location before the first value that is higher than it's value (double)
	void insertNode(long); //Insert  a node into location (long)
	void deleteNode(double); //Search for a node whose value is equal the double value and delete it
	void deleteNode(long); //Delete a node in a specific position
	void displayList() const; //Step through the list and display each node, as well as it's position in the list.
	int countNode() const; //Step through the list, count the number of nodes, and return the number as an int.


};
}


#endif

