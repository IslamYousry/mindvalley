#ifndef EASYGENERATOR_H_
#define EASYGENERATOR_H_

#include"RandomGenerator.h"
class EasyGenerator : public  RandomGenerator{
public:
	EasyGenerator(){}
	void generate(int** arr, int** colors, int size);
};

#endif /* EASYGENERATOR_H_ */
