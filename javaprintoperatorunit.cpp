#ifndef JAVAPRINTOPERATORUNIT_CPP
#define JAVAPRINTOPERATORUNIT_CPP
#include "printoperatorunit.cpp"

class JavaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperator( const std::string& text ) : PrintOperatorUnit(text) { }

    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
    }
};

#endif // JAVAPRINTOPERATORUNIT_CPP
