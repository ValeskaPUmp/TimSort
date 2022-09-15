#include "Item.h"

const bool Item::operator>(Item& item)
{
    return (this->cost > item.cost);
}
const bool Item::operator<=(Item& item)
{
    return (this->cost <= item.cost);
}
Item::~Item() {
    std::cout << "Object has been deleted";
}


