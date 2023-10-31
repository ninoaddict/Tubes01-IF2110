# include "user.h"
# include <stdio.h>
Word wetons[5];

void CreateUser(User * user){
    user->requestID = -1;
    user->accType = true;
    CreateWord(&(user->name));
    CreateWord(&(user->password));
    CreateWord(&(user->phoneNum));
    CreateWord(&(user->bio));
    CreateWord(&(user->weton));
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 10; j += 2){
            user->profilePic[i][j] = 'R';
        }
        for (int j = 1; j < 10; j += 2){
            user->profilePic[i][j] = '*';
        }
    }
}

void readPhoneNum(User * user){
    printf("Masukkan No HP: \n");
    Word num = readWord();
    printf("\n");
    while (!isAllNum(num)){
        printf("No HP tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan No HP: \n");
        num = readWord();
        printf("\n");
    }
    user->phoneNum = num;
}

void readBio(User * user){
    printf("Masukkan Bio Akun: \n");
    Word bio = readWord();
    printf("\n");
    user->bio = bio;
}

void ConstructWeton(){
    for (int i = 0; i < 5; i++){
        CreateWord(&wetons[i]);
    }
    // Weton pertama
    wetons[0].Length = 6;
    char pahing[] = "Pahing";
    for (int i = 0; i < 6; i++){
        wetons[0].TabWord[i] = pahing[i];
    }

    // Weton kedua
    wetons[1].Length = 6;
    char kliwon[] = "Kliwon";
    for (int i = 0; i < 6; i++){
        wetons[1].TabWord[i] = kliwon[i];
    }

    // Weton ketiga
    wetons[2].Length = 4;
    char wage[] = "Wage";
    for (int i = 0; i < 4; i++){
        wetons[2].TabWord[i] = wage[i];
    }

    // Weton keempat
    wetons[3].Length = 3;
    char pon[] = "Pon";
    for (int i = 0; i < 3; i++){
        wetons[3].TabWord[i] = pon[i];
    }

    // Weton kelima
    wetons[4].Length = 4;
    char legi[] = "Legi";
    for (int i = 0; i < 4; i++){
        wetons[4].TabWord[i] = legi[i];
    }
}

void readWeton(User * user){
    ConstructWeton();
    boolean still = true;
    printf("Masukkan Weton: \n");
    Word weton = readWord();
    printf("\n");
    for (int i = 0; i < 5; i++){
        if (isCharEqual(weton, wetons[i])){
            user->weton = wetons[i];
            still = false;
            break;
        }
    }
    while (still){
        printf("Weton anda tidak valid.\n\n");
        weton = readWord();
        printf("\n");
        for (int i = 0; i < 5; i++){
            if (isCharEqual(weton, wetons[i])){
                user->weton = wetons[i];
                still = false;
                break;
            }
        }
    }
}

void switchAccType(User * user){
    Word ans;
    if (user->accType){
        printf("Saat ini, akun Anda adalah akun Publik.\n");
        printf("Ingin mengubah ke Akun Privat?\n");
    }
    else{
        printf("Saat ini, akun Anda adalah akun Privat.\n");
        printf("Ingin mengubah ke Akun Publik?\n");
    }
    printf("(YA/TIDAK)  ");
    ans = readWord();
    if (ans.Length == 2) user->accType = !user->accType;
}

boolean isAllNum(Word w){
    for (int i = 0; i < w.Length; i++){
        if (w.TabWord[i] - '0' < 0 || w.TabWord[i] - '0' > 9) return false;
    }
    return true;
}

void changeProfilePicture(User * user){
    return;
}