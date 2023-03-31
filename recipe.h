#ifndef RECIPE_H
#define RECIPE_H

#include "allergen.h"

#include <QString>
#include <QVector>
#include <QVBoxLayout>

class RecipeButton;
class Recipe {

public:
    enum Deep { deep };

    Recipe();
    Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const Allergen &allergens, const QString &dietRestriction);
    Recipe(const Recipe &recipe, Deep);
    Recipe(const Recipe &recipe);

    const QString& getName() const;
    const QVector<QString>& getIngredients() const;
    const QVector<QString>& getInstructions() const;
    const Allergen& getAllergens() const;
    const QString& getDietRestriction() const;
    const bool getDisplayed() const;

    void setName(const QString &newName);
    void addIngredient(const QString &newIngredient);
    void addInstruction(const QString &newInstruction);
    void addAllergen(const QString &newAllergen);
    void setDietRestriction(const QString &newDietRestriction);
    void setDisplayed(bool newDisplayed);

    friend QDebug operator<< (QDebug &debug, const Recipe &recipe);
    friend void operator<< (QJsonObject &jsonObject, const Recipe &recipe);
    const bool operator==(const Recipe &recipe) const;

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
