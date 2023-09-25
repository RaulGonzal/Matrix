#include<iostream>
#include<string>
//#include<array>
#ifndef LIST_H
#include "list.h"
#endif

#include "list.hpp"	
using namespace std;
//NAME: Raul Gonzalez Cespedes
//FSUID: RG21D

template<class T>
int getLongestCol(List<T> *arr, int rows){      //finds the largest column number in a matrix
    int largest_col = 0;
    int temp_col = 0;
    Node<T>* temp;

    for (int i = 0; i < rows; i++){
        temp = arr[i].getHead();
        while (temp != NULL){
            temp_col = temp->getColumn_num(); 
            if (temp_col > largest_col){                     //checks if column at current position is greater than the largest column recorded
                largest_col = temp_col;
            }
            temp = temp->getNext();
        }
    }
    return largest_col;
}

template <class T>
List<T>* sparseTranspose(List<T> *arr, int rows){                       //transposes the matrix
    int largest_col = 0;
    int temp_col = 0;
    Node<T>* temp;

    List<T>* new_arr = new List<T>[getLongestCol(arr, rows) + 1];       //new list array were the amount of rows is largest column
    
    for (int count = 0; count < rows; count++){
        temp = arr[count].getHead();
        while (temp != NULL){
            new_arr[temp->getColumn_num()].addElement(temp->getVal(), count);       //switches columns and rows  
            temp = temp->getNext();  
        }
    }   
    
   return new_arr;
}

