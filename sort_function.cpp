void Sort::select_sort(string list[], int n) { // 선택정렬
	int least;
	string tmp;
	for(int i=0; i<n-1; i++) {
		least = i;	// 현재 값을 기준으로
		for(int j=i+1; j<n; j++) {
			// 더 작은 인덱스를 찾는다
			if(compareString(list[least],list[j])) {
				least = j;
			}
		}
		// swap 과정
		tmp = list[i];
		list[i] = list[least];
		list[least] = tmp;
	}
}
void Sort::insertion_sort(string list[], int n) { // 삽입정렬
	int i,j;
	string key;

	for(i=1; i<n; i++) {
		key = list[i];	// key의 값을 기준으로 위치를 찾아내서 삽입한다.
		for(j=i-1; j>=0 && compareString(list[j],key); j--) {
			list[j+1] = list[j];
		}
		list[j+1] = key;
	}

}
void Sort::bubble_sort(string list[], int n) { // 버블정렬
	string tmp;
	// 바로 옆의 원소와 비교해서 하나하나 순서를 찾는다
	for(int i=n-1; i>0; i--) {
		for(int j=0; j<i; j++) {
			if(compareString(list[j],list[j+1])) {
				tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
			}
		}
	}
}
void Sort::merge_sort(string list[], int left, int n) {	//합병정렬
	if(left<n) {
		int mid = (left+n)/2;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, n);
		merge(list, left, mid, n);
	}

}
void Sort::merge(string list[], int left, int mid, int n) { //합병정렬
	int i,j,result;
	// mid 사이즈만큼 분할해서 정렬 후 합병한다
	for(i=left, j=mid+1, result=left; i<=mid && j<=n;) {
		if(list[i] <= list[j]) {
			mergeList[result++] = list[i++];
		}else {
			mergeList[result++] = list[j++];
		}
	}
	if(i>mid) {
		for(int p=j; p<=n; p++) {
			mergeList[result++] = list[p];
		}
	}else {
		for(int p=i; p<=mid; p++) {
			mergeList[result++] = list[p];
		}
	}
	for(int p=left; p <=n; p++) {
		list[p] = mergeList[p];
	}

}
void Sort::quick_sort(string list[], int left, int right) {	//퀵정렬
	int low = left, high = right+1;
	string pivot = list[left];
	// pivot을 기준으로 왼쪽과 오른쪽으로 나눠서 비교한다
	if(left<right) {
		do {
			do {low++;}
			while(compareString(pivot,list[low]));
			do {high--;}
			while(compareString(list[high],pivot));
			if(low<high) {
				swap(list[low],list[high]);
			}
		}while(low<high);
		swap(list[left],list[high]);
		quick_sort(list,left,high-1);
		quick_sort(list,high+1,right);
	}

}
void Sort::heap_sort(string list[], int n) { //힙정렬
	Heap heap;
	// 힙안에서 최소값을 가져오는식으로 정렬한다
	for(int i=0; i<n; i++) {
		heap.insertMinHeap(list[i]);
	}
	for(int i=0; i<n; i++) {
		list[i] = heap.deleteMinHeap();
	}
}
