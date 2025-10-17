def heap(arr, n, i):
    
    largest = i #предположим что i - наибольший элемент
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]: # Если левый дочерний элемент больше корня
        largest = left

    if right < n and arr[right] > arr[largest]: # Если правый дочерний элемент больше корня
        largest = right

    if largest != i: # Если наибольший элемент не i
        arr[i], arr[largest] = arr[largest], arr[i]
        heap(arr, n, largest)  # Рекурсивно повторяем


def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heap(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heap(arr, i, 0)  # Вызываем heapify на уменьшенной куче

    return arr


arr = [1, 't', 2, 7, 6, 5, 4, 15, 14, 13, 12, 11, 10, 9, 8]
if all([type(arr[i]) == int or type(arr[i]) == float for i in range(len(arr))]):
    heap_sort(arr)
    print(arr)
else:
    print('incorrect input')
