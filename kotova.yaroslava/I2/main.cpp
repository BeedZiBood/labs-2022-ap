#include <iostream>
#include <fstream>
#include "algorithimsarrays.h"

int main(int argc, char* argv[]){
  const int divider = 3;

  if (argc != 2){
    std::cout << "File is wrong\n";
    return 2;
  }
//1
  int FirstArray[] = { 1, 2, 6, 12, 12, 12, 9, -5, 4, 4 };
  size_t arr1_index_m = 1;
  size_t arr1_index_n = 6;

  std::cout<< counterDivision(firstArray, 10, divider) << " ";
  std::cout << checkRepeatEl(firstArray, 10, arr1_index_m, arr1_index_n) << " ";
//2
  size_t size_arr2 = 0;
  size_t arr2_index_m = 1, arr2_index_n = 6;
  std::cin >> size_arr2;
  if (size_arr2 == 0){
    std::cout << "Empty array\n";
  }
  else{
    int* SecondArray = new int[size_arr2];
    std::srand(time(0));
    for (size_t i = 0; i < size_arr2; i++){
      secondArray[i] = std::rand();
    }
    try{
      size_t cnt_div_arr2 = counterDivision(secondArray, size_arr2, divider);
      size_t cnt_check_rep_el = checkRepeatEl(secondArray, size_arr2, arr2_index_m, arr2_index_n);
      std::cout << cnt_div_arr2 << " " << cnt_check_rep_el << " ";
    catch (const std::invalid_argument& e) {
      std::cout << e.what();
      delete[] secondArray;
      return 1;
    }
    delete[] secondArray;
  }
//3
  size_t arr3_index_m = 1, arr3_index_n = 6;
  std::ifstream file(argv[1]);
  if (!file_arr){
    std::cout << " file open with an error";
    return 1;
  }
  while (!file_arr.eof()){
    size_t size_arr3 = 0;
    file_arr >> size_arr3;
    if (!file_arr){
      std::cout << " reading file with an error ";
      return 1;
    }
    int* thirdArray = new int[size_arr3};
    for (size_t i = 0; i < size_arr3; i++){
      file_arr >> thirdArray[i];
      if (!file_arr)
      {
        std::cout << "reading file with an error ";
        delete[] thirdArray;
        return 1;
      }
    }
  size_t cnt_div_arr3 = counterDivision(thirdArray, size_arr3, divider);
  size_t cnt_check_rep_el3 =  checkRepeatEl(thirdArray, size_arr3, arr3_index_m, arr3_index_n);
  std::cout << cnt_div_arr3 << " " << cnt_check_rep_el3 << " ";
  delete[] thirdArray;
  return 0;
}
