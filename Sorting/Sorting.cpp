// Sorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

void selectSort(vector<int>& vec);
void bubbleSort(vector<int>& vec);
void insertSort(vector<int>& vec);
void mergeSort(vector<int>& vec);

void neitherland(vector<int>& vec, int num);
void neitherland2(vector<int>& vec, int num);
void quickSort(vector<int>& vec, int L, int R);
void quickSort2(vector<int>& vec, int L, int R);

void printVec(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    srand((int)time(0));
    vector<int> vec1;
    for (int i = 0; i < 100000; i++) {
        vec1.push_back(rand() % 100);
    }

    vector<int> vec2(vec1);
    vector<int> vec3(vec1);
    vector<int> vec4(vec1);
    vector<int> vec5(vec1);

    cout << "Select Sort:" << endl;
    auto start1 = system_clock::now();
    //selectSort(vec1);
    auto end1 = system_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << double(duration1.count()) * microseconds::period::num / microseconds::period::den << "s" << endl;

    cout << "Bubble Sort:" << endl;
    auto start2 = system_clock::now();
    //bubbleSort(vec2);
    auto end2 = system_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << double(duration2.count()) * microseconds::period::num / microseconds::period::den << "s" << endl;

    cout << "Insert Sort:" << endl;
    auto start3 = system_clock::now();
    //insertSort(vec3);
    auto end3 = system_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << double(duration3.count()) * microseconds::period::num / microseconds::period::den << "s" << endl;

    cout << "Merge Sort:" << endl;
    auto start4 = system_clock::now();
    mergeSort(vec4);
    auto end4 = system_clock::now();
    auto duration4 = duration_cast<microseconds>(end4 - start4);
    cout << double(duration4.count()) * microseconds::period::num / microseconds::period::den << "s" << endl;

    cout << "Quick Sort:" << endl;
    auto start5 = system_clock::now();
    quickSort2(vec5, 0, vec5.size());
    auto end5 = system_clock::now();
    auto duration5 = duration_cast<microseconds>(end5 - start5);
    cout << double(duration4.count()) * microseconds::period::num / microseconds::period::den << "s" << endl;

    //Neitherland question:
    //vector<int> vec{ 3, 4, 1, 6, 8, 3, 9, 1, 0, 7, 5, 4, 6 };
    //neitherland(vec, 4);
  /*  quickSort(vec, 0, vec.size());
    printVec(vec);*/

    return 0;
}

void neitherland(vector<int>& vec, int num) {
    int less = -1;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] <= num) {
            swap(vec[++less], vec[i]);
        }
    }
    cout << less << endl;
}

void neitherland2(vector<int>& vec, int num) {
    int less = -1;
    int greater = vec.size();
    for (int i = 0; i < greater;) {
        if (vec[i] < num) {
            swap(vec[++less], vec[i]);
            i++;
        }
        else if (vec[i] > num) {
            swap(vec[--greater], vec[i]);
        }
        else i++;
    }
    cout << less << endl << greater << endl;
}

int partition(vector<int>& vec, int L, int R) {
    int less = L-1;
    int num = vec[R - 1];
    for (int i = L; i < R; ++i) {
        if (vec[i] <= num) {
            swap(vec[++less], vec[i]);
        }
    }
    return less;
}

void quickSort(vector<int>& vec, int L, int R) {
    if (R-L < 2) {
        return;
    }
    srand(time(0));
    unsigned int index = rand() % (R - L) + L;
    swap(vec[index], vec[R - 1]);
    int M = partition(vec, L, R);
    quickSort(vec, L, M);
    quickSort(vec, M+1, R);
}

int partition2(vector<int>& vec, int L, int R) {
    int M = L-1;
    int num = vec[R - 1];
    for (int i = L; i < R; i++) {
        if (vec[i] <= num) {
            swap(vec[i], vec[++M]);
        }
    }
    return M;
}

void quickSort2(vector<int>& vec, int L, int R)
{
    if (R - L < 2) {
        return;
    }

    srand(time(0));
    unsigned int index = rand() % (R - L) + L;
    swap(vec[R - 1], vec[index]);
    int M = partition2(vec, L, R);
    quickSort2(vec, L, M);
    quickSort2(vec, M + 1, R);
}



void selectSort(vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[i])
                swap(vec[j], vec[i]);
        }
    }

}


void bubbleSort(vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        for (int j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        }
    }
}


void insertSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        for (int j = i; j > 0; --j) {
            if (vec[j] < vec[j - 1])
                swap(vec[j], vec[j - 1]);
            else break;
        }
    }
}


void mergeSort(vector<int>& vec, int L, int R);
void merge(vector<int>& vec, int L, int R);

void mergeSort(vector<int>& vec) {
    int L = 0;
    int R = vec.size();
    mergeSort(vec, L, R);
}

void mergeSort(vector<int>& vec, int L, int R) {
    if (L == R - 1)
        return;
    int M = L + ((R - L) >> 1);
    mergeSort(vec, L, M);
    mergeSort(vec, M, R);
    merge(vec, L, R);
}

void merge(vector<int>& vec, int L, int R) {
    vector<int> temp;
    int l = L;
    int m = L + ((R - L) >> 1);
    int M = m;
    while (L < m && M < R) {
        temp.push_back(vec[L] < vec[M] ? vec[L++] : vec[M++]);
    }
    while (L < m) {
        temp.push_back(vec[L++]);
    }
    while (M < R) {
        temp.push_back(vec[M++]);
    }
    copy(temp.begin(), temp.end(), vec.begin() + l);
}

void heapify() {

}