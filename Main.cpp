#include <iostream>
#include <vector>

using namespace std;


//vector <int> Compare(vector<int>& elements, vector<int>& left, vector<int>& right)
vector <int> Compare(vector<int>& left, vector<int>& right)
{
    int totalSum = left[0] + right[0];
    int maxPrefix = max(left[1], (left[0] + right[1]));
    int maxSuffix = max(right[2], right[0] + left[2]);
    int maxSum = max(max(left[3], right[3]), (left[2] + right[1]));

    return { totalSum, maxPrefix, maxSuffix, maxSum };
}

vector<int> FunctionMaxSubarray(vector<int>& elements, int low, int high)
{
    if (low == high)
    {
        return { elements[low], elements[low], elements[low], elements[low] };
    }
    else
    {
        int mid = (low + high) / 2;
        vector <int> left = FunctionMaxSubarray(elements, low, mid);
        vector <int> right = FunctionMaxSubarray(elements, mid + 1, high);
        return Compare(left, right); // old return Compare(A, left, right)
    }

}


int main()
{
    vector<int> elements = { -1,-2,-3,-4,-5 };

    int size = elements.size(); // calculate the entire sum of the elements

    vector<int> max_sum = FunctionMaxSubarray(elements, 0, size - 1); // function to find subarray


    cout << "tot sum :" << max_sum[0] << endl;
    cout << "max prefix:" << max_sum[1] << endl;
    cout << "mx suffix:" << max_sum[2] << endl;
    cout << "max sum of consecutive array:" << max_sum[3] << endl;

    return 0;
}