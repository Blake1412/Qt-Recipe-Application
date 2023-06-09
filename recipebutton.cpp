#include "recipebutton.h"
#include "ui_recipebutton.h"

RecipeButton::RecipeButton(const Recipe &recipe, QWidget *parent): recipe(recipe), QWidget(parent), ui(new Ui::RecipeButton) {
    ui->setupUi(this);
    connect(ui->selectRecipeButton, SIGNAL(clicked()), this, SLOT(selectRecipeButtonClickedSlot()));
    ui->recipeNameLabel->setText(recipe.name);
    ui->allergensLabel->setText(recipe.allergens.string());
    ui->dietaryRestrictionsLabel->setText(recipe.dietRestriction);
}

RecipeButton::~RecipeButton() {
    delete ui;
}

const Recipe& RecipeButton::getRecipe() const {
    return recipe;
}

void RecipeButton::selectRecipeButtonClickedSlot() {
    emit selectRecipeButtonClicked(recipe);
}

