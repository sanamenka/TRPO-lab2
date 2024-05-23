#ifndef CPPPRINTOPERATORUNIT_CPP
#define CPPPRINTOPERATORUNIT_CPP
#include "PrintOperatorUnit.cpp"

class CppPrintOperatorUnit : public PrintOperatorUnit {
public:
    // Конструктор, который принимает строку text в качестве аргумента и инициализирует приватное
    // поле m_text значением этой строки. Поле m_text хранит текст, который будет выведен при
    // выполнении оператора печати
    explicit CppPrintOperatorUnit(const std::string &text) : m_text(text) {}

    std::string compile(unsigned int level = 0) const override {
        return generateShift(level+1) + "printf(\"" + m_text + "\");\n";
    }

private:
    std::string m_text;
};
#endif // CPPPRINTOPERATORUNIT_CPP
