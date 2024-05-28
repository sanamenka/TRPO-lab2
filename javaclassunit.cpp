#ifndef JAVACLASSUNIT_CPP
#define JAVACLASSUNIT_CPP
#include "ClassUnit.cpp"

class JavaClassUnit : public ClassUnit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT
    };
    const std::vector<std::string> ACCESS_MODIFIERS = {"public", "protected", "private", "default"};

    explicit JavaClassUnit(const std::string &name) : ClassUnit(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }

    std::string compile(unsigned int level = 0) const
    {

        std::string result = "class " + m_name + " {\n";

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
        {

            if (m_fields[i].empty())
            {
                continue;
            }

            for (const auto &f: m_fields[i])
            {
                result += ACCESS_MODIFIERS[i] + f->compile(level + 1);
            }
            result += "\n";
        }

        result += generateShift(level) + "};\n";
        return result;
    }
};

#endif // JAVACLASSUNIT_CPP
