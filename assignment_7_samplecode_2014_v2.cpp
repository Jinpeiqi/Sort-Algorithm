//Jinpeiqi 12207549
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int N = 50000;
int data[N];

void ReadTextFileToArray(char *filename)
{
    ifstream input_file;
    input_file.open(filename);
    int number;
    for(int i = 0; i < N; i++)
    {
        if(input_file.good())
        {
            input_file >> number;
            data[i] = number;
        }
        else { break; }
    }
    input_file.close();
}

void CheckSortedArray(int n)
{
    for(int i = 0; i < (n-1); i++)
    {
        if(data[i]>data[i+1])
        {
            cout<< data[i]<< " " <<data[i+1] << endl;
            cout<< "The data index is: " << i << endl;
            cout<< "Sorting incomplete" <<endl;

        }
    }
    cout << "Sorting completed" << endl;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

double SelectionSort(int n)
{
    double counter =0;
    int min;
    for(int pass = 0; pass < (n-1); pass++)
    {
        min = pass;
        for(int i = (pass+1); i < n; i++)
        {
            if(data[i]<data[min])
            {
                min = i;
            }
            counter++;
        }
        Swap(&data[min], &data[pass]);
    }
    return counter;
}

double InsertionSort(int n)
{
    int pass;
    int i;
    int temp;
    double counter = 0;

    for(pass =0; pass < (n-1); pass++)
    {
        temp = data[pass+1];
        for(i = (pass+1); i >0; i--)
        {
            counter++;
            if(data[i-1] > temp)
            {
                data[i] = data[i-1];
            }
            else break;
        }
        data[i] = temp;
    }
    return counter;
}
double BubbleSort(int n)
{
    int i;
    double counter = 0;
    bool swapping = true;

    while(swapping)
    {
        swapping =false;
        for(i=0; i< (n-1); i++)
        {
            counter++;
            if(data[i] > data[i+1])
            {
                Swap(&data[i], &data[i+1]);
                swapping = true;
            }
        }
    }
    return counter;
}
int temp[N];

double Merge(int first, int last)
{
    double counter = 0;
    int i;
    int mid = (first + last) / 2;
    int i1 = first - 1;
    int i2 = first;
    int i3 = mid + 1;
    while((i2 <= mid) && (i3 <= last))
    {
        counter ++;
        if(data[i2] < data[i3])
        {
            i1++;
            temp[i1] = data[i2];
            i2++;
        }
        else
        {
            i1++;
            temp[i1] = data[i3];
            i3++;
        }
    }
    while(i2 <= mid)
    {
        i1++;
        temp[i1] = data[i2];
        i2++;
    }
    while(i3 <= last)
    {
        i1++;
        temp[i1] = data[i3];
        i3++;
    }
    for(i = first; i <= last; i++)
    {
        data[i] = temp[i];
    }
    return counter;
}

double MergeSort(int first, int last)
{
    double counter = 0;
    if(first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(first, mid);
        MergeSort(mid+1, last);
        counter += Merge(first, last);
    }
    return counter;
}

double QuickSort(int left, int right)
{
    double counter = 0;
    int i = left;
    int j = right;
    int pivot = data[(i+j)/2];

    while (i <= j)
    {
        counter++;
        while (data[i] < pivot)
        {
           i++;
           counter++;
        }
        while (data[j] > pivot)
        {
           j--;
           counter++;
        }
        if (i <= j)
        {
            Swap(&data[i], &data[j]);
            i++;
            j--;
        }
   }

   if (left < j)
       QuickSort(left, j);

   if (i < right)
       QuickSort(i, right);
    return counter;
}

int main(int argc, char** argv )
{
    if(argc != 4)
    {
        cout << "Cannot read 3 arguments from the command line." << endl;
        cout << "(1)file name, (2)algorithm_number, (3)number of elements to sort" << endl;
        exit(1);
    }

    ReadTextFileToArray(argv[1]);
    int algorithm_number = atoi(argv[2]);
    int n = 0;
    n = atoi(argv[3]);
    double counter = 0;
    switch (algorithm_number)
    {
    case 1:
        cout << "Selection Sort on file: " << argv[1] << endl;
        counter = SelectionSort(n);
        CheckSortedArray(n);
        cout << "The number of comparisons is: " << counter << endl;
        break;
    case 2:
        cout << "Insertion Sort on file: " << argv[1] << endl;
        counter = InsertionSort(n);
        CheckSortedArray(n);
        cout << "The number of comparisons is: " << counter << endl;
        break;
    case 3:
        cout << "Bubble Sort on file: " << argv[1] << endl;
        counter = BubbleSort(n);
        CheckSortedArray(n);
        cout << "The number of comparisons is: " << counter << endl;
        break;
    case 4:
        cout << "Merge Sort on file: " << argv[1] << endl;
        for(int i=0; i < N; i++)    //Initialize temp array;
        {
            temp[i] = 0;
        }
        counter = MergeSort(0, n-1);
        CheckSortedArray(n);
        cout << "The number of comparisons is: " << counter << endl;
        break;
    case 5:
        cout << "QuickSort on file: " << argv[1] << endl;
        counter = QuickSort(0, n-1);
        CheckSortedArray(n);
        cout << "The number of comparisons is: " << counter << endl;
        break;
    default:
        cout << "The algorithm_number is incorrect." << endl;
        break;
    }

    return 0;
}
