#include "reply.h"

void createBalasan(int id, Word author, Word text, DATETIME time, int idAuthorBalasan, Balasan *balasan)
{
    IDBALASAN(*balasan) = id;
    TEXTBALASAN(*balasan) = text;
    AUTHORBALASAN(*balasan) = author;
    DATEBALASAN(*balasan) = time;
    IDAUTHORBALASAN(*balasan) = idAuthorBalasan;
}

