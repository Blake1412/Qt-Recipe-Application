#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QVector>

struct Allergen {
    bool crustacean : 1;
    bool eggs : 1;
    bool fish : 1;
    bool milk : 1;
    bool peanuts : 1;
    bool soybeans : 1;
    bool treeNuts : 1;
    bool wheat : 1;
};

class Recipe {
public:
    Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const Allergen &allergens, const QString &dietRestriction);
    QString getName() const;
    QVector<QString> getIngredients() const;
    QVector<QString> getInstructions() const;
    Allergen getAllergens() const;
    QString getDietRestriction() const;

private:
    QString name;
    QVector<QString> ingredients;
    QVector<QString> instructions;
    Allergen allergens;
    QString dietRestriction;
};

#endif // RECIPE_H
