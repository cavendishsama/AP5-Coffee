#include "cappuccino.h"

Cappuccino::Cappuccino() : side_items {}{
    name = "Cappuccino";
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
}

Cappuccino::Cappuccino(const Cappuccino& cap){
    
}

Cappuccino::~Cappuccino()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Cappuccino::operator=(const Cappuccino& cap){

}

std::string Cappuccino::get_name(){
    return name;
}

double Cappuccino::price(){
    double _price {};
    for(const auto& j : ingredients)
        _price += j->price();
    for(const auto& i : side_items)
        _price += i->price();
    return _price;
}

void Cappuccino::add_side_item(Ingredient* side){
    side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items(){
    return side_items;
}