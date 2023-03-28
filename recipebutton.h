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
    Recipe getRecipe() const;

private:
    Ui::RecipeButton *ui;
    Recipe recipe;

signals:
    void selectRecipeButtonClicked();
};


#endif // RECIPEBUTTON_H
