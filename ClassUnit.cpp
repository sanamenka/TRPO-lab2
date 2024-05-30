#ifndef CLASSUNIT_CPP
#define CLASSUNIT_CPP
#include "Unit.cpp"
#include <memory>
#include <vector>

class ClassUnit : public Unit { // реализация элемента Класс
public:
    enum AccessModifier { // модификаторы доступа
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL,
        DEFAULT
    };

    const std::vector<std::string> ACCESS_MODIFIERS  = {
    "public", "protected", "private", "private protected", "file", "internal", "protected_internal","default"
    };
    // explicit предотвращает неявное преобразование типов при инициализации
    explicit ClassUnit(const std::string &name) : m_name(name) // конструктор
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) // метод для добавления вложенных элементов
    {
        unsigned int accessModifier = 0; // модификатор по умолчанию
        if( flags < ACCESS_MODIFIERS.size() ) { // Проверяем корректность flags и устанавливаем accessModifier в значение flags
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }



    using Fields = std::vector<std::shared_ptr<Unit>>;

protected:
    std::string m_name;
    std::vector<Fields> m_fields;
};

#endif // CLASSUNIT_CPP
