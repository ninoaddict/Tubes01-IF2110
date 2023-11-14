#include <stdio.h>
#include <stdlib.h>
#include "reply.h"
#include "../friend/friend.h"
#include "../tweet/tweet.h"
#include "../../../lib/binarytree/binarytree.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"

int depth, i;
Graph friend;
int id1, id2;

void createBalasan(int id, Word author, Word text, DATETIME time, Balasan *balasan)
{
    ID(*balasan) = id;
    TEXT(*balasan) = text;
    AUTHOR(*balasan) = author;
    DATE(*balasan) = time;
}

void displayBalasan(Kicauan kic, Balasan balasan, int depth, boolean isFriendwithTweet)
{
    // balasan pertama dari tweet memiliki depth = 1
    if (isFriendwithTweet)
    {
        if (isHaveReply(kic))
        {
            if (isFriend(friend, id1, id2))
            {
                for (i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ID = %d\n", ID(balasan));
                for (i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ");
                displayWordWithoutEnter(AUTHOR(balasan));
                printf("\n");
                for (i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ");
                displayWordWithoutEnter(TEXT(balasan));
                printf("\n");
                for (i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ");
                TulisDATETIME(DATE(balasan));
                printf("\n");
            }
            else
            {
                for (i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ID = %d\n", ID(balasan));
                for (i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| PRIVAT\n");
                for (i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| PRIVAT\n");
                for (i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| PRIVAT\n");
            }
        }
        else
        {
            printf("Belum terdapat balasan apapun pada kicauan tersebut.Yuk balas kicauan tersebut !");
        }
    }
    else{
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
    }
}

boolean isHaveReply(Kicauan kic)
{
    return BALASAN(kic) != NULL;
}