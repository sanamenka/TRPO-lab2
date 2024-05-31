#ifndef JAVAMETHODUNIT_CPP
#define JAVAMETHODUNIT_CPP
#include "MethodUnit.cpp"

class JavaMethodUnit : public MethodUnit {
public:
    enum Modifier
    {
        STATIC = 1,
        FINAL = 1 << 1,
        ABSTRACT = 1 << 2,
    };

    explicit JavaMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
        : MethodUnit(name, returnType, flags) {}


    std::string compile(unsigned int level = 0) const
    {

        std::string result = generateShift(level);

        if (m_flags & ABSTRACT)
        {
            result += "abstract ";
        }

        if (m_flags & FINAL)
        {
            result += "final ";
        }

        if (m_flags & STATIC)
        {
            result += "static ";
        }

        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";

        for (const auto &b: m_body)
        {

            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    }
};


#endif // JAVAMETHODUNIT_CPP
