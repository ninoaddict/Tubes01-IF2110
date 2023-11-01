# include "../user.h"
# include "../listuser.h"

int main(){
    ListUser listuser;
    int currIdx = -1;
    CreateListUser(&listuser);
    SignUp(&listuser, &currIdx);
    for (int i = 0; i < listuser.Neff; i++){
        showProfile(listuser.listU[i]);
    }
    printf("%d\n", listuser.Neff);
    changeProfilePicture(&listuser.listU[0]);
    showProfilePicture(listuser.listU[0]);
    return 0;
}