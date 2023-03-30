#include "recipe.h"
#include "recipeapp.h"
#include "recipebutton.h"
#include "ui_recipeapp.h"

#include <QCloseEvent>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#define BROWSE_PAGE 1
#define RECIPE_PAGE 2
#define CREATE_PAGE 3
#define FAVORITES_PAGE 4

RecipeApp::RecipeApp(QWidget *parent): QMainWindow(parent), ui(new Ui::RecipeApp), previousPages(QVector<int>{0}) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->pageSelectionButtons->setId(ui->browseButton, BROWSE_PAGE);
    ui->pageSelectionButtons->setId(ui->createButton, CREATE_PAGE);
    ui->pageSelectionButtons->setId(ui->favoritesButton, FAVORITES_PAGE);
    connect(ui->pageSelectionButtons, SIGNAL(idClicked(int)), this, SLOT(pageSelectionButtonClicked(int)));
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(backButtonClicked()));
    recipesFile = new QFile("recipes.json");
    recipesFile->open(QIODevice::ReadWrite | QIODevice::Text);
    loadRecipes();
    recipesFile->resize(0);
}

RecipeApp::~RecipeApp() {
    delete ui;
}

void RecipeApp::pageSelectionButtonClicked(int index) {
    previousPages.push_back(ui->stackedWidget->currentIndex());
    ui->stackedWidget->setCurrentIndex(index);
}

void RecipeApp::backButtonClicked() {
    if (!previousPages.empty()) ui->stackedWidget->setCurrentIndex(previousPages.back());
    previousPages.pop_back();
}

void RecipeApp::recipeButtonClicked() {
    RecipeButton *recipeButton = qobject_cast<RecipeButton *>(sender());
    Recipe recipe = recipeButton->getRecipe();
    ui->recipeNameLabel->setText(recipe.getName());
    ui->allergenLabel->setText(recipe.getAllergensString());
    ui->dietaryLabel->setText(recipe.getDietRestriction());

    QLayoutItem* item;
    while (ui->instructionsListLayout->count() > 1) {
        item = ui->instructionsListLayout->takeAt(0);
        delete item->widget();
        delete item;
    }

    while (ui->ingredientsListLayout->count() > 1) {
        item = ui->ingredientsListLayout->takeAt(0);
        delete item->widget();
        delete item;
    }

    QVector<QString> instructions = recipe.getInstructions();
    for (int i = 0; i < instructions.size(); i++) {
        ui->instructionsListLayout->insertWidget(0, new QLabel(instructions[i]));
    }
    QVector<QString> ingredients = recipe.getIngredients();
    for (int i = 0; i < ingredients.size(); i++) {
        ui->ingredientsListLayout->insertWidget(0, new QLabel(ingredients[i]));
    }

    previousPages.push_back(ui->stackedWidget->currentIndex());
    ui->stackedWidget->setCurrentIndex(RECIPE_PAGE);
}


void RecipeApp::on_addInstructionButton_clicked() {
    ui->instructionsCreateList->insertWidget(ui->instructionsCreateList->count() - 1, new QLineEdit);
}


void RecipeApp::on_addIngredientButton_clicked() {
    ui->ingredientsCreateList->insertWidget(ui->ingredientsCreateList->count() - 1, new QLineEdit);
}


void RecipeApp::on_createRecipeButton_clicked() {
    QVector<QString> ingredients;
    QVector<QString> instructions;
    QVector<QString> allergens;

    QLayoutItem* item;
    while(ui->ingredientsCreateList->count() > 1) {
        item = ui->ingredientsCreateList->takeAt(0);
        ingredients.append(qobject_cast<QLineEdit *>(item->widget())->text());
        delete item->widget();
        delete item;
    }
    ui->ingredientsCreateList->insertWidget(0, new QLineEdit());

    while(ui->instructionsCreateList->count() > 1) {
        item = ui->instructionsCreateList->takeAt(0);
        instructions.append(qobject_cast<QLineEdit *>(item->widget())->text());
        delete item->widget();
        delete item;
    }
    ui->instructionsCreateList->insertWidget(0, new QLineEdit());

    QLayout *layout = ui->allergensCreateButtons->layout();
    for (int i = 0; i < ui->allergensCreateButtons->layout()->count(); i++) {
        QCheckBox *allergen = qobject_cast<QCheckBox *>(layout->itemAt(i)->widget());
        if (allergen->isChecked()) {
            allergens.append(allergen->text());
            allergen->setChecked(false);
        }
    }

    Recipe recipe(ui->recipeNameCreateLabel->text(), ingredients, instructions, allergens, ui->dietaryRestrictionCreateButtons->checkedButton()->text());
    ui->recipeNameCreateLabel->setText("");
    recipes.append(recipe);
    displayRecipes();

    recipesJson << recipe;
}

void RecipeApp::loadRecipes() {
    QJsonDocument jsonFile = QJsonDocument::fromJson(recipesFile->readAll());
    recipesJson = jsonFile.object();
    for (auto it = recipesJson.begin(), end = recipesJson.end(); it != end; it++) {
        Recipe newRecipe;;
        newRecipe.setName(it.key());
        QJsonObject recipe = it.value().toObject();

        for (auto&& ingredient : (recipe.find("Ingredients").value().toArray())) {
            newRecipe.addIngredient(ingredient.toString());
        }
        for (auto&& instruction : recipe.find("Instructions").value().toArray()) {
            newRecipe.addInstruction(instruction.toString());
        }
        for (auto&& allergen : recipe.find("Allergens").value().toArray()) {
            newRecipe.addAllergen(allergen.toString());
        }
        newRecipe.setDietRestriction(recipe.find("Dietary Restriction").value().toString());
        RecipeApp::recipes.append(newRecipe);
    }
    displayRecipes();
}

void RecipeApp::displayRecipes() {
    for (Recipe &recipe : recipes) {
        if (!recipe.getDisplayed()) {
        recipe.setDisplayed(true);
        RecipeButton *recipeButton = new RecipeButton(recipe);
        connect(recipeButton, SIGNAL(selectRecipeButtonClicked()), this, SLOT(recipeButtonClicked()));
        ui->recipeListLayout->insertWidget(0, recipeButton);
        }
    }
}

void RecipeApp::closeEvent(QCloseEvent *event) {
    QJsonDocument jsonDoc(recipesJson);
    recipesFile->write(jsonDoc.toJson());
    recipesFile->close();
    event->accept();
}
