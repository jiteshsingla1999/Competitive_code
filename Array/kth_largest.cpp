#include <iostream>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int quick_sort_util(int *arr, int start, int stop, int ppos)
{
    int temp = arr[ppos];
    int i=start;
    int j=start;
    while(j<stop)
    {
        if(arr[j]<temp)
        {
            swap(arr, i,j);
            j++;i++;
            continue;
        }
        j++;
    }
    swap(arr, i, ppos);
    return i;
}

int quick_sort(int *arr,int start, int stop, int pos)
{
	///cout << start << "->" << stop << "->" << pos << endl;
    int upos = quick_sort_util(arr, start, stop, stop);
    if(upos==pos-1)
    return arr[upos];
    else if(upos>pos-1)
    return quick_sort(arr, start, upos-1, pos);
    else
    return quick_sort(arr, upos+1, stop, pos);
    
}

int main() {
	//code
	boost;
	int test;
	cin >> test;
	while(test--)
	{
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin >> arr[i];
	    
	    int pos;
	    cin >> pos;
	    int element = quick_sort(arr,0, n-1, pos);
	    cout << element << endl;
	}
	return 0;
}
