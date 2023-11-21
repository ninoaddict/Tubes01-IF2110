#include <stdio.h>
#include "datetime.h"
#include "../time/time.h"
#include "../boolean.h"

int GetMaxDay(int M, int Y){
    boolean leap;
    leap = false;
    if (Y%400 == 0){
        leap = true;
    }
    else if (Y%100 != 0 && Y%4 == 0){
        leap = true;
    }
    if (leap && M == 2){
        return 29;
    }
    else if (!leap && M == 2){
        return 28;
    }

    if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12){
        return 31;
    }
    else{
        return 30;
    }

}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
    return ((D>= 1) && (D <= GetMaxDay(M,Y)) && (IsTIMEValid(h,m,s)) && (M >= 1) && (M <= 12) && (Y > 0));

}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
    TIME t;
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    CreateTime(&t, hh,mm,ss);
    Time(*D) = t;
    
}

void BacaDATETIME(DATETIME *D){
    int hari, bulan, tahun, jam, menit,detik;
    // scanf("%d %d %d %d %d %d",&hari,&bulan, &tahun, &jam,&menit,&detik);

    // while (!IsDATETIMEValid(hari,bulan,tahun,jam,menit,detik)){
    //     printf("DATETIME tidak valid\n");
    //     scanf("%d %d %d %d %d %d",&hari,&bulan, &tahun, &jam,&menit,&detik);
    // }
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    hari = (*ptr).tm_mday;
    bulan = (*ptr).tm_mon;
    
    tahun = (*ptr).tm_year;

    jam = (*ptr).tm_hour;
    detik = (*ptr).tm_sec;
    menit = (*ptr).tm_min;
    CreateDATETIME(D,hari,bulan+1,tahun+1900,jam,menit,detik);

}

void TulisDATETIME(DATETIME D){
    printf("%02d/%02d/%d %02d:%02d:%02d",Day(D),Month(D),Year(D),Hour(Time(D)) , Minute(Time(D)), Second(Time(D)));  

}

boolean DEQ(DATETIME D1, DATETIME D2){
    return ((Day(D1) == Day(D2)) && (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (TEQ(Time(D1),Time(D2))) );
}
boolean DNEQ(DATETIME D1, DATETIME D2){
    return !(DEQ(D1,D2));
}

boolean DLT(DATETIME D1, DATETIME D2){
    if (DNEQ(D1,D2)){
        if (Year(D1) == Year(D2)){
            if (Month(D1) == Month(D2)){
                if (Day(D1) == Day(D2)){
                    return (TLT(Time(D1) , Time(D2)));
                }
                else{
                    return (Day(D1) < Day(D2));
                }

            }
            else{
                return (Month(D1) < Month(D2));
            }
        }
        else{
            return (Year(D1) < Year(D2));
        }

    }
    else{
        return false;
    }
}

boolean DGT(DATETIME D1, DATETIME D2){
    if (DNEQ(D1,D2)){
        return (DLT(D2,D1));

    }
    else{
        return false;
    }
}

DATETIME DATETIMENextNDetik(DATETIME D, int N){
    DATETIME D1;
    int day_temp;
    D1 = D;
    long detik;
    detik = TIMEToDetik(Time(D1)) + N + (Day(D1) - 1) * 86400;
    day_temp = 1;
    while(detik >= 86400){
        day_temp += 1;
        if (day_temp > GetMaxDay(Month(D1),Year(D1))){
            day_temp = 1;
            Month(D1) += 1;
            if (Month(D1) > 12){
                Month(D1) = 1;
                Year(D1) += 1;
            }
        }
        detik -= 86400;

    }
    Day(D1) = day_temp;
    Time(D1) = DetikToTIME(detik);
    return D1;

}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    DATETIME D1;
    D1 = D;
    long detik;
    detik = TIMEToDetik(Time(D1)) - N ;
    if (detik >= 0){
        return DATETIMENextNDetik(D,(-1)*N);
    }
    else{

        while(detik <0){
            Day(D1) -= 1;
            if (Day(D1) == 0){
                Month(D1) -= 1;
                if (Month(D1) == 0){
                    Month(D1) = 12;
                    Year(D1) -=1;
                }
                Day(D1) = GetMaxDay(Month(D1),Year(D1));
            }
            detik += 86400;

        }
        // Month(D1) -= 1;
        // if (Month(D1) == 0){
        //     Month(D1) = 12;
        //     Year(D1) -=1;
        // }
        // Day(D1) = GetMaxDay(Month(D1),Year(D1));
        // detik += 86400;
        Time(D1) = DetikToTIME(detik);
        return D1;

    }

    


}


