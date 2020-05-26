/*----------快排----------*/
int partition(vector<int>& a,int low,int high){
    int pivot=a[low];
    while(low<high){
        while(low<high&&a[high]>=pivot)high--;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
void quickSort(vector<int>& a,int low,int high){
    if(low<high){
        int pivotpos=partition(a,low,high);
        quickSort_sum(a,low,pivotpos-1);
        quickSort_sum(a,pivotpos+1,high);
    }
}

/*----------快排的变形，快速选择，用于解决TopK个最小数问题----------*/
int partition(vector<int>& a,int low,int high){
    int pivot=a[low];
    while(low<high){
        while(low<high&&a[high]>=pivot)high--;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}

void quickSelect(vector<int>& a,int low,int high,int k){
    if(low<high){
        int pivotpos=partition(a,low,high); //得到基准点，基准点左边都小于等于pivot，右边都大于等于pivot
        if(pivotpos > k)quickSelect(a,low,pivotpos-1,k);  //当前基准点左边的数比k个多，往左边分治
        else if(pivotpos < k)quickSelect(a,pivotpos+1,high,k);  //当前基准点的左边的数比k个少，往右边分治
        else return;                                          //pivotpos==k意味着0,1,...,k-1这k个数都是小于等于a[pivotpos]的，我们不可能再在右边找到一个数比前面这些数小，所以我们就找到了最小的k个数
    }
}
