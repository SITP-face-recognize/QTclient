#include "global.h"

QList <Student>* Student_List = new QList<Student>();
int Course_Id = -1;

int getId(QString stuId)
{
	for (auto iterator = Student_List->begin(); iterator != Student_List->end(); iterator++) {
		if (iterator->stuId == stuId)
			return iterator->id;
	}
	return -1;
}

QString getName(QString stuId)
{
	for (auto iterator = Student_List->begin(); iterator != Student_List->end(); iterator++) {
		if (iterator->stuId == stuId)
			return iterator->name;
	}
	return "_NULL_";
}