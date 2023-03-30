#ifndef RECIPE_H
#define RECIPE_H

#include "allergen.h"

#include <QString>
#include <QVector>
#include <QVBoxLayout>

using std::ostream;


class RecipeButton;
class Recipe {

public:
    Recipe();
    Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QString &dietRestriction);
    Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const Allergen &allergens, const QString &dietRestriction);

    QString getName() const;
    QVector<QString> getIngredients() const;
    QVector<QString> getInstructions() const;
    Allergen getAllergens() const;
    QString getDietRestriction() const;
    bool getDisplayed() const;

    void setName(const QString &newName);
    void addIngredient(const QString &newIngredients);
    void addInstruction(const QString &newInstructions);
    void addAllergen(const QString &newAllergens);
    void setDietRestriction(const QString &newDietRestriction);
    void setDisplayed(bool newDisplayed);

    friend QDebug operator<< (QDebug &debug, const Recipe &recipe);
    friend QJsonObject operator<< (QJsonObject &jsonObject, const Recipe &recipe);
    bool const operator==(const Recipe &recipe);

    friend RecipeButton;

private:
    QString name;
    QVector<QString> ingredients;
    QVector<QString> instructions;
    Allergen allergens;
    QString dietRestriction;
    bool displayed;
};

#endif // RECIPE_H
