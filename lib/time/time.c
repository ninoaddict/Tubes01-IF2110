#include <stdio.h>
#include "time.h"
#include "../boolean.h"

boolean IsTIMEValid(int H, int M, int S)
{
    /* Mengirim true jika H,M,S dapat membentuk T yang valid */
    return (((H >= 0) && (H <= 23)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <= 59)));
}

void CreateTime(TIME *T, int HH, int MM, int SS)
{
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME(TIME *T)
{
    /* I.S. : T tidak terdefinisi */
    /* F.S. : T terdefinisi dan merupakan jam yang valid */
    int HH, MM, SS;
    do
    {
        scanf("%d %d %d", &HH, &MM, &SS);
        if (!IsTIMEValid(HH, MM, SS))
        {
            printf("Jam tidak valid\n");
        }
    } while (!IsTIMEValid(HH, MM, SS));
    CreateTime(T, HH, MM, SS);
}

void TulisTIME(TIME T)
{
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format HH:MM:SS */
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik(TIME T)
{
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
    long detik;
    detik = Hour(T) * 3600 + Minute(T) * 60 + Second(T);
    return detik % 86400;
}

TIME DetikToTIME(long N)
{
    /* Mengirim  konversi detik ke TIME */
    TIME T;
    long detik;
    detik = (N + 86400) % 86400;
    Hour(T) = detik / 3600;
    Minute(T) = (detik - 3600 * Hour(T)) / 60;
    ;
    Second(T) = detik % 60;
    return T;
}

boolean TEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1=T2, false jika tidak */
    return (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2));
}
boolean TNEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    return (!TEQ(T1, T2)); // Debug using TEQ function
}

boolean TLT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1<T2, false jika tidak */
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}
boolean TGT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1>T2, false jika tidak */
    return (TIMEToDetik(T1) > TIMEToDetik(T2)); // Debug using TLT function
}

TIME NextDetik(TIME T)
{
    /* Mengirim 1 detik setelah T dalam bentuk TIME */
    long detik;
    detik = TIMEToDetik(T) + 1;
    return DetikToTIME(detik); // Debug, membuat kode lebih mudah dibaca
}

TIME NextNDetik(TIME T, int N)
{
    /* Mengirim N detik setelah T dalam bentuk TIME */
    long detik;
    detik = TIMEToDetik(T) + N;
    return DetikToTIME(detik); // Debug, membuat kode lebih mudah dibaca
}

TIME PrevDetik(TIME T)
{
    /* Mengirim 1 detik sebelum T dalam bentuk TIME */
    long detik;
    detik = TIMEToDetik(T) - 1;
    if (detik < 0)
    {
        detik = 86400 + detik;
    }
    return DetikToTIME(detik);
}
TIME PrevNDetik(TIME T, int N)
{
    /* Mengirim N detik sebelum T dalam bentuk TIME */
    long detik;
    detik = TIMEToDetik(T) - N;
    if (detik < 0)
    {
        detik = 86400 + detik;
    }
    return DetikToTIME(detik);
}

long Durasi(TIME TAw, TIME TAkh)
{
    /* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
    /* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

    long detik;
    detik = TIMEToDetik(TAkh) - TIMEToDetik(TAw);
    if (detik < 0)
    {
        detik = (long)86400 + detik;
    }
    return detik;
}
