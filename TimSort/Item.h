#pragma once
#include <iostream>
using namespace std;

class Item
{
public:
	int cost;
	Item(int cost) :cost(cost){}
	Item(const Item& copy) :cost(copy.cost){}
	~Item();
	const bool operator>(Item& item);
	const bool operator<=(Item& item);
};

