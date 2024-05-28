#ifndef JAVAPRINTOPERATORUNIT_CPP
#define JAVAPRINTOPERATORUNIT_CPP
#include "printoperatorunit.cpp"

class JavaPrintOperator : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperator( const std::string& text ) : PrintOperatorUnit(text) { }

    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
    }
};

#endif // JAVAPRINTOPERATORUNIT_CPP
