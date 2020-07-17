### Introduction to algorithms - T. H. Cormen, C. E. Leiserson, R. L. Rivest, C. Stein

This repository contains algortihms from the book in the title. The algorithms are written in C, ...

#### Sorting

* [merge_sort](./sorting/merge_sort.c) -> `gcc merge_sort.c -lm`
* [insertion_sort](./sorting/insertion_sort.c)
* [heap_sort](./sorting/heap_sort.c)

### Running times

* MS = `merge sort`, while HS = `heap sort`

| Vector size | Merge sort time (s) | Heap sort time (s)  |
|:---:|:----:|:---:|
|4|   0.000009| 0.000004  |
|8|   0.000003| 0.000003  |
|16|  0.000003|       0.000005 |
|32|  0.000010|      0.00000 |
|64|  0.000020|      0.000017 |
|128| 0.000035|     0.000058 |
|256| 0.000083|     0.000126 |
|512| 0.000168|     0.000270 |
|1024|0.000392|    0.000605 |
|2048|0.000754|    0.000962 |
|4096|0.001656|    0.001950 |
|8192|0.003776|    0.003234 |
|16384  | 0.007852|   0.005914 |
|32768 |  0.015361|   0.012337 |
|65536  | 0.035763|   0.033434 |
|131072 | 0.059230|  0.073530 |
|262144 | 0.116828|  0.119463 |
|524288 | 0.317476 |  0.235416

## @Regards, Alex