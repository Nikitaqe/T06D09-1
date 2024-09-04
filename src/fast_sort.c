#include <stdio.h>
#define NMAX 10

int input(int *a, int f);
void output(int *a, int *b, int f);
void siftDown(int *numbers, int root, int bottom);
void heapSort(int *numbers, int array_size);
void quickSort(int *numbers, int left, int right);

int main() {
    int data[NMAX], data1[NMAX];
    int flag = 1;
    flag = input(data, flag);
    for (int i = 0; i < NMAX; i++) {
        data1[i] = data[i];
    }
    if (flag == 1) {
        heapSort(data, NMAX);
        quickSort(data1, 0, NMAX - 1);
    }
    output(data, data1, flag);
    return 0;
}

int input(int *a, int f) {
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            f = 0;
        }
    }
    if (getchar() != '\n') {
        f = 0;
    }
    return f;
}

void output(int *a, int *b, int f) {
    if (f == 1) {
        for (int *p = a; p - a < NMAX; p++) {
            printf("%d ", *p);
        }
        printf("\n");
        for (int *p = b; p - b < NMAX; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    } else {
        printf("n/a\n");
    }
}

void quickSort(int *numbers, int left, int right) {
    int pivot;
    int index;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right) {
        while ((numbers[right] > pivot) && (left < right)) right--;
        if (left != right) {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] < pivot) && (left < right)) left++;
        if (left != right) {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    index = left;
    left = l_hold;
    right = r_hold;
    if (left < index) quickSort(numbers, left, index - 1);
    if (right > index) quickSort(numbers, index + 1, right);
}

void siftDown(int *numbers, int root, int bottom) {
    int maxChild;  // индекс максимального потомка
    int done = 0;  // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)   // если мы в последнем ряду,
            maxChild = root * 2;  // запоминаем левый потомок
        // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild]) {
            int temp = numbers[root];  // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else         // иначе
            done = 1;  // пирамида сформирована
    }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size) {
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--) siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}