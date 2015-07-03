#ifndef RANDOMGENERATOR_H_
#define RANDOMGENERATOR_H_

class RandomGenerator {
public:
	RandomGenerator(){}
	virtual void generate(int** arr, int** colors, int size) =0;
};

#endif /* RANDOMGENERATOR_H_ */
