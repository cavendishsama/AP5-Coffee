#include "cappuccino.h"

Cappuccino::Cappuccino() : side_items {}{
    name = "Cappuccino";
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
}

Cappuccino::Cappuccino(const Cappuccino& cap) : EspressoBased(cap) {

    auto temp {const_cast<Cappuccino&>(cap).get_side_items()};   //constcast bokon
    std::vector<std::string> v {"Cinnamon","Chocolate","Sugar","Cookie", \
                                "Espresso","Milk","MilkFoam","Water"};

    for(const auto& i : temp){
        size_t flag {};
        for(const auto& j : v){
            flag++;
            if(i->get_name() == j)
                break;
        }

        switch (flag)   //i'll explain what's going on in this section but i used flag to check which ingredient i'm
                        //adding to ingredinets vector (check the order of vector v and compare it to cases)
        {
        case 1: this->add_side_item(new Cinnamon(i->get_units()));    break;
        case 2: this->add_side_item(new Chocolate(i->get_units()));   break;
        case 3: this->add_side_item(new Sugar(i->get_units()));       break;
        case 4: this->add_side_item(new Cookie(i->get_units()));      break;
        case 5: this->add_side_item(new Espresso(i->get_units()));    break;
        case 6: this->add_side_item(new Milk(i->get_units()));        break;
        case 7: this->add_side_item(new MilkFoam(i->get_units()));    break;
        case 8: this->add_side_item(new Water(i->get_units()));       break;
        default:
            break;
        }
    }
}

Cappuccino::~Cappuccino()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Cappuccino::operator=(const Cappuccino& cap){

    if(this == &cap)
        return;

    ingredients.clear();
    auto temp {const_cast<Cappuccino&>(cap).get_ingredients()};   //constcast bokon
    std::vector<std::string> v {"Cinnamon","Chocolate","Sugar","Cookie", \
                                "Espresso","Milk","MilkFoam","Water"};

    for(const auto& i : temp){
        size_t flag {};
        for(const auto& j : v){
            flag++;
            if(i->get_name() == j)
                break;
        }

        switch (flag)   //i'll explain what's going on in this section but i used flag to check which ingredient i'm
                        //adding to ingredinets vector (check the order of vector v and compare it to cases)
        {
        case 1: this->add_side_item(new Cinnamon(i->get_units()));    break;
        case 2: this->add_side_item(new Chocolate(i->get_units()));   break;
        case 3: this->add_side_item(new Sugar(i->get_units()));       break;
        case 4: this->add_side_item(new Cookie(i->get_units()));      break;
        case 5: this->add_side_item(new Espresso(i->get_units()));    break;
        case 6: this->add_side_item(new Milk(i->get_units()));        break;
        case 7: this->add_side_item(new MilkFoam(i->get_units()));    break;
        case 8: this->add_side_item(new Water(i->get_units()));       break;
        default:
            break;
        }
    }
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