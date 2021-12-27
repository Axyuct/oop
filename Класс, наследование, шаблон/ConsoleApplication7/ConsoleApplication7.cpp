#include <iostream>
#include <utility>

/*
Смоделировать предметную область:
Кухня кафе. Обязательные сущности: повар, блюдо.
Можно добавлять дополнительные сущности по мере необходимости.
Обязательно наличие конструктора копирования и оператора присваивания хотя бы в одном классе.
Желательно описание классов и методов с помощью комментариев или с помощью XML документирования
 */

 /**
  * Абстрактная еда.
  */
class Food {
    std::string name;
    double proteins;
    double fat;
    double carbohydrates;
    double weight;
public:
    /**
     * Создаёт новый объект еды с названием, БЖУ и весом
     * @param name          - название
     * @param proteins      - белки
     * @param fat           - жиры
     * @param carbohydrates - углеводы
     * @param weight        - вес в граммах
     */
    Food(std::string name, double proteins, double fat, double carbohydrates, double weight)
        : name(std::move(name)), proteins(proteins), fat(fat), carbohydrates(carbohydrates), weight(weight) {}

    Food(const Food& another)
        : Food(another.name, another.proteins, another.fat, another.carbohydrates, another.weight) {}

    [[nodiscard]] const std::string& getName() const {
        return name;
    }

    [[nodiscard]] double getProteins() const {
        return proteins;
    }

    [[nodiscard]] double getFat() const {
        return fat;
    }

    [[nodiscard]] double getCarbohydrates() const {
        return carbohydrates;
    }

    [[nodiscard]] double getWeight() const {
        return weight;
    }

    [[nodiscard]] double calculateCalories() {
        return getProteins() * 4 + getFat() * 9 + getCarbohydrates() * 4;
    }
};

class Recipe {
    std::string name;
    double proteins;
    double fat;
    double carbohydrates;
public:
    Recipe(std::string name, double proteins, double fat, double carbohydrates) : name(std::move(name)), proteins(proteins),
        fat(fat), carbohydrates(carbohydrates) {}

    [[nodiscard]] const std::string& getName() const {
        return name;
    }

    void setName(const std::string& name) {
        Recipe::name = name;
    }

    [[nodiscard]] double getProteins() const {
        return proteins;
    }

    void setProteins(double proteins) {
        Recipe::proteins = proteins;
    }

    [[nodiscard]] double getFat() const {
        return fat;
    }

    void setFat(double fat) {
        Recipe::fat = fat;
    }

    [[nodiscard]] double getCarbohydrates() const {
        return carbohydrates;
    }

    void setCarbohydrates(double carbohydrates) {
        Recipe::carbohydrates = carbohydrates;
    }
};

class SushiRecipe : public Recipe {
    //
public:
    SushiRecipe() : Recipe("Sushi", 5.2, 6.2, 9.2) {};
};

class Chef {
    std::string name;
    Recipe recipe;
public:
    Chef(std::string name, Recipe recipe) : name(std::move(name)), recipe(std::move(recipe)) {}
    Food cook(double weight) {
        return Food{
            recipe.getName(),
            recipe.getProteins(),
            recipe.getFat(),
            recipe.getCarbohydrates(),
            weight
        };
    }

    [[nodiscard]] const std::string& getName() const {
        return name;
    }

    [[nodiscard]] const Recipe& getRecipe() const {
        return recipe;
    }
};

template<int PORTION_WEIGHT>
class Kitchen {
    Chef chef;
public:
    explicit Kitchen(Chef chef) : chef(std::move(chef)) {
        //
    }

    [[nodiscard]] const Chef& getChef() const {
        return chef;
    }

    void setChef(const Chef& chef) {
        this->chef = chef;
    }

    Food cook() {
        return chef.cook(PORTION_WEIGHT);
    }
};



int main() {
    Kitchen<290> kitchen{
        Chef {
            "Mike", SushiRecipe {}
        }
    };

    Food sushi = kitchen.cook();
    return 0;
}