#include "recipe.h"

Recipe::Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const Allergen &allergens, const QString &dietRestriction)
    : name(name), ingredients(ingredients), instructions(instructions), allergens(allergens), dietRestriction(dietRestriction) {

}

QString Recipe::getName() const {
    return name;
}

QVector<QString> Recipe::getIngredients() const {
    return ingredients;
}

QVector<QString> Recipe::getInstructions() const {
    return instructions;
}

Allergen Recipe::getAllergens() const {
    return allergens;
}

QString Recipe::getDietRestriction() const {
    return dietRestriction;
}
