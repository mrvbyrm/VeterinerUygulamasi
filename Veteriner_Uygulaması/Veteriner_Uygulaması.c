#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void randevuAl(char tur[], char ad[]);

int kedininInsanYasiniHesapla(int kediYasi) {			//Fonksiyon iþlendi
    int insanYasi;

    if (kediYasi <= 2) 
	{
        insanYasi = kediYasi * 4;
    } 
	else 
	{
        insanYasi = 2 * 4 + (kediYasi - 2) * 3;
    }
    return insanYasi;
}
int kontrolZamaniGecmisMi(char tur[], int sonKontrolAy, int sonKontrolYil, char ad[]) {
    time_t simdikiZaman;
    struct tm *simdikiZamanYapisi;
    time(&simdikiZaman);
    simdikiZamanYapisi = localtime(&simdikiZaman);
    int simdikiAy = simdikiZamanYapisi->tm_mon + 1;  // tm_mon 0-11 arasýnda deðer döndürür, bu nedenle 1 ekleyerek gerçek ay elde edilir
    int simdikiYil = simdikiZamanYapisi->tm_year + 1900;  // tm_year 1900'den baþlar

    int gecenSureAy = (simdikiYil - sonKontrolYil) * 12 + simdikiAy - sonKontrolAy;

    // Kontrol süresi 6 ayda bir olduðu için, 6 aydan fazla süre geçmiþse true döndür
    if (gecenSureAy >= 6) 
	{
        printf("Son kontrol tarihinden bu yana %d ay gecmis. Kontrol zamani gelmis!\n", gecenSureAy);
}
	else 
	{
        printf("Son kontrol tarihinden bu yana %d ay gecmis. Kontrol zamani gelmemis.\n", gecenSureAy);
        return 0;
    }
}

