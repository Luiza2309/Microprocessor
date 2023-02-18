Task 1
Salvez bitii numarului dat de la tastatura intr-un vector. Vectorul contine bitii in ordine inversa pentru comoditate. 
Primii 3 biti sunt transformati in baza 10 si salvati in N. 
Bitii de la 3 pana la (2*N+3)-1 reprezinta operatiile, se citesc doi cate doi biti si se verifica ce operatie reprezinta, urmand sa fie afisate.
Ultimii 4 biti sunt transformati in baza 10 si salvati in Dim.

Task 2
Citesc numere de la tastatura in functie de formula ((N+1)*Dim)/16. Le convertesc pe biti si le salvez intr-un vector.
Vectorul este impartit in secvente care au lungimea Dim, fiind 16/Dim secvente. Parcurg fiecare secventa si convertesc in baza 10,
iar rezultatul este salvat in vectorul operanzi[] care contine toti operanzii.
Parcurg bitii numarului initial si efectuez operatiile corespunzatoare intre operanzi.

Task 3
Salvez toti bitii numerelor citite de la tastatura intr-un vector s[]. Vectorul este impartit in secvente de lungimea Dim.
Fiecare secventa este parcursa si convertita in baza 10, rezultatul fiind salvat in vectorul operanzi[].
Se efectueaza calculele ca in programul precedent.

Task 4
Cauta intre operanzi inmultirea si impartirea, tinand cont de elementele intre care se afla aceste operatii.
Daca gaseste o inmultire sau o impartire o efectueaza si o salveaza in primul element din operatie, stergand al doilea element.
Toti ceilalti operanzi sunt copiati cu o pozitie inainte. Sunt date cu o pozitie inainte si toate operatiile situate dupa inmultire si impartire.
Se parcurge din nou vectorul operanzilor si cel al operatiilor, efectuandu-se adunarea si scaderea. (dupa prima parcurge nu mai sunt operatii de
inmultire si impartire in vectorul operatiilor)

ex:
1+2*3*4-5  =>  1+6*3*4-5  =>  1+6*4*5-  =>  1+6*4-5  =>  1+24*4-5  =>  1+24*5-  =>  1+24-5  =>  25-5  =>  20