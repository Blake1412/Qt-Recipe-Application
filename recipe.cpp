#include "recipe.h"

#include <sstream>
#include <QJsonObject>
#include <QJsonArray>

using std::stringstream;

bool const Recipe::operator== (const Recipe &recipe) {
    return recipe.name == name &&
           recipe.ingredients == ingredients &&
           recipe.instructions == instructions &&
           recipe.allergens.getAllergens().bits == allergens.getAllergens().bits &&
           recipe.dietRestriction == dietRestriction;
}


QDebug operator<< (QDebug &debug, const Recipe &recipe) {
    return debug << recipe.name << Qt::endl << recipe.dietRestriction << " | " << recipe.allergens.string() << Qt::endl;;
}

QJsonObject operator<< (QJsonObject &jsonObject, const Recipe &recipe) {
    QJsonObject jsonRecipe;
    QJsonArray ingredients;
    QJsonArray instructions;
    QJsonArray allergens;

    for (auto &ingredient : recipe.ingredients) {
        ingredients.append(ingredient);
    }

    for (auto &instruction : recipe.instructions) {
        instructions.append(instruction);
    }

    if (recipe.allergens.string() != "") {
        allergens = QJsonArray::fromStringList(recipe.allergens.string().right(recipe.allergens.string().size() - recipe.allergens.string().indexOf(":") - 2).split(", ", Qt::SkipEmptyParts));
    }

    jsonRecipe.insert("Ingredients", ingredients);
    jsonRecipe.insert("Instructions", instructions);
    jsonRecipe.insert("Allergens", allergens);
    jsonRecipe.insert("Dietary Restriction", recipe.dietRestriction);
    jsonObject.insert(recipe.name, jsonRecipe);

    return jsonObject;
}

Recipe::Recipe(){

}

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

void Recipe::setName(const QString &newName) {
    name = newName;
}

void Recipe::addIngredient(const QString &ingredient) {
    ingredients.append(ingredient);
}

void Recipe::addInstruction(const QString &instruction) {
    instructions.append(instruction);
}

void Recipe::addAllergen(const QString &allergen) {
    allergens.addAllergen(allergen);
}

void Recipe::setDietRestriction(const QString &newDietRestriction) {
    dietRestriction = newDietRestriction;
}

bool Recipe::getDisplayed() const {
    return displayed;
}

void Recipe::setDisplayed(bool newDisplayed) {
    displayed = newDisplayed;
}
