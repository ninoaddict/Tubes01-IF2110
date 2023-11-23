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
        printf("Masukkan nama:\n");
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
            printf("Masukkan nama:\n");
            name = readWord(25);
            printf("\n");
            errorCode = isUsernameNotValid(name, *listuser);
        }

        // masukkan password
        printf("Masukkan password:\n");
        Word password = readWord(25);
        printf("\n");
        while (!isPasswordValid(password))
        {
            printf("Password lebih dari 20 karakter!\n\n");
            printf("Masukkan password:\n");
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
        printf("Masukkan nama:\n");
        Word name = readWord(25);
        printf("\n");
        int idx = searchUserByID(*listuser, name);
        while (idx == -1)
        {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n\n");
            printf("Masukkan nama:\n");
            Word name = readWord(25);
            idx = searchUserByID(*listuser, name);
            printf("\n");
        }

        // masukkan password
        printf("Masukkan password:\n");
        Word password = readWord(25);
        printf("\n");
        while (!isWordEqual(password, listuser->listU[idx].password))
        {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n\n");
            printf("Masukkan password:\n");
            password = readWord(25);
            printf("\n");
        }

        // keluarkan pesan
        printf("Anda telah berhasil masuk dengan nama pengguna ");
        displayWordWithoutEnter(listuser->listU[idx].name);
        printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n\n");

        // set current idx
        *currIdx = idx;
    }
}

