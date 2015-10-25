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
#include <random>
#include <chrono>
#include <string>
#include <math.h>
using namespace std;

#include "LinkedListFinal.h"
using namespace linkedList;

int main()
{
	LinkedList list; //Define  a linked List
	cout << "totalNodes: " << list.countNode()<<endl;
	{
//----------------------------------------------------
		//Generate a random number seed using time since UNIX epoch
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
		//Seed the mt19937 random generator
	std::default_random_engine mt(seed);
		//Get a double from numbers 1 to 100
	std::uniform_real_distribution<double> dist(1, 10);
//---------------------------------------------------------------

		//Append 10 nodes using the dist(int, int) so that each node is a random double between 1 and 10
	for (double i=0; i<10; ++i)
		list.insertNode(dist(mt)); //Insert a random double between 1 and 10 into the Linked List
	cout<<"\nPopulated the list with 10 random doubles"<<endl;
	list.appendNode(100.100);//Demonstrate the appendNode function, adds a node to the end of list
	cout<<"\nAppended 100.100 to the list.\n";
}
	cout << "totalNodes: " <<list.countNode()<<endl;
	//Display the values in the list.
	list.displayList();

	//Insert a node in front of a node in the list beneath the first node that contains the larger value, or allow the user
	//choose a specific spot by typing # then position first.
{
		string insertNum; //String to hold the insert choice
		locale loc; //locale to allow substr() to work

	do{
	cout<<"\nPlease enter a double you would like to insert in the list, or if you want to enter a value into a specific position then type # followed by the position you would like to enter 1 to 11\ne.g. #3\n";
	cin >> insertNum;
	}while (!isdigit(insertNum[0]) && (insertNum[0] != '#' || insertNum.empty()) ); //check if entry begins with an #. If it does, then do list.insertNode(long) to insert at a position indicated behind #. If not,
																																		   //and if a number was entered, the search the list for the first number larger than the number entered, and insert
																																		   //node into the position before that.
																																		   //e.x. #3 -> inserts a number into position #3. '3' inserts the number 3 itself
	if (isdigit(insertNum[0]))
	{
		double insertNumDouble; //Used to hold the double converted from string
		insertNumDouble = strtod(insertNum.c_str(), nullptr); //Convert the string into a double
		list.insertNode(insertNumDouble); //Call insertNode with this new double, to insert in the specific position
	}

	else
	{
		string substrInsertNum = insertNum.substr(1); //Use substr to remove the '#' from entry (as in, remove the first character)
		long insertPos; //Used to hold the insertPosition after the '#' is stripped
		insertPos = strtol(substrInsertNum.c_str(), nullptr,0); //Use strol to convert string into a long
		while(insertPos <= 0)
		{
			cout << "You must enter a number greater than 0."<<endl;
			cin >> insertPos;
		}
		list.insertNode(insertPos); //Call list.insertNode with the position to insert
	}
}

	list.displayList(); //Display the updated list

	//Delete a node containing a specific value, or type # then the position of the node you want to delete.
	{
	string deleteNum; //String used to hold the input
	locale loc; //Set locale for str functions
	do{
		cout<<"\nPlease enter a double you would like to delete from the list, or if you want to enter a value into a specific position then type # followed by the position you would like to delete 1 to 11\ne.g. #3\n";
		cin >> deleteNum;
		}while (!isdigit(deleteNum[0]) && (deleteNum[0] != '#' || deleteNum.empty()) ); //Test to see if entry is a '#' or a number or if it's null

		if (isdigit(deleteNum[0])) //If a digit and not '#', then delete that exact number from the linked list
		{
			double deleteNumDouble; //Used to hold the converted string to double
			deleteNumDouble = strtod(deleteNum.c_str(), nullptr); //Convert string to double using strtod
			cout << "\n Deleting " << deleteNumDouble <<endl;
			list.deleteNode(deleteNumDouble); //call the deleteNode(double) function
		}

		else
		{
			string substrDeleteNum = deleteNum.substr(1); //Remove the '#' from the string
			long deletePos;
			deletePos = strtol(substrDeleteNum.c_str(), nullptr,0); //Assign the string to the deletePos (long)
			while(deletePos <= 0)
			{
				cout << "You must enter a number greater than 0."<<endl;
				cin >> deletePos;
			}
			list.deleteNode(deletePos); //Call list.deleteNode(deletePos) to delete the node at position deletePos
		}
	}

	cout << "\nFinished deleting operations. Printing new list:\n";
	list.displayList(); //Display the list
	{

		//int totalBeforeDeleteNodes = totalNodes; //We have to set totalBeforeDeleteNodes because every time a delete operation is called, the totalNodes count goes down
		while(list.countNode()) //Delete each node until the totalBeforeDeleteNodes is reached
		{
			list.deleteNode((long)1); //Delete the first node in. It calls 1 not x because each time a node is deleted, its size changes. We are going to delete the first node until we go through the entire list
			cout<<"\nThere are " << list.countNode() << " nodes left in the list.";
		}
	}
	cout << "\nDeleted the entire list."<<endl;
	list.displayList(); //Display the list.
	cout <<endl<<"Press any key to exit."<<endl;
	string anykey;
	cin>>anykey;
	return 0;
}
