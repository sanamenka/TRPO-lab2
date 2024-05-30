#ifndef JAVAFACTORY_CPP
#define JAVAFACTORY_CPP
#include "abstractfactory.cpp"
#include "JavaClassUnit.cpp"
#include "JavaMethodUnit.cpp"
#include "JavaPrintOperatorUnit.cpp"

// Класс фабрики для языка Java
class JavaFactory : public AbstractFactory {
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name)
    {
        return std::make_shared<JavaClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags)
    {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text)
    {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};
#endif // JavaFACTORY_CPP
