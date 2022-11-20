//  Sum of the Subset problem using the Backtracking approach.

#include <bits/stdc++.h>
using namespace std;

static int Total_num_nodess;

void printing_subsets(int A[], int no)  //  This function prints the subsets found
{
    for (int i = 0; i < no; i++)
    {
        cout << " " << A[i];
    }
    cout << "\n";
}


int comparison(const void *Lhss, const void *Rhss) // This function is responsible for comparison
{
    int *lhs = (int *)Lhss;
    int *rhs = (int *)Rhss;
    return *lhs > *rhs;
}



void subset_sum(int s[], int t[], int num, int t_size, int sum, int ite, int const target_sum)
{

    Total_num_nodess++;
    if (target_sum == sum)
    {
        printing_subsets(t, t_size);

        if (ite + 1 < num && sum - s[ite] + s[ite + 1] <= target_sum)
        {
            subset_sum(s, t, num, t_size - 1, sum - s[ite], ite + 1, target_sum);
        }
        return;
    }
    else
    {
        if (ite < num && sum + s[ite] <= target_sum)
        {
            for (int i = ite; i < num; i++)
            {
                t[t_size] = s[i];
                if (sum + s[i] <= target_sum)
                {
                    subset_sum(s, t, num, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}

void generateSubsets(int s[], int num, int target_sum) // this function finds subsets that generates the total required sum
{ 
    int *tuplet_vector = (int *)malloc(num * sizeof(int));
    int total = 0;

    qsort(s, num, sizeof(int), &comparison);
    for (int i = 0; i < num; i++)
    {
        total = total + s[i];
    }
    if (s[0] <= target_sum && total >= target_sum)
    {
        subset_sum(s, tuplet_vector, num, 0, 0, 0, target_sum);
    }
    free(tuplet_vector);
}

int main() // main
{
    int num;
    cout << "Enter the size of array : ";
    cin >> num;
    int weights[num];
    cout << "Enter the array elements : ";
    for (int i = 0; i < num; i++)
    {
        cin >> weights[i];
    }

    int target;
    cout << "Enter the total sum required : ";
    cin >> target;

    generateSubsets(weights, num, target);
    cout << " Total Generated Nodes are : " << Total_num_nodess;
    return 0;
}
