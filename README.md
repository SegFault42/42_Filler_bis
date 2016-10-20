# Filler

![Filler](https://i.gyazo.com/ce73d175e0bfcf5365d5f6430789287d.png)

##Install :
```bash
git clone https://github.com/SegFault42/42_Filler_bis.git
cd 42_Filler_bis
make
```

##Usage :
```bash
./resources/filler_vm -f resources/maps/map01 -p1 "./rabougue.filler -sgraphic" -p2 ./resources/players/hcao.filler

Launch program with a graphical interface "./rabougue.filler -graphic"
Lauch program with music "./rabougue.filler -s"
Showing final game result in percent "./rabougue.filler -p"
Print final map "./rabougue.filler -m"
```

##Main features
<img align="right" src="https://upload.wikimedia.org/wikipedia/fr/2/26/SDL_logo.png" width="25%" />
- Volume control
- Pause music
- Pause program
- Screenshot
- Design with SDL2

## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change volume</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd> or <kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Pause program</td>
<td valign="top" align="center"><kbd>&nbsp;space&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Pause music</td>
<td valign="top" align="center"><kbd>&nbsp;return&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Take a screenshot</td>
<td valign="top" align="center"><kbd>&nbsp;p&nbsp;</kbd></td>
</tr>
</tbody>
</table>

=======================================================================================================================

Résumé: Créez votre programme joueur pour affronter d’autres étudiants sur le célèbre (ou pas) plateau du Filler. Le principe est simple : deux joueurs s’affrontent sur un plateau, et doivent placer, tour à tour, la pièce que le maître du jeu (fourni sous la forme d’un exécutable Ruby) leur donne, gagnant ainsi des points. La partie s’arrête dès qu’une pièce ne peut plus être placée. Petit projet ludique !

Lien du sujet : [Filler.pdf][Filler]

### Langage autorisé:

- C

### Fonctions autorisées :
- read
- write
- malloc
- free
- perror
- strerror


   [Filler]: <https://github.com/SegFault42/42_Filler_bis/blob/master/filler.fr.pdf>

