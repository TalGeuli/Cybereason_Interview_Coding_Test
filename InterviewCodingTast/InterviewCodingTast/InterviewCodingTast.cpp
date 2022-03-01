// InterviewCodingTast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <D:/Interview_cybereason/InterviewCodingTast/InterviewCodingTast/pugixml.hpp>
#include <vector>

#include "Dish.h"

unsigned int GetCustomerDetailes(std::string& name, int& id, std::string& birthday);
unsigned int PrintDish(Dish& dish);
unsigned int GetOrder(std::string& name, std::vector <Dish>& Menue);

int main()
{
    //The Menue
    std::vector<Dish> Menue;
    
    //Reading the XML file
    pugi::xml_document doc;
    if (!doc.load_file("D:/Interview_cybereason/simple.xml")) return -1;

    pugi::xml_node breakfast_menue = doc.child("breakfast_menu");
    int dishNumber = -1;
    for (pugi::xml_node food = breakfast_menue.first_child(); food; food = food.next_sibling())
    {
        dishNumber++;
        std::string name;
        double price;
        std::string description;
        int calories;
        int elementCount = 0;
        for (pugi::xml_node element = food.first_child(); element; element = element.next_sibling())
        {
            if (elementCount == 0) {
                name = element.text().get();
            }
            if (elementCount == 1)
            {
                std::string strPrice = element.text().get();
                std::string strdPrice = strPrice.substr(1);
                double dPrice = std::stod(strdPrice);
                price = dPrice * 3.5;
            }
            if (elementCount == 2)
            {
                description = element.text().get();
            }
            if (elementCount == 3) {
                std::string strCalories = element.text().get();
                calories = stoi(strCalories);
            }
            elementCount++;
        }
        Dish dish(dishNumber, name, price, description, calories);
        Menue.push_back(dish);

    }

    //Get Customer detailes
    std::string name; // - the name needs to be without spaces
    int id;
    std::string birthday;
    GetCustomerDetailes(name, id, birthday);
    //Print the Menue
    std::cout << "Menue: " << "\n";
    for (size_t i = 0; i < Menue.size(); i++)
    {
        PrintDish(Menue.at(i));   
    }
    std::cout << "\n";
    std::cout << "\n";
    //Get custumer order
    GetOrder(name, Menue);
    

}

unsigned int GetCustomerDetailes(std::string &name, int &id, std::string &birthday ) 
{
   
    std::cout << "Please enter your name: " << "\n";
    std::cin >> name;
    std::cout << "Please enter your ID number: " << "\n";
    std::cin >> id;
    std::cout << "Please enter your birthday: " << "\n";
    std::cin >> birthday;
    std::cout << "\n";
    std::cout << "\n";
    return 1;
    
}

unsigned int PrintDish(Dish& dish) {
    std::cout << dish.dishNumber << ". " << dish.name << " - " << dish.price << " nis." << "\n";
    std::cout << "\t" <<dish.description << "." << "\n";
    std::cout << "\t" << dish.calories << " calories." << "\n";
    return 1;
}

unsigned int GetOrder(std::string &name, std::vector <Dish> &Menue)
{
    int dishId;
    double totalPrice = 0;
    std::cout << "Pick item from menue and press enter (-1 to finish): ";
    std::cin >> dishId;
    while (dishId != -1)
    {
        totalPrice = totalPrice + Menue.at(dishId - 1).price;
        std::cout << "Pick item from menue and press enter: (-1 to finish) ";
        std::cin >> dishId;
    }
    std::cout << "\n";
    std::cout << "Thank you " << name << ", your order total is: " << totalPrice << "nis." << "\n";
    return 1;
}
