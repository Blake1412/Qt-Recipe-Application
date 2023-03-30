#include "allergen.h"

#include <sstream>

using std::stringstream;

Allergen::Allergen() {
    allergens.bits = 0;
}

AllergenBitStruct Allergen::getAllergens() const {
    return allergens;
}

void Allergen::addAllergen(const QString allergen) {
    if (allergen == "Crustaceans") allergens.allergens.crustaceans = 1;
    if (allergen == "Eggs") allergens.allergens.eggs = 1;
    if (allergen == "Fish") allergens.allergens.fish = 1;
    if (allergen == "Milk") allergens.allergens.milk = 1;
    if (allergen == "Peanuts") allergens.allergens.peanuts = 1;
    if (allergen == "Soybeans") allergens.allergens.soybeans = 1;
    if (allergen == "Tree Nuts") allergens.allergens.treenuts = 1;
    if (allergen == "Wheat") allergens.allergens.wheat = 1;
}

void Allergen::removeAllergen(const QString allergen) {
    if (allergen == "Crustaceans") allergens.allergens.crustaceans = 0;
    if (allergen == "Eggs") allergens.allergens.eggs = 0;
    if (allergen == "Fish") allergens.allergens.fish = 0;
    if (allergen == "Milk") allergens.allergens.milk = 0;
    if (allergen == "Peanuts") allergens.allergens.peanuts = 0;
    if (allergen == "Soybeans") allergens.allergens.soybeans = 0;
    if (allergen == "Tree Nuts") allergens.allergens.treenuts = 0;
    if (allergen == "Wheat") allergens.allergens.wheat = 0;
}

QString Allergen::string() const {
    stringstream os;
    if (allergens.bits) {
        os << "Contains: ";
        if (allergens.allergens.crustaceans) os << "Crustaceans, ";
        if (allergens.allergens.eggs) os << "Eggs, ";
        if (allergens.allergens.fish) os << "Fish, ";
        if (allergens.allergens.milk) os << "Milk, ";
        if (allergens.allergens.peanuts) os << "Peanuts, ";
        if (allergens.allergens.soybeans) os << "Soybeans, ";
        if (allergens.allergens.treenuts) os << "Tree Nuts, ";
        if (allergens.allergens.wheat) os << "Wheat";
    }
    return QString::fromStdString(os.str());
}
