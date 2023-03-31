#ifndef RECIPEBUTTON_H
#define RECIPEBUTTON_H

#include "recipe.h"

#include <QWidget>

namespace Ui {
class RecipeButton;
}

class RecipeButton : public QWidget {
    Q_OBJECT

public:
    RecipeButton(const Recipe &recipe, QWidget *parent = nullptr);
    ~RecipeButton();
    const Recipe& getRecipe() const;

private:
    Ui::RecipeButton *ui;
    Recipe recipe;

private slots:
    void selectRecipeButtonClickedSlot();

signals:
    void selectRecipeButtonClicked(const Recipe& recipe);
};


#endif // RECIPEBUTTON_H
