#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include <iostream>

class list_element{
public:
	list_element(int n=0, list_element *next=nullptr):n(n),next(next){};
	int n;
	list_element *next;
};

class singlelist{
public:
	singlelist(list_element *head=nullptr, list_element *cursor=nullptr):head(head),cursor(cursor){};
	bool is_Empty(){
		if (head==nullptr)
			return 1;
		else 
			return 0;
	};

	void insert_before(int n){
		if (head==nullptr)
			cursor=head=new list_element(n,head);
		else 
			head=new list_element(n,head);
	};

	void insert_after(int n){
		if (head==nullptr)
			cursor=head=new list_element(n,head);
		else {
			while(cursor->next!=nullptr)
			cursor=cursor->next;
			cursor->next=new list_element(n,nullptr);
			cursor=cursor->next;
		}
	};

	list_element *FindPrevious(int n){
		//single list should find the previous element 
		list_element *p=head;
		while (p->next!=nullptr && p->next->n!=n)
			p=p->next;
		return p;
	};

	void Delete(int n){
		if (head->n==n){
			list_element *headtemp=head->next;
			delete head;
			head=headtemp;
		}
		else{
			list_element *position=FindPrevious(n);
			position->next=position->next->next;
			delete position;
		}
	};

	void disp(){
		list_element *t=head;
		std::cout<<"This is the list: "<<std::endl;
		while(t!=nullptr){
			std::cout<<t->n<<" ";
			t=t->next;
		}
		std::cout<<std::endl;
	}

private:
	list_element *head;
	list_element *cursor;
};
#endif