void randevuAl(char tur[], char ad[]) {		//Fonksiyon iþlendi
    char cinsiyet;
    char asi[20];
    float kilo;
    int dogumYili;
    int islem;
    char tarih[20];
    int h_sayisi,i;
	int asi_sayisi,j;

    printf("\n--- Randevu Al ---\n");
    printf("1. Asi icin randevu al\n");
    printf("2. Muayene icin randevu al\n");
    printf("0. Cikis icin\n");
    printf("Isleminizi Secin: ");
    scanf("%d", &islem);
    printf("Hayvan Sayisini girin : ");
    scanf("%d", &h_sayisi);

    if (islem == 1&& strcmp(tur, "kedi") == 0) 
	{
		char asi_turleri[][20] = {"Karma", "Ic Parazit", "Dis Parazit","Losemi Asisi"};		//karakter dizisi yapýsý iþlendi
        printf("Yapilacak asi sayisini girin : ");
        scanf("%d", &asi_sayisi);

        for (i = 1; i <= h_sayisi; i++) 
		{
			printf("%d.Hayvanin adini girin: ", i);
        	scanf("%s", ad);

            printf("%d.Hayvanin cinsiyetini girin (E: Erkek, D: Disi): ", i);
            scanf(" %c", &cinsiyet);

            printf("%d.Hayvanin kilosunu girin: ", i);
            scanf("%f", &kilo);

            printf("%d.Hayvanin dogum yilini girin: ", i);
            scanf("%d", &dogumYili);

            for (j = 1; j <= asi_sayisi; j++)   //iç içe döngü yapýsý iþlendi
			{
                printf("Asi Turleri: 'Karma','Ic Parazit','Dis Parazit','Losemi Asisi'\n");
                printf("%d. Asi Turunu Girin: ", j);
                scanf("%19s", asi_turleri[j - 1]); 
                printf("%d.Asi yapilacak tarihi girin (gg/aa/yy): ",j);
                scanf("%19s", tarih);

                printf("%d.Hayvanin Ad : %s - Cinsiyeti : %c - Kilosu : %.2f - Dogum Yili : %d - %d.Asi Turu : %s - %d.Asi Tarihi : %s\n", i, ad,cinsiyet, kilo, dogumYili, j,  asi_turleri[j - 1],j, tarih);
            }
        }
        printf("Basariyla kedi asi randevusu alinmistir.\n");
    }

	else if (islem == 1 && strcmp(tur, "kopek") == 0) 
	{
		char asi_turleri[][60]={"Karma","Parvovirus","Ic Parazit","Dis Parazit","Bronchine Asi","Puppy DP Asisi","Lyme Asisi"};  		//karakter dizisi yapýsý iþlendi
		
		printf("Yapilacak asi sayisini girin : ");
        scanf("%d", &asi_sayisi);

        for (i = 1; i <= h_sayisi; i++) 
		{
        	printf("%d.Hayvanin adini girin: ", i);
        	scanf("%s", ad);

            printf("%d.Hayvanin cinsiyetini girin (E: Erkek, D: Disi): ", i);
            scanf(" %c", &cinsiyet);

            printf("%d.Hayvanin kilosunu girin: ", i);
            scanf("%f", &kilo);

            printf("%d.Hayvanin dogum yilini girin: ", i);
            scanf("%d", &dogumYili);
}
            for (j = 1; j <= asi_sayisi; j++) //iç içe döngü yapýsý iþlendi
			{
                printf("Asi Turleri: 'Karma','Parvovirus','Ic Parazit','Dis Parazit,'Bronchine Asi','Puppy DP Asisi','Lyme Asisi'\n");
                printf("%d. Asi Turunu Girin: ", j);
                scanf("%19s", asi_turleri[j-1]);
                printf("%d.Asi yapilacak tarihi girin (gg/aa/yy): ",j);
                scanf("%19s", tarih);
                printf("%d.Hayvanin Ad : %s - Cinsiyeti : %c - Kilosu : %.2f - Dogum Yili : %d - %d.Asi Turu : %s - %d.Asi Tarihi : %s\n", i,ad , cinsiyet, kilo, dogumYili, j, asi_turleri[j-1],j, tarih);
            }
        printf("Basariyla kopek asi randevusu alinmistir.\n");
}

	else if (islem == 2 && strcmp(tur, "kedi") == 0) 
	{
        printf("Muayene yapilacak tarihi girin (gg/aa/yy): ");
        scanf("%s", tarih);

        printf("Basariyla kedi muayene randevusu alinmistir.\n");
        printf("Bilgileriniz: %s %c %f %d\n", tarih, cinsiyet, kilo, dogumYili);
    } 
	else if (islem == 2 && strcmp(tur, "kopek") == 0) 
	{
        printf("Muayene yapilacak tarihi girin (gg/aa/yy): ");
        scanf("%s", tarih);
        printf("Basariyla kopek muayene randevusu alinmistir.\n");
        printf("Bilgileriniz: %s %c %f %d\n", tarih, cinsiyet, kilo, dogumYili);
    } 
	else if (islem == 0) 
	{
        printf("Bir ust menuye yonlendiriliyorsunuz.\n");
    } 
	else 
	{
        printf("Hatali giris yaptiniz.\n");
    }
}
void randevuAlKus(char turu[], char adi[]) {
    char cinsiyet;
    int dogumYili;
    int islem;
    char tarih[20];

    printf("1. Muayene icin randevu al\n");
    printf("0. Cikis icin\n");

    printf("Isleminizi Secin: ");
    scanf("%d", &islem);

    if (islem == 1 && strcmp(turu, "kus") == 0) {
        printf("Kusunuzun adi : ");
        scanf("%s", adi);
        printf("Kusunuzun cinsiyedi (D=disi E=erkek) : ");
        scanf(" %c", &cinsiyet);
        printf("Kusunuzun dogum yili : ");
        scanf("%d", &dogumYili);
        printf("Muayene yapilacak tarihi girin (gg/aa/yy): ");
        scanf("%s", tarih);
        printf("Basariyla kus muayene randevusu alinmistir.\n");
        printf("Bilgileriniz: %s %c %d %s\n", adi, cinsiyet, dogumYili, tarih);
    } else if (islem == 0) {
        printf("Bir ust menuye yonlendiriliyorsunuz.\n");
    } else {
        printf("Hatali giris yaptiniz.\n");
    }
}

