//! @file
#ifndef CATALOG_FILLER_H
#define CATALOG_FILLER_H

#include "catalogs_creator/catalogs_creator.h"

/**
 * @brief This function fills the catalogs with the data from the dataset.
 *
 * The dataset folder should include the files:
 *
 * - "flights.csv"
 * - "passengers.csv"
 * - "reservations.csv"
 * - "users.csv"
 *
 * This path `trabalho-pratico/dataset/data` contain some examples
 *
 * @param dataset_folder_path The path to the dataset FOLDER
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @return 0 if the catalogs were filled successfully, -1 otherwise.
 */
int catalog_filler(char* dataset_folder_path, Catalogs CATALOGS);

#endif