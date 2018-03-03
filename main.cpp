#include "inventory.h"
#include "product.h"
#include <cstdlib>
#include <typeinfo>
#include <exception>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale>

using namespace std;

//global invenotry variable
Inventory inventory;

//function declarations
void getInvList();
void getInvTypes();
void getInvSize();
void getInvValue();
void getInvTotalCount();
void setup();
void options();
void function();
void finder();
void prompt();
void ptrDynamic();

class invalidInput: public exception{
	virtual const char* what() const throw()	{
		return  "Invalid Option, Try again...";
	}
}badInput;

class invalidProduct: public exception{
	virtual const char* what() const throw()	{
		return "We hit the second exception";
	}
}badProduct;

template<class T>
T MostExpensive(vector<T> a)	{
	T mostExpensive = a[0];
	for(int i = 1; i < a.size(); i++)	{
		if(mostExpensive.getPrice() < a[i].getPrice())	{
			mostExpensive = a[i];
		}
	}
	return mostExpensive;
}

template<class T>
T LeastExpensive(vector<T> a)	{
	T leastExpensive = a[0];
	for(int i = 1; i < a.size(); i++)	{
		if(leastExpensive.getPrice() > a[i].getPrice())	{
			leastExpensive = a[i];
		}
	}
	return leastExpensive;
}

int main()	{
	setup();
	prompt();
	options();
	
	return 0;
}

void options()	{
	cout << "\tInventory Options: " << endl;
	cout << "\t1. Inventory Size" << endl;
	cout << "\t2. Inventory List" << endl;
	cout << "\t3. Product Types in Inventory" << endl;
	cout << "\t4. Inventory Total Value" << endl;
	cout << "\t5. Inventory Total Count" << endl;
	cout << "\t6. Check if Product is in Stock" << endl;
	cout << "\t7. Find most Expenssive Item in Inventory" << endl;
	cout << "\t8. Find least Expensive Item in Inventory" << endl;
	cout << "\t9. Namespaces and pointer-Dynamic Cast Test" << endl;
	cout << "\t0. Quit Application" << endl;
	function();
}

void function()	{
	int choice;
	cout << "\tEnter Option #: " ;
	cin >> choice;
	
	try{
		if(choice == 1)	{
			getInvSize();
		}else if(choice == 2)	{
			getInvList();
		}else if(choice == 3)	{
			getInvTypes();
		}else if(choice == 4)	{
			getInvValue();
		}else if(choice == 5)	{
			getInvTotalCount();
		}else if(choice == 6)	{
			finder(); 
		}else if(choice == 7)	{
			vector<Product> inv = inventory.getInventory();
			cout <<  "\tMost expensive Item in Inventory: " << MostExpensive(inv).getProductName() << "\n" << endl;
		}else if(choice == 8)	{
			vector<Product> inv = inventory.getInventory();
			cout << "\tLeast expensive Item in Inventory: " << LeastExpensive(inv).getProductName() << "\n" << endl;
		}else if(choice == 9){
			 using namespace B;
			 inventorySpace();
			 using namespace A;
			 productSpace();
			 
			 ptrDynamic();
			 
		}else if(choice == 0)	{
			cout << "Goodbye!" << endl;
			exit(0);
		}
		else {
			throw badInput;
		}
		options();
	}catch(exception& e)	{
		cout << e.what() << endl;
		options();
		
	}
}

void setup()	{
	Product apple(0, "apple", "fruit", 1.99, 10);
	Product orange(1, "orange", "fruit", 2.99, 7);
	Product vcr(2, "vcr", "electronic", 69.99, 2);
	Product dvdPlayer(3, "DVD player", "electronic", 79.99, 15);
	Product soil(4, "garden soil", "garden", 10.99, 9);
	Product banana(5, "banana", "fruit", 0.99, 21);
	Product camera(6, "HD Camera", "electronic", 79.99, 8);
	Product vg1(7, "BattleField", "video game", 49.99, 6);
	Product vg2(8, "Skyrim", "video game", 49.99, 5);
	Product vg3(9, "Fallout4", "video game", 19.99, 15);
	
	inventory.add(vg3);
	inventory.add(vg1);
	inventory.add(vg2);
	inventory.add(soil);
	inventory.add(camera);
	inventory.add(vcr);
	inventory.add(dvdPlayer);
	inventory.add(apple);
	inventory.add(orange);
	inventory.add(banana);
	
	Product cmbo = vg1 + vg2;
	inventory.add(cmbo);
	
	vg1.updateCountM(2);
	vg2.updateCountM(2);
}

void ptrDynamic()	{
	VideoGame vg4("Call Of Duty", 39.99, 9);
	
	VideoGame* dynamic = &vg4;
	Product* dCast = dynamic_cast<Product*>(dynamic);
	cout << "\t\tAfter Dynamic cast of video game to product" << endl;
	cout << "\t\ttrying to print using product class methods: " << dCast->printProduct() << endl;
	cout << "\t\t pointer stored at mem Address: " << &dCast << endl;
	inventory.add(*dCast);
}

void prompt()	{
	string holder = typeid(inventory.getProduct(0)).name();
	string productType = holder.substr(1, holder.length());
	cout << "----------  Welcome to my Inventory App  ----------" << endl;
	cout << "Note: inventory is intented to hold objects of type: " << productType << "\n\n";
}

void getInvSize()	{
	cout << "\tDifferent Items In Inventory: " << inventory.getSize() << "\n" << endl;
}

void getInvValue()	{
	cout << "\tInventory Total Value: " << inventory.getTotalPrice() <<  "\n" << endl;
}

void getInvTotalCount()	{
	cout << "\tTotal Items In Inventory: " << inventory.getTotalCount()  << "\n"<< endl;
}

void finder()	{
	string toFind;
	cout << "Enter product name to search for: ";
	cin >> toFind;	
	
	try	{
		if(std::any_of(toFind.begin(), toFind.end(), ::isdigit))	{
			throw badProduct;
		}
		else{
			bool wasFound = inventory.myFinder(toFind);
			if(wasFound)	{
				cout << "\t\ttitem in stock\n" << endl;
			}
			else{
				cout << "\t\titem not in stock\n" << endl;
			}
		}
	}	
	catch(exception& e)	{
		cout << e.what() << endl;
		options();
	}
}

void getInvList()	{
	cout << "\t\t -- List of Product names -- " << endl;
	stack<string> myStack = inventory.getProductList();
	while(!myStack.empty())	{
		cout << "\t" << myStack.top() << endl;
		myStack.pop();
	}
	cout << "" << endl;
}

void getInvTypes()	{
	list<string> myTypes = inventory.getTypes();
	list<string>::const_iterator it = myTypes.begin();
	myTypes.sort();
	
	cout << "\t\t-- Product Types In Inventory --" << endl;
	for(it = myTypes.begin(); it != myTypes.end(); it++)	{
		cout << "\t\t" << *it << endl;
	}
	cout << "" << endl;
}
