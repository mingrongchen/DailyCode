#include<iostream>
#include<vector>

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[low];   // choose the first one as pivot

    while (low < high) {
        while (low < high && pivot <= arr[high]) high--;
        arr[low] = arr[high];

        while (low < high && pivot >= arr[low]) low++;
        arr[high] = arr[low];

    }

    arr[low] = pivot;

    return low;    // 返回基准元素的索引
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

template <typename T>
void bubbleSort(std::vector<T>& arr, int length) {
    bool swapped;    // is swapped?

    for (int i = 0; i < length - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        } // for end

        // if inside circulation isn't swapped, break the outside circulation
        if (!swapped) {
            break;
        }
    }
} // bubbleSort end

template <typename T>
void insertionSort(std::vector<T>& arr, int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;

        // 将比key大的元素向右移动
        for (; j >= 0 && arr[j] > key; j--) arr[j + 1] = arr[j];

        arr[j + 1] = key;
    }
}

template <typename T>
void selectionSort(std::vector<T>& arr, int length) {

    for (int i = 0; i < length - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < length; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }
}


template <typename T>
void heapify(std::vector<T>& arr, int length, int i) {
    int largest = i;    // 初始化父节点为最大值
    int left = 2 * i + 1;    // 左子节点
    int right = 2 * i + 2;    // 右子节点

    // 比较左子节点与父节点
    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    // 比较右子节点与父子节点
    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值不是父节点，交换并递归调整
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, length, largest);
    }
}


template <typename T>
void heapSort (std::vector<T>& arr, int length) {
    // 先构建最大堆
    for (int i = length / 2 - 1; i >= 0; --i) {
        heapify(arr, length, i);
    }

    // 逐个从堆中取出元素并调整堆 
    for (int i = length - 1; i > 0; --i) {
        // 将堆顶元素（最大值）移动到数组末尾
        std::swap(arr[0], arr[i]);
        // 调整剩余堆
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 122};
    int length = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vecArr(arr, arr + length);

    std::cout << "before sort array : ";
    // for (int i = 0; i < length; i++)
    // {
    //     std::cout << arr[i] << " ";
    // }

    // std::vector<int>::iterator
    for (auto it = vecArr.begin(); it != vecArr.end(); ++it) {
        std::cout << *it << " ";
    }

    // bubbleSort(vecArr, length);
    // quickSort(vecArr, 0, length - 1);
    // insertionSort(vecArr, length);
    // selectionSort(vecArr, length);
    heapSort(vecArr, length);

    std::cout << "\nafter sort array : ";
    // for (int i = 0; i < length; i++)
    // {
    //     std::cout << arr[i] << " ";
    // }

    for (auto it = vecArr.begin(); it != vecArr.end(); ++it) {
        std::cout << *it << " ";
    }
    
    return 0;
}