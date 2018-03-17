#include <stdio.h>
#include <stdlib.h>
void room_chooser(char,int);    // Odalari Secmeye Yarayan Fonksiyonun Tanimlanmasi
void book_stats();              // Secilen odalarin istatiklerini % olarak hesaplayan fonksiyonun tanimlanmasi
void book_payment(int,int);     // Odalarin Odeme secimi ve hizmet tutarinin kullaniciya sunuldugu fonksiyonun tanimlanmasi

int char_to_index(char,char);   // Switch-case yapilarinda girilen metinsel ifadelerin dizilerde aktif index olarak kullanimi için harfe  karþilik gelen index numarasina dönüþtüren fonksiyon
int size_of();                  // Odalarin tiplerine göre haftalik index sayilarini diger fonksiyonlarda iliþkili olani kullanmak üzere index degerini atayan Fonksiyon
void room_lister(int,char,char);    // Bos Odalari kullaniciya listeleyen fonksiyonun tanimlanmasi
void room_creater();            //  Her Sezon Her Hafta ve Her tip için ilgili oda numaralarini oluþturan ve diye alan Fonksiyon
int guest_processes(int,int,char);  // Kullanici oda ve misafir sayisi seçim iþlemlerinin yapildigi fonksiyonun tanimlanmasi

int rmRezerved[3][12][3][100],rmChoosen,rmAll[3][12][3][50];    // rmRezerved -> roomRezerved rezerve edilen odalarin tutuldugu dizi, rmChoosen-> anlik secilen oda numarasi, rmAll -> tüm odalarin tutuldugu  dizi
int indRezerved = 0,indRoom = 0,indStd = 0 ,indDelux = 0,indLarge = 0,indSeason = 0,index = 0; // ilgili index numaralarinin tanimlanmasi
int bkWeek,countStats = 0,countTry = 0,cpStd = 0,cpDelux = 0,cpLarge = 0;           //cp -> capasity, rm -> Room, ind-> index, bk-> Book, pay -> payment, pr -> price, st -> stats, nw -> new;
int stWeek[3][12];      // stWeek -> statsWeek yani Haftalik yogunluk istatistiklerinin tutuldugu Dizi
int rezStd = 0 ,rezDelux = 0,rezLarge = 0;   // Oda secim isleminden sonra Rezerve edilen odalarin tiplere göre index sayaçlari
double payStandart = 0,grandTotal = 0;      // payStandart -> standart ödemeler, grandTotal -> Genel Toplam degiþkenleri

    char bkSeason;      // Sezon Tipi
    char bkRoom;        // Oda Tipi
    char payStyle;      // Ödeme Tipi
    char nwBook;        // Yeni Kayit Sorgusu
