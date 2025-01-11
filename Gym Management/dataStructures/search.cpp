#include <iostream>

using namespace std;

void search(Node* head,int target) {

	node* current = head;
	while (current != NULL) {
		if (current = target) {
			cout << target << "is in linked list";
			break
		}
		else {
			cout << target << "is not in linked list";

		}
		current = current->next;
	}


	void bSearch(int bottom,int top,int mid,int bTarget,int arr[]) {

		bool found = 0;

		while (found == 0 && bottom <= top) {
			mid = (top+bottom)/2
				if (bTarget == arr[mid]) {
					found = 1;
					return mid;
				}
				else  {
					if (bTarget < arr[mid]) {
						top = mid - 1;
					}
					  else(bTarget > arr[mid]) {
						bottom = mid + 1;
					  }
						
				}

		}

		if (!found) {
			cout << "Target not found";
		}
			
		
		


}
		
		
		
	




}