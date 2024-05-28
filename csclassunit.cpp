#ifndef CSCLASSUNIT_CPP
#define CSCLASSUNIT_CPP
#include "ClassUnit.cpp"

class CSClassUnit : public ClassUnit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL
    };

    const std::vector<std::string> ACCESS_MODIFIERS = {
    "public", "protected", "private", "private protected", "file", "internal", "protected_internal"
    };


    explicit CSClassUnit(const std::string &name) : ClassUnit(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }

    void add(const std::shared_ptr<Unit> &unit, Flags flags) override
    {
        int accessModifier = INTERNAL;

        if (flags < ACCESS_MODIFIERS.size()) {
            accessModifier = flags;
        }

        m_fields[accessModifier].push_back(unit);
    }


    std::string compile(unsigned int level = 0) const override {

        std::string result = "class " + m_name + " {\n";

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {

            if (m_fields[i].empty()) {
                continue;
            }

            for (const auto &f: m_fields[i]) {
                result += ACCESS_MODIFIERS[i] + f->compile(level + 1);
            }
            result += "\n";
        }

        result += generateShift(level) + "};\n";
        return result;
    }
};
#endif // CSCLASSUNIT_CPP
