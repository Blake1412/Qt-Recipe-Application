#include "recipeapp.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RecipeApp w;
    w.show();
    return a.exec();
}
