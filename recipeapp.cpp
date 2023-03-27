#include "recipeapp.h"
#include "ui_recipeapp.h"

RecipeApp::RecipeApp(QWidget *parent): QMainWindow(parent), ui(new Ui::RecipeApp) {
    ui->setupUi(this);
}

RecipeApp::~RecipeApp() {
    delete ui;
}

