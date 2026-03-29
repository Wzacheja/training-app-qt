#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>
#include <vector>

#include "TrainingMaterial.h"

/**
 * @class DataManager
 * @brief Odpowiada za wczytywanie danych aplikacji z plików JSON.
 *
 * Pierwsza wersja umożliwia wczytanie materiałów szkoleniowych z pliku JSON
 * i zwrócenie ich w postaci wektora obiektów TrainingMaterial.
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
};

#endif // DATAMANAGER_H
