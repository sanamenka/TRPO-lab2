#ifndef CSCLASSUNIT_CPP
#define CSCLASSUNIT_CPP
#include "ClassUnit.cpp"

class CsharpClassUnit : public ClassUnit {
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

    // Конструктор, который принимает строку name в качестве аргумента и передает ее базовому
    // классу ClassUnit для инициализации имени класса, а также устанавливает размер вектора
    // m_fields равным количеству доступных модификаторов класса
    explicit CsharpClassUnit(const std::string &name) : ClassUnit(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }

    // Метод для добавления вложенных элементов
    void add(const std::shared_ptr<Unit> &unit, Flags flags)
    {
        // Установка модификатора по умолчанию
        int accessModifier = PRIVATE;
        // Проверяет корректность flags и устанавливает accessModifier в значение flags
        if (flags < ACCESS_MODIFIERS.size()) {
            accessModifier = flags;
        }
        // добавляет указатель unit в вектор, соответствующий модификатору доступа accessModifier
        // Таким образом, подэлемент класса будет добавлен в правильную группу вектора m_fields в
        // зависимости от переданных флагов flags
        m_fields[accessModifier].push_back(unit);
    }

    // Метод для формирования строкового представления класса со всеми его подэлементами,
    // учитывая модификаторы доступа и вложенность, level Уровень вложенности элемента
    std::string compile(unsigned int level = 0) const override {
        // Создание переменной, которая будет содержать сгенерированный результат
        std::string result = "class " + m_name + " {\n";
        // Цикл, который проходит по доступным модификаторам класса
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            // Если вектор, содержащий подэлементы класса для текущего модификатора, пуст, то
            // пропускается текущая итерация цикла
            if (m_fields[i].empty()) {
                continue;
            }
            // Если не пуст, то для каждого поля вызывается метод compile и результат добавляется
            // в строку result вместе с соответствующим модификатором доступа
            for (const auto &f: m_fields[i]) {
                result += ACCESS_MODIFIERS[i] + f->compile(level + 1) + "\n";
            }
        }
        // Формируется строка окончания класса
        result += generateShift(level) + "};\n";
        return result;
    }
};
#endif // CSCLASSUNIT_CPP
