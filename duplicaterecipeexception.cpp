#include "duplicaterecipeexception.h"

DuplicateRecipeException::DuplicateRecipeException(const QString& message): recipeName(message) {

}

QString DuplicateRecipeException::message() {
    return "Error! Duplicate recipe " + recipeName + " with same details already exists.";
}
