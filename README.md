# DAA_TA_2

Name: Shristi Gupta

Roll no.: 23

Batch: A2

                                                   TA_2_DAA
                                                                     
 ==> Problem Statement: 
 
 Sum of the Subset problem using the Backtracking approach and demonstrate any two applications in the form of test cases.   

 
 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                     

The SUBSET-SUM problem involves determining whether or not a subset from a list of integers can sum to a target value. 

For example, if we consider the list of nums = [1, 2, 3, 4] . If the target = 7 , then there are two subsets that achieve this sum: {3, 4} and {1, 2, 4} 

For Example :

we have a givem array as 
W = [5,10,12,13,15,18]
Total sum = 73
Required sum = 30
so, the tree formed in below picture displays the node selection process.

![Example_subset_sum](https://user-images.githubusercontent.com/91418248/203297201-11d037ca-3295-4269-bfa7-19a46fd8f590.jpeg)

                                                   CODE:
                                                              
 
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



OUTPUT:


![image](https://user-images.githubusercontent.com/91418248/202909179-f2c9d4ca-3c80-4f9d-9a0f-b9657eafa400.png)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

==> Applications of subset-sum-problem:

  [1] buying a movie ticket

  While buying a ticket for a movie show a person has variety of coins and notes (coins:1,2,5,10,20 and notes:10,20,50,100,200,1000,2000) and the person has to total     up  the coins and notes to meet the sum that will complete the required cost of buying the ticket.


      Enter the total number of coins and notes: 8 
      Enter the values of money: 1
      20
      10
      50
      100
      200
      5
      2
      Enter the cost of ticket: 87
      
      output:
      
![image](https://user-images.githubusercontent.com/91418248/202906062-067bcb89-1aaf-4b9a-8166-7f77227156a6.png)



  [2] Puzzle Block Game

  A puzzle block game consisting of various pieces and each piece covers some area the player sets a target to cover some area daily and finish the game.  

  
      Enter the number of pieces in the puzzle box: 10
      Enter the value of areas covered by each 10 piece: 20
      23
      14
      36
      42
      65
      12
      52
      61
      19
      Enter the total area you want to cover in one day : 200
      
      output:
      
 ![image](https://user-images.githubusercontent.com/91418248/202908493-dc776cb7-f071-4956-bbab-c97a1328ae8e.png)

[3]Computer passwords

Passwords provide the first line of defense against unauthorized access to your computer and personal information.

As many as 500 artificial intelligences are generated by the computer.The internal file stores them. A password is a subset of $\{1,\dots,500\}$. (in practice, there is a program to convert a normal sequence-of-symbols password to such a subset.) Instead of having the password for the user, the computer keeps the total associated with the appropriate subset. When the user types in the subset, the computer tests whether the total is correct. It does not keep a record of the subset. Thus impersonation is possible only if somebody can reconstruct the subset knowing the $a_i$ and the total.

  [4]Message verification

An individual (S) wishes to send messages to an individual (R).The secrecy of the message is not important. However, R wants to be sure that the message he is receiving is not from an imposter and has not been tampered with. $S$ and $R$ agree on a set of $a_i$ (say 500) and a set of totals $T_j$ (say 200). These numbers may be publicly known, but only $S$ knows which subsets of the $a_i$ correspond to which $T_j$. The message sent by $S$ is a subset of size 100 of $\{1,\dots,200\}$. He does this by sending 100 subsets of the $a_i$ corresponding to the message he wants to send.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

                                                         

#Time Complexity: O(2^N)
                                                          
