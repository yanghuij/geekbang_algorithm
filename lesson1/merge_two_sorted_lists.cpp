#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode protect = {0, nullptr};
	ListNode *prev = &protect;

	while (l1 || l2) {
		if (l2 == nullptr || (l1 != nullptr && l1->val <= l2->val)) {
			prev->next = l1;
			l1 = l1->next;
		} else {
			prev->next = l2;
			l2 = l2->next;
		}
		prev = prev->next;
	}

	return protect.next;
}

ListNode* makeList(int array[], int n) {
	ListNode head = {0, nullptr};
	ListNode* prev = &head;
	
	for (int i = 0; i < n; i++) {
		ListNode* node = new ListNode;
		node->val = array[i];
		node->next = nullptr;
		
		prev->next = node;
		prev = prev->next;
	}
	
	return head.next;
}
	
void test1() {
	int a1[] = {1, 2, 4};
	int a2[] = {1, 3, 4};
	
	cout << "test1" <<endl;
	
	ListNode *l1 = makeList(a1, sizeof(a1) / sizeof(a1[0]));
	ListNode *l2 = makeList(a2, sizeof(a2) / sizeof(a2[0]));
	
	ListNode *ls = mergeTwoLists(l1, l2);
	
	cout << "[";
	while (ls) {
		cout << ls->val << " ";
		ls = ls->next;
	}
	
	cout << "]"<< endl;
}

void test2() {
	int a1[] = {};
	int a2[] = {};
	
	cout << "test2" <<endl;
	
	ListNode *l1 = makeList(a1, sizeof(a1) / sizeof(a1[0]));
	ListNode *l2 = makeList(a2, sizeof(a2) / sizeof(a2[0]));
	
	ListNode *ls = mergeTwoLists(l1, l2);
	
	cout << "[";
	while (ls) {
		cout << ls->val << " ";
		ls = ls->next;
	}
	
	cout << "]"<< endl;
}

void test3() {
	int a1[] = {};
	int a2[] = {0};
	
	cout << "test3" <<endl;
	
	ListNode *l1 = makeList(a1, sizeof(a1) / sizeof(a1[0]));
	ListNode *l2 = makeList(a2, sizeof(a2) / sizeof(a2[0]));
	
	ListNode *ls = mergeTwoLists(l1, l2);
	
	cout << "[";
	while (ls) {
		cout << ls->val << " ";
		ls = ls->next;
	}
	
	cout << "]"<< endl;
}

int main(void) {
	test1();
	test2();
	test3();
	
	return 0;
}