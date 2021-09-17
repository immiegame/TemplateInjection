#include "TemplateRegistry.h"
#include <iostream>

int main() {
	TemplateRegistry<RandomClass>* templateRegistryObject = new TemplateRegistry<RandomClass>();
	templateRegistryObject->RegisterClasses();

	RandomClass* myRandomClass = templateRegistryObject->getNew(0);
	myRandomClass->saySomething();
	RandomClass* myRandomClass2 = templateRegistryObject->getNew(1);
	myRandomClass2->saySomething();
	
	std::cin.get();
}