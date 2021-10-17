import os
import sys
import random
import time
import math
import matplotlib.pyplot as plt
import psutil
sys.setrecursionlimit(100000000)


#MERGE SORT (RECURSIVE)
def Merge_sort(arr,p,r):
    if p < r:
        #taking middle value of the array
        q = math.floor((p+r)/2)

        #recurrsive call of array
        Merge_sort(arr,p,q)
        Merge_sort(arr,q+1,r)
        Merge(arr,p,q,r)

def Merge(arr,p,q,r):
    #dividing original array into 2 different subarrays
    subarr_1 = q-p+1
    subarr_2 = r-q
    left_list = [0] * subarr_1
    right_list = [0] * subarr_2

    #appending half in left subarray
    for i in range(0,subarr_1):
        left_list[i] = arr[p+i]

    #appending half in right subarray
    for j in range(0,subarr_2):
        right_list[j] += arr[q+1+j]

    #initialising variables to 0
    i,j,k = 0,0,p

    #following divide and conquer paradigm to sort array
    while i < subarr_1 and j < subarr_2:
        if left_list[i] <= right_list[j]:
            arr[k] = left_list[i]
            i += 1
        else:
            arr[k] = right_list[j]
            j += 1
        k += 1

    #if any element of 1st half is less,it goes to left part
    while i < subarr_1:
        arr[k] = left_list[i]
        i += 1
        k += 1

    #if any element of 2nd half is less,goes to right part
    while j < subarr_2:
        arr[k] = right_list[j]
        j += 1
        k += 1


