import os
import sys
import pathlib

def read_file(file_string, file_name):
    file_string = file_string.split("\n")

    number_of_inputs  = 0
    number_of_outputs = 0

    ## PROCESS INPUTS
    if file_string[0].find("input"):
        number_of_inputs  = file_string[0].count("matrix")

    if file_string[1].find("output"):
        number_of_outputs = file_string[1].count("matrix")

    if number_of_inputs == 2:
        generate_function_two_inputs(file_string[3:], file_name)
    else:
        print("TO BE IMPLEMENTED")
    
def generate_function_two_inputs(function, file_name):
    generated_string = "#ifndef __MULTIPLY_PARALLEL_HPP__\n#define __MULTIPLY_PARALLEL_HPP__\n\n#include <vector>\n#include <math.h>\n#include <sched.h>\n#include <pthread.h>\n#include <framework/iterators/iterators.hpp>\n#include <framework/settings/settings.hpp>\n#include <framework/interfaces/base_parallel.hpp>\n\nnamespace framework{\n\nnamespace base\n{\n\ntemplate<typename T>\nvoid * " + file_name.replace(".", "_") + "_pthread(void * iterators__)\n{\n\titerators<T>* iterators_ = (iterators<T>*)iterators__;\n"

    print(generated_string)

abs_path = os.path.abspath(__file__)
length_abs_path = len(abs_path)
path_to_functions = abs_path[:length_abs_path - 32] + "/parallel/" 

for path in pathlib.Path(path_to_functions).iterdir():
    if path.is_file():
        current_file = open(path, "r")
        read_file(current_file.read(), current_file.name.split("/")[-1])
        current_file.close()