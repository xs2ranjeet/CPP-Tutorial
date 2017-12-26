#ifndef _ALG_STACK_H
#define _ALG_STACK_H

#include <iostream>
#include <stdint.h>
#include <stdbool.h>
#include <exception>

namespace alg{

	template<typename T=uintptr_t>
	class Stack{
	private:
		class StackEmptyException:public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Stack exception is empty.\n";
			}
		}excp_empty;

		class StackOutOfBoundException:public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Stack Index out of bound exception.\n";
			}
		}excp_ioob;

		uint32_t m_capacity;
		uint32_t m_size;
		T *m_elements;

	public:
		Stack(const uint32_t& capacity): m_capacity(capacity),m_size(0){
			this->m_elements = new T[m_capacity];
		}

		~Stack(){
			delete [] m_elements;
		}

		Stack(const Stack&)=delete;
		Stack(const Stack&&)=delete;
		Stack& operator=(const Stack&)=delete;
		Stack& operator=(const Stack&&)=delete;

		inline bool isEmpty(){
			return m_size==0?true:false;
		}

		inline void pop(){
			if( m_size == 0) throw excp_empty;
			else m_size--;
		}

		inline T& top() const{
			if( m_size == 0) throw excp_empty;
			return m_elements[m_size-1];
		}

		inline bool push(const T & elem){
			if(m_size == m_capacity)  return false;
			m_elements[m_size++] = elem;
			return true;
		}

		inline uint32_t count() const{
			return m_size;
		}

		T& operator[](const uint32_t& idx) const{
			if (idx >= m_capacity || idx < 0) throw excp_ioob;
			return m_elements[m_size -1 -idx];
		}

	};

	int StackTest(){
		Stack<std::string> s(4);
		s.push("Gaura");
		s.push("Arjuna");
		s.push("Krishna");

		std::cout<<"Stack count: "<<s.count()<< std::endl;
		for( uint32_t i = 0; i< s.count(); ++i)
			std::cout<<"Stack  value at ->"<<i<<" : "<<s[i]<<std::endl;

		std::cout<<"Top element: "<<s.top()<<std::endl;
		s.pop();
		s.push("Hari hari");
		std::cout<<"---------------------------------------\n";
		for( uint32_t i = 0; i< s.count(); ++i)
			std::cout<<"Stack  value at ->"<<i<<" : "<<s[i]<<std::endl;
		s.pop();
		s.pop();
		s.pop();
		s.pop();
		std::cout<<"End---------------------------\n";
	}
	
		
}

#endif