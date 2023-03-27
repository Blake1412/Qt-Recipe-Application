#include "recipeapp.h"
#include "ui_recipeapp.h"

RecipeApp::RecipeApp(QWidget *parent): QMainWindow(parent), ui(new Ui::RecipeApp), previousPages(vector<int>{}) {
    ui->setupUi(this);
    connect(ui->pageSelectionButtons, SIGNAL(idClicked(int)), this, SLOT(pageSelectionButtonClicked(int)));
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(backButtonClicked()));
}

RecipeApp::~RecipeApp() {
    delete ui;
}

void RecipeApp::pageSelectionButtonClicked(int index) {
    previousPages.push_back(ui->stackedWidget->currentIndex());
    ui->stackedWidget->setCurrentIndex(index * -1);
}

void RecipeApp::backButtonClicked() {
    if (!previousPages.empty()) ui->stackedWidget->setCurrentIndex(previousPages.back());
    previousPages.pop_back();
}

