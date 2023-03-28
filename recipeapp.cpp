#include "recipe.h"
#include "recipeapp.h"
#include "recipebutton.h"
#include "ui_recipeapp.h"

RecipeApp::RecipeApp(QWidget *parent): QMainWindow(parent), ui(new Ui::RecipeApp), previousPages(QVector<int>{0}) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->pageSelectionButtons->setId(ui->browseButton, 1);
    ui->pageSelectionButtons->setId(ui->createButton, 3);
    ui->pageSelectionButtons->setId(ui->favoritesButton, 4);
    connect(ui->pageSelectionButtons, SIGNAL(idClicked(int)), this, SLOT(pageSelectionButtonClicked(int)));
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(backButtonClicked()));

    Recipe recipe("Cereal", QVector<QString>{"milk", "cereal"}, QVector<QString>{"Pout ceral in bowl", "Add milk"}, QVector<QString>{"Milk", "Wheat"}, "Omnivorous");
    RecipeButton *recipeButton = new RecipeButton(recipe);
    connect(recipeButton, SIGNAL(selectRecipeButtonClicked()), this, SLOT(recipeButtonClicked()));

    ui->recipeListLayout->insertWidget(0, recipeButton);
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
    while ((item = ui->instructionsListLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
    while ((item = ui->ingredientsListLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }

    ui->instructionsListLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));
    ui->ingredientsListLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));

    QVector<QString> instructions = recipe.getInstructions();
    for (int i = 0; i < instructions.size(); i++) {
        ui->instructionsListLayout->insertWidget(0, new QLabel(instructions[i]));
    }
    QVector<QString> ingredients = recipe.getIngredients();
    for (int i = 0; i < ingredients.size(); i++) {
        ui->ingredientsListLayout->insertWidget(0, new QLabel(ingredients[i]));
    }

    previousPages.push_back(ui->stackedWidget->currentIndex());
    ui->stackedWidget->setCurrentIndex(2);
}

