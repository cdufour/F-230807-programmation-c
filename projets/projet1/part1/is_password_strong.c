#include <stdio.h>
#include <string.h>

int is_password_strong(char * psw){
    int chiffre=0,maj=0,caracSpe=0,i=0;
    if(strlen(psw)>=10){
        while(i<=strlen(psw)){
            if(chiffre>0 && (maj>0 && caracSpe>0)){
                return 1;
            }
            if(chiffre==0 && (psw[i]>='0' && psw[i]<='9')){
                chiffre++;
            }else if(maj==0 && (psw[i]>='A' && psw[i]<='Z')){
                maj++;
            }else if(caracSpe==0 && !(psw[i]>='a' && psw[i]<='z')) {
                caracSpe++;
            }
            i++;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    //char s[] = "ZpI?7)pOVx;y"; 
    //char s[] = "abc";
    printf("%s\n", (is_password_strong(argv[1])) ? "Password strong" : "Password not strong");
}