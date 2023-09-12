# Projet en C

## Partie 1

Dans un cadre de renforcement sécuritaire de son infrastructure, la société SecU vous charge de développer une bibliothèque de fonctions en langage C.  

- generate_password
- is_password_strong
- cypher_rotate
- get_file_header
- is_file_png
- html_minifier

<br>

__generate_password__  
Entrée: longueur du mot de passe, présence de caractères spéciaux (0/1)  
Sortie: chaîne de caractères aléatoire contenant des lettres de l’alphabet (minuscule et majuscule), des chiffres et, selon paramétrage, des caractères spéciaux.  
Exemple d’utilisation: generate_password(10, 1) => pM2ga_bn1#  
<br>

__is_password_strong__  
Entrée: chaîne de caractères  
Sortie: 1 si la chaîne réunit toutes ces conditions:  
- de longueur 10 au moins
- contient au moins une majuscule
- contient au moins un chiffre
- contient au moins un caractère spécial  

0 sinon.  
Exemple d’utilisation: is_password_strong(“abc”) => 0   
<br>

__cypher_rotate__  
Implémentation du chiffrement par décalage/rotation (cf chiffre de César)  
Entrée: chaîne de caractères, sens de la rotation, longueur du décalage  
Sortie: chaîne de caractères avec décalage des caractères  
La rotation ne se fera que pour les lettres de l’alphabet minuscules.  
Exemple d’utilisation: cypher_rotate(“ab2aZ”, 0, 1) => “bc2bZ”    
Lien (Chiffre de César en python): https://www.tutorialspoint.com/cryptography_with_python/cryptography_with_python_caesar_cipher.htm  
<br>

__get_file_header__  
Entrée: fichier binaire  
Sortie: format de fichier trouvé (parmi ceux recherchés)  
On se limitera à rechercher les formats de fichier suivants: jpg, png, exe, pdf, doc  
Lien: https://en.wikipedia.org/wiki/List_of_file_signatures  
<br>

__is_file_png__  
Entrée: fichier binaire  
Sortie: 1 si le fichier est au format PNG, 0 sinon  
<br>

__html_minifier__  
Entrée: fichier html avec indentations et sauts de ligne  
Sortie: fichier html sans indentations et sans sauts de ligne    
Vous pouvez tester la fonction sur le fichier projet.html présent dans le dépôt  


## Partie 2

La société SecU vous charge de créer trois programmes:  
- secu_encrypt
- secu_generator
- secu_wc  

### secu_encrypt
Le programme devra rendre illisible un fichier en permutant plusieurs de ses octets.  

__Les règles de permutation.__  
Une clé sera fournie au programme (par argument de ligne de commande).  
Cette clé sera de longueur comprise en 4 et 10. Seuls les caractères de l’alphabet minuscule seront autorisés.  
Prévoir une gestion d’erreur dans le cas où la clé n’est pas fournie ou bien si elle ne respecte pas les contraintes.  
<br>
La longueur de la clé permettra de déterminer le nombre de permutations à réaliser.  
Si la clé est de longueur 5, 5 permutations seront à réaliser.  
<br> 
La longueur de la chaîne sera divisée par 2 afin de dissocier deux sous-chaînes de caractères. Si la chaîne est de longueur impaire, seule la partie entière de la division sera retenue.  
<br>
A chaque caractère sera associé un indice numérique (a:1, b:2, etc.).  
Les équivalences numériques de chaque caractère seront ensuite additionnées pour chaque sous-chaîne afin d’obtenir la position des deux   premiers octets à permuter.  
<br>
On multipliera ensuite itérativement (de 2 jusqu’à la longueur maximale de la clé) les positions initiales afin de déterminer la positions des prochains octets à permuter.  
<br>
<br>
si k = abdce, longueur impaire (5), “e” est ignoré  
a:1 + b:2 = 3  
c:3 + d:4 = 7  
5 permutations entre les octets suivants: 3 ⇔ 7, 6 ⇔ 14, 9 ⇔ 21, 12 ⇔ 28, 15 ⇔ 35  
<br>
si k = christophe, longueur paire (10)  
c:3 + h:8 + r:18 + i:9 + s:19 = 57  
t:20 + o:15 + p:16 + h:8 + e:5 = 64  
10 permutations entre les octets suivants: 57 ⇔ 64, 114 ⇔ 128, 171 ⇔ 192, …  
<br>
Une option permettra de savoir si l’on est en mode cryptage ou décryptage.  
En mode cryptage le fichier de sortie prendra l’extension supplémentaire .enc  
En mode décryptage le fichier de sortie perdra l’extension .enc  
<br>
Le programme refusera d’encrypter des fichiers de taille non comprise entre 1KB et 100KB.  
<br>

__Exemples d’utilisation de la commande:__  
secu_crypt -e -k abcde -f file1.png => output: fichier secu_file1.png.enc (fichier crypté)  
secu_crypt -d -k abcde -f secu_file1.png.enc => output: fichier secu_file1.png (fichier décrypté)  
<br>
<br>
Rédiger un script python itérant sur la totalité d’un dossier afin de crypter l’ensemble des fichiers s’y trouvant.  
Le script exécutera le programme secu_crypt sous forme de sous-processus.  
Il affichera dans la console, à chaque encryptage, un log de type “Fichier xxx encrypté”.  
Lien (vidéo youtube sur Python subprocess): https://youtu.be/2Fp1N6dof0Y  

### secu_generator 
Le programme générera au choix:  
- des caractères: a-Z + caractères spéciaux au choix  
- des chiffres: 0-9  
- de l’hexadécimal (0-9 + A-F)   
- des octets (mode binaire)  
<br>
Les éléments générés se feront de façon aléatoire et sur une longueur paramétrable.  
<br>
Par défaut la sortie standard sera l’écran/terminal mais une option de ligne de commande permettra de choisir de l’enregistrer dans un fichier.  
<br>
<br>

__Exemples d’utilisation de la commande:__  
secu_generator -c 1000              => affiche 1000 caractères dans le terminal  
secu_generator -c 1000 -f tmp.txt   => écrit 1000 caractères dans un fichier tmp.txt  
secu_generator -n 50                => affiche 50 chiffres dans le terminal  
secu_generator -b 1024 -f file      => écrit 1024 octets dans le fichier file  
secu_generator -h 32                => affiche une chaîne hexa de longueur 32 dans le terminal	  

### secu_wc
Le programme sera une “reproduction” de la commande linux wc.  
Lien: https://www.malekal.com/la-commande-wc-utilisation-et-exemples/  
Il s’agit d’une imitation partielle. Pas besoin d’implémenter toutes les options.  
Seule l’option -c (limiter la sortie sur le nombre de caractères seulement) est requise.   
<br>

__Exemples d’utilisation de la commande:__  
secu_wc file1.txt       => output: 5 10 100 file1.txt   
secu_wc -c file1.txt    => output: 100 file1.txt  