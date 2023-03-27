#ifndef RECIPEAPP_H
#define RECIPEAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RecipeApp; }
QT_END_NAMESPACE

class RecipeApp : public QMainWindow {
    Q_OBJECT

public:
    RecipeApp(QWidget *parent = nullptr);
    ~RecipeApp();

private:
    Ui::RecipeApp *ui;
};
#endif // RECIPEAPP_H
