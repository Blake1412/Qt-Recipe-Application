#include "recipe.h"
#include "qdebug.h"

#include <sstream>
#include <QJsonObject>
#include <QJsonArray>

using std::stringstream;

QDebug operator<< (QDebug debug, const Recipe &recipe) {
    return debug << recipe.name << Qt::endl << recipe.dietRestriction << " | " << recipe.getAllergensString() << Qt::endl;;
}

QJsonObject operator<< (QJsonObject &jsonObject, const Recipe &recipe) {
    QJsonObject jsonRecipe;
    QJsonArray ingredients;
    QJsonArray instructions;
    QJsonArray allergens;

    for (QString const &ingredient : recipe.ingredients) {
        ingredients.append(ingredient);
    }

    for (QString const &instruction : recipe.instructions) {
        instructions.append(instruction);
    }

    for (QString const &allergen : recipe.allergens) {
        allergens.append(allergen);
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

Recipe::Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QString &dietRestriction)
    : name(name), ingredients(ingredients), instructions(instructions), dietRestriction(dietRestriction) {

}

Recipe::Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QVector<QString> &allergens, const QString &dietRestriction)
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

QVector<QString> Recipe::getAllergens() const {
    return allergens;
}

QString Recipe::getDietRestriction() const {
    return dietRestriction;
}

QString Recipe::getAllergensString() const{
    stringstream os;
    if (!allergens.isEmpty()) {
    os << "Contains: ";
    for (int i = 0; i < allergens.length() - 1; i++) {
        os << allergens[i].toStdString() << ", ";
    }
    os << allergens.back().toStdString();
    }
    return  QString::fromStdString(os.str());
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
    allergens.append(allergen);
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
