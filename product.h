#ifndef product_h
#define product_h

#include <iostream>
#include <string>

using namespace std;

namespace A	{
	void productSpace();
}

class Product	{
	protected:
		int barcode;
		string productName;
		string type;
		double price;
		int count;
		
	public:
		virtual ~Product(){};
		Product();
		Product(int b, string n, string t, double p, int c);
		string getProductName();
		string getType();
		int getBarcode();
		int getCount();
		double getPrice();
		
		void updateCountP(int c);
		void updateCountM(int s);
		void setName(string s);
		void setPrice(double d);
		void setType(string s);
		void setCount(int c);
		string printProduct();
		
		friend bool operator ==(const Product &p1, const Product &p2);
		friend const Product operator +(const Product &p1,const Product &p2);
};


class VideoGame: public Product	{
	protected:
		string name;
		double price;
		int count;
	public:
		VideoGame();
		VideoGame(string s, double p, int c);
};
#endif