long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;
    long hari_awal,hari_akhir;
    long detik_awal,detik_akhir;
    hari_akhir = Year(DAkh)*365 + Day(DAkh);
    hari_awal = Year(DAw)*365 + Day(DAw);
    for (i = 0 ; i < Month(DAkh);++i){
        hari_akhir += days[i];
    }
    for (i = 0 ; i < Month(DAw);++i){
        hari_awal += days[i];
    }
    detik_awal = TIMEToDetik(Time(DAw)) + hari_awal*86400;
    detik_akhir = TIMEToDetik(Time(DAkh)) + hari_akhir*86400;
    return detik_akhir - detik_awal;


}

DATETIME string_toDate_time(char arr[]){
    Word store;
    DATETIME t;
    int i = 0,word_count = 0,insert_date=0;
    int date[3];
    int time[3];

    CreateWord(&store);

    while (arr[i] != ' '){
        if (arr[i] == '/'){
            store.Length = word_count;
            word_count = 0;
            date[insert_date] = wordToInteger(store);
            insert_date ++;
            
        }
        else{
            store.TabWord[word_count] = arr[i];
            word_count ++;

        }
        i++;
    }
    store.Length = word_count;
    word_count = 0;
    date[insert_date] = wordToInteger(store);
    insert_date ++;
    i++;
    insert_date = 0;
    word_count = 0;
    while (arr[i] != '\n'){
        if (arr[i] == ':'){
            store.Length = word_count;
            word_count = 0;
            time[insert_date] = wordToInteger(store);
            insert_date ++;
            
        }
        else{
            store.TabWord[word_count] = arr[i];
            word_count ++;

        }
        i++;
    }
    store.Length = word_count;
    word_count = 0;
    time[insert_date] = wordToInteger(store);
    insert_date ++;
    CreateDATETIME(&t,date[0],date[1],date[2],time[0],time[1],time[2]);
    return t;
}

Word dateTimeToWord(DATETIME t){
    Word date;
    int i = 0;
    // int date[] = {t.DD,t.MM,t.YYYY,t.T.HH,t.T.MM,t.T.SS};

    date.TabWord[i] = (t.DD/10) + '0';
    i++;
    date.TabWord[i] = (t.DD%10) + '0';
    i++;
    date.TabWord[i] = '/';
    i++;
    date.TabWord[i] = (t.MM/10) + '0';
    i++;
    date.TabWord[i] = (t.MM%10) + '0';
    i++;
    date.TabWord[i] = '/';
    i++;
    date.TabWord[i] = (t.YYYY /1000) + '0';
    i++;
    date.TabWord[i] = ((t.YYYY % 1000)/100) + '0';
    i++;
    date.TabWord[i] = ((t.YYYY%100)/10) + '0';
    i++;
    date.TabWord[i] = ((t.YYYY%10)) + '0';
    i++;
    date.TabWord[i] = ' ';
    i++;
    date.TabWord[i] = t.T.HH/10 + '0';
    i++;    
    date.TabWord[i] = t.T.HH%10 + '0';
    i++;
    date.TabWord[i] = ':';
    i++;
    date.TabWord[i] = t.T.MM/10 + '0';
    i++;
    date.TabWord[i] = t.T.MM%10 + '0';
    i++;
    date.TabWord[i] = ':';
    i++;
    date.TabWord[i] = t.T.SS/10 + '0';
    i++;
    date.TabWord[i] = t.T.SS%10 + '0';
    i++;
    date.TabWord[i] = '\n';
    i++;
    date.Length = i;
    
    

    date.Length = i;
    return date;
    // 2034

}



