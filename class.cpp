#include <string>
#include "class.h"
    

    size_t FlatMap::std_comparer(std::string first, std::string second) { //tut vse eshe max
        size_t len_first = first.size();
        size_t len_second = second.size();
        size_t len_min = std::min(len_first, len_second); //len_min
        if (len_min == 0)
            if (len_first == len_second)
                return 2;
            else
                return (len_second == 0);
        for (size_t i = 0; i < len_min; ++i)
            if (first[i] != second[i])
                return ((first[i] - second[i]) > 0); //first > second?
        if (len_first != len_second)
            return (len_first > len_second);
        else return 2; //если строки равны
    }

    size_t FlatMap::binarys_search(std::string** bebix, const std::string* argument) {
        int len = (int)(sizez - 1);
        int start = 0;
        int finish = len;
        for (int index_medium = len / 2; ;) {
            if (start > finish) {
                return (size_t)start;
            }
            index_medium = start + (finish - start) / 2;
            size_t compare = std_comparer(*argument, *bebix[index_medium]);
            if (compare == 2)
                return index_medium;
            else
                if (compare) {
                    start = index_medium + 1;
                }
                else {
                    finish = index_medium - 1;
                }
        }
        return 0;
    }

    std::string** map;
    size_t sizez;


    // стандартный конструктор
    FlatMap::FlatMap() {
        sizez = 0;
        map = NULL;
    }

    // конструктор копирования
    FlatMap::FlatMap(const FlatMap& other_map) {
        sizez = other_map.sizez;
        if (other_map.map == NULL)
            map = NULL;
        else {
            size_t len = sizez;
            map = new (std::string * [len]);
            for (size_t i = 0; i < len; i++)
                map[i] = new std::string[2];
            for (size_t i = 0; i < len; ++i)
                for (size_t index = 0; index < 2; ++index) {
                    map[i][index] = other_map.map[i][index];
                }
        }
    }

    // деструктор
    FlatMap::~FlatMap() {
        if (map != NULL) {
            std::size_t len = sizez;
            for (std::size_t i = 0; i < len; ++i)
                delete[] map[i];
            delete[] map;
        }
    }

    // оператор присваивания
    FlatMap& FlatMap::operator=(const FlatMap& other_map) {
        sizez = other_map.sizez;
        if (sizez) {
            map = new std::string * [sizez];
            for (int index = 0; index < sizez; index++) {
                map[index] = new std::string[2];
                map[index][0] = other_map.map[index][0];
                map[index][1] = other_map.map[index][1];
            }
        }
        else
            map = NULL;
        return *this;
    }

    // получить количество элементов в таблице
    std::size_t FlatMap::size() const {
        return sizez;
    }

    // доступ / вставка элемента по ключу
    std::string& FlatMap::operator[](const std::string& key) {
        if (map == NULL) {
            sizez = 1;
            map = new std::string * [1];
            map[0] = new std::string[2];
            map[0][0] = key;
            return map[0][1];
        }
        else {
            if (this->contains(key)) {
                size_t index = binarys_search(map, &key);
                return map[index][1];
            }
            size_t index = binarys_search(map, &key);
            std::string** value = new std::string * [sizez + 1];
            for (size_t i = 0; i < index; i++) {
                value[i] = new std::string[2];
                value[i][0] = map[i][0];
                value[i][1] = map[i][1];
                delete[] map[i];
            }
            value[index] = new std::string[2];
            value[index][0] = key;
            for (size_t i = index; i < sizez; i++) {
                value[i + 1] = new std::string[2];
                value[i + 1][0] = map[i][0];
                value[i + 1][1] = map[i][1];
                delete[] map[i];
            }
            delete[] map;
            map = value;
            sizez++;
            return map[index][1];
        }

    }

    // возвращает true, если запись с таким ключом присутствует в таблице
    bool FlatMap::contains(const std::string& key) {
        size_t index = binarys_search(map, &key);
        if ((index < sizez) && (map[index][0] == key))
            return 1;
        else
            return 0;
    }

    // удаление элемента по ключу, возвращает количество удаленных элементов (0 или 1)
    std::size_t FlatMap::erase(const std::string& key) {
        if (this->contains(key)) {
            size_t index = binarys_search(map, &key);
            std::string** bill = new std::string * [sizez];
            for (size_t i = 0; i < index; i++) {
                bill[i] = new std::string[2];
                bill[i][0] = map[i][0];
                bill[i][1] = map[i][1];
                delete[] map[i];
            }
            delete[] map[index];
            for (size_t i = index; i < sizez - 1; i++) {
                bill[i] = new std::string[2];
                bill[i][0] = map[i + 1][0]; //
                bill[i][1] = map[i + 1][1];
                delete[] map[i + 1];
            }
            delete[] map;
            map = bill;
            sizez--;
            return 1;
        }
        else
            return 0;

    }

    // очистка таблицы, после которой size() возвращает 0, а contains() - false на любой ключ
    void FlatMap::clear() { //perepisat' cherez size
        if (map != NULL) {
            std::size_t len = sizez;
            for (std::size_t i = 0; i < len; ++i)
                delete[] map[i];
            delete[] map;
        }
        map = NULL;
        sizez = 0;
    }
