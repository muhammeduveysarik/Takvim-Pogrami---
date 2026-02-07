

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>  
#include <stdlib.h> 

int main() {

    system(" ");

    char secim;
    int yataycerceve;
    int dikeycerceve = 15;
    int yil;
    int hata;

    
    while (1) {

        int menuden_cikis = 0;

        
        while (1) {
            system("CLS");      
            system("Color 07"); 

            yataycerceve = 50;
            printf("\n\n\n\n\t\t\t");

           
            printf("%c", 201);
            for (int i = 0; i < yataycerceve; i++)
                printf("%c", 205);
            printf("%c", 187);
            printf("\n\t\t\t");


            for (int p = 0; p < dikeycerceve; p++) {
                printf("%c", 186); 
                int j = 0;
                do {
                   
                    if (p == 4 && j == 17) {
                        printf("TAKVIM PROGRAMI");
                        yataycerceve = yataycerceve - 14; 
                    }
                    else if (p == 9 && j == 5) {
                        printf("Devam etmek icin D veya d tusuna basiniz");
                        yataycerceve = yataycerceve - 39;
                    }
                    else if (p == 10 && j == 10) {
                        printf("CIKIS icin ESC tusuna basiniz");
                        yataycerceve = yataycerceve - 28;
                    }
                    else {
                        printf(" ");
                    }
                    j++;
                } while (j < yataycerceve);

                yataycerceve = 50; 
                printf("%c", 186); 
                printf("\n\t\t\t");
            }

            
            printf("%c", 200); 
            for (int i = 0; i < yataycerceve; i++)
            printf("%c", 205);
            printf("%c", 188); 
            printf("\n\n");

            
            secim = _getch(); 

            if (secim == 27) { 
                system("CLS");
                printf("Cikmak istediginizden emin misiniz? (E/H)");
                char cikisSecim = _getch();
                if (cikisSecim == 'E' || cikisSecim == 'e') return 0; 
            }
            else if (secim == 'd' || secim == 'D') {
                menuden_cikis = 1; 
                break;
            }
        }

        if (menuden_cikis == 0) continue; 

       
        hata = 0;
        do {
            system("CLS");
            printf("\n\n\n\n");
            printf("\t\t\t\t     TAKVIM PROGRAMI\n");
            printf("\t\t\t----------------------------------------\n\n");

            if (hata == 1) {
                printf("\t\t    Lutfen 1910-2090 arasi bir yil giriniz!\n\n");
            }

            printf("\t\t\t   Takvim yilini giriniz\n");
            printf("\t\t\t\t   ");

            
            if (scanf("%d", &yil) != 1) {
                while (getchar() != '\n');
                hata = 1;
                continue;
            }

           
            if (yil >= 1910 && yil <= 2090) {
                break; 
            }
            else {
                hata = 1;
            }
        } while (1);



        int aylar[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        char ay_isimleri[12][10] = {
            "OCAK", "SUBAT", "MART", "NISAN", "MAYIS", "HAZIRAN",
            "TEMMUZ", "AGUSTOS", "EYLUL", "EKIM", "KASIM", "ARALIK"
        };

        
        if ((yil % 4 == 0 && yil % 100 != 0) || (yil % 400 == 0)) {
            aylar[1] = 29;
        }

        system("CLS");
        printf("\n\t\t\t%d YILI TAKVIMI\n", yil);
        printf("   |------------------------------------------------------|\n");


      
        for (int i = 0; i < 12; i++) {

           
            int z_yil = yil;
            int z_ay = i + 1;
            int z_gun = 1;


            if (z_ay < 3) {
                z_ay += 12;
                z_yil -= 1;
            }

            int q = z_gun;
            int m = z_ay;
            int k = z_yil % 100;
            int j = z_yil / 100;

            
            int h = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

            
            int bosluk_sayisi = (h + 5) % 7;


            printf("\n\t\t\t  %s\n", ay_isimleri[i]);

            
            printf("\n     Pzt     Sal     Car     Per     Cum\033[31m     Cmt     Paz\033[0m\n");

           
            for (int b = 0; b < bosluk_sayisi; b++) {
                printf("        ");
            }

            int sayac = bosluk_sayisi;

           
            for (int gun = 1; gun <= aylar[i]; gun++) {

                
                if (sayac == 5 || sayac == 6) {
                    printf("\033[31m%8d\033[0m", gun);
                }
                else {
                    printf("%8d", gun); 
                }

                sayac++;

               
                if (sayac % 7 == 0) {
                    printf("\n");
                    sayac = 0;
                }
            }

            printf("\n  |-------------------------------------------------------|\n");
        }

        
        printf("\nTekrar denemek icin bir tusa basiniz\n");
        printf("Cikmak icin ESC tusuna basiniz");

        char son_secim = _getch();
        if (son_secim == 27) { 
            system("CLS");
            printf("Cikmak istediginizden emin misiniz? (E/H)");
            char cikisSecim = _getch();
            if (cikisSecim == 'E' || cikisSecim == 'e') {
                return 0;
            }
        }
    }
    return 0;
}
