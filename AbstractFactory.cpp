#ifndef ABSTRACTFACTORY_CPP
#define ABSTRACTFACTORY_CPP
#include <iostream>
#include "ClassUnit.cpp"
#include "PrintOperatorUnit.cpp"
#include "MethodUnit.cpp"


class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}

    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) = 0; // метод создания классов
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags) = 0; // метод создания методов
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0; // метод создания оператора вывода
};

#endif // ABSTRACTFACTORY_CPP
