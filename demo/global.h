#ifndef GLOBAL_H
#define GLOBAL_H


#include <QStandardItemModel>
#include <QList>
class Student
{
public:
	int id;
	QString stuId;
	QString name;
	Student(int i, QString s, QString u)
	{
		id = i;
		stuId = s;
		name = u;
	}
};

extern	QList <Student>* Student_List;//���ſ�ѧ���б�
extern  int Course_Id; //��ǰ��ѡ�Ŀγ�

int getId(QString stuId);

QString getName(QString stuId);

#endif // GLOBAL_H
