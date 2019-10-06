# EAE-Advertisement-App

#     #     İlan uygulaması     #     #
Bir buton ile bir LED’in uyarı sekansının ayarlanabildiği basit bir gömülü yazılım geliştirmenizi bekliyoruz.
Kullanıcı devrede bulunan bir butona kısa süre ile bastığında, yine aynı devredeki bir LED “kısa basma modu” döngüsüne, 
uzun süre bastığında ise “uzun basma modu” döngüsüne alınacaktır. Bahsedilen modlar;
Kısa basma modu: İki kere 1 saniyelik yanıp sönme, iki kere 2 saniyelik yanıp-sönme döngüsü
(on1sn-off1sn-on1sn-off1sn-on2sn-off2sn-on2sn-off2sn-on1sn-off1sn…)
Uzun basma modu: Dört kere 1 saniyelik yanıp-sönme, dört kere 2 saniyelik yanıp-sönme döngüsü
(on1sn-off1sn-on1sn-off1sn-on1sn-off1sn-on1sn-off1sn-on2sn-off2sn-on2sn-off2sn-on2sn-off2sn-on2sn-off2sn-on1sn-off1sn…)

Kurallar:
- Butona basma algılanırken 100ms debounce süresi kullanılacaktır. Uzun basma süresi 3 saniyedir.
- Uygulama kısa basma modunda başlar.
- Butona basılması durumu LED’in yanıp-sönme döngüsünü etkilemeyecektir. 
  Buton basılı tutulduğu sürece LED bulunduğu modun döngüsünde devam edecektir. 
  Buton bırakıldığında mod değişimi gerekiyorsa döngü yeni moda uygun olarak yeniden başlar (ör; uzun basma modunda iken kısa basma yapmak).
  Eğer mod değişimi gerekmiyorsa (ör; uzun basma modunda yine butona uzun basmak) LED döngüsü butona hiç basılmamış gibi devam edecektir.
