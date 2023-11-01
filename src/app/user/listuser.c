#include "listuser.h"

// CONSTRUCTOR
void CreateListUser(ListUser *listuser)
{
    listuser->Neff = 0;
    for (int i = 0; i < 20; i++)
    {
        CreateUser(&(listuser->listU[i]));
    }
}

// SELEKTOR
int searchUserByID(ListUser listuser, Word name)
{
    for (int i = 0; i < listuser.Neff; i++)
    {
        if (name.Length == listuser.listU[i].name.Length)
        {
            boolean same = true;
            for (int j = 0; j < name.Length; j++)
            {
                if (name.TabWord[j] != listuser.listU[i].name.TabWord[j])
                {
                    same = false;
                    break;
                }
            }
            if (same)
                return i;
        }
    }
    return -1;
}

int isUsernameNotValid(Word name, ListUser listuser)
{
    // cek panjang
    if (name.Length > 20)
        return 1;

    // cek apakah sudah ada yang menggunakan username tersebut sebelumnya
    if (searchUserByID(listuser, name) != -1)
        return 2;

    // cek apakah udah ada sebelumnya
    for (int i = 0; i < name.Length; i++)
    {
        if (name.TabWord[i] != ' ')
            return 0;
    }
    return 3;
}

boolean isPasswordValid(Word password)
{
    return (password.Length <= 20);
}

void SignUp(ListUser *listuser, int *currIdx)
{
    if (*currIdx != -1)
    {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n\n");
    }
    else
    {
        // masukkan nama
        printf("Masukkan nama: \n");
        Word name = readWord(25);
        printf("\n");
        int errorCode = isUsernameNotValid(name, *listuser);
        while (errorCode)
        {
            if (errorCode == 1)
            {
                printf("Username terlalu panjang!\n\n");
            }
            else if (errorCode == 2)
            {
                printf("Wah, sayang sekali nama tersebut telah diambil.\n\n");
            }
            else
            {
                printf("Username tidak boleh hanya terdiri atas spasi!\n\n");
            }
            printf("Masukkan nama: \n");
            name = readWord(25);
            printf("\n");
            errorCode = isUsernameNotValid(name, *listuser);
        }

        // masukkan password
        printf("Masukkan password: \n");
        Word password = readWord(25);
        printf("\n");
        while (!isPasswordValid(password))
        {
            printf("Password lebih dari 20 karakter!\n\n");
            printf("Masukkan password: \n");
            password = readWord(25);
            printf("\n");
        }

        // keluarkan pesan berhasil
        listuser->listU[listuser->Neff].name = name;
        listuser->listU[listuser->Neff].password = password;
        listuser->Neff += 1;
        printf("Anda telah berhasil masuk dengan nama pengguna ");
        displayWordWithoutEnter(listuser->listU[listuser->Neff - 1].name);
        printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n\n");

        // set current idx
        *currIdx = listuser->Neff - 1;
    }
}

void LogIn(ListUser *listuser, int *currIdx)
{
    if (*currIdx != -1)
    {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n\n");
    }
    else
    {
        // masukkan nama
        printf("Masukkan nama: \n");
        Word name = readWord(25);
        printf("\n");
        int idx = searchUserByID(*listuser, name);
        while (idx == -1)
        {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n\n");
            printf("Masukkan nama: \n");
            Word name = readWord(25);
            idx = searchUserByID(*listuser, name);
            printf("\n");
        }

        // masukkan password
        printf("Masukkan password: \n");
        Word password = readWord(25);
        printf("\n");
        while (isWordEqual(password, listuser->listU[idx].password))
        {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n\n");
        }

        // keluarkan pesan
        printf("Anda telah berhasil masuk dengan nama pengguna ");
        displayWordWithoutEnter(listuser->listU[idx].name);
        printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n\n");

        // set current idx
        *currIdx = idx;
    }
}