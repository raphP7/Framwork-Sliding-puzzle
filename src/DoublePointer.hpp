
#ifndef DOUBLEPOINTER_HPP_
#define DOUBLEPOINTER_HPP_
template<class T> class DoublePointer{
public:
	T *a;
	T *b;
	DoublePointer(T* _a , T* _b):a(_a),b(_b){
	}
	~DoublePointer(){
		std::cout<<"delete de DoublePointer"<<std::endl;
	}
};

#endif /* DOUBLEPOINTER_HPP_ */
