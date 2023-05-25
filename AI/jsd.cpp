#include <bits/stdc++.h> 
using namespace std;

struct Job
{
    int index;
    int deadline;
    int profit;
};

// Comparator to sort jobs in descending order of profit
struct comp
{
    bool operator()(Job *a, Job *b)
    {
        return (a->profit) > (b->profit);
    }
};

int main()
{
    int n;
    vector<Job *> job;

    cout << "Enter no. of jobs: ";
    cin >> n;

    // Input job details
    for (int i = 0; i < n; i++)
    {
        int d, p;
        cout << "Enter job deadline and profit of job id " << i+1 << ": ";
        cin >> d >> p;

        // Create a new Job object and assign values
        Job *newJob = new Job;
        newJob->deadline = d;
        newJob->index = i + 1;
        newJob->profit = p;

        job.push_back(newJob);
    }

    // Sort jobs based on profit in descending order
    sort(job.begin(), job.end(), comp());

    cout << "\nJobs in sorted order \n\n";
    cout << "Job id\tdeadline\tprofit\n";

    // Display sorted job details
    for (auto a : job)
    {
        cout << a->index << "\t" << a->deadline << "\t\t" << a->profit << "\n";
    }
    cout << endl;

    int maxDeadline = 0;

    // Find the maximum deadline among all jobs
    for (auto j : job)
    {
        if (j->deadline > maxDeadline)
        {
            maxDeadline = j->deadline;
        }
    }

    // Initialize arrays to store the job sequence and profit
    vector<int> jobIndex(maxDeadline, 0);
    vector<int> profit(maxDeadline, 0);

    // Assign jobs to appropriate slots in the sequence
    for (auto j : job)
    {
        int d = j->deadline;
        while (d != -1)
        {
            d--;
            if (jobIndex[d] == 0)
            {
                profit[d] = j->profit;
                jobIndex[d] = j->index;
                break;
            }
        }
    }

    cout << "Sequence of job: ";
    for (int i = 0; i < maxDeadline; i++)
    {
        if (jobIndex[i] != 0)
        {
            cout << jobIndex[i] << " --> ";
        }
    }
    cout << endl;
    cout << endl;

    // Calculate and display the total profit
    cout << "Total profit is: " << accumulate(profit.begin(), profit.end(), 0) << endl;

    return 0;
}


/*

Enter no. of jobs : 5
Enter job deadline and profit of job id 1 : 5 10
Enter job deadline and profit of job id 2 : 5 15
Enter job deadline and profit of job id 3 : 4 2
Enter job deadline and profit of job id 4 : 6 12
Enter job deadline and profit of job id 5 : 3 5

ewJobs in sorted order 

Job id  deadline  profit 
2         5         15
4         6         12
1         5         10
5         3         5
3         4         2

Sequence of job : 3 --> 5 --> 1 --> 2 --> 4 -->

Total profit is : 44

*/
