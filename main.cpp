#include <vector>
#include <iostream>
#include <chrono>


void merge(std::vector<int>& data, int start, int mid, int end) {
    // mục đích để không thây đổi dữ liệu  gốc
    int temp[end - start + 1];
    
    int i = start, j = mid + 1, d = 0;
    
    while (i <= mid && j <= end) {
        temp[d++] = (data[i] < data[j]) ? data[i++] : data[j++];
        // if (data[i] < data[j]) {
        //     temp[d++] = data[i++];
        // } else {
        //     temp[d++] = data[j++];
        // }
    }
    
    while (i <= mid) {
        temp[d++] = data[i++];
    }
    
    while (j <= end) {
        temp[d++] = data[j++];
    }
    
    for (int i = start; i <= end; i++) {
        data[i] = temp[i - start];
    }
}


void mergeSort(std::vector<int>& data, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(data, start, mid);
        mergeSort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}


bool compare(const int& numberOne, const int& numberTwo) {
    return numberOne > numberTwo;
}

void waps(int& numberOne, int& numberTwo) {
    int temp = numberOne;
    numberOne = numberTwo;
    numberTwo = temp;
}

void bubbleSort(std::vector<int>& data) {
    int length = data.size();
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if ( compare(data[j], data[j + i]) ) {
                waps(data[j], data[j + i]);
            } 
        }
        
    }
}

int main() {
    std::vector<int> arr = {
        3, -1, 2, 7, 4
    };
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    
 // Bắt đầu đo thời gian chạy
    auto start = std::chrono::high_resolution_clock::now();

    // mergeSort(arr, 0, n - 1);
    bubbleSort(arr);
    
   // Kết thúc đo thời gian chạy và tính thời gian đã trôi qua
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nTime taken by function: " << duration << " nanoseconds" << std::endl;
}



