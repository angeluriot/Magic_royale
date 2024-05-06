# 🃏 Magic Royale

![Release](https://img.shields.io/badge/Release-v1.0-blueviolet)
![Language](https://img.shields.io/badge/Language-C%2B%2B-0052cf)
![Size](https://img.shields.io/badge/Size-269Ko-f12222)
![Open Source](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)

<br/>

*⚠️ This project was made for school with a deadline and I chose to leave it as it was at the time of submission ⚠️*

<br/>

This project is a simplified clone of the card game **[Magic the Gathering Arena](https://magic.wizards.com/en/mtgarena)**, it implements the basic mechanics of the game with a display in the console *(no external libraries were allowed)*. The major difference with the original game is that we took the cards from another game: **[Clash Royale](https://clashroyale.com)**.

<br/>

<p align="center">
	<img src="https://i.imgur.com/J6jsG0h.png" width="700">
</p>

<br/>

# 📋 Summary

* **[📋 Summary](#-summary)**
* **[✨ Features](#-features)**
* **[🃏 Cards](#-cards)**
	* [🏞️ Lands](#%EF%B8%8F-lands)
	* [🐉 Creatures](#-creatures)
	* [🪄 Spells](#-spells)
* **[🛠️ Install](#%EF%B8%8F-install)**
* **[🗓️ Releases](#%EF%B8%8F-releases)**
* **[🙏 Credits](#-credits)**

<br/>

# ✨ Features

- Create your own decks of cards *(with a **.txt** file in the* `decks` *folder)*.

- Start a game with two players and choose their names.

- Play the cards you want to use.

- Attack with your creatures.

- Block opponent's creatures.

- Change the order of attacks.

<br/>

# 🃏 Cards

The game has a total of 93 cards, 5 **[lands](#lands)**, 72 **[creatures](#creatures)** and 16 **[spells](#spells)**.

<br/>

## 🏞️ Lands

Land cards give you the resources to play other cards:

| Swamp | Island | Forest | Mountain | Plain |
| :-: | :-: | :-: | :-: | :-: |
| <img src="https://i.imgur.com/KphcUNf.png" height="180"> | <img src="https://i.imgur.com/YWiOqdI.png" height="180"> | <img src="https://i.imgur.com/U4tM6fS.png" height="180"> | <img src="https://i.imgur.com/7cehiJB.png" height="180"> | <img src="https://i.imgur.com/QaYI54P.png" height="180"> |
| ![Black](https://i.imgur.com/FOgaANE.png) Black | ![Blue](https://i.imgur.com/mIKhvAF.png) Blue | ![Green](https://i.imgur.com/wAQXqTG.png) Green | ![Red](https://i.imgur.com/KUtPu2A.png) Red | ![White](https://i.imgur.com/23AueSy.png) White |

<br/>

## 🐉 Creatures

Creatures cards can be played to attack or defend, they stay in the game until they die.

They can have standard capacities, see the list below:

- `Flying`: Only creatures whith `Reach` can attack it.
- `Reach`: Can attack `Flying` creatures.
- `First Strike`: Attack first.
- `Haste`: Can attack on first turn.
- `Unblockable`: Cannot be blocked and cannot attack while blocking.
- `Zone Damage`: Damages go to all blockers.
- `Multi Hit`: Attack both blockers and the player.
- `Freeze`: Low the blocker's dammages.
- `Kamikaze`: Die on attack.
- `Shield`: The shield takes the first hit.

They can also have unique abilities, their effect is described in the ***Unique ability*** column:

| Card | Type | Price | Power / Toughness | <div align="center">Capacities</div> | <div align="center">Unique ability</div> |
| :-: | :-: | :-: | :-: | :- | :- |
| <img src="https://i.imgur.com/ygCvjHx.png" height="100"><br/>**Electro Spirit** | Spirit | 1 | 2 / 1 | `Freeze`, `Kamikaze` | |
| <img src="https://i.imgur.com/GT0uFlD.png" height="100"><br/>**Fire Spirit** | Spirit | 1 | 2 / 1 | `Zone_Damage`, `Kamikaze` | |
| <img src="https://i.imgur.com/Lt4i4aR.png" height="100"><br/>**Ice Spirit** | Spirit | 1 | 1 / 2 | `Freeze`, `Kamikaze` | |
| <img src="https://i.imgur.com/SvxOw6f.png" height="100"><br/>**Skeletons** | Skeleton | 1 | 2 / 1 | | |
| <img src="https://i.imgur.com/Iapwgco.png" height="100"><br/>**Bats** | Bat | 1 ![Black](https://i.imgur.com/FOgaANE.png) | 3 / 1 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/fvjL2Xj.png" height="100"><br/>**Spear Goblins** | Goblin | 1 ![Red](https://i.imgur.com/KUtPu2A.png) | 2 / 2 | `Reach` | |
| <img src="https://i.imgur.com/lcXzhPC.png" height="100"><br/>**Bomber** | Skeleton | 1 ![Black](https://i.imgur.com/FOgaANE.png) | 3 / 1 | `Zone_Damage` | |
| <img src="https://i.imgur.com/ac1WLkK.png" height="100"><br/>**Goblins** | Goblin | 1 ![Red](https://i.imgur.com/KUtPu2A.png) | 2 / 2 | | |
| <img src="https://i.imgur.com/zlTZSbo.png" height="100"><br/>**Firecracker** | Human | 2 ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 2 | `Reach`, `Multi_Hit`, `Zone_Damage` | |
| <img src="https://i.imgur.com/iiSBL4k.png" height="100"><br/>**Goblin Gang** | Goblin | 2 ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 2 | `Reach` | Adds 1 power to all Goblin type allies while alive. |
| <img src="https://i.imgur.com/6xSK9Bh.png" height="100"><br/>**Minions** | Minion | 2 ![Blue](https://i.imgur.com/mIKhvAF.png) | 3 / 2 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/HrjyHZH.png" height="100"><br/>**Archers** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) | 3 / 2 | `Reach` | |
| <img src="https://i.imgur.com/Le34AAm.png" height="100"><br/>**Knight** | Knight | 2 ![White](https://i.imgur.com/23AueSy.png) | 2 / 3 | | |
| <img src="https://i.imgur.com/6QbWZiD.png" height="100"><br/>**Skeleton Dragons** | Dragon | 2 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 3 / 3 | `Flying`, `Reach`, `Zone_Damage` | |
| <img src="https://i.imgur.com/Kl0Om3v.png" height="100"><br/>**Rascals** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 3 / 4 | `Reach` | |
| <img src="https://i.imgur.com/Beqplf6.png" height="100"><br/>**Minion Horde** | Minion | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | 5 / 2 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/IjBmurT.png" height="100"><br/>**Barbarians** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 4 / 3 | | |
| <img src="https://i.imgur.com/lIHngL2.png" height="100"><br/>**Elite Barbarians** | Human | 4 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 4 / 4 | | |
| <img src="https://i.imgur.com/Vu0jRDv.png" height="100"><br/>**Royal Giant** | Giant | 4 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 5 | `Reach`, `Unblockable` | |
| <img src="https://i.imgur.com/aCytEtE.png" height="100"><br/>**Royal Recruits** | Human | 4 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 5 / 4 | `Multi_Hit` | |
| <img src="https://i.imgur.com/IRyHPmn.png" height="100"><br/>**Ice Golem** | Golem | 1 ![Green](https://i.imgur.com/wAQXqTG.png) | 1 / 3 | `Unblockable`, `Freeze` | Applies the effects of the Freeze capacity to all opponent creatures on death. |
| <img src="https://i.imgur.com/zCwYjyZ.png" height="100"><br/>**Elixir Golem** | Golem | 2 ![Green](https://i.imgur.com/wAQXqTG.png) | 1 / 4 | `Unblockable` | Spawns 1 Elixir Golemites on death. Elixir Golemites spawns 1 Sentient Blobs on death. Sentient Blobs gives 2 Forest cards to the opponent on death. |
| <img src="https://i.imgur.com/VcjPaX9.png" height="100"><br/>**Dart Goblin** | Goblin | 2 ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 2 | `Reach` | |
| <img src="https://i.imgur.com/N54TT37.png" height="100"><br/>**Mega Minion** | Minion | 2 ![Blue](https://i.imgur.com/mIKhvAF.png) | 2 / 3 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/MTG0aib.png" height="100"><br/>**Battle Healer** | Angel | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 1 / 3 | `Flying`, `Reach` | Adds 1 toughness to all allied creatures while alive. |
| <img src="https://i.imgur.com/4O5vBzt.png" height="100"><br/>**Flying Machine** | Machine | 3 ![White](https://i.imgur.com/23AueSy.png) | 2 / 4 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/LTHr2Vs.png" height="100"><br/>**Zappies** | Machine | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) | 3 / 3 | `Reach`, `Freeze` | |
| <img src="https://i.imgur.com/0ArQF4i.png" height="100"><br/>**Battle Ram** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) | 3 / 1 | `Haste`, `Unblockable`, `Kamikaze` | Spawns 1 Barbarian on death. |
| <img src="https://i.imgur.com/TO2JDw0.png" height="100"><br/>**Hog Rider** | Boar | 3 ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 3 | `Haste`, `Unblockable` | |
| <img src="https://i.imgur.com/kFXRIRI.png" height="100"><br/>**Mini Pekka** | Demon | 2 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 4 / 2 | | |
| <img src="https://i.imgur.com/GQ3PU4b.png" height="100"><br/>**Musketeer** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 3 / 3 | `Reach` | |
| <img src="https://i.imgur.com/h0j3dXs.png" height="100"><br/>**Valkyrie** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 2 / 4 | `Zone_Damage` | |
| <img src="https://i.imgur.com/8Gbkc15.png" height="100"><br/>**Wizard** | Wizard | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | 4 / 3 | `Reach`, `Zone_Damage` | |
| <img src="https://i.imgur.com/0C28J9h.png" height="100"><br/>**Royal Hogs** | Boar | 3 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 4 / 3 | `Haste`, `Unblockable` | |
| <img src="https://i.imgur.com/hwMIuWs.png" height="100"><br/>**Giant** | Giant | 3 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 2 / 5 | `Unblockable` | |
| <img src="https://i.imgur.com/fMBmVT3.png" height="100"><br/>**Three Musketeers** | Human | 6 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 6 / 5 | `Reach` | |
| <img src="https://i.imgur.com/VUq9QII.png" height="100"><br/>**Wall Breakers** | Skeleton | 1 ![Black](https://i.imgur.com/FOgaANE.png) | 5 / 2 | `Unblockable`, `Kamikaze` | |
| <img src="https://i.imgur.com/0Hvr81k.png" height="100"><br/>**Barbarian Barrel** | Human | 1 ![White](https://i.imgur.com/23AueSy.png) | 2 / 2 | `Haste` | Inflicts 1 damage to all enemy creatures on spawn. |
| <img src="https://i.imgur.com/qdJcuep.png" height="100"><br/>**Guards** | Skeleton | 2 ![Black](https://i.imgur.com/FOgaANE.png) | 2 / 3 | `Shield` | |
| <img src="https://i.imgur.com/EphIYxU.png" height="100"><br/>**Skeleton Army** | Skeleton | 2 ![Black](https://i.imgur.com/FOgaANE.png) | 4 / 1 | `Multi_Hit` | |
| <img src="https://i.imgur.com/9P3uC44.png" height="100"><br/>**Goblin Barrel** | Goblin | 2 ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 2 | `Haste`, `Unblockable` | |
| <img src="https://i.imgur.com/bfFlRGY.png" height="100"><br/>**Hunter** | Humain | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 3 / 3 | `Reach`, `Multi_Hit`, `Zone_Damage` | |
| <img src="https://i.imgur.com/8WD6DLs.png" height="100"><br/>**Dark Prince** | Knight | 2 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 2 / 4 | `Haste`, `Zone_Damage`, `Shield` | |
| <img src="https://i.imgur.com/zX1y63x.png" height="100"><br/>**Baby Dragon** | Dragon | 3 ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 3 | `Flying`, `Reach`, `Zone_Damage` | |
| <img src="https://i.imgur.com/56G9WCU.png" height="100"><br/>**Electro Dragon** | Dragon | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | 4 / 3 | `Flying`, `Reach`, `Freeze` | |
| <img src="https://i.imgur.com/rxwhdoY.png" height="100"><br/>**Cannon Cart** | Machine | 4 ![White](https://i.imgur.com/23AueSy.png) | 3 / 4 | | Spawns 1 Cannon on death. |
| <img src="https://i.imgur.com/Bf0MVSe.png" height="100"><br/>**Executioner** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 3 / 4 | `Multi_Hit`, `Reach` | |
| <img src="https://i.imgur.com/ZnynJFK.png" height="100"><br/>**Bowler** | Goblin | 3 ![Red](https://i.imgur.com/KUtPu2A.png) ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 4 | `Zone_Damage`, `Multi_Hit` | |
| <img src="https://i.imgur.com/mE27QBU.png" height="100"><br/>**Prince** | Knight | 3 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 4 / 3 | `First_Strike`, `Haste` | |
| <img src="https://i.imgur.com/JYyqA2C.png" height="100"><br/>**Witch** | Wizard | 4 ![Blue](https://i.imgur.com/mIKhvAF.png) | 3 / 4 | `Reach`, `Zone_Damage` | Spawns 1 Skeleton every turn. |
| <img src="https://i.imgur.com/AiuozVy.png" height="100"><br/>**Balloon** | Skeleton | 3 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 5 / 2 | `Flying`, `Unblockable`, `Zone_Damage` | Inflicts 1 damage to all enemy creatures on death. |
| <img src="https://i.imgur.com/NTWy762.png" height="100"><br/>**Goblin Giant** | Goblin | 4 ![Red](https://i.imgur.com/KUtPu2A.png) ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 5 | `Reach`, `Unblockable` | Spawns 1 Spear Goblins on death |
| <img src="https://i.imgur.com/d3axxNd.png" height="100"><br/>**Giant Skeleton** | Skeleton | 4 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 2 / 6 | | Inflicts 3 damages to all enemy creatures on death. |
| <img src="https://i.imgur.com/39mEPiV.png" height="100"><br/>**Pekka** | Demon | 5 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 4 / 5 | | |
| <img src="https://i.imgur.com/p2uIjqR.png" height="100"><br/>**Electro Giant** | Giant | 5 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 7 | `Reach`, `Unblockable`, `Freeze` | |
| <img src="https://i.imgur.com/GiMOBzC.png" height="100"><br/>**Golem** | Golem | 6 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 2 / 8 | `Unblockable` | Inflicts 1 damage to all enemy creatures and spawns 1 Golemites on death. Golemites also inflicts 1 damage to all enemy creatures on death. |
| <img src="https://i.imgur.com/fu0vypQ.png" height="100"><br/>**Fisherman** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) | 2 / 3 | `First_Strike` | |
| <img src="https://i.imgur.com/gAC6ScV.png" height="100"><br/>**Royal Ghost** | Specter | 2 ![Black](https://i.imgur.com/FOgaANE.png) | 3 / 2 | `First_Strike` | |
| <img src="https://i.imgur.com/RVdRLge.png" height="100"><br/>**Bandit** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) | 3 / 2 | `First_Strike`, `Haste` | |
| <img src="https://i.imgur.com/hinKLqx.png" height="100"><br/>**Miner** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) | 2 / 3 | `Haste`, `Unblockable` | |
| <img src="https://i.imgur.com/reOtyLp.png" height="100"><br/>**Princess** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) | 3 / 2 | `Reach`, `Zone_Damage` | |
| <img src="https://i.imgur.com/MfnINC5.png" height="100"><br/>**Ice Wizard** | Wizard | 2 ![Blue](https://i.imgur.com/mIKhvAF.png) | 2 / 3 | `Reach`, `Zone_Damage`, `Freeze` | Inflicts the effects of Freeze capacity to all enemy creatures on spawn. |
| <img src="https://i.imgur.com/V2iEXmS.png" height="100"><br/>**Mother Witch** | Wizard | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) | 2 / 4 | `Reach` | Turns creatures she kills into hogs. |
| <img src="https://i.imgur.com/FmdMCVe.png" height="100"><br/>**Magic Archer** | Elf | 3 ![White](https://i.imgur.com/23AueSy.png) | 3 / 3 | `Reach`, `Multi_Hit` | |
| <img src="https://i.imgur.com/rCzWjTF.png" height="100"><br/>**Night Witch** | Wizard | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) | 3 / 3 | | Spawns 1 Bat every turn. |
| <img src="https://i.imgur.com/p2cZOFO.png" height="100"><br/>**Electro Wizard** | Wizard | 2 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | 3 / 3 | `Reach`, `Multi_Hit`, `Freeze` | Inflicts 1 damage to all enemy creatures on spawn. |
| <img src="https://i.imgur.com/uXVGetW.png" height="100"><br/>**Inferno Dragon** | Dragon | 2 ![Red](https://i.imgur.com/KUtPu2A.png) ![Red](https://i.imgur.com/KUtPu2A.png) | 4 / 2 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/eYF3T7T.png" height="100"><br/>**Lumberjack** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) | 4 / 2 | | Casts a Rage spell 1 turn after his death. |
| <img src="https://i.imgur.com/pZMg2IW.png" height="100"><br/>**Ram Rider** | Human | 3 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 4 | `Multi_Hit`, `Freeze`, `Haste` | |
| <img src="https://i.imgur.com/jJ0MLEB.png" height="100"><br/>**Sparky** | Machine | 5 ![Blue](https://i.imgur.com/mIKhvAF.png) | 5 / 3 | `Zone_Damage` | |
| <img src="https://i.imgur.com/HllRYOd.png" height="100"><br/>**Mega Knight** | Knight | 5 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 3 / 6 | `First_Strike`, `Zone_Damage` | Inflicts 2 damages to all enemy creatures on spawn. |
| <img src="https://i.imgur.com/8nvT4xs.png" height="100"><br/>**Lava Hound** | Demon | 5 ![Red](https://i.imgur.com/KUtPu2A.png) ![Red](https://i.imgur.com/KUtPu2A.png) | 2 / 7 | `Flying`, `Reach`, `Unblockable` | Spawns 1 Lava Pups on death. |

<br/>

## 🪄 Spells

Spell cards can be played to apply effects on the game:

| Card | Price | <div align="center">Effect</div> |
| :-: | :-: | :- |
| <img src="https://i.imgur.com/JLcTIHI.png" height="100"><br/>**Giant Snowball** | 1 ![Blue](https://i.imgur.com/mIKhvAF.png) | Reduces power by 1 for all enemy creatures. |
| <img src="https://i.imgur.com/1XaYXqT.png" height="100"><br/>**Zap** | 1 ![Blue](https://i.imgur.com/mIKhvAF.png) | Inflicts 1 damage to all enemy creatures. |
| <img src="https://i.imgur.com/QdxT6C1.png" height="100"><br/>**Arrows** | 2 ![White](https://i.imgur.com/23AueSy.png) | Inflicts 2 damages to all enemy creatures. |
| <img src="https://i.imgur.com/SVnpUbM.png" height="100"><br/>**Heal Spirit** | 1 | Increases toughness by 1 for all allied creatures. |
| <img src="https://i.imgur.com/2EucZoB.png" height="100"><br/>**Earthquake** | 2 ![Green](https://i.imgur.com/wAQXqTG.png) | Inflicts 3 damages to enemy creatures that do not have the `Flying` capacity. |
| <img src="https://i.imgur.com/ceGqlpp.png" height="100"><br/>**Fireball** | 2 ![Red](https://i.imgur.com/KUtPu2A.png) ![Red](https://i.imgur.com/KUtPu2A.png) | Inflicts 3 damages to all enemy creatures. |
| <img src="https://i.imgur.com/leYKSVj.png" height="100"><br/>**Rocket** | 4 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | Inflicts 6 damages to the target of your choice. |
| <img src="https://i.imgur.com/IL5njAc.png" height="100"><br/>**Mirror** | 1 ![White](https://i.imgur.com/23AueSy.png) | Adds a copy of the last summoned creature in your hand. |
| <img src="https://i.imgur.com/OQlWbdY.png" height="100"><br/>**Rage** | 1 ![White](https://i.imgur.com/23AueSy.png) | Increases power by 1 for all allied creatures. |
| <img src="https://i.imgur.com/w8DdJUA.png" height="100"><br/>**Clone** | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) | Duplicates all your creatures but with 1 toughness. |
| <img src="https://i.imgur.com/HBP2HKt.png" height="100"><br/>**Tornado** | 2 ![Green](https://i.imgur.com/wAQXqTG.png) | Inflicts 1 damage and reduces power by 1 to all enemy creatures. |
| <img src="https://i.imgur.com/fpFMiVW.png" height="100"><br/>**Poison** | 2 ![Red](https://i.imgur.com/KUtPu2A.png) ![Red](https://i.imgur.com/KUtPu2A.png) | Inflicts 2 damages and reduces power by 1 to all enemy creatures. |
| <img src="https://i.imgur.com/Kqzm5YD.png" height="100"><br/>**Freeze** | 2 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | The opponent cannot block on this turn. |
| <img src="https://i.imgur.com/oB1X6Fv.png" height="100"><br/>**Lightning** | 4 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | Inflicts 4 damages to all enemy creatures. |
| <img src="https://i.imgur.com/ri5hNrz.png" height="100"><br/>**The Log** | 1 ![Green](https://i.imgur.com/wAQXqTG.png) | Inflicts 2 damages to enemy creatures that do not have the `Flying` capacity. |
| <img src="https://i.imgur.com/mLaiDeQ.png" height="100"><br/>**Graveyard** | 3 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | Resurrects the last two cards of the graveyard. |

<br/>

# 🛠️ Install

### Makefile

```shell
$ make
$ make run
```

### CMake

See the [installation part](https://github.com/angeluriot/Skeleton#install) of my **[Skeleton project template](https://github.com/angeluriot/Skeleton)**.

<br/>

# 🗓️ Releases

If you just want to test the program without editing the source code, go see the **[Releases](https://github.com/angeluriot/Magic_royale/releases)**.

<br/>

# 🙏 Credits

* [**Angel Uriot**](https://github.com/angeluriot) : Co-creator of the project.
* [**Arthur Azambre**](https://github.com/arthurazambre) : Co-creator of the project.
