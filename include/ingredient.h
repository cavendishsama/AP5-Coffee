#ifndef INGREDIENT_H
#define INGREDIENT_H

#include<iostream>
#include<string>

class Ingredient
{
public:
    double get_price_unit() {   return price_unit;  }
    size_t get_units()  {   return units;   }
    virtual std::string get_name() = 0;

    double price() {    return units * price_unit;  }
    

protected:
    Ingredient(double m_price_unit, size_t m_units) : price_unit { m_price_unit }, units{ m_units } {}

    double price_unit;
    size_t units;
    std::string name;
};


#endif // INGREDIENT_H