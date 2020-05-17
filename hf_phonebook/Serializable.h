#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
class serializable {
	virtual void write();
	virtual void read() const;
};
#endif // !SERIALIZABLE_H

