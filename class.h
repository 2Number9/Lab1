#pragma once
#include <string>


class FlatMap {


private:
    size_t std_comparer(std::string first, std::string second); //tut vse eshe max

    size_t binarys_search(std::string** bebix, const std::string* argument);

public:

    std::string** map;
    size_t sizez;

    FlatMap();
    
    FlatMap(const FlatMap& other_map);

    ~FlatMap();

    FlatMap& operator=(const FlatMap& other_map);

    std::size_t size() const;

    std::string& operator[](const std::string& key);

    bool contains(const std::string& key);

    std::size_t erase(const std::string& key);

    
    void clear();

};