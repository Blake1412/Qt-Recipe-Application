#include "recipebutton.h"
#include "ui_recipebutton.h"

using std::copy;
using std::begin;
using std::end;
using std::stringstream;
using std::ostream_iterator;

RecipeButton::RecipeButton(const Recipe &recipe, QWidget *parent): recipe(recipe), QWidget(parent), ui(new Ui::RecipeButton) {
    ui->setupUi(this);
    connect(ui->selectRecipeButton, SIGNAL(clicked()), this, SIGNAL(selectRecipeButtonClicked()));
    ui->recipeNameLabel->setText(recipe.getName());
    ui->allergensLabel->setText(recipe.getAllergensString());
    ui->dietaryRestrictionsLabel->setText(recipe.getDietRestriction());
}

RecipeButton::~RecipeButton() {
    delete ui;
}

Recipe RecipeButton::getRecipe() const {
    return recipe;
}

