#ifndef CLASSUNIT_CPP
#define CLASSUNIT_CPP
#include "Unit.cpp"
#include <memory>
#include <vector>

class ClassUnit : public Unit {
public:
    const std::vector<std::string> *ACCESS_MODIFIERS;

    // Конструктор класса ClassUnit
    // Устанавливает размер вектора m_fields равным количеству доступных модификаторов класса
    explicit ClassUnit(const std::string &name) : m_name(name) {
        m_fields.resize(ACCESS_MODIFIERS->size());
    }

    // Метод для добавления вложенных элементов
    void add( const std::shared_ptr< Unit >& unit, Flags flags )
    {
        unsigned int accessModifier = 0;
        if( flags < ACCESS_MODIFIERS->size() ) {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }


    // Объявление псевдонима Fields для std::vector<std::shared_ptr<Unit>>
    using Fields = std::vector<std::shared_ptr<Unit>>;

protected:
    std::string m_name;
    std::vector<Fields> m_fields;
};

#endif // CLASSUNIT_CPP
