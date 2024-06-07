#include <iostream>
#include "CppFactory.cpp"
#include "CSFactory.cpp"
#include "JavaFactory.cpp"

// Метод из методички для создания класса с использованием указанной фабрики
void GenerateProgram(const std::shared_ptr<AbstractFactory>& factory) { // Принимаем умный указатель на фабрику

    // Создание объектов классов, методов и операторов вывода с использованием фабрики
    std::shared_ptr<ClassUnit> classUnit = factory->createClassUnit("MyClass");
    std::shared_ptr<MethodUnit> methodUnit1 = factory->createMethodUnit("testFunc1", "void", 0);
    std::shared_ptr<MethodUnit> methodUnit2 = factory->createMethodUnit("testFunc2", "void", 1);
    std::shared_ptr<MethodUnit> methodUnit3 = factory->createMethodUnit("testFunc3", "void", 100 | 10000);
    std::shared_ptr<MethodUnit> methodUnit4 = factory->createMethodUnit("testFunc4", "void", 0);
    std::shared_ptr<PrintOperatorUnit> printOperatorUnit = factory->createPrintOperatorUnit(R"(Hello, world!\n)");

    methodUnit2->add(printOperatorUnit);

    classUnit->add(methodUnit1, ClassUnit::AccessModifier::PUBLIC);
    classUnit->add(methodUnit2, ClassUnit::AccessModifier::PRIVATE);
    classUnit->add(methodUnit3, ClassUnit::AccessModifier::PUBLIC);
    classUnit->add(methodUnit4, ClassUnit::AccessModifier::PROTECTED);

    std::cout << classUnit->compile() << std::endl;
}

int main() {
    // Выделяем память в куче для объектов конкретных фабрик и инициализируем ими умные указатели
    std::shared_ptr<AbstractFactory> factoryCpp = std::make_shared<CppFactory>();
    std::shared_ptr<AbstractFactory> factoryCsharp = std::make_shared<CSFactory>();
    std::shared_ptr<AbstractFactory> factoryJava = std::make_shared<JavaFactory>();

// Вызываем функцию GenerateProgram с использованием C++ фабрики
    std::cout << "Class on C++:" << std::endl << std::endl;
    GenerateProgram(factoryCpp);

// Вызываем функцию GenerateProgram с использованием С# фабрики
    std::cout << "//////////////////////////////////////////////"<< std::endl << "Class on C#:" << std::endl << std::endl;
    GenerateProgram(factoryCsharp);

// Вызываем функцию GenerateProgram с использованием Java фабрики
    std::cout << "//////////////////////////////////////////////"<< std::endl << "Class on Java:" << std::endl << std::endl;
    GenerateProgram(factoryJava);

    return 0;
}
