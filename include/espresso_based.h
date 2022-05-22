#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include"ingredient.h"
#include"sub_ingredients.h"

#include <chrono>                    // for operator""s, chrono_literals
#include <ftxui/dom/elements.hpp>    // for text, gauge, operator|, flex, hbox, Element
#include <ftxui/screen/screen.hpp>   // for Screen
#include <thread>                    // for sleep_for
#include "ftxui/dom/node.hpp"        // for Render
#include "ftxui/screen/color.hpp"    // for ftxui
#include <random>
#include <iomanip>

class EspressoBased
{
public:
    virtual std::string get_name() = 0;
    virtual double price() = 0;

    void brew();
    std::vector<Ingredient*>& get_ingredients();

    virtual ~EspressoBased();

protected:
    EspressoBased() = default;
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;

};

#endif // ESPRESSO_BASED_H