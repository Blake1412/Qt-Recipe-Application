#include "recipebutton.h"
#include "ui_recipebutton.h"

RecipeButton::RecipeButton(const Recipe &recipe, QWidget *parent): recipe(recipe), QWidget(parent), ui(new Ui::RecipeButton) {
    ui->setupUi(this);
    connect(ui->selectRecipeButton, SIGNAL(clicked()), this, SIGNAL(selectRecipeButtonClicked()));
    ui->recipeNameLabel->setText(recipe.name);
    ui->allergensLabel->setText(recipe.getAllergensString());
    ui->dietaryRestrictionsLabel->setText(recipe.dietRestriction);
}

RecipeButton::~RecipeButton() {
    delete ui;
}

Recipe RecipeButton::getRecipe() const {
    return recipe;
}

