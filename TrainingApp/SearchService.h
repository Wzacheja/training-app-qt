#ifndef SEARCHSERVICE_H
#define SEARCHSERVICE_H


#include <string>
#include <vector>


#include "Chapter.h"
#include "TrainingMaterial.h"

/**
 * @class SearchService
 * @brief Realizuje wyszukiwanie materiałów szkoleniowych
 * w strukturze kursu po tagach
 * (komponent, lokalizacja, kod błędu)
 */
class SearchService
{
public:
    /**
     * @brief Wyszukuje materiały szkoleniowe zawierające podany tag
     * @param course Struktura kursu
     * @param tag Szukany tag
     * @return Wektor znalezionych materiałów szkoleniowych
     */
    std::vector<TrainingMaterial> searchByTag(const std::vector<Chapter>& course,
                                              const std::string& tag) const;


    /**
     * @brief Zwraca listę wszystkich tagów występujących w kursie
     * @param course Kurs
     * @return Wektor wszystkich tagów
     */
    std::vector<std::string> getAllTags(const std::vector<Chapter>& course) const;
};

#endif // SEARCHSERVICE_H
