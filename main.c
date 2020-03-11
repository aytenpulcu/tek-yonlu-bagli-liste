#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Tek yonlu dogrusal bagli liste 
typedef struct liste
{
    int numara;
    struct liste *sonraki;
} blist;

blist *ilk=NULL,*gecici;

blist *bilgi_al(int num)
{
    blist *bilgi=(blist*)malloc(sizeof(blist));
    bilgi->numara=num;
    return bilgi;
}

void ekle(blist *bilgi)
{
    if (ilk==NULL)
    {
        ilk=bilgi;
        ilk->sonraki=NULL;
    }
    else
    {
        gecici=ilk;
        while(gecici->sonraki!=NULL)
            gecici=gecici->sonraki;
        gecici->sonraki=bilgi;
        bilgi->sonraki=NULL;
    }
}

void sirala()
{
    blist *kontrol;
    int a;
    for(gecici=ilk; gecici!=NULL; gecici=gecici->sonraki)
    {
        for(kontrol=gecici->sonraki; kontrol!=NULL; kontrol=kontrol->sonraki)
        {
            if(kontrol->numara < gecici->numara)
            {
                a = gecici->numara;
                gecici->numara = kontrol->numara;
                kontrol->numara = a;
            }
        }
    }
}

int listele()
{
    gecici=ilk;
    if(gecici==NULL)
        return 0;
    while(gecici)
    {
        printf("%d,",gecici->numara);
        gecici=gecici->sonraki;
    }
    return 1;
}
blist *ara(int num)
{
    gecici=ilk;
    while(gecici)
    {
        if(gecici->numara==num)
            return gecici;
        gecici=gecici->sonraki;
    }
    return NULL;
}

void silme(int silnum)
{
    blist *bironceki;
    gecici=ilk;
    bironceki=NULL;
    while(gecici)//silinecek kayiti bul
    {
        if(gecici->numara==silnum)
            break;
        bironceki=gecici;
        gecici=gecici->sonraki;
    }
    if(gecici!=NULL)//silinecek kayit bulundumu
    {
        if(bironceki==NULL)//silinecek kayit ilk eleman ise
        {
            ilk==NULL;
            ilk=ilk->sonraki;

        }
        else
        {
            bironceki->sonraki=gecici->sonraki;
        }
        free(gecici);
        printf("kayit silindi");
        getch();
    }
    else
        printf("kayit silinemedi");
    getch();
}

void main()
{
    blist *bilgi ,*bul;
    char secim;
    int numara;
    while(1==1)
    {
        system("cls");
        puts("Ekle[e]\nListele[l]\nAra[a]\nSil[s]\nSirala[t]\nCikis[c]\nSecim?:");
        secim=getchar();

        switch(secim)
        {
        case'e':
            puts("elemani girin:");
            scanf("%d",&numara);
            bilgi=bilgi_al(numara);
            ekle(bilgi);
            break;
        case'l':
            if(listele()==0)
            {
                printf("kayit yok");
                getch();
            }
            else
            {
                printf("kayit bu kadar");
                getch();
            }
            break;

        case'a':
            printf("aranacak elemani girin:");
            scanf("%d",&numara);
            if(ara(numara)==NULL)
            {

                printf("Boyle bir kayit yok");
                getch();
            }
            else
                printf("kayit bulunudu");
            getch();
            break;
        case's':
            printf("silmek istediginiz kayit:");
            scanf("%d",&numara);
            silme(numara);
            break;
        case't':
            sirala();
            printf("kayitlar kucukten buyuge siralandi!");
            getch();
            break;
        case'c':
            exit(0);
        }
    }

}
