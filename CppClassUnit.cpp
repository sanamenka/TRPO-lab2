#ifndef CPPCLASSUNIT_CPP
#define CPPCLASSUNIT_CPP
#include "ClassUnit.cpp"

class CppClassUnit : public ClassUnit{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    const std::vector<std::string> ACCESS_MODIFIERS  = {"public", "protected", "private"};


    explicit CppClassUnit(const std::string &name) : ClassUnit(name) {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }

    void add(const std::shared_ptr<Unit> &unit, Flags flags) // Метод для добавления вложенных файлов
    {
        int accessModifier = PRIVATE;

        if (flags < ACCESS_MODIFIERS.size())
        {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }

    // Метод для генерации кода. level - уровень вложенности
    virtual std::string compile(unsigned int level = 0) const
    {
        std::string result = "class " + m_name + " {\n"; // в result будем сохраняем сгенерированную строку
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i){ // цикл прохода по доступным модификаторам
            // если вектор, содержащий подэлементы класса для текущего модификатора пуст - идем дальше
            if (m_fields[i].empty()){
                continue;
            }
            // для С++ добавляем ключевое слово модификатора (public: и тд)
            result += ACCESS_MODIFIERS[i] + ":\n";

            // если не пуст, то перебираются все элементы вектора m_fields и формируется строка для каждого подэлемента класса
            for (const auto &f: m_fields[i]){
                result +=f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n"; // завершение формирования строки
        return result;
    }
};
#endif // CPPCLASSUNIT_CPP
