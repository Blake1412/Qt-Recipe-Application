#ifndef RECIPEAPP_H
#define RECIPEAPP_H

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

private:
    Ui::RecipeApp *ui;
    vector<int> previousPages;
};
#endif // RECIPEAPP_H