void kayit(char ad[], int cipNumarasi) {    //Fonksiyon iþlendi
    char cinsiyet;
    float kilo;
    int yas, ay;

    printf("Lutfen hayvaninizin yasini girin: ");
    scanf("%d", &yas);
    
    if (yas < 1) 
	{
        printf("Lutfen hayvaninizin ayini girin: ");
        scanf("%d", &ay);

        if (ay < 2) 
		{
            printf("Kayit yapilamadi. Lutfen hayvaninizin 2.ayindan sonra kayit yaptirin.\n");
            return;
        }
    }
    printf("Hayvaninizin adini girin: ");
    scanf("%s", ad);
    printf("Hayvaninizin cip numarasini girin: ");
    scanf("%d", &cipNumarasi);
    printf("Hayvaninizin cinsiyetini girin (Erkek: E Disi: D): ");
    scanf(" %c", &cinsiyet);
    printf("Hayvaninizin kilosunu girin: ");
    scanf("%f", &kilo);

    printf("Hayvaninizin Bilgileri\n");
    printf("Hayvaninizin Ad: %s - Cip Numarasi: %d - Cinsiyet: %c - Kilo: %.2f\n", ad, cipNumarasi, cinsiyet, kilo);
    printf("Kaydiniz basariyla tamamlanmistir.\n");
}

void rastgeleKediAdiBelirle(char ad[], char cinsiyet) {		//Fonksiyon iþlendi
    const char erkekAdlar[][10] = {"Duman", "Sakiz", "Gece", "Alaca","Papyon","Cakil","Pati"};	//karakter dizisi iþlendi
    const char disiAdlar[][10] = {"Luna", "Bella", "Yumak", "Mia", "Maya","Lila","Ipek","Yildiz"};  //karakter dizisi iþlendi

    const char (*adlar)[10];
    int adlarSayisi;

    if (cinsiyet == 'E') 
	{
        adlar = erkekAdlar;
        adlarSayisi = sizeof(erkekAdlar) / sizeof(erkekAdlar[0]);
    } 
	else 
	{
        adlar = disiAdlar;
        adlarSayisi = sizeof(disiAdlar) / sizeof(disiAdlar[0]);
    }
    int rastgeleIndex = rand() % adlarSayisi;
    snprintf(ad, 50, "%s", adlar[rastgeleIndex]);
}

void rastgeleKopekAdiBelirle(char ad[], char cinsiyet) {				//Fonksiyon iþlendi
    const char erkekAdlar[][10] = {"Buddy", "Badem","Max", "Sansli","Haydut","Kaptan","Lokum","Dobby"};		//karakter dizisi iþlendi
    const char disiAdlar[][10] = {"Daisy", "Lucy", "Poncik","Maya","Mutlu","Ada","Mavi","Venus","Luna"};		//karakter dizisi iþlendi

    const char (*adlar)[10];
    int adlarSayisi;

    if (cinsiyet == 'E') 
	{
        adlar = erkekAdlar;
        adlarSayisi = sizeof(erkekAdlar) / sizeof(erkekAdlar[0]);
    } 
	else 
	{
        adlar = disiAdlar;
        adlarSayisi = sizeof(disiAdlar) / sizeof(disiAdlar[0]);
    }
    int rastgeleIndex = rand() % adlarSayisi;
    snprintf(ad, 50, "%s", adlar[rastgeleIndex]);
}
void rastgeleKusAdiBelirle(char ad[]) 
{
    const char adlar[][10] = {"Cico", "Prens", "Mango", "Zeytin", "Þeker", "Cici", "Þahin", "Limon"};
    int adlarSayisi = sizeof(adlar) / sizeof(adlar[0]);
    int rastgeleIndex = rand() % adlarSayisi;
    snprintf(ad, 50, "%s", adlar[rastgeleIndex]);
}

