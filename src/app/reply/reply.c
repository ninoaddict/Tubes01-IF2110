#include <stdio.h>
#include <stdlib.h>
#include "reply.h"
#include "../friend/friend.h"
#include "../tweet/tweet.h"
#include "../../../lib/binarytree/binarytree.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"

void createBalasan(int id, Word author, Word text, DATETIME time, Balasan *balasan)
{
    ID(*balasan) = id;
    TEXT(*balasan) = text;
    AUTHOR(*balasan) = author;
    DATE(*balasan) = time;
}

void Balas (int IDKicau, int IDbalasan){

}

void deleteBalasan(int IDbalasan){
    
}

void displayBalasan(Kicauan kic, Balasan balasan, int depth, boolean isFriendwithTweet)
{
    // balasan pertama dari tweet memiliki depth = 1
    if (isFriendwithTweet)
    {
        if (isHaveBalasan(kic))
        {
            if (isFriend(friend, id1, id2))
            {
                for (int i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ID = %d\n", ID(balasan));
                for (int i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ");
                displayWordWithoutEnter(AUTHOR(balasan));
                printf("\n");
                for (int i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ");
                displayWordWithoutEnter(TEXT(balasan));
                printf("\n");
                for (int i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ");
                TulisDATETIME(DATE(balasan));
                printf("\n");
            }
            else
            {
                for (int i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| ID = %d\n", ID(balasan));
                for (int i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| PRIVAT\n");
                for (int i = 0; i < depth - 1; i++)
                {
                    printf("    ");
                }
                printf("| PRIVAT\n");
                for (int i = 0; i < depth - 1; i++)
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
