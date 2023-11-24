#include "user.h"
Word wetons[6];

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
    CreateMatrix(&(user->profilePic));
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
    while (bio.Length > 0 && isAllSpace(bio))
    {
        printf("Bio Anda tidak valid\n\n");
        printf("Masukkan Bio Akun:\n");
        bio = readWord(135);
    }
    printf("\n");
    user->bio = bio;
}

void ConstructWeton()
{
    for (int i = 0; i < 6; i++)
    {
        CreateWord(&wetons[i]);
    }
    // Weton pertama
    assignWord(&wetons[0], "Pahing", 6);

    // Weton kedua
    assignWord(&wetons[1], "Kliwon", 6);

    // Weton ketiga
    assignWord(&wetons[2], "Wage", 4);

    // Weton keempat
    assignWord(&wetons[3], "Pon", 3);

    // Weton kelima
    assignWord(&wetons[4], "Legi", 4);
}

void readWeton(User *user)
{
    ConstructWeton();
    boolean still = true;
    printf("Masukkan Weton:\n");
    Word weton = readWord(10);
    printf("\n");
    if (weton.Length == 0)
        return;
    for (int i = 0; i < 6; i++)
    {
        if (isCharEqual(weton, wetons[i]))
        {
            user->weton = wetons[i];
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
    Word ans, ya;
    assignWord(&ya, "YA", 2);
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
    if (isWordEqual(ans, ya))
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
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            user->profilePic.Buffer[i][j] = currentWord.TabWord[0];
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
            if (user.profilePic.Buffer[i][j] == 'R')
            {
                print_red(user.profilePic.Buffer[i][j + 1]);
            }
            else if (user.profilePic.Buffer[i][j] == 'G')
            {
                print_green(user.profilePic.Buffer[i][j + 1]);
            }
            else
            {
                print_blue(user.profilePic.Buffer[i][j + 1]);
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
    printf("\n");
}