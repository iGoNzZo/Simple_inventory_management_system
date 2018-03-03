#include "inventory.h"
#include <algorithm>

namespace B	{
	void inventorySpace()	{
		cout << "\t\tHello From inventorySpace..." << endl;
	}
}

Inventory::Inventory()	{}
Inventory::Inventory(vector<Product> v)	{}

void Inventory::add(Product i)	{
	items.push_back(i);
}

Product Inventory::getProduct(int i)	{
	return items[i];
}

vector<Product> Inventory::getInventory()	{
	return items;
}

int Inventory::getTotalCount()	{
	int totCount = 0;
	for(int i = 0; i < items.size(); i++)	{
		totCount = totCount + items[i].getCount();
	}
	return totCount;
}

double Inventory::getTotalPrice()	{
	double sum = 0;
	for(int i = 0; i < items.size(); i++)	{
		sum = sum + (items[i].getPrice() * items[i].getCount());
	}
	return sum;
}

stack<string> Inventory::getProductList()	{
	stack<string> productList;
	for(int i = 0; i < items.size(); i++)	{
		productList.push(items[i].getProductName());
	}
	return productList;
}

bool Inventory::myFinder(string s)	{
	Product p(0, s, "", 0.00, 0);
	bool found;
	if(find(items.begin(), items.end(), p) != items.end())	{
		found = true;
	}
	return found;
}

list<string> Inventory::getTypes()	{
	list<string> types;

	for(int i = 0; i < items.size(); i++)	{
			types.push_back(items[i].getType());
	}
	types.unique();
	return types;
}

int Inventory::getSize()	{
	return items.size();
}
