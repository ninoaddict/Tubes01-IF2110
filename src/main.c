#include "main.h"

int main()
{
    setup();
    while (run)
    {
        printf(">> ");
        readCommand(command);
        idxCommand = -1;
        for (int i = 0; i < 24; i++)
        {
            if (isWordEqual(command[0], commands[i]))
            {
                idxCommand = i;
                break;
            }
        }
        // printf("BEFORE: %d\n", currID);
        switch (idxCommand)
        {
        case 0:
            SignUp(&listuser, &currID);
            break;
        case 1:
            LogIn(&listuser, &currID);
            break;
        case 2:
            if (currID == -1)
            {
                printf("Anda memang tidak pernah masuk...\n\n");
            }
            else
            {
                printf("Keluar dari akun...\n\n");
                currID = -1;
            }
            break;
        case 3:
            run = false;
            printf("Selesai\n");
            break;
        case 4:
            if (currID != -1)
            {
                showProfile(listuser.listU[currID]);
                readBio(&(listuser.listU[currID]));
                readPhoneNum(&(listuser.listU[currID]));
                readWeton(&(listuser.listU[currID]));
                printf("Profil Anda sudah berhasil diperbaharui\n\n");
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;
        case 5:
            int idNameProfile = searchUserByID(listuser, command[1]);
            if (listuser.listU[idNameProfile].accType)
                showProfile(listuser.listU[idNameProfile]);
            else if (currID != -1 && (isFriend(friendGraph, currID, idNameProfile)))
            {
                showProfile(listuser.listU[idNameProfile]);
            }
            else
            {
                printf("Wah, akun ");
                displayWordWithoutEnter(listuser.listU[idNameProfile].name);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
                displayWord(listuser.listU[idNameProfile].name);
                printf("\n");
            }
            break;
        case 6:
            if (currID != -1)
                switchAccType(&listuser.listU[currID]);
            else
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            break;
        case 7:
            if (currID != -1)
                changeProfilePicture(&listuser.listU[currID]);
            else
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            break;
        case 8:
            friendList(listuser, currID, friendGraph);
            break;
        case 9:
            deleteFriend(&listuser, currID, &friendGraph);
            break;
        case 10:
            addFriendReq(&listuser, currID, &friendGraph);
            break;
        case 11:
            cancelFriendReq(&listuser, currID, &friendGraph);
            break;
        case 12:
            displayFriendRequestList(listuser, currID);
            break;
        case 13:
            printf("masuk\n");
            confirmFriendRequest(&listuser, currID, &friendGraph);
            break;
        case 14:
            if (currID != -1)
            {
                bacaKicauan(&lkic, listuser.listU[currID], &currTweetID, currID);
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;
        case 15:
            if (currID != -1)
            {
                displayListKicauan(lkic, friendGraph, currID);
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;
        case 16:
            if (currID != -1)
            {
                likeKicau(&lkic, listuser, friendGraph, wordToInteger(command[1]), currID);
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;
        case 17:
            if (currID != -1)
            {
                updateKicau(&lkic, currID, wordToInteger(command[1]));
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;
        case 18:
            if (currID != -1)
            {
                makeKicauanUtama(&lkic, currID, wordToInteger(command[1]), &id_utas);
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;

        case 19:
            if (currID != -1)
            {
                sambungUtas(&lkic, currID, wordToInteger(command[1]), wordToInteger(command[2]));
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;

        case 20:
            if (currID != -1)
            {
                DATETIME date;
                Word text;
                putusUtas(&lkic, &date, &text, currID, wordToInteger(command[1]), wordToInteger(command[2]));
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;

        case 21:
            if (currID != -1)
            {
                cetakUtas(lkic, friendGraph, listuser, currID, wordToInteger(command[1]));
            }
            else
            {
                printf("Silahkan masuk terlebih dahulu ke akun Anda!\n\n");
            }
            break;
        case 22:
            searchFriendGroup(listuser, currID, friendGraph);
            break;
        case 23:
            searchFYB(lkic, friendGraph, currID, listuser);
            break;
        default:
            break;
        }
        // printf("AFTER: %d\n", currID);
    }
    return 0;
}