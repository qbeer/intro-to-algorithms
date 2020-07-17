#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> // to include DBL_MAX
#include <time.h>  // for random generation

void merge(double *vec, int start_index, int middle_index, int end_index);
void merge_sort(double *vec, int start_index, int end_index);
void print_vec(double *vec, int size, char *comment);

int main(int argc, char *argv[])
{

    srand(time(NULL));

    for (int vec_size = 4; vec_size < pow(2, 20); vec_size *= 2)
    {
        // alloc and fill vector
        double *pseudo_random_vec = malloc(sizeof(double) * vec_size);
        for (int i = 0; i < vec_size; ++i)
        {
            pseudo_random_vec[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
        }

        clock_t begin = clock();

        merge_sort(pseudo_random_vec, 0, vec_size - 1);

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%d\t%lf\n", vec_size, time_spent);
    }

    return 0;
}

void print_vec(double *vec, int size, char *comment)
{
    printf("%s\n", comment);
    for (int i = 0; i < size; i++)
    {
        printf("%lf ", vec[i]);
    }
    printf("\n");
}

void merge(double *vec, int start_index, int middle_index, int end_index)
{

    int left_array_size = (middle_index - start_index + 1);
    int right_array_size = (end_index - middle_index);

    double *left = malloc((left_array_size + 1) * sizeof(double));
    double *right = malloc((right_array_size + 1) * sizeof(double));

    for (int i = 0; i < left_array_size; ++i)
    {
        left[i] = vec[start_index + i];
    }

    for (int j = 0; j < right_array_size; ++j)
    {
        right[j] = vec[middle_index + 1 + j];
    }

    left[left_array_size] = DBL_MAX;
    right[right_array_size] = DBL_MAX;

    int left_array_index = 0;
    int right_array_index = 0;

    for (int k = start_index; k <= end_index; ++k)
    {
        if (left[left_array_index] <= right[right_array_index])
        {
            vec[k] = left[left_array_index];
            left_array_index++;
        }
        else
        {
            vec[k] = right[right_array_index];
            right_array_index++;
        }
    }
}

void merge_sort(double *vec, int start_index, int end_index)
{
    if (start_index < end_index)
    {
        int middle_index = (int)floor((double)(start_index + end_index) / 2.);
        merge_sort(vec, start_index, middle_index);
        merge_sort(vec, middle_index + 1, end_index);
        merge(vec, start_index, middle_index, end_index);
    }
}