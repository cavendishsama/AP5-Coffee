#include "espresso_based.h"

void EspressoBased::brew(){

}

std::vector<Ingredient*>& EspressoBased::get_ingredients(){
    return ingredients;
}

EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

EspressoBased::EspressoBased(const EspressoBased& esp){
    ingredients = esp.ingredients;
    name = esp.name;
}

void EspressoBased::operator=(const EspressoBased& esp){
    ingredients.clear();
    auto temp {const_cast<EspressoBased&>(esp).get_ingredients()};   //constcast bokon
    // std::queue<std::string> q ;
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
        case 1: ingredients.push_back(new Cinnamon(i->get_units()));    break;
        case 2: ingredients.push_back(new Chocolate(i->get_units()));   break;
        case 3: ingredients.push_back(new Sugar(i->get_units()));       break;
        case 4: ingredients.push_back(new Cookie(i->get_units()));      break;
        case 5: ingredients.push_back(new Espresso(i->get_units()));    break;
        case 6: ingredients.push_back(new Milk(i->get_units()));        break;
        case 7: ingredients.push_back(new MilkFoam(i->get_units()));    break;
        case 8: ingredients.push_back(new Water(i->get_units()));       break;
        default:
            break;
        }
    }
}

