#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>
#include <vector>

#include "TrainingMaterial.h"
#include "Chapter.h"

/**
 * @class DataManager
 * @brief Odpowiada za wczytywanie danych aplikacji z plików JSON.
 *
 * Druga wersja umożliwia wczytanie kursu z pliku JSON
 * i zwrócenie go w postaci wektora Chapter, oraz
 * to co pierwsza, czyli mateirał szkoleniowy z pliku JSON.
 *
 * Kolejne wersje umożliwią wczytanie: pytań, postępów i multimediów.
 */
class DataManager
{
public:
    /**
     * @brief Wczytuje materiały szkoleniowe z pliku JSON
     * @param filePath Ścieżka do pliku JSON
     * @return Wektor materiałów szkoleniowych
     */
    std::vector<TrainingMaterial> loadTrainingMaterials(const std::string& filePath) const;

    /**
     * @brief Wczytuje strukturę kursu z pliku JSON
     * @param filePath Ścieżka do pliku JSON
     * @return Wektor rozdziałów
     */
    std::vector<Chapter> loadCourse(const std::string& filePath) const;
};

#endif // DATAMANAGER_H
