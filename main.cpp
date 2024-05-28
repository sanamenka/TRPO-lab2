#include <iostream>
#include "CppFactory.cpp"
#include "CSFactory.cpp"
#include "JavaFactory.cpp"

// Функция для создания класса с использованием указанной фабрики
void createAndCompileClass(const std::shared_ptr<AbstractFactory>& factory) {
    // Создание объектов классов, методов и операторов вывода с использованием фабрики
    std::shared_ptr<ClassUnit> classUnit = factory->createClassUnit("testClass");
    std::shared_ptr<MethodUnit> methodUnit1 = factory->createMethodUnit("testFunc1", "void", 1);
    std::shared_ptr<MethodUnit> methodUnit2 = factory->createMethodUnit("testFunc2", "void", 0);
    std::shared_ptr<MethodUnit> methodUnit3 = factory->createMethodUnit("testFunc3", "void", 0);
    std::shared_ptr<PrintOperatorUnit> printOperatorUnit = factory->createPrintOperatorUnit(R"(Hello, world!\n)");

    methodUnit2->add(printOperatorUnit);

    classUnit->add(methodUnit1, ClassUnit::AccessModifier::PUBLIC);
    classUnit->add(methodUnit2, ClassUnit::AccessModifier::PUBLIC);
    classUnit->add(methodUnit3, ClassUnit::AccessModifier::PUBLIC);

    std::cout << classUnit->compile() << std::endl;
}

int main() {

    std::shared_ptr<AbstractFactory> factoryCpp = std::make_shared<CppFactory>();
    std::shared_ptr<AbstractFactory> factoryCsharp = std::make_shared<CSFactory>();
    std::shared_ptr<AbstractFactory> factoryJava = std::make_shared<JavaFactory>();


    std::cout << "Class on C++:" << std::endl << std::endl;

    createAndCompileClass(factoryCpp);

    std::cout << "Class on C#:" << std::endl << std::endl;

    createAndCompileClass(factoryCsharp);

    std::cout << "Class on Java:" << std::endl << std::endl;

    createAndCompileClass(factoryJava);

    return 0;
}
