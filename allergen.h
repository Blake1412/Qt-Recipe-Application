#ifndef ALLERGEN_H
#define ALLERGEN_H

#include <QString>
#include <cstdint>

union AllergenBitStruct {
     uint8_t bits;
     struct Allergens {
         bool crustaceans:1;
         bool eggs:1;
         bool fish:1;
         bool milk:1;
         bool peanuts:1;
         bool soybeans:1;
         bool treenuts:1;
         bool wheat:1;
     } allergens;
 };

class Allergen
{

public:
    Allergen();
    const AllergenBitStruct &getAllergens() const;
    void addAllergen(const QString& allergen);
    void removeAllergen(const QString& allergen);
    QString string() const;

private:
    AllergenBitStruct allergens;

};



#endif // ALLERGEN_H
