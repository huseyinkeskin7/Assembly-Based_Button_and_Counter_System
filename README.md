# Assembly-Based_Button_and_Counter_System
# Türkçe
Bu projede, Assembly dili kullanılarak iki farklı sistem geliştirilmiştir:
    Durum Değişim Algılayıcı (State Change Detection):
    Bir buton yardımıyla yapılan her basış sayısı takip edilir. Basış sayısı 3’e tam bölünüyorsa LED1 yanar, aksi durumda LED2 yanar. Her 3 basışta sayaç sıfırlanır.
    Mod-10 Yukarı/Aşağı Sayıcı (Mod-10 Up/Down Counter):
        PB1: Sayacı artırır (0’dan 9’a).
        PB2: Sayacı azaltır (9’dan 0’a).
        PB3: Mevcut değeri sabitler (pause).
        CD4511 entegresi ve 7 segment display kullanılarak gösterim yapılır.
Bu proje, mikrodenetleyicilerde Assembly dilinin doğrudan donanım kontrolündeki gücünü göstermek için temel bir uygulama sunar.

# English
This project features two independent systems written in Assembly language:
    State Change Detection:
    A button press is counted. If the count is divisible by 3, LED1 lights up; otherwise, LED2 turns on. The counter resets every 3 presses.
    Mod-10 Up/Down Counter:
        PB1: Increments the counter (0 to 9).
        PB2: Decrements the counter (9 to 0).
        PB3: Freezes the current value (pause).
        Uses CD4511 IC and 7-segment display for output.
This project demonstrates low-level hardware control through microcontrollers using Assembly, ideal for learning timing, logic control, and peripheral handling.
