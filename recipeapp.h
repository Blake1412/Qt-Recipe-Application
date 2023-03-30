#ifndef RECIPEAPP_H
#define RECIPEAPP_H

#include <QFile>
#include <QMainWindow>
#include <QJsonObject>

QT_BEGIN_NAMESPACE

class Recipe;
namespace Ui { class RecipeApp; }
QT_END_NAMESPACE

class RecipeApp : public QMainWindow {
    Q_OBJECT

public:
    RecipeApp(QWidget *parent = nullptr);
    ~RecipeApp();

private slots:
    void pageSelectionButtonClicked(int index);
    void backButtonClicked();
    void recipeButtonClicked();
    void on_addInstructionButton_clicked();
    void on_addIngredientButton_clicked();
    void on_createRecipeButton_clicked();

private:
    void loadRecipes();
    void displayRecipes();
    void closeEvent(QCloseEvent *event) override;
    Ui::RecipeApp *ui;
    QVector<int> previousPages;
    QVector<Recipe> recipes;
    QFile *recipesFile;
    QJsonObject recipesJson;

};
#endif // RECIPEAPP_H