void friendList(ListUser listuser, int currIdx, Friend friend)
{
    if (currIdx == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
    else
    {
        int listFriendIdx[listuser.Neff], cnt = 0;
        for (int i = 0; i < listuser.Neff; i++)
        {
            if (i != currIdx && isFriend(friend, currIdx, i))
            {
                listFriendIdx[cnt] = i;
                cnt++;
            }
        }
        if (!cnt)
        {
            displayWordWithoutEnter(listuser.listU[currIdx].name);
            printf(" belum mempunyai teman\n\n");
        }
        else
        {
            displayWordWithoutEnter(listuser.listU[currIdx].name);
            printf(" memiliki %d teman\n", cnt);
            printf("Daftar teman ");
            displayWord(listuser.listU[currIdx].name);
            for (int i = 0; i < cnt; i++)
            {
                printf("| ");
                displayWord(listuser.listU[listFriendIdx[i]].name);
            }
            printf("\n");
        }
    }
}

void deleteFriend(ListUser *listuser, int currIdx, Friend *friend)
{
    if (currIdx == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    }
    else
    {
        printf("Masukkan nama pengguna:\n");
        Word name = readWord(25);
        printf("\n");
        int idx = searchUserByID(*listuser, name);
        if (idx == -1)
        {
            printf("Pengguna bernama ");
            displayWordWithoutEnter(name);
            printf(" tidak ditemukan.\n\n");
        }
        else if (!isFriend(*friend, currIdx, idx))
        {
            displayWordWithoutEnter(name);
            printf(" bukan teman Anda\n\n");
        }
        else
        {
            printf("Apakah anda yakin ingin menghapus ");
            displayWordWithoutEnter(name);
            printf(" dari daftar teman anda? (YA/TIDAK) ");
            Word confirm = readWord(25), ya;
            assignWord(&ya, "YA", 2);
            if (isWordEqual(ya, confirm))
            {
                listuser->listU[currIdx].friendNum--;
                listuser->listU[idx].friendNum--;
                unsetFriend(friend, currIdx, idx);
                displayWordWithoutEnter(name);
                printf(" berhasil dihapus dari teman Anda.\n\n");
            }
            else
            {
                printf("Penghapusan teman dibatalkan.\n\n");
            }
        }
    }
}

void addFriendReq(ListUser *listuser, int currIdx, Friend *friend)
{
    // kalau belum login
    if (currIdx == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    else if (PQLength(listuser->listU[currIdx].friendReqList))
    {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n\n");
        return;
    }
    printf("Masukkan nama pengguna:\n");
    Word name = readWord(25);
    printf("\n");
    int nameIdx = searchUserByID(*listuser, name);
    if (nameIdx == -1)
    {
        printf("Pengguna bernama ");
        displayWordWithoutEnter(name);
        printf(" tidak ditemukan\n\n");
    }
    else if (isRequested(*friend, currIdx, nameIdx))
    {
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
        displayWordWithoutEnter(name);
        printf(". Silakan tunggu hingga permintaan Anda disetujui.\n\n");
    }
    else if (isFriend(*friend, currIdx, nameIdx))
    {
        printf("Pengguna yang bernama ");
        displayWordWithoutEnter(name);
        printf(" adalah teman anda. Silahkan coba lagi!\n\n");
    }
    else
    {
        setRequest(friend, currIdx, nameIdx); // set request di matrix friend
        addToFriendReqList(&(listuser->listU[nameIdx].friendReqList), currIdx, listuser->listU[currIdx].friendNum);
        printf("Permintaan pertemanan kepada ");
        displayWordWithoutEnter(name);
        printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n\n");
    }
}

void cancelFriendReq(ListUser *listuser, int currIdx, Friend *friend)
{
    if (currIdx == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    printf("Masukkan nama pengguna:\n");
    Word name = readWord(25);
    printf("\n");
    int nameIdx = searchUserByID(*listuser, name);
    if (nameIdx == -1)
    {
        printf("Pengguna bernama ");
        displayWordWithoutEnter(name);
        printf(" tidak ditemukan\n\n");
    }
    else if (!isRequested(*friend, currIdx, nameIdx))
    {
        printf("Anda belum mengirimkan permintaan pertemanan kepada ");
        displayWordWithoutEnter(name);
        printf(".\n\n");
    }
    else if (isFriend(*friend, currIdx, nameIdx))
    {
        printf("Pengguna yang bernama ");
        displayWordWithoutEnter(name);
        printf(" adalah teman anda. Silahkan coba lagi!\n\n");
    }
    else
    {
        unsetRequest(friend, currIdx, nameIdx);
        removeFromFriendReqList(&(listuser->listU[nameIdx].friendReqList), currIdx);
        printf("Permintaan pertemanan kepada ");
        displayWordWithoutEnter(name);
        printf(" telah dibatalkan.\n\n");
    }
}

void displayFriendRequestList(ListUser listuser, int currIdx)
{
    if (currIdx == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    int countPQ = PQLength(listuser.listU[currIdx].friendReqList);
    if (!countPQ)
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n\n");
    }
    else
    {
        printf("Terdapat %d permintaan pertemanan untuk Anda\n\n", countPQ);
        PQAddress currNode = listuser.listU[currIdx].friendReqList;
        while (currNode != NULL)
        {
            pii val = INFO(currNode);
            printf("| ");
            displayWord(listuser.listU[val.first].name);
            printf("| Jumlah teman: %d\n\n", val.second);
            currNode = NEXT(currNode);
        }
    }
}

void confirmFriendRequest(ListUser *listuser, int currIdx, Friend *friend)
{
    if (currIdx == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (PQLength(listuser->listU[currIdx].friendReqList) == 0)
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n\n");
    }
    else
    {
        pii val;
        dequeue(&(listuser->listU[currIdx].friendReqList), &val);
        printf("Permintaan pertemanan teratas dari ");
        displayWord(listuser->listU[val.first].name);
        printf("\n");
        printf("| ");
        displayWord(listuser->listU[val.first].name);
        printf("| Jumlah teman: %d\n\n", val.second);
        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK)  ");
        Word confirm = readWord(25), ya;
        assignWord(&ya, "YA", 2);
        printf("\n");
        if (isWordEqual(ya, confirm))
        {
            setFriend(friend, currIdx, val.first);
            listuser->listU[currIdx].friendNum += 1;
            listuser->listU[val.first].friendNum += 1;
            printf("Permintaan pertemanan dari ");
            displayWordWithoutEnter(listuser->listU[val.first].name);
            printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
            displayWordWithoutEnter(listuser->listU[val.first].name);
            printf(".\n\n");
        }
        else
        {
            printf("Permintaan pertemanan dari ");
            displayWordWithoutEnter(listuser->listU[val.first].name);
            printf(" telah ditolak\n\n");
        }
    }
}

void searchFriendGroup(ListUser listuser, int currIdx, Friend friend)
{
    if (currIdx == -1)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    makeSet(listuser.Neff);
    for (int i = 0; i < listuser.Neff; i++)
    {
        for (int j = i + 1; j < listuser.Neff; j++)
        {
            if (i != j && isFriend(friend, i, j))
            {
                unionSet(i, j);
            }
        }
    }
    int friendGroupResult[20], idx = 0;
    for (int i = 0; i < listuser.Neff; i++)
    {
        if (findParent(currIdx) == findParent(i))
        {
            friendGroupResult[idx] = i;
            idx++;
        }
    }
    printf("Terdapat %d orang dalam Kelompok Teman ", idx);
    displayWordWithoutEnter(listuser.listU[currIdx].name);
    printf(" :\n");
    for (int i = 0; i < idx; i++)
    {
        displayWord(listuser.listU[friendGroupResult[i]].name);
    }
    printf("\n");
}