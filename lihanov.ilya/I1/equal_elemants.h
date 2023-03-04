#ifndef EQUAL_ELEMENTS
#define EQUAL_ELEMENTS

struct Equal
{
	void operator()(unsigned int currentValue);

	unsigned int previousValue;
	unsigned int beforePreviousValue;

	unsigned int countV;
};

#endif

