#include "product.h"
#include <sstream>


namespace A	{
	void productSpace()	{
		cout << "\t\tHello from productSpace..." << endl;
	}
}

VideoGame::VideoGame()	{}
VideoGame::VideoGame(string s, double p, int c)	{
	name = s;
	price = p;
	count = c;
}

Product::Product()	{
	barcode = 0;
	productName = "empty";
	type = "empty";
	price = 0;
	count = 0;
}

Product::Product(int b, string n, string t, double p, int c)	{
	barcode = b;
	productName = n;
	type = t;
	price = p;
	count = c;
}

string Product::getType()	{
	return type;
}

string Product::getProductName()	{
	return productName;
}

double Product::getPrice()	{
	return price;
}

int Product::getBarcode()	{
	return barcode;
}

int Product::getCount()	{
	return count;
}

void Product::setName(string s)	{
	productName = s;
}

void Product::setPrice(double d)	{
	price = d;
}

void Product::setCount(int c)	{
	count = c;
}

void Product::setType(string s)	{
	type = s;
}

void Product::updateCountM(int c)	{
	if(c > count)	{
		cout << "Product Not in Stock" << endl;
	}
	else	{
		count = count - c;
	}
}

void Product::updateCountP(int c)	{
	if(c > count)	{
		cout << "Product Not in Stock" << endl;
	}
	else	{
		count = count + c;
	}
}

string Product::printProduct()	{
	std::stringstream ss1;
	std::stringstream ss2;
	std::stringstream ss3;
	ss1 << barcode;
	ss2 << price;
	ss3 << count;
	
	string sB; 
	string sP; 
	string sC; 
	
	ss1 >> sB;
	ss2 >> sP;
	ss3 >> sC;
	string holder = (productName + " " + sB + " " + type + " " + sP + " " + sC);
	return holder; 
}

bool operator ==(const Product &p1, const Product &p2)	{
	return p1.productName == p2.productName;
}

const Product operator +(const Product &p1,const Product &p2)	{
	string comboName = p1.productName + "/" + p2.productName + " COMBO";
	int count = 4;
	double price = (p1.price + p2.price - 10);
	string type = p1.type;
	int barcode = p1.barcode + p2.barcode;
	
	Product tempCombo(barcode, comboName, type, price, count);
	return tempCombo;
}
