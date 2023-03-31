#ifndef DUPLICATERECIPEEXCEPTION_H
#define DUPLICATERECIPEEXCEPTION_H

#include <Qstring>
#include <exception>

using std::exception;

class DuplicateRecipeException: public exception {
public:
    DuplicateRecipeException(const QString& recipeName);
    QString message();

private:
    QString recipeName;

};

#endif // DUPLICATERECIPEEXCEPTION_H
