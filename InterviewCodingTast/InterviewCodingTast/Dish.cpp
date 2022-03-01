#include "Dish.h"

Dish::Dish(int _dishNumber, std::string _name, double _price, std::string _description, int _calories)
{
	dishNumber = _dishNumber;
	name = _name;
	price = _price;
	description = _description;
	calories = _calories;
}
