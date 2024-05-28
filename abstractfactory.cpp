#ifndef ABSTRACTFACTORY_CPP
#define ABSTRACTFACTORY_CPP
#include "Unit.cpp"
#include "ClassUnit.cpp"
#include "PrintOperatorUnit.cpp"
#include "MethodUnit.cpp"
#include "CSClassUnit.cpp"
#include "CSMethodUnit.cpp"
#include "CSPrintOperatorUnit.cpp"
#include "JavaClassUnit.cpp"
#include "JavaMethodUnit.cpp"
#include "JavaPrintOperatorUnit.cpp"
#include "CppClassUnit.cpp"
#include "CppMethodUnit.cpp"
#include "CppPrintOperatorUnit.cpp"

// Объявление интерфейса ProgrammFactory

class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    // Методы создания объектов классов, методов и операторов вывода
    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0;
};

#endif // ABSTRACTFACTORY_CPP
