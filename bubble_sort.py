def bubble_sort(arr):
    fl = True
    while fl:
        fl = False
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                fl = True
    return arr