void kediDiyetVeEgzersizOnerileri(char cinsiyet, float kilo, int dogumYili) 
{
    float bmi = kilo / ((float)(2023 - dogumYili) * (2023 - dogumYili));

    printf("\n--- Kedi Diyet ve Egzersiz Onerileri ---\n");
    if (bmi < 18.5) 
	{
        printf("BMI : %.2f - Kediniz zayif. Daha fazla kalori iceren bir diyet dusunebilirsiniz.\n",bmi);
        printf("Egzersiz onerisi: Oyuncagi ile oynatin.\n");
    } 
	else if (bmi >= 18.5 && bmi < 24.9) 
	{
        printf("BMI : %.2f - Kedinizin kilosu normal. Saglikli bir diyet ve duzenli egzersizle devam edebilirsiniz.\n",bmi);
        printf("Egzersiz onerisi: Gunluk oyun surelerini arttirin.\n");
    }
	else 
	{
        printf("BMI : %.2f - Kediniz obez. Dusuk kalorili bir diyet ve daha fazla egzersiz onerilir.\n",bmi);
        printf("Egzersiz onerisi: Yavasca baslayarak kedinizi daha fazla hareket ettirin.\n");
    }
}

void kopekDiyetVeEgzersizOnerileri(char cinsiyet, float kilo, int dogumYili) {
    float bmi = kilo / ((float)(2023 - dogumYili) * (2023 - dogumYili));

    printf("\n--- Köpek Diyet ve Egzersiz Onerileri ---\n");
    if (bmi < 18.5) 
	{
        printf("BMI : %.2f - Kopeginiz zayif. Daha fazla kalori iceren bir diyet dusunebilirsiniz.\n",bmi);
        printf("Egzersiz onerisi: Yuruyuslere cikarin.\n");
    } 
	else if (bmi >= 18.5 && bmi < 24.9) 
	{
        printf("BMI : %.2f - Kopeginizin kilosu normal. Saglikli bir diyet ve duzenli egzersizle devam edebilirsiniz.\n",bmi);
        printf("Egzersiz onerisi: Oyun oynayarak egzersiz yapin.\n");
    } 
	else 
	{
        printf("BMI : %.2f - Kopeginiz obez. Dusuk kalorili bir diyet ve daha fazla egzersiz onerilir.\n",bmi);
        printf("Egzersiz onerisi: Hafif tempolu kosulara baslayin.\n");
    }
}
void semptomlar() {
    printf("Semptomlar:\n");
    printf("1. Kusma:\n");
    printf("2. Halsizlik:\n");
    printf("3. Hapsirma:\n");
    printf("4. Oksurme:\n");
    
    int semptomSecimi;
    printf("Lutfen semptom numarasini girin (1-4): ");
    scanf("%d", &semptomSecimi);

    switch (semptomSecimi) {		//switch case yapýsý iþlendi
        case 1:
            printf("Kusma semptomu secildi. \nBu semptomlarin nedeni :\n");
            printf("   - Sindirim sorunlari\n");
            printf("   - Zehirlenme\n");
            printf("   - Bagirsak tikanikligi\n");
            printf("Lutfen veterinerinize basvurun.\n");
            break;						//break yapýsý iþlendi
        case 2:
            printf("Halsizlik semptomu secildi. Bu semptomlarin nedeni :\n");
            printf("   - Enfeksiyon\n");
            printf("   - Anemi (kansizlik)\n");
            printf("   - Organ problemleri\n");
            printf("Lutfen veterinerinize basvurun.\n");
            break;						//break yapýsý iþlendi
        case 3:
            printf("Hapsirma semptomu secildi. Bu semptomlarin nedeni :\n");
            printf("   - Ust solunum yolu enfeksiyonu\n");
            printf("   - Alerjiler\n");
            printf("   - Yabanci cisimlerin solunum yolu\n");
            printf("Lutfen veterinerinize basvurun.\n");
            break;
        case 4:
            printf("Oksurme semptomu secildi. Bu semptomlarin nedeni :\n");
            printf("   - Alt solunum yolu enfeksiyonu\n");
            printf("   - Kalp problemleri\n");
            printf("   - Astim\n");
            printf("Lutfen veterinerinize basvurun.\n");
            break;
        default:
            printf("Gecersiz semptom numarasi!\n");
            break;
    }
}
int main() {

    srand(time(NULL));

    char ad[50];
    char cinsiyet;
    float kilo;
    int dogumYili;
    int secim = -1;
    int scm;
    char tur[10];
    int cipNumarasi;
    

    while (secim != 0) {
        printf("\n--------------------------------------------------------------------------------------------------\n");
        printf("--- VETERINER UYGULAMASI ---\n");
        printf(" 1. Kedi Islemleri Menusu\n");
        printf(" 2. Kopek Islemleri Menusu\n");
        printf(" 3. Kus Islemleri Menusu\n");
        printf(" 0. Cikis\n");
        printf("\n--------------------------------------------------------------------------------------------------\n");
        printf("Seciminiz (0-2): ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
            	printf("\n--------------------------------------------------------------------------------------------------\n");
                printf("\n--- KEDI ISLEMLERI MENUSU ---\n");
                printf("1. Kedi Adi Sec\n");
                printf("2. Kedinizin Insan Yasini Hesapla\n");
                printf("3. Kedinizin Kilo Indeksini Hesapla\n");
                printf("4. Randevu Al\n");
                printf("5. Sisteme Kayit\n");
                printf("6. Semptomlar\n");
                printf("7. Kontrol Zamani Belirleme\n");
                printf("0. Cikis\n");
                printf("\n--------------------------------------------------------------------------------------------------\n");
                printf("Yapmak istediginiz islem: ");
                scanf("%d", &scm);
                if (scm == 1) 
				{
					printf("Seciminiz : 1.Kedi Adi Sec\n");
                    printf("Cinsiyet (E: Erkek, D: Disi): ");
                    scanf(" %c", &cinsiyet);
                    rastgeleKediAdiBelirle(ad, cinsiyet);
                    printf("Kedinizin adi rastgele belirlendi: %s\n", ad);
                } 
				else if (scm == 2) 
				{
					printf("Seciminiz : 2. Kedinizin Insan Yasini Hesapla\n");
                    int kediYasi;
                    printf("Kedinin yasini girin: ");
                    scanf("%d", &kediYasi);
                    int insanYasi = kedininInsanYasiniHesapla(kediYasi);
                    printf("Kedinin insan yasi: %d\n", insanYasi);
                } 
				else if (scm == 3) 
				{
					printf("Secim1iniz : 3. Kedinizin Kilo Indeksini Hesapla\n");
                    printf("Kilo: ");
                    scanf("%f", &kilo);
                    printf("Dogum Yili: ");
                    scanf("%d", &dogumYili);
                    kediDiyetVeEgzersizOnerileri(cinsiyet, kilo, dogumYili);
                }
				else if (scm == 4) 
				{
					printf("Seciminiz : 4. Randevu Al\n");
                    randevuAl("kedi", ad);
                } 
                else if (scm == 5) 
				{
                	printf("Seciminiz : 5. Sisteme Kayit\n");
                    kayit(ad,cipNumarasi);
                } 
                else if (scm == 6) 
				{
                	printf("Seciminiz : 6. Semptomlar\n");
                    semptomlar();
                } 
                else if(scm==7) 
                {
                	int sonKontrolAy, sonKontrolYil;
	                char ad[50];
	                char tur[10];
	                printf("Son kontrol tarihinin ayini girin (1-12): ");
	                scanf("%d", &sonKontrolAy);
	                printf("Son kontrol tarihinin yilini girin: ");
	                scanf("%d", &sonKontrolYil);
	                kontrolZamaniGecmisMi(tur, sonKontrolAy, sonKontrolYil, ad);
					}	
				else if (scm == 0) 
				{
                    printf("Bir ust menuye yonlendiriliyorsunuz.\n");
                } 
				else 
				{
                    printf("Hatali giris yaptiniz.\n");
                }
                break;
            case 2:
                printf("\n--------------------------------------------------------------------------------------------------\n");
                printf("\n--- KOPEK ISLEMLERI MENUSU ---\n");
                printf("1. Kopek Adi Sec\n");
                printf("2. Kopeginizin Insan Yasini Hesapla\n");
                printf("3. Kopeginizin Kilo Indeksini Hesapla\n");
                printf("4. Randevu Al\n");
                printf("5. Sisteme Kayit\n");
                printf("6. Semptomlar\n");
                printf("7. Kontrol Zamani Belirleme\n");
                printf("0. Cikis\n");
                printf("\n--------------------------------------------------------------------------------------------------\n");
                printf("Yapmak istediginiz islem: ");
                scanf("%d", &scm);
                if (scm == 1) 
				{
					printf("Seciminiz : 1. Kopek Adi Sec\n");
                    printf("Cinsiyet (E: Erkek, D: Disi): ");
                    scanf(" %c", &cinsiyet);
                    rastgeleKopekAdiBelirle(ad, cinsiyet);
                    printf("Kopeginizin adi rastgele belirlendi: %s\n", ad);
                } 
				else if (scm == 2) 
				{
					printf("Seciminiz : 2. Kopeginizin Insan Yasini Hesapla\n");
                    int kopekYasi;
                    printf("Kopeginizin yasini girin: ");
                    scanf("%d", &kopekYasi);
                    int insanYasi = kedininInsanYasiniHesapla(kopekYasi);
                    printf("Kopeginizin insan yasi: %d\n", insanYasi);
                } 
				else if (scm == 3) 
				{
					printf("Seciminiz : 3. Kopeginizin Kilo Indeksini Hesapla\n");
                    printf("Kilo: ");
                    scanf("%f", &kilo);
                    printf("Dogum Yili: ");
                    scanf("%d", &dogumYili);
                    kopekDiyetVeEgzersizOnerileri(cinsiyet, kilo, dogumYili);
                } 
				else if (scm == 4) 
				{
					printf("Seciminiz : 4. Randevu Al\n");
                    randevuAl("kopek", ad);
                } 
                else if (scm == 5) 
				{
					printf("Seciminiz : 5. Sisteme Kayit\n");
                    kayit(ad,cipNumarasi);
                } 
				else if (scm == 6) 
				{
					printf("Seciminiz : 6. Semptomlar\n");
                    semptomlar();
                }
                else if(scm==7)
                {
                	int sonKontrolAy, sonKontrolYil;
	                char ad[50];
	                char tur[10];
	                char secim;
	                printf("Son kontrol tarihinin ayini girin (1-12): ");
	                scanf("%d", &sonKontrolAy);
	                printf("Son kontrol tarihinin yilini girin: ");
	                scanf("%d", &sonKontrolYil);
	                kontrolZamaniGecmisMi(tur, sonKontrolAy, sonKontrolYil, ad);	 
				}
				else if (scm == 0) 
				{
                    printf("Bir ust menuye yonlendiriliyorsunuz.\n");
                }
				else
				{
                    printf("Hatali giris yaptiniz.\n");
                }
                break;
        
        case 3:
        		printf("\n--------------------------------------------------------------------------------------------------\n");
        		printf("\n--- KUS ISLEMLERI MENUSU ---\n");
                printf("1. Kus Adi Sec\n");
                printf("2. Muayene Randevusu Al\n");
                printf("3. Semptomlar\n");
                printf("4. Kontrol Zamani Belirleme\n");
                printf("0. Cikis\n");
                printf("\n--------------------------------------------------------------------------------------------------\n");
                printf("Yapmak istediginiz islem: ");
                scanf("%d", &scm);
                if(scm==1)
                {
                	rastgeleKusAdiBelirle(ad);
				}
                else if(scm==2)
                {
                	randevuAlKus("kus",ad);
				}
				else if(scm==3)
				{
					semptomlar();
				}
				else if(scm==4)
				{
					int sonKontrolAy, sonKontrolYil;
	                char ad[50];
	                char tur[10];
	                printf("Son kontrol tarihinin ayini girin (1-12): ");
	                scanf("%d", &sonKontrolAy);
	                printf("Son kontrol tarihinin yilini girin: ");
	                scanf("%d", &sonKontrolYil);
	                kontrolZamaniGecmisMi(tur, sonKontrolAy, sonKontrolYil, ad);
				}
				else
				{
					printf("Hatali giris yaptiniz.\n");
				}
			break;
			case 0: break;
		default : 
		printf("Hatali giris yaptiniz."); break;
		}
	}
    printf("Cikis yaptiniz.\n");
    return 0;
}
