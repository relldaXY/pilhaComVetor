//! Copyright 2017
/*!
*   author relldaXY
*   since 03/17/2017
*   version 1.0
*/


#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t

#include <stdexcept>  // C++ exceptions

namespace structures {

//! ArrayStack class.
/*!
    Describe the basic structure of the array stack with functions like push, pop and some like that  
*/
template<typename T> class ArrayStack {
 private:
        T* contents;
        int top_;
        std::size_t max_size_;
        static const auto DEFAULT_SIZE = 10u;

 public:
        //! A constructor.
        /*!
        Inicialize the stack with a default size
        */
        ArrayStack() {
            max_size_ = DEFAULT_SIZE;
            contents = new T[max_size_];
            top_ = -1;
        }
        //! A constructor.
        /*!
        Inicialize the stack with a max size
        */
        explicit ArrayStack(std::size_t max) {
            max_size_ = max;
            contents = new T[max_size_];
            top_ = -1;
        }
        //! A destructor .
        /*!
        */
        ~ArrayStack() {
            delete[] contents;
        }
        //! the method push .
        /*!
        */
        void push(const T& data) {
            if (full()) {
	            throw std::out_of_range("The ArrayStack is full");
	        } else {
	            contents[++top_] = data;
	        }
        }
        //! The method pop.
        /*!
            to pop content from the array stack 
        */
        T pop() {
            if (empty()) {
	            throw std::out_of_range("The ArrayStack is empty");
	        } else {
	            return contents[top_--];
	        }
        }
        //! The method top.
        /*!
            find out the content that's on top from array stack
        */
        T& top() {
            if (empty()) {
                throw std::out_of_range("The ArrayStack is empty");
            } else {
                return contents[top_];
            }
        }
        //! The method clear.
        /*!
            clear the array stack
        */
        void clear() {
            if (empty()) {
                throw std::out_of_range("The ArrayStack is empty");
            } else {
                top_=-1;
            }
        }
        //! The method size.
        /*! 
            to get the size about array stack 
        */
        std::size_t size() {
            return top_ + 1;
        }
        //! The method max_size.
        /*!
            to get the max_size 
        */
        std::size_t max_size() {
            return max_size_;
        }
        //! The method empty.
        /*!
            to know if the array stack is empty or not
        */
        bool empty() {
            return top_ == -1;
        }
        //! The method full.
        /*!
            to know if the array stack is full or not
        */
        bool full() {
            return top_ == (max_size_ - 1);
        }
};

}  // namespace structures



#endif
