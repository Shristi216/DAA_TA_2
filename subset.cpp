//  Sum of the Subset problem using the Backtracking approach.

#include <bits/stdc++.h>

using namespace std;

static int Total_num_nodess;

void printing_subsets(int Arr[], int no) //  This function prints the subsets found
{

    for (int i = 0; i < no; i++)
    {
        cout << " " << Arr[i];
    }
    cout << "\n";
}
int comparison(const void *Lhss, const void *Rhss) // This function is responsible for comparison
{

    int *left = (int *)Lhss;
    int *right = (int *)Rhss;
    return *left > *right;
}

void subset_sum(int s[], int t[], int num, int tsize, int sum, int ite, int const total_sum)
{

    Total_num_nodess++;
    if (total_sum == sum)
    {
        printing_subsets(t, tsize);
        if (ite + 1 < num && sum - s[ite] + s[ite + 1] <= total_sum)
        {
            subset_sum(s, t, num, tsize - 1, sum - s[ite], ite + 1, total_sum);
        }
        return;
    }

    else
    {
        if (ite < num && sum + s[ite] <= total_sum)
        {
            for (int i = ite; i < num; i++)
            {
                t[tsize] = s[i];
                if (sum + s[i] <= total_sum)
                {
                    subset_sum(s, t, num, tsize + 1, sum + s[i], i + 1, total_sum);
                }
            }
        }
    }
}

void generateSubsets(int s[], int num, int total_sum) // this function finds subsets that generates the total required sum
{

    int *tuplet_vector = (int *)malloc(num * sizeof(int));
    int total = 0;
    qsort(s, num, sizeof(int), &comparison);
    for (int i = 0; i < num; i++)
    {
        total = total + s[i];
    }
    if (s[0] <= total_sum && total >= total_sum)
    {
        subset_sum(s, tuplet_vector, num, 0, 0, 0, total_sum);
    }
    free(tuplet_vector);
}

int main() // main
{

    int num;
    cout << "Enter the size of array : ";
    cin >> num;
    int array[num];
    cout << "Enter the array elements : ";
    for (int i = 0; i < num; i++)
    {
        cin >> array[i];
    }
    int total_target;
    cout << "Enter the total sum required : ";
    cin >> total_target;
    generateSubsets(array, num, total_target);
    cout << " Total Generated Nodes are : " << Total_num_nodess;
    return 0;
}
