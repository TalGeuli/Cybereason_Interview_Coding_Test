#pragma once
#include <iostream>

#include <string>
#include <cstdint>
#include <vector>
class Dish
{
	public:
		int dishNumber;
		std::string name;
		double price;
		std::string description;
		int calories;

		Dish(int _dishNumber,std::string _name, double _price, std::string _description, int _calories);

};

