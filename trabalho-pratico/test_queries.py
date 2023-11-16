#!/bin/python3

import glob
import os
import hashlib
import subprocess

def delete_previous_results(pattern):
    files_to_delete = glob.glob(pattern)
    
    if not files_to_delete:
        return
    
    print(f"Deleting previous results")
    
    for file_path in files_to_delete:
        try:
            os.remove(file_path)
        except Exception:
            print(f"Error while deleting previous results")

def calculate_md5(file_path):
    with open(file_path, "rb") as file:
        md5 = hashlib.md5()
        while chunk := file.read(8192):
            md5.update(chunk)
    
    return md5.hexdigest()

def calculate_md5_for_files(pattern):
    files_to_calculate_hash = glob.glob(pattern)
    
    if not files_to_calculate_hash:
        print(f"No files found matching the pattern '{pattern}'.")
        return
    
    md5_list = []
    
    for file_path in files_to_calculate_hash:
        try:
            md5_hash = calculate_md5(file_path)
            md5_list.append(md5_hash)
        except Exception as e:
            print(f"An error occurred while calculating MD5 hash for '{file_path}': {e}")

    return md5_list

def run_program(i):
    command = f"./programa-principal dataset/data dataset/inputs/input_{i}.txt"
    
    try:
        subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    except subprocess.CalledProcessError as e:
        print(f"Error while running the command for input_{i}.txt: {e}")


correct_md5_list = calculate_md5_for_files("dataset/outputs/command*_output.txt")

incorrect_results_by_query = {}

for i in range(1, 11):
    if not os.path.exists(f"dataset/inputs/input_{i}.txt"):
        continue

    delete_previous_results("Resultados/command*_output.txt")
    print(f"Checking Query {i}")

    run_program(i)

    result_md5_list = calculate_md5_for_files("Resultados/command*_output.txt")

    # verify if one of the result_md5_list isn't present in the correct_md5_list
    are_all_correct = True
    incorrect_results = []
    for result_md5 in (result_md5_list or []):
        if result_md5 not in correct_md5_list:
            are_all_correct = False
            incorrect_results.append(result_md5)

    if len(incorrect_results) > 0:
        incorrect_results_by_query[i] = incorrect_results

if (len(incorrect_results_by_query) == 0):
    print("All results are correct!")
    exit(0)

print("\nIncorrect results by query:")
for query, incorrect_results in incorrect_results_by_query.items():
    print(f"\tQuery {query}:")
    for result in incorrect_results:
        print(f"\t\t Hash:  {result}")

exit(1)