int main(){
        room_creater();     // Oteldeki bütün odalarimizi yarattik
		printf("Hangi mevsimde tatil yapmak istersiniz?");
		do{
        printf("\nBahar icin 'B', Yaz icin 'Y', Sonbahar icin 'S' tusuna basiniz  :");
		scanf(" %c",&bkSeason);
			switch(bkSeason)
			{
				case 'B':{
				    double prStd=40.00,prLarge=300.00,prDelux=75.00;    // Oda Tiplerinin Dönemsel Hizmet Fiyatlari tanimlanmasi
				    countTry=0;
                   	do{
                        printf("Hotelde kalmak istediginiz hafta(1-12) :");
                        scanf("%d",&bkWeek);
						switch(bkWeek)
						{
							case 1:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);    // Odalarin Listelenmesi
                                                    room_chooser(bkRoom,bkWeek);            // Listelenen odalardan yapilan secim islemi ve kontrolleri
                                                    guest_processes(cpStd,prStd,bkRoom);    // Kullanici islemleri
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);     // Kullanicinin hatalarini yakalamak içiin oluþturulan  countTry -> Deneme Say degiþkeninin kontrolü
                                book_stats();       // Yapilan Rezerve iþlemlerinin istatistiklerinin hesaplanmasi
                                break;
							}
                            case 2:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 3:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 4:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 5:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 6:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 7:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 8:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 9:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 10:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 11:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 12:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
							default:{
								printf("\nLutfen gecerli bir hafta giriniz.");
								countTry++;
								break;
							}
						}
					}while(countTry<3);
					printf("\nBahar Doneminde Haftalara Gore Otel Doluluk yuzdeleri(%%) asagidaki gibidir: ");
					for(int i=0;i<12;i++){
                        printf("\n%d. Hafta :%%%d",i+1,stWeek[indSeason][i]);   // Hesaplanan istatistiklerin listelenmesi
					}
					printf("\nYeni Rezervasyon islemi icin 'E', Sistemden cikmak icin her-hangi bir harf giriniz :");
					scanf(" %c", &nwBook);
					if(nwBook == 'E'){
                        countTry=0;
					}
					else{
                        countTry=3;
					}

					break;
				}
				case 'Y':{
				    countTry=0;
				    double prStd=60,prLarge=400,prDelux=90;
                    do{
                        printf("Hotelde kalmak istediginiz hafta(1-12) :");
                        scanf("%d",&bkWeek);
						switch(bkWeek)
						{
							case 1:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 2:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 3:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 4:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 5:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 6:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 7:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 8:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 9:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 10:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 11:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 12:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
							default:{
								printf("\nLutfen gecerli bir hafta giriniz.");
								countTry++;
								break;
							}
						}
					}while(countTry<3);
					printf("\nBahar Doneminde Haftalara Gore Otel Doluluk yuzdeleri(%%) asagidaki gibidir: ");
					for(int i=0;i<12;i++){
                        printf("\n%d. Hafta :%%%d",i+1,stWeek[indSeason][i]);
					}
					printf("\nYeni Rezervasyon islemi icin 'E', Sistemden cikmak icin her-hangi bir harf giriniz :");
					scanf(" %c", &nwBook);
					if(nwBook == 'E'){
                        countTry=0;
					}
					else{
                        countTry=3;
					}

					break;
				}
				case 'S':{
				     double prStd=25,prLarge=250,prDelux=50;
				     countTry=0;
                    do{
                        printf("Hotelde kalmak istediginiz hafta(1-12) :");
                        scanf("%d",&bkWeek);
						switch(bkWeek)
						{
							case 1:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 2:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 3:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 4:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 5:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 6:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 7:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 8:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 9:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 10:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 11:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
                            case 12:{
                                do{
                                    printf("Standart Odalar icin 'S',Deluxe Odalar icin 'D',Large Deluxe Odalarimiz icin 'L' harfini tuslayiniz :");
                                    scanf(" %c",&bkRoom);
                                    switch(bkRoom){
                                        case 'S':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpStd,prStd,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'D':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpDelux,prDelux,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        case 'L':{
                                                    room_lister(bkWeek,bkSeason,bkRoom);
                                                    room_chooser(bkRoom,bkWeek);
                                                    guest_processes(cpLarge,prLarge,bkRoom);
                                                    countTry=3;
                                        break;
                                        }
                                        default:{
                                                    printf("\nLutfen gecerli bir oda tipi belirtiniz.");
                                                    countTry++;
                                        break;}
                                    }
                                }while(countTry<3);
                                book_stats();
                                break;
							}
							default:{
								printf("\nLutfen gecerli bir hafta giriniz.");
								countTry++;
								break;
							}
						}
					}while(countTry<3);
					printf("\nBahar Doneminde Haftalara Gore Otel Doluluk yuzdeleri(%%) asagidaki gibidir: ");
					for(int i=0;i<12;i++){
                        printf("\n%d. Hafta :%%%d",i+1,stWeek[indSeason][i]);
					}
					printf("\nYeni Rezervasyon islemi icin 'E', Sistemden cikmak icin her-hangi bir harf giriniz :");
					scanf(" %c", &nwBook);
					if(nwBook == 'E'){
                        countTry=0;
					}
					else{
                        countTry=3;
					}

					break;
				}
				default:{
					printf("\nGirdiginiz mevsim degeri gecersizdir lutfen tekrar deneyiniz.");
					countTry++;
					break;
                }
			}
    }while(countTry<3);

}
void room_creater(){  // Sezon ve Haftalara göre oda tiplerine uygun oda numaralarinin rmAll dizisine uygun degerlerin alindigi fonksiyon

       for(int s=0;s<3;s++){                // Sezon index döngüsü
                for(int w=0;w<12;w++){      // Hafta index döngüsü
                    indStd=0;
                    indDelux=0;
                        for(int t=0;t<3;t++ ){  // Oda Tipi döngüsü
                            indLarge=0;
                                for(int i=1;i<101;i++){ // Oda numarasi döngüsü

                                    if(t == 2){     // Oda Tipi  2 ise Large Odalari  index olarak temsil  ediliþidir
                                        if(i%2==0 && i%3==0){   // Large odalarda 6'nin katlari olan odalardir.
                                             rmAll[s][w][t][indLarge]=i;    //[indLarge] mantigi uygun index degerlerini indLarge sayaci ile aldirmaktir.
                                             //printf("[%d][%d][%d][%d]=%d\n",s,w,t,indLarge,rmAll[s][w][t][indLarge]);
                                             indLarge++;
                                        }
                                    }

                                    if(t == 1){ // Oda Tipi 1 ise Delux odalari index olarak temsil  ediliþidir
                                       if(i%2 == 0 && i%3 != 0){   // Delux odalar  2'nin katlari olan 6'nin katlarini içermeyen odalardir.
                                            rmAll[s][w][t][indDelux]=i;
                                           // printf("[%d][%d][%d][%d]=%d\n",s,w,t,indDelux,rmAll[s][w][t][indDelux]);
                                            indDelux++;
                                        }
                                    }


                                    if(t == 0) {    // Oda Tipi 0 Standart odalarin index olarak temsil  ediliþidir
                                        if(i%2 != 0){   // Standart odalar 1-100 arasindaki tek sayilara sahip odalardir.
                                            rmAll[s][w][t][indStd]=i;
                                            //printf("[%d][%d][%d][%d]=%d\n",s,w,t,indStd,rmAll[s][w][t][indStd]);
                                            indStd++;
                                            }
                                        }
                                }
                            }
                        }
                    }
}
int size_of(){  // Oda Tipine göre index adli degiþkenin diger metodlarda kullanilmak üzere uygun index Degerini aldigi fonksiyondur.
           if(indRoom == 0){
                index = indStd;
           }
           else if(indRoom==1){
                index = indDelux;
           }
           else{
                index = indLarge;
           }
           return index;
}

