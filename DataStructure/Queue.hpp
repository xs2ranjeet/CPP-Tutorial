#ifndef _ALG_QUEUE_H
#define _ALG_QUEUE_H

#include <iostream>
#include <stdint.h>
#include <stdbool.h>
#include <exception>

namespace alg{

	template<typename T=uintptr_t>
	class Queue{
	private:
		class QueueEmptyException:public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Queue: queue is empty.\n";
			}
		} excp_empty;
		class QueueIndexOutOfBoundException:public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Queue: index out of bound.\n";
			}
		} excp_ioob;


	private:
		uint32_t m_capacity;
		uint32_t m_front;
		uint32_t m_rear;
		T *m_elements;

	public:
		Queue(const uint32_t capacity): m_capacity(capacity), m_front(-1), m_rear(-1){
			this->m_elements = new T[m_capacity];			
		}

		~Queue(){
			delete [] m_elements;
		}

		Queue(const Queue&)=delete;
		Queue(const Queue&&)=delete;

		Queue& operator=(const Queue&)=delete;
		Queue& operator=(const Queue&&)=delete;

		inline bool isEmpty() const{
			return m_front == -1?true:false;
		}

		inline bool isFull() const{
			return ((m_rear+1)%m_capacity == m_front ? true: false);
		}

		inline uint32_t size() const{
			return (m_capacity- m_front+m_rear+1)%m_capacity;
		}

		inline bool  EnQueue(const T& elem) {
			if(this->isFull()) return false;

			m_rear = (m_rear+1)%m_capacity;
			m_elements[m_rear] = elem;
			if(m_front == -1)
				m_front = m_rear;
			return true;
		}

		inline T DeQueue(){
			if(this->isEmpty())
				throw excp_empty;
			T data = m_elements[m_front];
			if(m_front == m_rear)
				m_front = m_rear = -1;
			else
				m_front = (m_front+1)%m_capacity;
			return data;
		}

	};

	int QueueTest(){
		Queue<std::string> q(5);
		std::cout<<"Queue Size: "<<q.size()<<std::endl;
		std::cout<<"Queue isEmpty: "<<q.isEmpty()<<std::endl;
		
		std::cout<<"Enq: "<<q.EnQueue("Gopinath")<<std::endl;
		std::cout<<"Enq: "<<q.EnQueue("Shayam")<<std::endl;
		std::cout<<"Enq: "<<q.EnQueue("Radhey")<<std::endl;
		std::cout<<"Enq: "<<q.EnQueue("hari")<<std::endl;
		std::cout<<"Enq: "<<q.EnQueue("Govind")<<std::endl;
		std::cout<<"Enq: "<<q.EnQueue("murari")<<std::endl;
		std::cout<<"Queue Size: "<<q.size()<<std::endl;
		
		std::cout<<"Deq: "<<q.DeQueue()<<std::endl;
		std::cout<<"Deq: "<<q.DeQueue()<<std::endl;
		std::cout<<"Deq: "<<q.DeQueue()<<std::endl;
		std::cout<<"Deq: "<<q.DeQueue()<<std::endl;
		std::cout<<"Deq: "<<q.DeQueue()<<std::endl;
		std::cout<<"Deq: "<<q.DeQueue()<<std::endl;
		
		return 1;
	}
};
#endif