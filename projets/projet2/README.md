# Projet en C

Ecrire les programmes suivants:  
- file_merge
- html_checker
- base_converter
- lipsum

### file_merge
Programme fusionnant (concaténant) et "défusionnant" des fichiers.
Le programme prendra par la ligne de commande le noms de fichiers à fusionner.
Sortie: fichier unique créé par la fusion des fichiers pris en entrée 
<br>
Le programme, par une option -u, devra "unmerge" le fichier  
<br>
Trouver un moyen de stocker dans le fichier de sortie, les informations
vous permettant de "défusionner" les fichiers par la suite.
<br>
Des fichiers de différents types pourront être fusionnés.

__Exemples d'utilisation de la commande:__  
file_merge file1.png file2.png file3.pdf => output: fichier files.merge  
file_merge -u files.merge => output: fichiers file1.png file2.png file3.pdf
<br>
<br>

### html_checker
Le programme vérifiant  le bon format (partiel) d'un fichier html. 
Le programme vérifiera que chaque balise ouvrante parmis celles recherchées est accompagnée de la balise fermante correspondante.   
Balises recherchées: 
```
<strong>, <p>, <h1>, <h2>, <a>
```

__Exemples d'utilisation de la commande:__  
html_checker file.html => output: ok   
html_checker file_bad.html => output: not ok 
<br>
<br>

### base_converter
Programme donnant deux autres bases à partir d'une fournie en entrée. 
Bases prises en compte: binaire (2), décimale (10), hexadécimale (16)   
Option indiquant la base de départ: -b (2, 10, 16) 

__Exemples d'utilisation de la commande:__  
base_converter 42 -b 10 => output: 101010 (2) 2A (16)   
base_converter 2A -b 16 => output: 101010 (2) 42 (10)
<br>
<br>

### lipsum  
En cours de rédaction...