void room_lister(int bkWeek,char bkSeason,char bkRoom){ //  seçilen Hafta, seçilen Sezon ve Oda Tiplerini  içeren degiþkenleri alarak
           char_to_index(bkRoom,bkSeason);      // bkRoom ve bkSeason  degiþkenlerinin indexe çevrilmesi indRoom ve indSeason degiþkenlerinin bu  fonksiyon ile alinmasi
           size_of();       //  index degiþkeni alindi
           //printf("\n%d %d ",indRoom,indSeason);
           printf("---------------------------------------------------------");
           printf("\nBos Odalar:\n");
            for(int i=0;i<index;i++)        //  Alinan index numarasi ile boþ odalari listeleyen döngü
            {

                for(int j=0;j<100;j++)  // Rezerve edilen odalar ile Odalarin kontrolünün saglandigi döngü
                {
                    if( rmAll[indSeason][bkWeek-1][indRoom][i] ==  rmRezerved[indSeason][bkWeek-1][indRoom][j]) // Bu oda Daha önce secilmiþ mi?
                    {
                            rmAll[indSeason][bkWeek-1][indRoom][i]=0;       // Eger böyle bir oda  varsa ilgili odanin degerini 0 olarak yeniden düzenledik
                    }
                }
                if(rmAll[indSeason][bkWeek-1][indRoom][i] != 0)         //  Eger Oda numarasi 0 degilse
                {
                    if(i%2 == 0 && i%5 == 0 || i==100)
                    {
                    printf("\n");
                    }
                    printf("-- %d --", rmAll[indSeason][bkWeek-1][indRoom][i]);  // Odayi boþ odalardan biri olarak listele
                }

}


}
void room_chooser(char bkRoom,int bkWeek){  // bkRoom ve bkWeek degiþkenleri ile odalarin listelendigi fonksiyon
        size_of();  // ilgili index degerini aldik
        int flag_rmRezerved = 0,flag_rmName = 0;    // flag yapisi geregi  0 ve 1 degerlerini alan degiþkenleri tanimlandi
        countTry=0;
       do{
        printf("\nSectiginiz Oda:");
        scanf("%d",&rmChoosen);
        for(int i=0;i<100;i++){
            if(rmChoosen == rmRezerved[indSeason][bkWeek-1][indRoom][i]){   // Odanin daha önce secilen oda numaralarindan biri olup olmadigini kontrol edildi
                flag_rmRezerved  = 1;   // Eger secilmiþ bir odaysa flag degeri 1 olarak atandi
                countTry++;
                continue;
            }
        }
        for(int i=0;i<index;i++){
            if(rmChoosen == rmAll[indSeason][bkWeek-1][indRoom][i]){ // Secilen oda numarasinin secilmek istenen oda tipine ait bir numara olup olmadigini kontrol edildi
            flag_rmName = 1;    // varsa flag degeri 1 olarak ataniyor
            }
        }
        if(flag_rmName == 0){   // ilgili flag = 0 ise bu istenmeyen bir durumdur
           printf("Gecersiz secim islemi lutfen tekrar secim yapiniz:\n");
           countTry++;
        }
        else if(flag_rmRezerved == 1){ //ilgili flag = 1 ise bu istenmeyen bir durumdur
            printf("Gecersiz secim islemi lutfen tekrar secim yapiniz:\n");
            countTry++;
        }
        else{   // flaglar geçerli ise odanin tipine göre ilgili Rezerve oda dizisine alinmasi
            if(bkRoom =='S'){
                rmRezerved[indSeason][bkWeek-1][indRoom][rezStd] = rmChoosen;
                rezStd++;
            }
            else if(bkRoom='D'){
                rmRezerved[indSeason][bkWeek-1][indRoom][rezDelux] = rmChoosen;
                rezDelux++;
            }
            else {
                rmRezerved[indSeason][bkWeek-1][indRoom][rezLarge] = rmChoosen;
                rezLarge++;
            }
            countTry=3;
        }
       }while(countTry<3);
}
int char_to_index(char bkRoom,char bkSeason){   // bkRoom ve bkSeason char degerlerini indRoom ve indSeason degerlerine dönüstürdüğümüz fonksiyon

        if(bkRoom=='S'){indRoom=0; }
        else if(bkRoom=='D'){indRoom=1;}
        else{ indRoom=2;}
        if(bkSeason=='B'){indSeason=0; }
        else if(bkSeason=='Y'){indSeason=1;}
        else{ indSeason=2;}
        return indRoom,indSeason;       // indRoom ve indSeason olarak char olan bkRoom ve bkSeason'ı dönüstürdük

}

