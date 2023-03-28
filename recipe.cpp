#include "recipe.h"

#include <sstream>

using std::stringstream;

Recipe::Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QVector<QString> &allergens, const QString &dietRestriction)
    : name(name), ingredients(ingredients), instructions(instructions), allergens(allergens), dietRestriction(dietRestriction) {

}

Recipe::Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QString &dietRestriction)
    : name(name), ingredients(ingredients), instructions(instructions), dietRestriction(dietRestriction) {

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