#QUICK SORT (Recursive)
# To do Partition of array
def quicksort(x, l, r):
    i = l
    j = r
    # pivot element in the middle
    p = x[l + (r - l) // 2]

    while i <= j:
        while x[i] < p:
            i += 1
        while x[j] > p:
            j -= 1
        # swap
        if i <= j:
            x[i], x[j] = x[j], x[i]
            i += 1
            j -= 1
        # sort left list
    if l < j:
        quicksort(x, l, j)
    # sort right list
    if i < r:
        quicksort(x, i, r)


def partition(arr, l, h):
    i = (l - 1)
    x = arr[h]

    for j in range(l, h):
        if arr[j] <= x:
            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[h] = arr[h], arr[i + 1]
    return (i + 1)


# Function to do Quick sort
# arr[] --> Array to be sorted,
# l  --> Starting index,
# h  --> Ending index

#quick sort (iterative)
def quickSortIterative(arr, l, h):
    # Create an auxiliary stack
    size = h - l + 1
    stack = [0] * (size)

    # initialize top of stack
    top = -1

    # push initial values of l and h to stack
    top = top + 1
    stack[top] = l
    top = top + 1
    stack[top] = h

    # Keep popping from stack while is not empty
    while top >= 0:

        # Pop h and l
        h = stack[top]
        top = top - 1
        l = stack[top]
        top = top - 1

        # Set pivot element at its correct position in
        # sorted array
        p = partition(arr, l, h)

        # If there are elements on left side of pivot,
        # then push left side to stack
        if p - 1 > l:
            top = top + 1
            stack[top] = l
            top = top + 1
            stack[top] = p - 1

        # If there are elements on right side of pivot,
        # then push right side to stack
        if p + 1 < h:
            top = top + 1
            stack[top] = p + 1
            top = top + 1
            stack[top] = h


def mergeSort(a):
    current_size = 1
    while current_size < len(a) - 1:
        left = 0
        while left < len(a) - 1:
            mid = min((left + current_size - 1), (len(a) - 1))
            right = ((2 * current_size + left - 1,
                      len(a) - 1)[2 * current_size + left - 1 > len(a) - 1])
            merge(a, left, mid, right)
            left = left + current_size * 2
        current_size = 2 * current_size


def merge(a, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = [0] * n1
    R = [0] * n2
    for i in range(0, n1):
        L[i] = a[l + i]
    for i in range(0, n2):
        R[i] = a[m + i + 1]
    i, j, k = 0, 0, l
    while i < n1 and j < n2:
        if L[i] > R[j]:
            a[k] = R[j]
            j += 1
        else:
            a[k] = L[i]
            i += 1
        k += 1
    while i < n1:
        a[k] = L[i]
        i += 1
        k += 1
    while j < n2:
        a[k] = R[j]
        j += 1
        k += 1


def partition(arr, l, h):
    i = (l - 1)
    x = arr[h]
    for j in range(l, h):
        if arr[j] <= x:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[h] = arr[h], arr[i + 1]
    return (i + 1)


# Driver Code
quick_rec = []
quick_it = []
mer_rec = []
mer_it = []
size = []
qReccMem = []
qIterMem = []
recMemory = []
iterMemory = []
q_it = []
m_it = []
q_rec =[]
m_rec =[]


x = list(map(int, input("Enter all Array sizes with spaces(eg: 10 100 1000):: ").split()))
print("\n")

for n in x:
    arr = random.sample(range(n), n)
    size.append(n)

    # return the memory usage in MB
    # For Iterative Quick sort
    start = time.time()
    process = psutil.Process(os.getpid())
    quickSortIterative(arr, 0, n-1)
    qIterMem.append(process.memory_info()[0] / float(2 ** 20))
    end = time.time()
    q_it.append(end-start)

    # For recurrsive quick sort
    start = time.time()
    process = psutil.Process(os.getpid())
    quicksort(arr, 0, n-1)
    qReccMem.append(process.memory_info()[0] / float(2 ** 20))
    end = time.time()
    q_rec.append(end-start)

    # For iterative merge sort
    start = time.time()
    process = psutil.Process(os.getpid())
    mergeSort(arr)
    iterMemory.append(process.memory_info()[0] / float(2 ** 20))
    end = time.time()
    m_it.append(end - start)

    # For recurrsive merge sort
    start = time.time()
    process = psutil.Process(os.getpid())
    Merge_sort(arr, 0, n-1)
    recMemory.append(process.memory_info()[0] / float(2 ** 20))
    end = time.time()
    m_rec.append(end - start)


    quick_rec.append(q_rec)
    quick_it.append(q_it)
    mer_rec.append(m_rec)
    mer_it.append(m_it)

print("MERGE SORT :-")
print('     Array Size : ', size)
print('    Time Taken by Recursion Method : ', m_rec)
print('    Time Taken by Iteration Method : ', m_it)
print('    Memory consumed in Recursion : ',   recMemory)
print('    Memory consumed in Iteration : ',   iterMemory, '\n\n')

print("QUICK SORT :-")
print('   Array Size : ', size)
print('   Time Taken by Recursion Method : ', q_rec)
print('   Time Taken by Iteration Method : ', q_it)
print('   Memory consumed in Recursion : ',   qReccMem)
print('   Memory consumed in Iteration : ',   qIterMem, '\n\n')

for i in range(2):
    if i == 0:
        #Graph for Time Taken v/s Array Size
        # plt.yscale('log')
        plt.plot(x, q_rec, color='blue', marker='o', label='Quick Recursion')
        plt.plot(x, q_it, color='yellow', marker='o', label='Quick Iterative')
        plt.plot(x, m_rec, color='red', marker='o', label='Merge Recursion')
        plt.plot(x, m_it, color='green', marker='o', label='Merge Iterative')
        plt.legend()
        plt.xlabel('Size of Array (n)')
        plt.ylabel('Time Taken (in sec)')
        plt.title('''
        Time Complexity Graph between Iterative and Recursive
                  (Time vs Array Size)
                  ''')
        plt.grid(True)
        plt.show()

    if i == 1:
        #Graph for Memory v/s Array Size
        plt.title('''
        Memory Consumption Graph between Iterative and Recursive
                  (Memory vs Array Size)
                  ''')
        plt.xlabel('Size of Array (n)')
        plt.ylabel('Memory Consumption (in MB)')
        plt.plot(x, recMemory, color='blue', marker='o', label='Quick Recursion')
        plt.plot(x, qIterMem, color='yellow', marker='o', label='Quick Iterative')
        plt.plot(x,iterMemory, color='red', marker='o', label='Merge Recursion')
        plt.plot(x, recMemory, color='green', marker='o', label='Merge Iterative')
        plt.legend()
        plt.grid(True)
        plt.show()