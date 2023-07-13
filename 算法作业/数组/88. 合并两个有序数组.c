void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //三指针
	int src = n - 1;
	int des = m - 1;
	int	 back = m + n - 1;
	while (src >=0 && des >=0) {
		//nums2元素大于nums1元素
		if (nums2[src] > nums1[des]) {
			nums1[back--] = nums2[src--];
		}
		//nums2元素小于nums元素
		else {
			nums1[back--] = nums1[des--];
		}
	}
	while (src >= 0) {
		nums1[back--] = nums2[src--];
	}
}