int main()
{
    //////////////////INTEGER LIST 1////////////////////
    cout <<"Sparse Integer Matrix:\n";
    List<int> intList;

    int rows = 0;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cin.ignore();

    List<int>* IntArr = new List<int>[rows];
    cout << "Enter the values 1 row at a time. The first value will be the 0-value: \n";

    //intakes matrix
    for(int i = 0; i < rows; i++){
        cin >> intList;
        IntArr[i] = intList;
    }
    cout << endl;
    //prints matrix
    cout << "The Sparse Matrix is:" << endl; 
    for(int count = 0; count < rows; count++){
        cout << "Row " << count << ": ";
        IntArr[count].print();
    }
    cout << endl;
 
    //////////////////INTEGER LIST 2////////////////////
    List<int> intList2;
    rows = 0;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cin.ignore();

    cout << "Enter the values 1 row at a time. The first value will be the 0-value: \n";
    List<int>* IntArr_2 = new List<int>[rows];

    //intakes matrix
    for(int i = 0; i < rows; i++){
        cin >> intList2;
        IntArr_2[i] = intList2;
    }
    cout << endl;
    //prints matrix
    cout<< "The Sparse Matrix is:" << endl; 
    for(int count = 0; count < rows; count++){
        cout << "Row " << count << ": ";
        IntArr_2[count].print();
    }
    cout << endl; 

    ///////////////////////INT ADDITION///////////////////////////
    List<int>* int_sum = new List<int>[rows];
    cout << "The sum is " << endl;
    for (int i = 0; i < rows; i++){
        int_sum[i] = IntArr[i] + IntArr_2[i];                   //adds the two lists
    }

    for(int count = 0; count < rows; count++){                  //prints the lists
        cout << "Row " << count << ": ";
        int_sum[count].print();
    }
    cout << endl;

    //////////////////INT TRANSPOSE 1//////////////////// 
    cout << "The transpose of the first matrix is " << endl; 

    List<int>* transpose = sparseTranspose(IntArr, rows);       //holds the returned array of type list<T>

    //prints transpose for int list 1
   for(int j = 0; j < getLongestCol(IntArr, rows) + 1 ; j++){
        cout << "Row " << j << ": ";
        transpose[j].print();
    }
    cout << endl;

    //////////////////INT TRANSPOSE 2//////////////////// 
    cout << "The transpose of the second matrix is " << endl; 

    List<int>* IntTrans_2 = sparseTranspose(IntArr_2, rows);    //holds the returned array of type list<T>

    //prints transpose for int list 2
   for(int j = 0; j < getLongestCol(IntArr_2, rows) + 1 ; j++){
        cout << "Row " << j << ": ";
        IntTrans_2[j].print();
    }
    cout << endl;

    //////////////////////////DOUBLE 1/////////////////////////////
    cout <<"Sparse Double Matrix:\n";
    List<double> doubleList1;

    int drows = 0;
    cout << "Enter the number of rows: ";
    cin >> drows;
    cin.ignore();

    cout << "Enter the values 1 row at a time. The first value will be the 0-value: \n";
    List<double>* doub_arr1 = new List<double>[drows];

    //intakes matrix
    for(int i = 0; i < drows; i++){
        cin >> doubleList1;
        doub_arr1[i] = doubleList1;
    }
    cout << endl;
    //prints matrix
    cout<< "The Sparse Matrix is:" << endl; 
    for(int count = 0; count < drows; count++){
        cout << "Row " << count << ": ";
        doub_arr1[count].print();
    }
    cout << endl;
 
    //////////////////////////DOUBLE 2/////////////////////////////
    List<double> doubleList2;

    drows = 0;
    cout << "Enter the number of rows: ";
    cin >> drows;
    cin.ignore();

    cout << "Enter the values 1 row at a time. The first value will be the 0-value: \n";
    List<double>* doub_arr2 = new List<double>[drows];

    //intakes matrix
    for(int i = 0; i < drows; i++){
        cin >> doubleList2;
        doub_arr2[i] = doubleList2;
    }
    cout << endl;
    //prints matrix
    cout<< "The Sparse Matrix is:" << endl; 
    for(int count = 0; count < drows; count++){
        cout << "Row " << count << ": ";
        doub_arr2[count].print();
    }
    cout << endl;
    
    ////////////////////////DOUBLE ADDITION////////////////////////
    List<double>* d_sum = new List<double>[drows];
    cout << "The sum is " << endl;
    for (int i = 0; i < drows; i++){
        d_sum[i] = doub_arr1[i] + doub_arr2[i];                 //adds the two lists
    }

    for(int count = 0; count < drows; count++){
        cout << "Row " << count << ": ";
        d_sum[count].print();                                   //prints the sum of the two lists
    }
    cout << endl;
    //////////////////DDOUBLE TRANSPOSE 1////////////////////  
    cout << "The transpose of the first matrix is" << endl; 

    List<double>* d_trans1 = sparseTranspose(doub_arr1, drows);

    //prints transpose for double list 1
   for(int j = 0; j < getLongestCol(doub_arr1, drows) + 1 ; j++){
        cout << "Row " << j << ": ";
        d_trans1[j].print();
    }
    cout << endl;

    //////////////////DDOUBLE TRANSPOSE 2//////////////////// 
    cout << "The transpose of the second matrix is" << endl; 

    List<double>* d_trans2 = sparseTranspose(doub_arr2, drows);

    //prints transpose for double list 2
   for(int j = 0; j < getLongestCol(doub_arr2, drows) + 1 ; j++){
        cout << "Row " << j << ": ";
        d_trans2[j].print();
    }
    cout << endl;
    //////////////////////STRING 1///////////////////////////
    cout <<"Sparse String Matrix:\n";
    List<string> StringList1;

    int srows = 0;
    cout << "Enter the number of rows: ";
    cin >> srows;
    cin.ignore();

    cout << "Enter the values 1 row at a time. The first value will be the 0-value: \n";
    List<string>* s_arr1 = new List<string>[srows];

    //intakes matrix
    for(int i = 0; i < srows; i++){
        cin >> StringList1;
        s_arr1[i] = StringList1;
    }
    cout << endl;
    //prints matrix 
    for(int count = 0; count < srows; count++){
        cout << "Row " << count << ": ";
        s_arr1[count].print();
    }

    cout << endl;
    //////////////////////STRING 2///////////////////////////
    List<string> StringList2;

    srows = 0;
    cout << "Enter the number of rows: ";
    cin >> srows;
    cin.ignore();

    cout << "Enter the values 1 row at a time. The first value will be the 0-value: \n";
    List<string>* s_arr2 = new List<string>[srows];

    //intakes matrix
    for(int i = 0; i < srows; i++){
        cin >> StringList2;
        s_arr2[i] = StringList2;
    }
    cout << endl;
    //prints matrix 
    for(int count = 0; count < srows; count++){
        cout << "Row " << count << ": ";
        s_arr2[count].print();
    }

    cout << endl;
   //////////////////////STRING ADDITION///////////////////////////
   List<string>* str_sum = new List<string>[srows];
    cout << "The sum is " << endl;
    for (int i = 0; i < srows; i++){
        str_sum[i] = s_arr1[i] + s_arr2[i];
    }

    for(int count = 0; count < srows; count++){
        cout << "Row " << count << ": ";
        str_sum[count].print();
    }
    //////////////////STRING TRANSPOSE 1////////////////////
    cout << endl; 
    cout << "The transpose of the first matrix is" << endl; 

    List<string>* s_trans1 = sparseTranspose(s_arr1, srows);

    //prints transpose for string list 1
   for(int j = 0; j < getLongestCol(s_arr1, srows) + 1 ; j++){
        cout << "Row " << j << ": ";
        s_trans1[j].print();
    }
    cout << endl;
     //////////////////STRING TRANSPOSE 2////////////////////  
    cout << "The transpose of the second matrix is" << endl; 

    List<string>* s_trans2 = sparseTranspose(s_arr2, srows);

    //prints transpose for string list 2
   for(int j = 0; j < getLongestCol(s_arr2, srows) + 1 ; j++){
        cout << "Row " << j << ": ";
        s_trans2[j].print();
    }
    cout << endl;
    //////////////////////////////////////////////////////////////
    delete [] IntArr;
    delete [] IntArr_2;
    delete [] transpose;
    delete [] IntTrans_2;
    delete [] int_sum;
    delete [] s_arr1;
    delete [] s_arr2;
    delete [] s_trans1;
    delete [] s_trans2;
    delete [] str_sum;
    delete [] doub_arr1;
    delete [] doub_arr2;
    delete [] d_trans1;
    delete [] d_trans2;
    delete [] d_sum;

    return 0;
}