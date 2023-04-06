#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template<class T>
class Stack : public LinkedList<T>{
	public:
		virtual bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0) return false; //this를 사용해서 first가 클래스 변수임을 나타냄
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T> *current = this->first;
			this->first = current->link; //first를 두번째 노드로 변경
			element = current -> data;
			delete current;
			this->current_size--; //this를 사용해서 current_size가 클래스 변수임을 나타냄
			return true;
			}
};
