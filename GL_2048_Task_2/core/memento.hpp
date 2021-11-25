#ifndef GL_MEMENTO_H
#define GL_MEMENTO_H
#include <cstring>
#include <QtCore>

#define FIELD_SIZE 16

class Memento
{
    bool isSaved;
    qint32 backup_field[FIELD_SIZE];
public:
    void saveStep(qint32* src, const qint32& len);
    void restoreStep(qint32* dest, const qint32& len);
    bool canRestore();
};

#endif
