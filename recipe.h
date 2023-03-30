#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QVector>
#include <QVBoxLayout>

using std::ostream;

class RecipeButton;
class Recipe {

friend QDebug operator<< (QDebug debug, const Recipe &recipe);
friend QJsonObject operator<< (QJsonObject &jsonObject, const Recipe &recipe);

public:
    Recipe();
    Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QString &dietRestriction);
    Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QVector<QString> &allergens, const QString &dietRestriction);

    QString getName() const;
    QVector<QString> getIngredients() const;
    QVector<QString> getInstructions() const;
    QVector<QString> getAllergens() const;
    QString getDietRestriction() const;
    QString getAllergensString() const;
    bool getDisplayed() const;

    void setName(const QString &newName);
    void addIngredient(const QString &newIngredients);
    void addInstruction(const QString &newInstructions);
    void addAllergen(const QString &newAllergens);
    void setDietRestriction(const QString &newDietRestriction);
    void setDisplayed(bool newDisplayed);

    friend RecipeButton;

private:
    QString name;
    QVector<QString> ingredients;
    QVector<QString> instructions;
    QVector<QString> allergens;
    QString dietRestriction;
    bool displayed;
};

#endif // RECIPE_H
