#include "user.h"
Word wetons[5];

void CreateUser(User *user)
{
    user->accType = true;
    user->friendNum = 0;
    CreateWord(&(user->name));
    CreateWord(&(user->password));
    CreateWord(&(user->phoneNum));
    CreateWord(&(user->bio));
    CreateWord(&(user->weton));
    CreateFriendRequest(&(user->friendReqList));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j += 2)
        {
            user->profilePic[i][j] = 'R';
        }
        for (int j = 1; j < 10; j += 2)
        {
            user->profilePic[i][j] = '*';
        }
    }
}

void readPhoneNum(User *user)
{
    printf("Masukkan No HP:\n");
    Word num = readWord(1023);
    printf("\n");
    while (!isAllNum(num))
    {
        printf("No HP tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan No HP: \n");
        num = readWord(1023);
        printf("\n");
    }
    user->phoneNum = num;
}

void readBio(User *user)
{
    printf("Masukkan Bio Akun:\n");
    Word bio = readWord(135);
    printf("\n");
    user->bio = bio;
}

void ConstructWeton()
{
    for (int i = 0; i < 5; i++)
    {
        CreateWord(&wetons[i]);
    }
    // Weton pertama
    wetons[0].Length = 6;
    char pahing[] = "Pahing";
    for (int i = 0; i < 6; i++)
    {
        wetons[0].TabWord[i] = pahing[i];
    }

    // Weton kedua
    wetons[1].Length = 6;
    char kliwon[] = "Kliwon";
    for (int i = 0; i < 6; i++)
    {
        wetons[1].TabWord[i] = kliwon[i];
    }

    // Weton ketiga
    wetons[2].Length = 4;
    char wage[] = "Wage";
    for (int i = 0; i < 4; i++)
    {
        wetons[2].TabWord[i] = wage[i];
    }

    // Weton keempat
    wetons[3].Length = 3;
    char pon[] = "Pon";
    for (int i = 0; i < 3; i++)
    {
        wetons[3].TabWord[i] = pon[i];
    }

    // Weton kelima
    wetons[4].Length = 4;
    char legi[] = "Legi";
    for (int i = 0; i < 4; i++)
    {
        wetons[4].TabWord[i] = legi[i];
    }
}

void readWeton(User *user)
{
    ConstructWeton();
    boolean still = true;
    printf("Masukkan Weton:\n");
    Word weton = readWord(10);
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        if (isCharEqual(weton, wetons[i]))
        {
            user->weton = wetons[i];
            displayWord(wetons[i]);
            still = false;
            break;
        }
    }
    while (still)
    {
        printf("Weton anda tidak valid.\n\n");
        weton = readWord(10);
        printf("\n");
        for (int i = 0; i < 5; i++)
        {
            if (isCharEqual(weton, wetons[i]))
            {
                user->weton = wetons[i];
                still = false;
                break;
            }
        }
    }
}

void switchAccType(User *user)
{
    Word ans;
    if (user->accType)
    {
        printf("Saat ini, akun Anda adalah akun Publik.\n");
        printf("Ingin mengubah ke Akun Privat?\n");
    }
    else
    {
        printf("Saat ini, akun Anda adalah akun Privat.\n");
        printf("Ingin mengubah ke Akun Publik?\n");
    }
    printf("(YA/TIDAK) ");
    ans = readWord(10);
    if (ans.Length == 2)
        user->accType = !user->accType;
    printf("\n");
}

boolean isAllNum(Word w)
{
    for (int i = 0; i < w.Length; i++)
    {
        if (w.TabWord[i] - '0' < 0 || w.TabWord[i] - '0' > 9)
            return false;
    }
    return true;
}

void changeProfilePicture(User *user)
{
    printf("Foto profil Anda saat ini adalah\n");
    showProfilePicture(*user);
    printf("Masukkan foto profil yang baru\n");
    STARTWORD();
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 10; j++){
            user->profilePic[i][j] = currentWord.TabWord[0];
            ADVWORD();
        }
    }
}

void showProfilePicture(User user)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j += 2)
        {
            if (user.profilePic[i][j] == 'R')
            {
                print_red(user.profilePic[i][j + 1]);
            }
            else if (user.profilePic[i][j] == 'G')
            {
                print_green(user.profilePic[i][j + 1]);
            }
            else
            {
                print_blue(user.profilePic[i][j + 1]);
            }
        }
        printf("\n");
    }
}

void showProfile(User user)
{
    printf("| Nama: ");
    displayWord(user.name);
    printf("| Bio Akun: ");
    displayWord(user.bio);
    printf("| No HP: ");
    displayWord(user.phoneNum);
    printf("| Weton: ");
    displayWord(user.weton);
    printf("\nFoto profil akun ");
    displayWord(user.name);
    showProfilePicture(user);
}