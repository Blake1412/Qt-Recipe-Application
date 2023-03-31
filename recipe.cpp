#include "recipe.h"

#include <sstream>
#include <QJsonObject>
#include <QJsonArray>

using std::stringstream;

bool const Recipe::operator== (const Recipe &recipe) const {
    return recipe.name == name &&
           recipe.ingredients == ingredients &&
           recipe.instructions == instructions &&
           recipe.allergens.getAllergens().bits == allergens.getAllergens().bits &&
           recipe.dietRestriction == dietRestriction;
}


QDebug operator<< (QDebug &debug, const Recipe &recipe) {
    return debug << recipe.name << Qt::endl << recipe.dietRestriction << " | " << recipe.allergens.string() << Qt::endl;;
}

void operator<< (QJsonObject &jsonObject, const Recipe &recipe) {
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
}

Recipe::Recipe(){

}

Recipe::Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const Allergen &allergens, const QString &dietRestriction)
    : name(name), ingredients(ingredients), instructions(instructions), allergens(allergens), dietRestriction(dietRestriction) {

}

Recipe::Recipe(const Recipe &recipe, Deep): Recipe(recipe) {
    name.detach();
    ingredients.detach();
    instructions.detach();
    dietRestriction.detach();
}

Recipe::Recipe(const Recipe &recipe)
    : name(recipe.name), ingredients(recipe.ingredients), instructions(recipe.instructions), allergens(recipe.allergens), dietRestriction(recipe.dietRestriction) {

}

const QString& Recipe::getName() const {
    return name;
}

const QVector<QString>& Recipe::getIngredients() const {
    return ingredients;
}

const QVector<QString>& Recipe::getInstructions() const {
    return instructions;
}

const Allergen& Recipe::getAllergens() const {
    return allergens;
}

const QString& Recipe::getDietRestriction() const {
    return dietRestriction;
}

void Recipe::setName(const QString &newName) {
    name = newName;
}

const bool Recipe::getDisplayed() const {
    return displayed;
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

void Recipe::setDisplayed(bool newDisplayed) {
    displayed = newDisplayed;
}
