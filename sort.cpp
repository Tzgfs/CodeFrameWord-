#include <iostream>
#include <vector>

using namespace std;

/*冒泡排序*/
vector<int> bubble_sort(vector<int> u_in)
{
    vector<int> unii = u_in;
    for (int i = 0; i < unii.size(); i++)
    {
        int temp = 0;
        for (int j = i + 1; i < unii.size(); j++)
        {
            if (unii[i] > unii[j])
            {
                temp=unii[i];
                unii[i]=unii[j];
                unii[j]=temp;
            }
        }
    }
    return unii;
}

/*归并排序*/
void mergearr(int *a, int begin, int mid, int end, int *temp)
{
    int i = begin, j = mid+1;
    int m = mid, n = end;
    int k=0;
    while(i<=m && j<=n){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=m){
        temp[k++]=a[i++];
    }
    while(j<=n){
        temp[k++]=a[j++];
    }
    for(i=0;i<k;i++){
        a[begin + i]= temp[i];
    }
}
//归并排序算子
void merge_sort(int *a, int begin, int end, int *temp){
    if(begin<end){
        int mid =(begin+end)/2;
        merge_sort(a,begin,mid,temp);
        merge_sort(a,mid+1,end,temp);
        mergearr(a,begin,mid,end,temp);
    }
}

int *MergeSort(int *a, int len){
    int *temp = new int[len];
    merge_sort(a,0,len-1,temp);
    return temp;
}

/*快速排序*/
void quick_sort(int *a, int left, int right){
    if(left>= right){
        return ;
    }
    int i=left;
    int j=right;
    int based = a[left];
    while(i<j){
        while(i<j&&a[j]>=based)
        {
            j--;
        }
        if(i<j){
            a[i]=a[j];
            i++;
        }
        while(i<j&&a[i]<based){
            i++;
        }
        if(i<j){
            a[j]=a[i];
            j--;
        }
        else{
           break;
        }
    }
    a[i]=based;
    quick_sort(a, left, j-1);
    quick_sort(a, j+1, right);
}

/*选择排序*/
void select_sort(int *a,int n){
    int min;
    for(int i= 0; i<n; i++){
        min = i;
        for(int j=i+1 ;j<n; j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
        if(min!=i){
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}


//二分查找 非递归
int BinSearch(int *a, int size, int key){
    int low = 0, high = size-1;
    int mid;
    while(low<=high){
        mid =(low+high)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

//二分查找 递归
int BinarySearch(int *a, int low,int high, int key){
    if(low<=high){
        int mid=(low+high)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return BinarySearch(a,low,mid-1,key);
        else 
            return BinarySearch(a,mid+1,high,key);
    }
}


int main()
{
    //int a[]={7,5,4,2,3,1,6};
    int a[]={1,2,3,4,5,6,7};
    int temp=BinSearch(a,7,1);
    int *ptr= a;
    int size =7;
    while(size--){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
    size =7;
    select_sort(a,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    cout<<"temp: "<<temp;
    return 0;
}