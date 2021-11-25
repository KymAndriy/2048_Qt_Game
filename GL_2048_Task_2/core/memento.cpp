#include "memento.hpp"

void Memento::saveStep(qint32 *src, const qint32 &len)
{
    isSaved = true;
    memcpy(backup_field, src, len * sizeof(qint32));
}

void Memento::restoreStep(qint32 *dest, const qint32 &len)
{
    if (isSaved)
    {
        isSaved = false;
        memcpy(dest, backup_field, len * sizeof(qint32));
    }
}

bool Memento::canRestore()
{
    return isSaved;
}
