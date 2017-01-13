/*
 * JoyToPower.h
 *
 *  Created on: Jan 12, 2017
 *      Author: S-2508657
 */

#ifndef SRC_JOYTOPOWER_H_
#define SRC_JOYTOPOWER_H_

class JoyToPower {
public:
	JoyToPower(int joyInput);
	virtual ~JoyToPower();
private:
	int inputValue;
	int map(int s1, int s2, int e1, int e2, int input);
};

#endif /* SRC_JOYTOPOWER_H_ */