void book_payment(int cpName,int prName){   //ilgili oda tipine girilen kapasite ve fiyat değerleriyle ödeme işlemlerinin yapıldığı fonksiyon

        payStandart= cpName * prName;   // standart ödeme durumu hesaplanıyor

            do{
                printf("---------------------------------------------------------");
                printf("\nLutfen Yapmak istediginiz odeme seklini belirtiniz.\n");
                printf("On Odemeli Rezervasyon icin 'O', Havale ile Odeme icin 'H', Standart(Klasik) Odeme icin 'S' giriniz:");
                scanf(" %c",&payStyle);
                switch(payStyle){
                case 'O':{
                    grandTotal = payStandart*0.85;          // On odemeli durumda Toplam fiyat üzerinde yapılan %15lik indirimin hesaplanması
                    printf("Hizmet Tutari: %.2f TL",grandTotal);
                    countTry=3;
                break;}
                case  'H':{
                    if(cpName>3 && cpName<=5 ){
                    grandTotal = payStandart - prName * 0.5;        // Havale islemlerinde 3 kisiden fazla ise 4. kisi icin yapılan  %50 lik indirimin hesaplanması
                    printf("Hizmet Tutari: %.2f TL",grandTotal);
                    countTry=3;
                    }
                    else if(cpName > 5){
                    grandTotal = payStandart - prName * 0.75;   // Havale islemlerinde 5 kisiden fazla ise 6. kisi icin yapılan  %75 lik indirimin hesaplanması
                    printf("Hizmet Tutari: %.2f TL",grandTotal);
                    countTry=3;
                    }
                    else{
                        grandTotal = payStandart;
                        printf("Hizmet Tutari: %.2f TL",grandTotal);
                        countTry=3;
                    }
                break;}
                case 'S':{
                    grandTotal= payStandart;
                    printf("Hizmet Tutari: %.2f TL",grandTotal);
                    countTry=3;
                break;}
                default:{
                    printf("Gecersiz odeme sekli, odeme sekilleri:\n");
                    countTry++;
                 break;}
                }
        }while(countTry<3);
}

