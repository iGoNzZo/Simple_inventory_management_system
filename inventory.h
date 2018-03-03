#ifndef inventory_h
#define inventory_h

#include <vector>
#include <list>
#include <stack>
#include "product.h"

using namespace std;

namespace B	{
	void inventorySpace();
}

class Inventory	{
	protected:
		vector<Product> items;
		
	public:
		Inventory();
		Inventory(vector<Product> v);
		void add(Product item);
		int getTotalCount();
		int getSize();
		double getTotalPrice();
		list<string> getTypes();
		bool myFinder(string s);
		stack<string> getProductList();
		vector<Product> getInventory();
		Product getProduct(int i);
		string name();
};
#endif