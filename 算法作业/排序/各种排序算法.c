//插入排序
void InsertSort(int* a, int n)
{
    for(int j = 0;j < n-1;j++)
    {
        int end = j;
        int temp = a[end + 1];
        while(end >= 0)
        {
            if(a[end] >= temp)
            {
                break;
            }
            else
            {
                a[end+1] = a[end];
                end--;
            }
        }
        a[end+1] = temp;

    }
  
}

// 希尔排序
void ShellSort(int* a, int n)
{
    int gap = n;
    while(gap > 1)
    {
        gap = gap / 3 + 1;
        for(int j = 0;j < n- gap;j++)
        {
            int end = j;
            int temp = a[end+gap];
            while(end >= 0)
            {
                if(a[end] > temp)
                {
                    a[end+gap] = a[end];
                    end = end-gap;
                }
                else
                {
                    break;
                }
            }
            a[end+gap] = temp;

        }
    }
}

// 选择排序
void SelectSort(int* a, int n)
{
    
    int left = 0;
    int right = n-1;
    while(left < right)
    {
        int max = left;
        int min = left;
        for(int i = left+ 1;i <= right;i++)
        {
            if(a[max] < a[i])max = i;
            if(a[min] > a[i])min = i;
        }

        swap(a+left, a+min);
        if(max == left)
        max == min;
        swap(a+right, a+max);
        left++;
        right--;
    }
}

// 堆排序
void AdjustDwon(int* a, int n, int root);
{
    int child = root * 2 + 1;
    while(child < n)
    {
        if(a[child] < a[child + 1])
        child++;
        if(a[root] < a[child])
        {
            swap(a+root, a+child);
            root = child;
            child = 2 * root + 1;
        }
        else
        {
            break;
        }
    }
    
}

void HeapSort(int* a, int n)
{
    for(int i = (i - 2) / 2; i >= 0;i--)
    {//建堆
        AdjustDwon(a, n, i);
    }
    int end = n - 1;
    while(end > 0)
    {
        swap(a+end, a);
        adjustDwon(a, end, 0);
        end--;
    }

}

// 冒泡排序
void BubbleSort(int* a, int n)
{
    for(int j = 0;j < n - 1;j++)
    {
        for(int i = 0;i < n - j -1;i++)
        {
            if(a[i] > a[i+1])
            {
                swap(a+i, a+i+1);
            }
        }
    }
}

//快速排序
void QuickSort(int* a, int begin, int end)
{
    if(begin >= end) return;
    int left = begin;
    int right = end;
    int keyi = left;
    while(left < right)
    {
        while(left < right && a[right] >= a[keyi])right--;
        while(left < right && a[left] <= a[keyi])left++;
        sawp(a+left, a+right);
    }
    swap(a+keyi, a+left);
    keyi = left;
    QuickSort(a, begin, keyi - 1);
    QuickSort(a, keyi + 1, end);

}

int PartSort1(int* a, int begin, int end)
{//hoare法
    int left = begin;
    int right = end;
    int keyi = begin;
    while(left < right)
    [
        while(left < right && a[left] < a[keyi])left++;
        while(left < right && a[right] > a[keyi])right--;

        swap(a+left, a+right);
    ]
    swap(a + keyi, a + left);
    keyi = left;
    return keyi;
}

int PartSort2(int* a, int begin, int end)
{//挖坑法
    int left = begin;
    int right = end;
    int key = a[begin];
    int hope = begin;//坑位
    while(left < right)
    {
        whlie(left < right && a[right] > key)right--;
        swap(a+right,a+hope);
        hope = right;
        while(lekt < right && a[left] < key)left++;
        swap(a+left, a+hope);
        hope = left;
    }
    a[hope] = key;
    return hope;
}

int PartSort3(int* a, int begin, int end)
{//前后指针法
    int keyi = begin;
    int cur = begin + 1;
    int prev = begin;
    while(cur <= end)
    {
        if(a[cur] < a[keyi] && ++p != cur)
        {
            swap(&a[++prev], &a[cur]);
        }
        cur++;
    }
    swap(a+prev, a+ keyi);
    return prev;

}

void QuickSortNonR(int* a, int begin, int end)
{// 快速排序 非递归实现
    ST st;
	
    StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

    while(!StackEmpty(&st))
    {
        

        int right = StackTop(&st);
        StackPop(&st);
        int left = StackTop(&st);
        StackPop(&st);

        int keyi = PartSort1(a, left, right);

        if(keyi + 1 < right)
        {
            StackPush(&st, keyi + 1)
            StackPush(&st, right)

        }
        
        if(keyi - 1 > left)
        {
            StackPush(&st, left);
            StackPush(&st, keyi - 1);
        }
        
    }

}

void _MergeSort(int* a, int* tmp, int begin, int end)
{
    if(begin >= end) return;
    int mid = (begin + end) / 2;
    _MergeSort(a, tmp, begin, mid);
    _MergeSort(a, tmp, mid + 1, end);

    //归并
    int begin1 = begin, end1 = mid;
    int begin2 = mid + 1, end2 = end;
    int k = begin;
    while(begin1 <= end1 && begin2 <= end2)
    {
        if(a[begin1] < a[begin2])
        {
            temp[k++] = a[begin1++];
        }
        else{
            temp[k++] = a[begin2++];
        }
    }
    while(begin1 <= end1)temp[k++] = a[begin1++];
    while(begin2 <= end2)temp[k++] = a[begin2++];
    
    memcpy(a + beign, tmp + begin,sizeof(int) *(end - begin + 1) );
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if(tmp == NULL)
    {
        printf("malloc fail");
        exit(-1);
    }

    _MergeSort(a, tmp, 0, n-1);
    free(tmp);
    tmp = NULL;
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

    int range = 1;
    while(range < n)
    {
        for(int i = 0;i < n;i += 2 * range)
        {
            //归并
            int begin1 = i, end1 = i + range - 1;
            int begin2 = i + range, end2 = i + 2 * range - 1;

            if (end1 >= n)
			{//end1 begin2 end2 越界
				//修正区间 ->拷贝数据 
				end1 = n - 1;
				//不存在区间
				begin2 = n;

				end2 = n - 1;
			}
			else if (begin2 >= n)
			{//begin2 end2 越界
				begin2 = n;

				end2 = n - 1;
			}
			else if (end2 >= n)
			{//end2 越界
				end2 = n - 1;
			}

            int j = i;
            whlie(begin1 < end1 && begin2 < end2)
            {
                if(a[begin1] < a[begin2])
                {
                    temp[j++] = a[begin1++];
                }
                else
                {
                    temp[j++] = a[begin2++];
                }
            }
            while(begin1 <= end1)temp[j++] = a[begin1++];
            while(begin2 <= end2)temp[j++] = a[begin2++];
        }
        //整体归并完再拷贝
        memcpy(a, tmp, sizeof(int)* (n));
        range *= 2;
    }
    free(tmp);
    tmp = NULL;
}

// 计数排序
void CountSort(int* a, int n)
{
    int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
    
    int range = max - min + 1;
    int* countA = (int*)calloc(range,sizeof(int));
	if (countA == NULL)
	{
		printf("calloc fail");
		exit(-1);
	}

    //统计次数
    for(int i = 0;i < n;i++)
    {
        countA[a[i] - min]++;
    }

    //排序
    int k = 0;
    for(int i = 0;i < range;i++)
    {
        while(countA[i]--)
        a[k++] = i+min;
    }

    free(countA);
}