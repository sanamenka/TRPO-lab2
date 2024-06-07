#ifndef CPPPRINTOPERATORUNIT_CPP
#define CPPPRINTOPERATORUNIT_CPP
#include "printoperatorunit.cpp"

class CppPrintOperatorUnit : public PrintOperatorUnit {

public:
    // конструктор принимает строку и инициализирует m_text, который будет выведен оператором печати
    explicit CppPrintOperatorUnit( const std::string& text ) : PrintOperatorUnit(text) { }
    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // CPPPRINTOPERATORUNIT_CPP
