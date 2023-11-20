#include <stdio.h>
#include <stdlib.h>
#include "reply.h"

void createBalasan(int id, Word author, Word text,  Balasan *balasan)
{
    IDBALASAN(*balasan) = id;
    TEXTBALASAN(*balasan) = text;
    AUTHORBALASAN(*balasan) = author;
    // DATEBALASAN(*balasan) = time;
}

// void Balas(int IDKicau, int IDbalasan, boolean isFriend(Graph friend, int id1, int id2))
// {
//     if (isIDBalasValid(IDbalasan))
//     {
//         if (isFriend)
//         {
//             printf("Masukkan balasan: \n");
//             Word text = readWord(280);
//             if (text.Length > 0)
//             {
//                 printf("Selamat! balasan telah diterbitkan!\n");
//                 printf("Detil balasan:\n");
//                 DATETIME time;
//                 BacaDATETIME(&time);
            
//                 createBalasan(id2, currUser)
//             }
//             else
//             {
//                 printf("Balasan tidak boleh hanya berisi spasi!");
//             }
//         }
//         else
//         {
//             printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
//         }
//     }
//     else
//     {
//         printf("Wah, tidak terdapat kicauan yang ingin Anda balas!");
//     }
// }

// void deleteBalasan(int IDbalasan)
// {
//     dele
// }

// void displayBalasan(Kicauan kic, Balasan balasan, int depth, boolean isFriendwithTweet, Graph frine)
// {
//     // balasan pertama dari tweet memiliki depth = 1
//     if (isFriendwithTweet)
//     {
//         if (idKicauanHaveBalasan(listkic, id))
//         {
//             if (isFriend(friend, id1, id2))
//             {
//                 for (int i = 0; i < depth - 1; i++)
//                 {
//                     printf("    ");
//                 }
//                 printf("| IDBALASAN = %d\n", IDBALASAN(balasan));
//                 for (int i = 0; i < depth - 1; i++)
//                 {
//                     printf("    ");
//                 }
//                 printf("| ");
//                 displayWordWithoutEnter(AUTHORBALASAN(balasan));
//                 printf("\n");
//                 for (int i = 0; i < depth - 1; i++)
//                 {
//                     printf("    ");
//                 }
//                 printf("| ");
//                 displayWordWithoutEnter(TEXTBALASAN(balasan));
//                 printf("\n");
//                 for (int i = 0; i < depth - 1; i++)
//                 {
//                     printf("    ");
//                 }
//                 printf("| ");
//                 TulisDATETIME(DATEBALASAN(balasan));
//                 printf("\n");
//             }
//             else
//             {
//                 for (int i = 0; i < depth - 1; i++)
//                 {
//                     printf("    ");
//                 }
//                 printf("| IDBALASAN = %d\n", IDBALASAN(balasan));
//                 for (int i = 0; i < depth - 1; i++)
//                 {
//                     printf("    ");
//                 }
//                 printf("| PRIVAT\n");
//                 for (int i = 0; i < depth - 1; i++)
//                 {
//                     printf("    ");
//                 }
//                 printf("| PRIVAT\n");
//                 for (int i = 0; i < depth - 1; i++)
//                 {
//                     printf("    ");
//                 }
//                 printf("| PRIVAT\n");
//             }
//         }
//         else
//         {
//             printf("Belum terdapat balasan apapun pada kicauan tersebut.Yuk balas kicauan tersebut !");
//         }
//     }
//     else
//     {
//         printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
//     }
// }
