#ifndef RECIPEAPP_H
#define RECIPEAPP_H

#include "recipe.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RecipeApp; }
QT_END_NAMESPACE

using std::vector;

class RecipeApp : public QMainWindow {
    Q_OBJECT

public:
    RecipeApp(QWidget *parent = nullptr);
    ~RecipeApp();

private slots:
    void pageSelectionButtonClicked(int index);
    void backButtonClicked();
    void recipeButtonClicked();

private:
    Ui::RecipeApp *ui;
    QVector<int> previousPages;
};
#endif // RECIPEAPP_H
