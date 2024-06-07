#ifndef UNIT_CPP
#define UNIT_CPP
#include <memory>
#include <vector>

class Unit {
public:
    using Flags = unsigned int;
    virtual ~Unit() = default;

    virtual void add(const std::shared_ptr<Unit> &, Flags) // Метод для добавления вложенных файлов, по умолчанию не поддреживается
    {
        throw std::runtime_error("Not supported");
    }

    virtual std::string compile(unsigned int level = 0) const = 0; // Метод для генерации кода, level - уровень вложенности

protected:
    virtual std::string generateShift(unsigned int level) const // Метод который возвращает строку с пробелом
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for (unsigned int i = 0; i < level; ++i)
        {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_CPP
