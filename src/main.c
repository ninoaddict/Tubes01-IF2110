#include "main.h"

int main()
{
    setup();
    while (run)
    {
        printf(">> ");
        readCommand(command);
        idxCommand = -1;
        for (int i = 0; i < 14; i++)
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
            break;
        case 5:
            int idNameProfile = searchUserByID(listuser, command[1]);
            if (listuser.listU[idNameProfile].accType)
                showProfile(listuser.listU[idNameProfile]);
            else if (currID != -1 && (isFriend(friendGraph, currID, idNameProfile) || currID == idNameProfile))
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
        default:
            break;
        }
        // printf("AFTER: %d\n", currID);
    }
    return 0;
}