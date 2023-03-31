#ifndef RECIPEAPP_H
#define RECIPEAPP_H

#include "allergen.h"

#include <QFile>
#include <QMainWindow>
#include <QJsonObject>
#include <QAbstractButton>


QT_BEGIN_NAMESPACE

namespace Ui { class RecipeApp; }
QT_END_NAMESPACE

class Recipe;
class RecipeApp : public QMainWindow {
    Q_OBJECT

public:
    RecipeApp(QWidget *parent = nullptr);
    ~RecipeApp();
    void addRecipe(const Recipe &recipe);

private slots:
    void pageSelectionButtonClicked(int index);
    void backButtonClicked();
    void recipeButtonClicked(const Recipe& recipe);
    void on_addInstructionButton_clicked();
    void on_addIngredientButton_clicked();
    void on_createRecipeButton_clicked();
    void on_searchBar_textEdited(const QString &newText);
    void allergenButtonClicked(QAbstractButton *button, bool checked);
    void dietRestrictionButtonClicked(QAbstractButton *button);

private:
    void loadRecipes();
    void displayRecipes();
    void closeEvent(QCloseEvent *event) override;
    Ui::RecipeApp *ui;
    QFile *recipesFile;
    QVector<int> previousPages;
    QVector<Recipe> recipes;
    QJsonObject recipesJson;

};
#endif // RECIPEAPP_H
