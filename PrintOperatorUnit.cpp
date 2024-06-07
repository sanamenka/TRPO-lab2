#ifndef PRINTOPERATORUNIT_CPP
#define PRINTOPERATORUNIT_CPP
#include "Unit.cpp"
#include <memory>

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { } // конструктор инициализирует строку m_text

protected:
    std::string m_text; // строка хранения нашего текста для вывода
};

#endif // PRINTOPERATORUNIT_CPP
