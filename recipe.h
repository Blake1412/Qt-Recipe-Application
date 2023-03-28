#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QVector>

using std::ostream;

class Recipe {
public:
    Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QVector<QString> &allergens, const QString &dietRestriction);
    Recipe(const QString &name, const QVector<QString> &ingredients, const QVector<QString> &instructions, const QString &dietRestriction);
    QString getName() const;
    QVector<QString> getIngredients() const;
    QVector<QString> getInstructions() const;
    QVector<QString> getAllergens() const;
    QString getDietRestriction() const;
    QString getAllergensString() const;

private:
    QString name;
    QVector<QString> ingredients;
    QVector<QString> instructions;
    QVector<QString> allergens;
    QString dietRestriction;
};

#endif // RECIPE_H