int guest_processes(int cpName,int prName,char bkRoom){ // Musteri islemlerinin yani Misafir sayisina göre ilgili islemlerin yapıldığı fonksiyon
            int cpMoment, countTry=0;
            do{
            if(cpName == 0){
            printf("Misafir Sayisi:");
            scanf("%d",&cpName);
            cpMoment = cpName;
            countTry=0;
            }
            else{
            if( ((bkRoom == 'D' || bkRoom=='S') && cpMoment > 4 && cpMoment < 200)) {
                room_lister(bkWeek,bkSeason,bkRoom);
                room_chooser(bkRoom,bkWeek);
                cpMoment-=4;

            }
            else if((bkRoom=='L' && cpMoment > 7 && cpMoment < 112 )){
                room_lister(bkWeek,bkSeason,bkRoom);
                room_chooser(bkRoom,bkWeek);
                cpMoment -= 7;
            }
            else if((bkRoom == 'D' || bkRoom=='S') && cpMoment > 0 && cpMoment <= 4){
                cpMoment -=4;
                book_payment(cpName,prName);
            }
            else if(bkRoom=='L' && cpName > 0 && cpName <= 7){
                cpMoment -=7;
                book_payment(cpName,prName);
            }
            else{
                printf("Gecersiz kisi sayisi lutfen tekrar kisi sayisi seciniz: ");
                countTry++;
            }
            }
            }while(cpMoment>=1 && countTry<3);

}

void book_stats(){      // Rezerve(book) edilen odaların istatistiklerinin hesaplanıp haftalık değerleri içeren diziye aktaran fonksiyon
            countStats=0;
            for(int i=0;i<100;i++)
            {
                for(int j=0;j<3;j++)
                {

                    if(rmRezerved[indSeason][bkWeek-1][j][i] != 0)
                    {
                       // printf("\n[%d][%d][%d][%d] = %d",indSeason,bkWeek-1,j,i,rmRezerved[indSeason][bkWeek-1][j][i]);
                        countStats++;
                    }
                }
            }
            stWeek[indSeason][bkWeek-1]=countStats;
}
